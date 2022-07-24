OUTPUT_FORMAT("binary")
ENTRY (kmain)

SECTIONS
{
  . = 0x100000;
	/* The kernel will live at 3GB in the virtual address space, */
	/* which will be mapped to 1MB in the physical address space. */

  phys = .;

	. = 0xC0000000;

	_kernel_start = .;

	/* Add a symbol that indicates the start address of the kernel. */
	.text ALIGN (4K) : AT (phys + (ADDR (.text) - 0xC0000000))
	{
		*(.text)
	}
	.rodata ALIGN (4K) : AT (phys + (ADDR (.rodata) - 0xC0000000))
	{
		*(.rodata)
	}
	.data ALIGN (4K) : AT (phys + (ADDR (.data) - 0xC0000000))
	{
		*(.data)
	}
	.bss ALIGN (4K) : AT (phys + (ADDR (.bss) - 0xC0000000))
	{
    _hello = .;
		*(COMMON)
		*(.bss)
	}
	/* Add a symbol that indicates the end address of the kernel. */
	_kernel_end = .;
}