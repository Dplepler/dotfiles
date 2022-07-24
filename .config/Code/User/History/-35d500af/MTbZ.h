#ifndef GDT_H
#define GDT_H

typedef struct _GDT_DESCRIPTOR_STRUCT {

  uint16_t limit;
  uint16_t base_ll;
  uint8_t base_mh;
  uint8_t access;
  uint8_t flags_and_limit;
  uint8_t base_hh;

} __attribute__((packed)) gdtDescriptor;



#endif