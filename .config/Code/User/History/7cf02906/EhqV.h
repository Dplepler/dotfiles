#ifndef HEAP_H
#define HEAP_H

#include "vmm.h"

#define HEAP_SIGNATURE 0xB00B5555

typedef struct _HEAP_HEADER_STRUCT {

  uint32_t signature;
  size_t size;          // Requested size
  size_t rsize;         // Actual size created where rsize >= size

  struct _HEAP_HEADER_STRUCT*  flink;
  struct _HEAP_HEADER_STRUCT*  blink;

  struct _HEAP_HEADER_STRUCT* split_flink;




} heap_header;

void* malloc(size_t size);




#endif