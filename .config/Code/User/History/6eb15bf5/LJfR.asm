%macro ISR_NO_ERROR 1

  push byte 0
  push byte %1
  jmp isr_common_handler

%endmacro

%macro ISR_ERROR 1
 
  push byte %1
  jmp isr_common_handler

%endmacro

global _isr0
_isr0: ISR_NO_ERROR 0
global _isr1
_isr1: ISR_NO_ERROR 1
global _isr2
_isr2: ISR_NO_ERROR 2
global _isr3
_isr3: ISR_NO_ERROR 3
global _isr4
_isr4: ISR_NO_ERROR 4
global _isr5
_isr5: ISR_NO_ERROR 5
global _isr6
_isr6: ISR_NO_ERROR 6
global _isr7
_isr7: ISR_NO_ERROR 7
global _isr8
_isr8: ISR_ERROR 8
global _isr9
_isr9: ISR_NO_ERROR 9
global _isr10
_isr10: ISR_ERROR 10
global _isr11
_isr11: ISR_ERROR 11
global _isr12
_isr12: ISR_ERROR 12 
global _isr13
_isr13: ISR_ERROR 13 
global _isr14
_isr14: ISR_ERROR 14
global _isr15
_isr15: ISR_NO_ERROR 15
global _isr16
_isr16: ISR_NO_ERROR 16
global _isr17
_isr17: ISR_ERROR 17
global _isr18
_isr18: ISR_NO_ERROR 18
global _isr19
_isr19: ISR_NO_ERROR 19
global _isr20
_isr20: ISR_NO_ERROR 20
global _isr21
_isr21: ISR_NO_ERROR 21
global _isr22
_isr22: ISR_NO_ERROR 22
global _isr23
_isr23: ISR_NO_ERROR 23
global _isr24 
_isr24: ISR_NO_ERROR 24
global _isr25
_isr25: ISR_NO_ERROR 25
global _isr26
_isr26: ISR_NO_ERROR 26
global _isr27
_isr27: ISR_NO_ERROR 27
global _isr28
_isr28: ISR_NO_ERROR 28
global _isr29
_isr29: ISR_NO_ERROR 29
global _isr30
_isr30: ISR_NO_ERROR 30
global _isr31
_isr31: ISR_NO_ERROR 31


extern _fault_handler

isr_common_handler:

  ; Save registers
  pusha
  push ds
  push es
  push fs
  push gs

  ; Load the data segment descriptor
  mov ax, 0x10 
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  push esp
  
  mov eax, _fault_handler
  call eax      
  pop eax
  pop gs
  pop fs
  pop es
  pop ds
  popa
  add esp, 8     ; Cleanup
  iret           ; Return from interrupt




