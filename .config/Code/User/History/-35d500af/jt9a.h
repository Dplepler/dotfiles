#ifndef GDT_H
#define GDT_H

typedef struct _GDT_DESCRIPTOR_STRUCT {

  uint16_t limit;
  uint16_t base_ll;


} __attribute__((packed)) gdtDescriptor;



#endif