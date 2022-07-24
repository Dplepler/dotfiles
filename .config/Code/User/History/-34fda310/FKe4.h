#ifndef VMM_H
#define VMM_H

#include "pmm.h"

#define PD_ADDRESS      0xFFFFF000  
#define PD_OFFSET       0xFFC00000  // Used when calculating with different addresses to get a page table 

#define ENTRIES 0x400     // Amount of table entries

void* memset(void* addr, uint8_t c, size_t n);
void* memcpy(void* s1, const void* s2, size_t n);

pgulong_t* page_physical_address(pgulong_t* addr);
pgulong_t page_get_entry_index(pgulong_t* addr);
pgulong_t* page_get_table_address(uint16_t pd_index);
int page_check_free_page_memory(pgulong_t* table_addr, size_t length);
pgulong_t* page_get_free_addr(size_t length);
pgulong_t* page_map(pgulong_t* addr, size_t length, uint16_t flags);
bool page_unmap(pgulong_t* addr, size_t length);
bool page_is_empty(pgulong_t* pt_addr);
bool page_is_aligned(pgulong_t* addr);

pgulong_t* pd_assign_table(pgulong_t pd_index, uint16_t flags);
pgulong_t pd_get_entry_index(pgulong_t* addr);
bool pd_remove_entry(pgulong_t* addr);

void pd_remove_empty_pt(pgulong_t pd_index);
void pd_flush_tlb(pgulong_t pd_index);
void page_clean(pgulong_t* addr);


#endif