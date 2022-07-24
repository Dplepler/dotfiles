#ifndef GDT_H
#define GDT_H

typedef struct _GDT_DESCRIPTOR_STRUCT {

  uint16_t limit;
  uint16_t base_ll;
  uint8_t base_hh;
  uint8_t flags1;
  uint8_t flags2_and_limit;
  


} __attribute__((packed)) gdtDescriptor;



#endif