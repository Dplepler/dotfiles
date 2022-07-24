#include "pmm.h"

static uint32_t frame_bitmap[NPAGES / BITS_IN_LONG];

void bitmap_mark_kernel() {

  size_t kernel_pages = (pgulong_t)(((uint32_t)&_kernel_end) - ((uint32_t)&_kernel_start)) / 0x1000;      
  const uint32_t kernel_first_index = ((uint32_t)&_kernel_start) / 0x1000;    

  /* Mark all kernel's page frames as used in the bitmap */
  for (uint32_t i = 0; i <= kernel_pages; i++) {
    MARK_USED(frame_bitmap, (kernel_first_index + i));
  }
}


/*
palloc_single allocates a single free page and marks it as used
Output: Unused page frame address
*/
pgulong_t* palloc_single() {

  uint32_t i = 0;

  /* Search for a free page */
  /* We calculate 32 bits each time, so we can easily skip big chunks of used memory */
  for (; i < NPAGES; i++) {
    if (frame_bitmap[i] ^ ~0 && CHECK_FREE_FRAME(frame_bitmap, i)) { break; }   
  }

  if (i == NPAGES) { PANIC("You ran out of RAM :("); }

  MARK_USED(frame_bitmap, i);

  return (pgulong_t*)(i * 0x1000);     // Return free page frame
}