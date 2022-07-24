#ifndef GDT_H
#define GDT_H

typedef struct _GDT_DESCRIPTOR_STRUCT {

  uint32_t null1;
  uint32_t null2;


} __attribute__((packed)) gdtDescriptor;



#endif