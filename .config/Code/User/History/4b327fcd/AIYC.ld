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
	.text ALIGN (4K) : AT (_kernel_start)
	{
		*(.text)
	}
	.rodata ALIGN (4K) : AT (_kernel_start + (ADDR (.rodata) - ADDR (.text)))
	{
    rodata = .;
		*(.rodata)
	}
	.data ALIGN (4K) : AT (_kernel_start + (data - ADDR (.rodata)))
	{
    data = .;
		*(.data)
	}
	.bss ALIGN (4K) : AT (_kernel_start + (ADDR (.bss) - ADDR (.data)))
	{
    _hello = .;
		*(COMMON)
		*(.bss)
	}
	/* Add a symbol that indicates the end address of the kernel. */
	_kernel_end = .;
}