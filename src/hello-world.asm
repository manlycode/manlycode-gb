; vi: ft=z80
include "gbhw.inc"
include "ibmpc1.inc"
include "memory.inc"

; Interrupt Vector
SECTION "Vblank",ROM0[$0040]
	reti
SECTION "Lcdc",ROM0[$0048]
	reti
SECTION "Timer",ROM0[$0050]
	reti
SECTION "Serial",ROM0[$0058]
	reti
SECTION "P1thru4",ROM0[$0060]
	reti


SECTION "HEADER",ROM0[$0100]
	nop
	jp begin
	ROM_HEADER	ROM_NOMBC, ROM_SIZE_32KBYTE, RAM_SIZE_0KBYTE



SECTION "Program",ROM0[$0150]
	INCLUDE "tiles.inc"

begin:
	di		; disable the interrupts

	ld sp,$ffff	; Set the stack pointer to highest memory location +1

	
	ld a, %11100100 ; set up the background palette
	ld [rBGP], a
	
	call StopLCD

	; turn the ldc back on
	ld	a, LCDCF_ON|LCDCF_BG8000|LCDCF_BG9800|LCDCF_BGON|LCDCF_OBJ16|LCDCF_OBJOFF 
	ld	[rLCDC], a	

	; set up the tile data
	ld hl, tiles_tile_data
	ld de, _VRAM
	ld bc, tiles_tile_data_size
	call mem_CopyVRAM

	; set up the map
	ld hl, tiles_map_data
	ld de, _SCRN0
	ld bc, tiles_tile_map_size
	call mem_CopyVRAM

	ld b, 20
	ld c, 50
loop:
	ld a, [rLY]   ; wait until we're at a vblank (lcd y coordinate)
	cp 145        ; are we at LCD line 145?
	jr  nz,loop  ; no? keep waiting

	dec b
	jr nz, loop

	dec c
	call z, InvertPalette

	call IncrementYScroll
	ld b, 20

	jr loop

InvertPalette:
	ld a, [rBGP]
	xor a, %11111111
	ld [rBGP], a
	ld c, 50
	ret

StopLCD:
	ld a,0		; set up the scroll registers
	ld [rSCX], a
	ld [rSCY], a

	ld a, [rLCDC]	; Turn off the lcd
	rlca		; rotate register a left 
	ret nc	; is the screen already off? Is bit 7 a 1?

.wait:
	ld a, [rLY]   ; wait until we're at a vblank (lcd y coordinate)
	cp 145	      ; are we at LCD line 145?
	jr  nz,.wait  ; no? keep waiting

	ret


IncrementXScroll:
	ld hl, rSCX
	ld a, [hl]
	inc a
	ld [hl], a
	ret

IncrementYScroll:
	ld hl, rSCY
	ld a, [hl]
	inc a
	ld [hl], a
	ret
