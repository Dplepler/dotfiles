DAP_START:

	DAP_SIZE:

		db 10h

	DAP_NULL:

		db 0

	DAP_SECTORS:

		dw 16

	DAP_KERNEL_OFFSET:

		dw KERNEL_OFFSET
		dw 0

	; Write third disk sector, where kernel is located on the disk
	DAP_LBA:

		dd 2h	
		dd 0

DAP_END:	
