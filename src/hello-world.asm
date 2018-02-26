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

	
	ld a, %11100000 ; set up the background palette
	ld [rBGP], a

	ld a, %11100100 ; set up the sprite palette
	ld [rOBP0], a
	
	call StopLCD


	; top left
	ld hl, _OAMRAM
	ld a, 60
	ldi [hl], a
	ld a, 60
	ldi [hl], a
	ld a, 0
	ldi [hl], a
	ld a, OAMF_PAL0
	ldi [hl], a

	; top right
	ld a, 60
	ldi [hl], a
	ld a, 68
	ldi [hl], a
	ld a, 1
	ldi [hl], a
	ld a, OAMF_PAL0
	ldi [hl], a

	; bottom left
	ld a, 68
	ldi [hl], a
	ld a, 60
	ldi [hl], a
	ld a, 3
	ldi [hl], a
	ld a, OAMF_PAL0
	ldi [hl], a

	; bottom right
	ld a, 68
	ldi [hl], a
	ld a, 68
	ldi [hl], a
	ld a, 4
	ldi [hl], a
	ld a, OAMF_PAL0
	ldi [hl], a


	; turn the ldc back on
	ld	a, LCDCF_ON|LCDCF_BG8000|LCDCF_BG9800|LCDCF_BGON|LCDCF_OBJ8|LCDCF_OBJON
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


	; OAM ram
	; Byte 0: LCD Y coord
	; Byte 1: LCD X coord
	; Byte 2: CHR Code
	; Byte 3: Attribute Flag
	;   Bit 7: display priority
	;   Bit 6: vertical flip
	;   Bit 5: horizontal flip
	;   Bit 4: DMG palette


	; ld hl, $fe04
	; ld a, 80
	; ldi [hl], a
	; ld a, 80
	; ldi [hl], a
	; ld a, 1
	; ldi [hl], a
	; ld a, OAMF_PAL0
	; ldi [hl], a



	ld b, 20
	ld c, 50
loop:
	ld a, [rLY]   ; wait until we're at a vblank (lcd y coordinate)
	cp 145        ; are we at LCD line 145?
	jr  nz,loop  ; no? keep waiting

	dec b
	jr nz, loop

	dec c
	; call z, InvertPalette

	call IncrementYScroll
	call MoveSprite
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

MoveSprite:
	ld hl, _OAMRAM+1
	ld a, [hl]
	inc a

	; cp 160 ; max x?
	; call z, ResetSprite

	ld [hl], a

	ld hl, _OAMRAM+5
	ld a, [hl]
	inc a
	ld [hl], a

	ld hl, _OAMRAM+9
	ld a, [hl]
	inc a
	ld [hl], a

	ld hl, _OAMRAM+13
	ld a, [hl]
	inc a
	ld [hl], a
	ret

; ResetSprite:
; 	ld b, 0
; 	ld [_OAMRAM+1], b
; 	ld [_OAMRAM+5], b
; 	ld [_OAMRAM+9], b
; 	ld [_OAMRAM+13], b
; 	ret
; 
