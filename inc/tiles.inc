; vi: ft=z80
; ///////////////////////
; //                   //
; //  File Attributes  //
; //                   //
; ///////////////////////

; Filename: tiles.png
; Pixel Width: 256px
; Pixel Height: 256px

; /////////////////
; //             //
; //  Constants  //
; //             //
; /////////////////

tiles_tile_map_size EQU $0400
tiles_tile_map_width EQU $20
tiles_tile_map_height EQU $20

tiles_tile_data_size EQU $B0
tiles_tile_count EQU $0400

; ////////////////
; //            //
; //  Map Data  //
; //            //
; ////////////////

tiles_map_data:
DB $00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02
DB $00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02
DB $03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02
DB $03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02
DB $02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01
DB $02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01
DB $02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04
DB $02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04
DB $00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02
DB $00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02
DB $03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02
DB $03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02
DB $02,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06
DB $07,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06
DB $02,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09
DB $0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09
DB $05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02
DB $05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02
DB $08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02
DB $08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02
DB $02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01
DB $02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01
DB $02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04
DB $02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04
DB $00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02
DB $00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02
DB $03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02
DB $03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02
DB $02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01
DB $02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01
DB $02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04
DB $02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04
DB $00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02
DB $00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02
DB $03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02
DB $03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02
DB $02,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06
DB $07,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06
DB $02,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09
DB $0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09
DB $05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02
DB $05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02
DB $08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02
DB $08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02
DB $02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01
DB $02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01
DB $02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04
DB $02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04
DB $00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02
DB $00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02
DB $03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02
DB $03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02
DB $02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01
DB $02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01
DB $02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04
DB $02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04
DB $00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02
DB $00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02,$00,$01,$02,$02
DB $03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02
DB $03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02,$03,$04,$02,$02
DB $02,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06
DB $07,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06,$07,$02,$05,$06
DB $02,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09
DB $0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09,$0A,$02,$08,$09

; /////////////////
; //             //
; //  Tile Data  //
; //             //
; /////////////////

tiles_tile_data:
DB $FF,$7F,$FF,$C0,$FF,$A0,$FF,$9F,$FF,$90,$FF,$90,$FF,$90,$FF,$90
DB $FF,$FE,$FF,$03,$FD,$07,$F9,$FF,$F9,$0F,$F9,$0F,$F9,$0F,$F9,$0F
DB $FF,$00,$FF,$00,$FF,$00,$FF,$00,$FF,$00,$FF,$00,$FF,$00,$FF,$00
DB $FF,$90,$FF,$90,$FF,$90,$FF,$90,$FF,$9F,$E0,$BF,$C0,$FF,$FF,$7F
DB $F9,$0F,$F9,$0F,$F9,$0F,$F9,$0F,$F9,$FF,$05,$FF,$03,$FF,$FF,$FE
DB $FF,$3F,$FF,$60,$FF,$50,$FF,$4F,$FF,$48,$FF,$48,$FF,$48,$FF,$48
DB $FF,$FF,$FF,$01,$FE,$03,$FC,$FF,$FC,$07,$FC,$07,$FC,$07,$FC,$07
DB $FF,$00,$FF,$80,$FF,$80,$FF,$80,$FF,$80,$FF,$80,$FF,$80,$FF,$80
DB $FF,$48,$FF,$48,$FF,$48,$FF,$48,$FF,$4F,$F0,$5F,$E0,$7F,$FF,$3F
DB $FC,$07,$FC,$07,$FC,$07,$FC,$07,$FC,$FF,$02,$FF,$01,$FF,$FF,$FF
DB $FF,$80,$FF,$80,$FF,$80,$FF,$80,$FF,$80,$FF,$80,$FF,$80,$FF,$00
