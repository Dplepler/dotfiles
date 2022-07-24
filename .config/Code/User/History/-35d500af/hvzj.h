#ifndef GDT_H
#define GDT_H

typedef struct _GDT_DESCRIPTOR_STRUCT {

  uint16_t limit;
  


} __attribute__((packed)) gdtDescriptor;



#endif