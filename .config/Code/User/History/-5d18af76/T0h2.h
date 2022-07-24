#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>

/* Gate types
0b0101 or 0x5: Task Gate, note that in this case, the offset value is unused and should be set to zero.
0b0110 or 0x6: 16-bit Interrupt Gate
0b0111 or 0x7: 16-bit Trap Gate
0b1110 or 0xE: 32-bit Interrupt Gate
0b1111 or 0xF: 32-bit Trap Gate
*/

/* Useful attributes
0x8E: 32 bit Interrupt Gate
0x8F: 32 bit Trap Gate
0x85: Task Gate
*/

/* Descriptor table entry */
typedef struct _INTERRUPT_DESCRIPTOR_STRUCT {

  uint16_t offset_lh; // Lower half of interrupt address
  uint16_t selector;  // Code segment
  uint8_t unused;     // Not used, should be 0
  uint8_t attributes; // Gate type
  uint16_t offset_hh; // Higher half of interrupt address

} InterruptDescriptor;

typedef struct _DESCRIPTOR_POINTER_STRUCT {


} idtptr;

typedef struct 

#endif