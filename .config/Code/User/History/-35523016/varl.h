#ifndef PMM_H
#define PMM_H

#define NPAGES 0x100000       // Pages in RAM
#define BITS_IN_LONG 32
#define BITS_IN_BYTE 8

#define CHECK_FREE_FRAME(bitmap, i) (!CHECK_USED_FRAME(bitmap, i))
#define CHECK_USED_FRAME(bitmap, i) (bitmap[(uint32_t)i / BITS_IN_LONG] &   (1 << ((uint32_t)i % BITS_IN_LONG)))
#define MARK_USED(bitmap, i)        (bitmap[(uint32_t)i / BITS_IN_LONG] |=  (1 << ((uint32_t)i % BITS_IN_LONG)))
#define MARK_UNUSED(bitmap, i)      (bitmap[(uint32_t)i / BITS_IN_LONG] &= ~(1 << ((uint32_t)i % BITS_IN_LONG)))

#define CHANGE_PD(pd) asm("mov %0, %%eax\nmov %%eax, %%cr3":: "m"(pd))

#define MAX_PAGES_ALLOCATED 20

void bitmap_mark_kernel();



#endif