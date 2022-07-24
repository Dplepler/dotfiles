#include "pmm.h"

static uint32_t frame_bitmap[NPAGES / BITS_IN_LONG];


/*

*/
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

/* 
pallocn allocates a specified amount of page frames 
in addition it will mark these pages as used

Input: Frame address array, amount to allocate
*/
void pallocn(pgulong_t** frames, size_t size) {
  for (size_t i = 0; i < size; i++) {
    frames[i] = palloc_single();
  }
}

/*
palloc allocates pages and returns their offsets

This function will allocate a chunk of pages each time to increase performance
*/
pgulong_t* palloc() {

  static bool allocate = true;
  static uint8_t pallocated = 0;
  static pgulong_t* current_frames[MAX_PAGES_ALLOCATED];

  if (pallocated == MAX_PAGES_ALLOCATED) { allocate = true; }
  
  /* Allocate N pages */
  if (allocate) { 
    pallocn(current_frames, MAX_PAGES_ALLOCATED); 
    pallocated = allocate = 0;    
  }

  pallocated++;
  return current_frames[pallocated - 1];
}