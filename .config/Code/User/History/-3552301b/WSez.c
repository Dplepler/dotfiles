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
