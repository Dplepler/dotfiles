#ifndef HAL_H
#define HAL_H

#include <stddef.h>
#include <stdint.h>

uint8_t inportb(uint16_t port);
void outportb(uint16_t port, uint8_t value);

static inline void flush_tlb_single(unsigned long* addr) {
   __asm__ __volatile__ ("invlpg (%0)" ::"r" (addr) : "memory");
}

static inline void flush_tlb_all() {

    __asm__ __valotile__ ("movl cr3, ")


}

#endif