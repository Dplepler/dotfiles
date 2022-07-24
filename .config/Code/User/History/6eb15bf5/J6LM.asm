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
_isr0: ISR_NO_ERROR
global _isr1
_isr1: ISR_NO_ERROR
global _isr2
_isr2: ISR_NO_ERROR
global _isr3
_isr3: ISR_NO_ERROR
global _isr4
_isr4: ISR_NO_ERROR
global _isr5
_isr5: ISR_NO_ERROR
global _isr6
_isr6: ISR_NO_ERROR
global _isr7
_isr7: ISR_NO_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8
_isr8: ISR_ERROR
global _isr8


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




