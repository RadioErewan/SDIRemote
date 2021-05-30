/*
 *
 * Arial_14
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : Arial14.h
 * Date                : 02.05.2008
 * Font size in bytes  : 7788
 * Font width          : 13
 * Font height         : 14
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#ifndef SHARED_12_H
#define SHARED_12_H

#define SHARED_12_WIDTH 07
#define SHARED_12_HEIGHT 10

/*
 * added for backward compability
 */



GLCDFONTDECL(shared12) = {
    0x14, 0x61, // size

    0x07, // width
    0x10, // height
    0x20, // first char
    0x5f, // char count
    
    0x02, 0x01, 0x04, 0x06, 0x05, 0x8, 0x07, 0x01, 0x03, 0x03, 0x07, 0x06, 0x02, 0x05, 0x01, 0x07, 0x06, 0x05, 0x05, 0x05, 0x06, 0x05, 0x05, 0x05, 0x06, 0x05, 0x01, 0x02, 0x06, 0x06, 0x06, 0x05, 0x8, 0x07, 0x06, 0x05, 0x06, 0x05, 0x05, 0x06, 0x06, 0x04, 0x05, 0x06, 0x05, 0x07, 0x06, 0x07, 0x06, 0x07, 0x07, 0x05, 0x07, 0x06, 0x07, 0x07, 0x07, 0x07, 0x06, 0x03, 0x07, 0x03, 0x06, 0x8, 0x03, 0x07, 0x06, 0x05, 0x06, 0x06, 0x05, 0x06, 0x06, 0x06, 0x04, 0x05, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x05, 0x05, 0x05, 0x06, 0x07, 0x07, 0x07, 0x07, 0x05, 0x04, 0x01, 0x04, 0x05,
    
 
    // @0 ' ' (2 pixels wide)
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    0x00, 0x00,
    0x00, 0x00,
    
    // @4 '!' (1 pixels wide)
    //
    //
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    //
    //
    // #
    //
    //
    //
    0xFC,
    0x13,
    
    // @6 '"' (4 pixels wide)
    //
    //
    // ## #
    // ## #
    // ## #
    //  # #
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    0x1C, 0x3C, 0x00, 0x3C,
    0x00, 0x00, 0x00, 0x00,
    
    // @14 '#' (6 pixels wide)
    //
    //
    //  ## #
    //  ## #
    //  ## #
    // ######
    //  ## #
    //  ## #
    //  ## #
    // ######
    //  ## #
    //  ## #
    //  ## #
    //
    //
    //
    0x20, 0xFC, 0xFC, 0x20, 0xFC, 0x20,
    0x02, 0x1F, 0x1F, 0x02, 0x1F, 0x02,
    
    // @26 '$' (5 pixels wide)
    //   #
    //   #
    //  ####
    // ##
    // #
    // #
    // #
    // ####
    //    ##
    //     #
    //     #
    //    ##
    // ####
    //   #
    //
    //
    0xF8, 0x8C, 0x87, 0x84, 0x04,
    0x10, 0x10, 0x30, 0x19, 0x0F,
    
    // @36 '%' (8 pixels wide)
    //
    //
    //  ###
    //  # ##
    //  # ##
    //  ###
    //      ###
    // #####
    //     ###
    //     #  #
    //     #  #
    //     #  #
    //      ##
    //
    //
    //
    0x80, 0xBC, 0xA4, 0xBC, 0x98, 0x40, 0x40, 0x40,
    0x00, 0x00, 0x00, 0x00, 0x0F, 0x11, 0x11, 0x0E,
    
    // @52 '&' (7 pixels wide)
    //
    //
    //  ####
    //  #
    // ##
    //  #
    //  ######
    // ##  ##
    // ##  ##
    // ##  ##
    // ##  ##
    // ##  ##
    //  #####
    //
    //
    //
    0x90, 0xFC, 0x44, 0x44, 0xC4, 0xC0, 0x40,
    0x0F, 0x1F, 0x10, 0x10, 0x1F, 0x1F, 0x00,
    
    // @66 ''' (1 pixels wide)
    //
    //
    // #
    // #
    // #
    // #
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    0x3C,
    0x00,
    
    // @68 '(' (3 pixels wide)
    //  ##
    // ##
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // ##
    //  ##
    //
    0xFE, 0x03, 0x01,
    0x3F, 0x60, 0x40,
    
    // @74 ')' (3 pixels wide)
    // ##
    //  #
    //  ##
    //  ##
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //  ##
    //  ##
    //  #
    // ##
    //
    0x01, 0x0F, 0xFC,
    0x40, 0x78, 0x1F,
    
    // @80 '*' (7 pixels wide)
    //
    //
    //    #
    //    #
    // #######
    //   ##
    //  ## #
    //  #  ##
    //
    //
    //
    //
    //
    //
    //
    //
    0x10, 0xD0, 0x70, 0x3C, 0xD0, 0x90, 0x10,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    
    // @94 '+' (6 pixels wide)
    //
    //
    //
    //
    //
    //    #
    //    #
    // ######
    //    #
    //    #
    //    #
    //
    //
    //
    //
    //
    0x80, 0x80, 0x80, 0xE0, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
    
    // @106 ',' (2 pixels wide)
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //  #
    //  #
    //  #
    // ##
    //
    0x00, 0x00,
    0x40, 0x78,
    
    // @110 '-' (5 pixels wide)
    //
    //
    //
    //
    //
    //
    //
    // #####
    //
    //
    //
    //
    //
    //
    //
    //
    0x80, 0x80, 0x80, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00,
    
    // @120 '.' (1 pixels wide)
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    // #
    //
    //
    //
    0x00,
    0x10,
    
    // @122 '/' (7 pixels wide)
    //      ##
    //      #
    //      #
    //     ##
    //     #
    //     #
    //    #
    //    #
    //   ##
    //   #
    //   #
    //  ##
    //  #
    // ##
    // #
    //
    0x00, 0x00, 0x00, 0xC0, 0x38, 0x0F, 0x01,
    0x60, 0x38, 0x0F, 0x01, 0x00, 0x00, 0x00,
    
    // @136 '0' (6 pixels wide)
    //
    //
    //  ####
    //  #  ##
    // ##   #
    // ##  ##
    // ## ###
    // ## # #
    // ###  #
    // ###  #
    // ##   #
    //  #  ##
    //  ####
    //
    //
    //
    0xF0, 0xFC, 0x04, 0xC4, 0x6C, 0xF8,
    0x07, 0x1F, 0x13, 0x10, 0x18, 0x0F,
    
    // @148 '1' (5 pixels wide)
    //
    //
    //  ##
    // # #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    // #####
    //
    //
    //
    0x08, 0x04, 0xFC, 0x00, 0x00,
    0x10, 0x10, 0x1F, 0x10, 0x10,
    
    // @158 '2' (5 pixels wide)
    //
    //
    // ####
    //    #
    //    ##
    //    ##
    //    ##
    //    #
    //   ##
    //  ##
    // ##
    // #
    // #####
    //
    //
    //
    0x04, 0x04, 0x04, 0xFC, 0x70,
    0x1C, 0x16, 0x13, 0x11, 0x10,
    
    // @168 '3' (5 pixels wide)
    //
    //
    // ####
    //    #
    //    ##
    //    ##
    //    #
    // ####
    //    ##
    //    ##
    //    ##
    //    ##
    // ####
    //
    //
    //
    0x84, 0x84, 0x84, 0xFC, 0x30,
    0x10, 0x10, 0x10, 0x1F, 0x0F,
    
    // @178 '4' (6 pixels wide)
    //
    //
    //   #
    //   #
    //  ##
    //  ##
    //  #  #
    //  #  #
    // ##  #
    // ######
    //     #
    //     #
    //     #
    //
    //
    //
    0x00, 0xF0, 0x3C, 0x00, 0xC0, 0x00,
    0x03, 0x03, 0x02, 0x02, 0x1F, 0x02,
    
    // @190 '5' (5 pixels wide)
    //
    //
    // ####
    // #
    // #
    // #
    // ####
    //    ##
    //    ##
    //    ##
    //    ##
    //    ##
    // ####
    //
    //
    //
    0x7C, 0x44, 0x44, 0xC4, 0x80,
    0x10, 0x10, 0x10, 0x1F, 0x0F,
    
    // @200 '6' (5 pixels wide)
    //
    //
    // ####
    // #
    // #
    // #
    // ####
    // #   #
    // #   #
    // #   #
    // #   #
    // #  ##
    //  ###
    //
    //
    //
    0xFC, 0x44, 0x44, 0x44, 0x80,
    0x0F, 0x10, 0x10, 0x18, 0x0F,
    
    // @210 '7' (5 pixels wide)
    //
    //
    // #####
    //    ##
    //    ##
    //    #
    //    #
    //   ##
    //   #
    //   #
    //  ##
    //  #
    //  #
    //
    //
    //
    0x04, 0x04, 0x84, 0xFC, 0x1C,
    0x00, 0x1C, 0x07, 0x00, 0x00,
    
    // @220 '8' (6 pixels wide)
    //
    //
    //  ####
    //  #  ##
    //  #   #
    //  #   #
    //  #  ##
    //  ####
    //  #   #
    // ##   #
    // ##   #
    // ##   #
    //  #####
    //
    //
    //
    0x00, 0xFC, 0x84, 0x84, 0xCC, 0x78,
    0x0E, 0x1F, 0x10, 0x10, 0x10, 0x1F,
    
    // @232 '9' (5 pixels wide)
    //
    //
    // ####
    // #  ##
    // #   #
    // #   #
    // #   #
    // #   #
    // #####
    //     #
    //     #
    //    ##
    // ####
    //
    //
    //
    0xFC, 0x04, 0x04, 0x0C, 0xF8,
    0x11, 0x11, 0x11, 0x19, 0x0F,
    
    // @242 ':' (1 pixels wide)
    //
    //
    //
    //
    //
    // #
    //
    //
    //
    //
    //
    //
    // #
    //
    //
    //
    0x20,
    0x10,
    
    // @244 ';' (2 pixels wide)
    //
    //
    //
    //
    //
    //  #
    //
    //
    //
    //
    //
    //  #
    //  #
    //  #
    // ##
    //
    0x00, 0x20,
    0x40, 0x78,
    
    // @248 '<' (6 pixels wide)
    //
    //
    //
    //
    //      #
    //    ###
    //  ###
    // ##
    // ###
    //   ####
    //      #
    //
    //
    //
    //
    //
    0x80, 0xC0, 0x40, 0x60, 0x20, 0x30,
    0x01, 0x01, 0x03, 0x02, 0x02, 0x06,
    
    // @260 '=' (6 pixels wide)
    //
    //
    //
    //
    //
    //
    // ######
    //
    //
    // ######
    //
    //
    //
    //
    //
    //
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
    
    // @272 '>' (6 pixels wide)
    //
    //
    //
    //
    // #
    // ####
    //    ###
    //      #
    //    ###
    //  ###
    // ##
    //
    //
    //
    //
    //
    0x30, 0x20, 0x20, 0x60, 0x40, 0xC0,
    0x04, 0x06, 0x02, 0x03, 0x01, 0x01,
    
    // @284 '?' (5 pixels wide)
    //
    //
    // ####
    //    #
    //    ##
    //    ##
    //    #
    //   #
    //  ##
    //  ##
    //
    //
    //  ##
    //
    //
    //
    0x04, 0x04, 0x84, 0x7C, 0x30,
    0x00, 0x13, 0x13, 0x00, 0x00,
    
    // @294 '@' (8 pixels wide)
    //
    //
    //  #######
    //  #     #
    // ## ### #
    // ## # # #
    // #### # #
    // #### # #
    // #### # #
    // #### # #
    // ## #####
    //  #
    //  #####
    //
    //
    //
    0xF0, 0xFC, 0xC4, 0xF4, 0x14, 0xF4, 0x04, 0xFC,
    0x07, 0x1F, 0x13, 0x17, 0x14, 0x17, 0x04, 0x07,
    
    // @310 'A' (7 pixels wide)
    //
    //
    //   ##
    //   ###
    //   # #
    //   # #
    //  ## #
    //  #  ##
    //  #   #
    //  #####
    // ##   #
    // #    ##
    // #    ##
    //
    //
    //
    0x00, 0xC0, 0x7C, 0x0C, 0xF8, 0x80, 0x00,
    0x1C, 0x07, 0x02, 0x02, 0x02, 0x1F, 0x18,
    
    // @324 'B' (6 pixels wide)
    //
    //
    // #####
    // ##  ##
    // ##   #
    // ##   #
    // ##   #
    // #####
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ######
    //
    //
    //
    0xFC, 0xFC, 0x84, 0x84, 0x8C, 0x78,
    0x1F, 0x1F, 0x10, 0x10, 0x10, 0x1F,
    
    // @336 'C' (5 pixels wide)
    //
    //
    //  ####
    // ##
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // ##
    //  ####
    //
    //
    //
    0xF8, 0x0C, 0x04, 0x04, 0x04,
    0x0F, 0x18, 0x10, 0x10, 0x10,
    
    // @346 'D' (6 pixels wide)
    //
    //
    // ######
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ######
    //
    //
    //
    0xFC, 0xFC, 0x04, 0x04, 0x04, 0xFC,
    0x1F, 0x1F, 0x10, 0x10, 0x10, 0x1F,
    
    // @358 'E' (5 pixels wide)
    //
    //
    // #####
    // #
    // #
    // #
    // #
    // #####
    // #
    // #
    // #
    // #
    // #####
    //
    //
    //
    0xFC, 0x84, 0x84, 0x84, 0x84,
    0x1F, 0x10, 0x10, 0x10, 0x10,
    
    // @368 'F' (5 pixels wide)
    //
    //
    // #####
    // #
    // #
    // #
    // #
    // #####
    // #
    // #
    // #
    // #
    // #
    //
    //
    //
    0xFC, 0x84, 0x84, 0x84, 0x84,
    0x1F, 0x00, 0x00, 0x00, 0x00,
    
    // @378 'G' (6 pixels wide)
    //
    //
    //  #####
    //  #
    //  #
    // ##
    // ##
    // ## ###
    // ##   #
    // ##   #
    //  #   #
    //  #   #
    //  #####
    //
    //
    //
    0xE0, 0xFC, 0x04, 0x84, 0x84, 0x84,
    0x03, 0x1F, 0x10, 0x10, 0x10, 0x1F,
    
    // @390 'H' (6 pixels wide)
    //
    //
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ######
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    //
    //
    //
    0xFC, 0xFC, 0x80, 0x80, 0x80, 0xFC,
    0x1F, 0x1F, 0x00, 0x00, 0x00, 0x1F,
    
    // @402 'I' (4 pixels wide)
    //
    //
    // ####
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    // ####
    //
    //
    //
    0x04, 0x04, 0xFC, 0x04,
    0x10, 0x10, 0x1F, 0x10,
    
    // @410 'J' (5 pixels wide)
    //
    //
    //  ####
    //    ##
    //    ##
    //    ##
    //    ##
    //    ##
    //    ##
    //    ##
    //    ##
    //    #
    // ####
    //
    //
    //
    0x00, 0x04, 0x04, 0xFC, 0xFC,
    0x10, 0x10, 0x10, 0x1F, 0x07,
    
    // @420 'K' (6 pixels wide)
    //
    //
    // ##  ##
    // ##  #
    // ## ##
    // ## #
    // ###
    // ###
    // ## #
    // ## ##
    // ##  #
    // ##  ##
    // ##   #
    //
    //
    //
    0xFC, 0xFC, 0xC0, 0x30, 0x1C, 0x04,
    0x1F, 0x1F, 0x00, 0x03, 0x0E, 0x18,
    
    // @432 'L' (5 pixels wide)
    //
    //
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #####
    //
    //
    //
    0xFC, 0x00, 0x00, 0x00, 0x00,
    0x1F, 0x10, 0x10, 0x10, 0x10,
    
    // @442 'M' (7 pixels wide)
    //
    //
    // ##   ##
    // ##  # #
    // ### # #
    // # # # #
    // # # # #
    // # ##  #
    // # ##  #
    // #     #
    // #     #
    // #     #
    // #     #
    //
    //
    //
    0xFC, 0x1C, 0xF0, 0x80, 0x78, 0x04, 0xFC,
    0x1F, 0x00, 0x01, 0x01, 0x00, 0x00, 0x1F,
    
    // @456 'N' (6 pixels wide)
    //
    //
    // ###  #
    // ###  #
    // ###  #
    // ###  #
    // #### #
    // ## # #
    // ## # #
    // ## # #
    // ## ###
    // ##  ##
    // ##  ##
    //
    //
    //
    0xFC, 0xFC, 0x7C, 0xC0, 0x00, 0xFC,
    0x1F, 0x1F, 0x00, 0x07, 0x1C, 0x1F,
    
    // @468 'O' (7 pixels wide)
    //
    //
    //  #####
    // ##   #
    // ##   ##
    // ##   ##
    // ##   ##
    // ##   ##
    // ##   ##
    // ##   ##
    // ##   ##
    // ##   #
    //  #####
    //
    //
    //
    0xF8, 0xFC, 0x04, 0x04, 0x04, 0xFC, 0xF0,
    0x0F, 0x1F, 0x10, 0x10, 0x10, 0x1F, 0x07,
    
    // @482 'P' (6 pixels wide)
    //
    //
    // #####
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ######
    // ##
    // ##
    // ##
    // ##
    // ##
    //
    //
    //
    0xFC, 0xFC, 0x84, 0x84, 0x84, 0xF8,
    0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00,
    
    // @494 'Q' (7 pixels wide)
    //
    //
    //  #####
    // ##   #
    // ##   ##
    // ##   ##
    // ##   ##
    // ##   ##
    // ##   ##
    // ##   ##
    // ##   ##
    // ##   #
    //  ######
    //       #
    //
    //
    0xF8, 0xFC, 0x04, 0x04, 0x04, 0xFC, 0xF0,
    0x0F, 0x1F, 0x10, 0x10, 0x10, 0x1F, 0x37,
    
    // @508 'R' (7 pixels wide)
    //
    //
    // #####
    // ##  ##
    // ##  ##
    // ##  ##
    // ##  ##
    // #####
    // ## ##
    // ##  #
    // ##  ##
    // ##  ##
    // ##   ##
    //
    //
    //
    0xFC, 0xFC, 0x84, 0x84, 0xFC, 0x78, 0x00,
    0x1F, 0x1F, 0x00, 0x01, 0x0F, 0x1C, 0x10,
    
    // @522 'S' (5 pixels wide)
    //
    //
    //  ####
    // #
    // #
    // #
    // #
    // ####
    //    ##
    //     #
    //     #
    //    ##
    // ####
    //
    //
    //
    0xF8, 0x84, 0x84, 0x84, 0x04,
    0x10, 0x10, 0x10, 0x19, 0x0F,
    
    // @532 'T' (7 pixels wide)
    //
    //
    // #######
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //
    //
    //
    0x04, 0x04, 0x04, 0xFC, 0x04, 0x04, 0x04,
    0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,
    
    // @546 'U' (6 pixels wide)
    //
    //
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    //  ####
    //
    //
    //
    0xFC, 0xFC, 0x00, 0x00, 0x00, 0xFC,
    0x0F, 0x1F, 0x10, 0x10, 0x10, 0x0F,
    
    // @558 'V' (7 pixels wide)
    //
    //
    // #    ##
    // ##   #
    // ##   #
    //  #   #
    //  #  ##
    //  #  #
    //  ## #
    //  ## #
    //   ###
    //   ##
    //   ##
    //
    //
    //
    0x1C, 0xF8, 0x00, 0x00, 0xC0, 0x7C, 0x04,
    0x00, 0x03, 0x1F, 0x1C, 0x07, 0x00, 0x00,
    
    // @572 'W' (7 pixels wide)
    //
    //
    // #     #
    // #     #
    // #     #
    // #    ##
    // #    ##
    // #  # #
    // # ## #
    // # ####
    // # # ##
    // # # ##
    // ##  ##
    //
    //
    //
    0xFC, 0x00, 0x00, 0x80, 0x00, 0xE0, 0x7C,
    0x1F, 0x10, 0x0F, 0x03, 0x1E, 0x1F, 0x00,
    
    // @586 'X' (7 pixels wide)
    //
    //
    // ##   ##
    //  #  ##
    //  ## #
    //   # #
    //   ##
    //    #
    //   ###
    //   # #
    //  ## ##
    //  #   #
    // ##   ##
    //
    //
    //
    0x04, 0x1C, 0x70, 0xC0, 0x38, 0x0C, 0x04,
    0x10, 0x1C, 0x07, 0x01, 0x07, 0x1C, 0x10,
    
    // @600 'Y' (7 pixels wide)
    //
    //
    // #    ##
    // ##   #
    //  #  ##
    //  ## #
    //   ###
    //   ##
    //    #
    //    #
    //    #
    //    #
    //    #
    //
    //
    //
    0x0C, 0x38, 0xE0, 0xC0, 0x70, 0x1C, 0x04,
    0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,
    
    // @614 'Z' (6 pixels wide)
    //
    //
    //  #####
    //      #
    //     ##
    //     #
    //    ##
    //    #
    //   ##
    //  ##
    //  ##
    // ##
    // ######
    //
    //
    //
    0x00, 0x04, 0x04, 0xC4, 0x74, 0x1C,
    0x18, 0x1E, 0x17, 0x11, 0x10, 0x10,
    
    // @626 '[' (3 pixels wide)
    // ###
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // ###
    //
    0xFF, 0x01, 0x01,
    0x7F, 0x40, 0x40,
    
    // @632 '\' (7 pixels wide)
    // #
    // ##
    //  #
    //  #
    //  ##
    //   #
    //   ##
    //    #
    //    #
    //    ##
    //     #
    //     #
    //      #
    //      #
    //      ##
    //
    0x03, 0x1E, 0x70, 0xC0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0x0E, 0x70, 0x40,
    
    // @646 ']' (3 pixels wide)
    // ###
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    //   #
    // ###
    //
    0x01, 0x01, 0xFF,
    0x40, 0x40, 0x7F,
    
    // @652 '^' (6 pixels wide)
    //   ##
    //   ###
    //   # #
    //  ## #
    //  #  ##
    // ##   #
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    0x20, 0x38, 0x0F, 0x03, 0x1E, 0x30,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    
    // @664 '_' (8 pixels wide)
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    // ########
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    
    // @680 '`' (3 pixels wide)
    //
    //
    // ##
    //  ##
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    0x04, 0x0C, 0x08,
    0x00, 0x00, 0x00,
    
    // @686 'a' (7 pixels wide)
    //
    //
    //
    //
    //
    //  ####
    //     ##
    //     ##
    //  #####
    // ##  ##
    // #   ##
    // ##  ##
    //  ######
    //
    //
    //
    0x00, 0x20, 0x20, 0x20, 0xE0, 0xC0, 0x00,
    0x0E, 0x1B, 0x11, 0x11, 0x1F, 0x1F, 0x10,
    
    // @700 'b' (6 pixels wide)
    //
    //
    // ##
    // ##
    // ##
    // #####
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // #####
    //
    //
    //
    0xFC, 0xFC, 0x20, 0x20, 0x20, 0xC0,
    0x1F, 0x1F, 0x10, 0x10, 0x10, 0x0F,
    
    // @712 'c' (5 pixels wide)
    //
    //
    //
    //
    //
    //  ####
    // ##
    // #
    // #
    // #
    // #
    // ##
    //  ####
    //
    //
    //
    0xC0, 0x60, 0x20, 0x20, 0x20,
    0x0F, 0x18, 0x10, 0x10, 0x10,
    
    // @722 'd' (6 pixels wide)
    //
    //
    //      #
    //      #
    //      #
    //  #####
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    //  #####
    //
    //
    //
    0xC0, 0xE0, 0x20, 0x20, 0x20, 0xFC,
    0x0F, 0x1F, 0x10, 0x10, 0x10, 0x1F,
    
    // @734 'e' (6 pixels wide)
    //
    //
    //
    //
    //
    //  ####
    //  #   #
    //  #   #
    // ######
    // ##
    //  #
    //  #
    //  #####
    //
    //
    //
    0x00, 0xE0, 0x20, 0x20, 0x20, 0xC0,
    0x03, 0x1F, 0x11, 0x11, 0x11, 0x11,
    
    // @746 'f' (5 pixels wide)
    //
    //
    //  ####
    //  #
    //  #
    // #####
    //  #
    //  #
    //  #
    //  #
    //  #
    //  #
    // ####
    //
    //
    //
    0x20, 0xFC, 0x24, 0x24, 0x24,
    0x10, 0x1F, 0x10, 0x10, 0x00,
    
    // @756 'g' (6 pixels wide)
    //
    //
    //
    //
    //
    //  #####
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    //  #####
    //  ##
    //  #####
    //      #
    //      #
    // ######
    0xC0, 0xE0, 0x20, 0x20, 0x20, 0xE0,
    0x83, 0x9F, 0x9C, 0x94, 0x94, 0xF7,
    
    // @768 'h' (6 pixels wide)
    //
    //
    // ##
    // ##
    // ##
    // #####
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    //
    //
    //
    0xFC, 0xFC, 0x20, 0x20, 0x20, 0xC0,
    0x1F, 0x1F, 0x00, 0x00, 0x00, 0x1F,
    
    // @780 'i' (6 pixels wide)
    //
    //
    //    #
    //
    //
    // ####
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    ###
    //
    //
    //
    0x20, 0x20, 0x20, 0xE4, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1F, 0x10, 0x10,
    
    // @792 'j' (4 pixels wide)
    //
    //
    //    #
    //
    //
    //  ###
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    //    #
    // ####
    0x00, 0x20, 0x20, 0xE4,
    0x80, 0x80, 0x80, 0xFF,
    
    // @800 'k' (5 pixels wide)
    //
    //
    // #
    // #
    // #
    // #  ##
    // # ##
    // ###
    // ###
    // # #
    // # ##
    // #  #
    // #  ##
    //
    //
    //
    0xFC, 0x80, 0xC0, 0x60, 0x20,
    0x1F, 0x01, 0x07, 0x1C, 0x10,
    
    // @810 'l' (7 pixels wide)
    //
    //
    // ####
    //   ##
    //   ##
    //   ##
    //   ##
    //   ##
    //   ##
    //   ##
    //   ##
    //   ##
    //    ####
    //
    //
    //
    0x04, 0x04, 0xFC, 0xFC, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0F, 0x1F, 0x10, 0x10, 0x10,
    
    // @824 'm' (7 pixels wide)
    //
    //
    //
    //
    //
    // ### ###
    // #  #  #
    // #  #  #
    // #  #  #
    // #  #  #
    // #  #  #
    // #  #  #
    // #  #  #
    //
    //
    //
    0xE0, 0x20, 0x20, 0xC0, 0x20, 0x20, 0xE0,
    0x1F, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x1F,
    
    // @838 'n' (6 pixels wide)
    //
    //
    //
    //
    //
    // #####
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    //
    //
    //
    0xE0, 0xE0, 0x20, 0x20, 0x20, 0xC0,
    0x1F, 0x1F, 0x00, 0x00, 0x00, 0x1F,
    
    // @850 'o' (6 pixels wide)
    //
    //
    //
    //
    //
    //  #####
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    //  #####
    //
    //
    //
    0xC0, 0xE0, 0x20, 0x20, 0x20, 0xE0,
    0x0F, 0x1F, 0x10, 0x10, 0x10, 0x1F,
    
    // @862 'p' (6 pixels wide)
    //
    //
    //
    //
    //
    // #####
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // #####
    // ##
    // ##
    // ##
    0xE0, 0xE0, 0x20, 0x20, 0x20, 0xC0,
    0xFF, 0xFF, 0x10, 0x10, 0x10, 0x0F,
    
    // @874 'q' (6 pixels wide)
    //
    //
    //
    //
    //
    //  #####
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    //  #####
    //      #
    //      #
    //      #
    0xC0, 0xE0, 0x20, 0x20, 0x20, 0xE0,
    0x0F, 0x1F, 0x10, 0x10, 0x10, 0xFF,
    
    // @886 'r' (5 pixels wide)
    //
    //
    //
    //
    //
    // #####
    //  #
    //  #
    //  #
    //  #
    //  #
    //  #
    // ####
    //
    //
    //
    0x20, 0xE0, 0x20, 0x20, 0x20,
    0x10, 0x1F, 0x10, 0x10, 0x00,
    
    // @896 's' (5 pixels wide)
    //
    //
    //
    //      
    //      
    // #### 
    // #    
    // #    
    // #### 
    //    ##
    //    ##
    //    ##
    // #### 
    //      
    //      
    //      
    0xE0, 0x20, 0x20, 0x20, 0x00, 
    0x11, 0x11, 0x11, 0x1F, 0x0E, 
    
    // @906 't' (5 pixels wide)
    //      
    //      
    //      
    //  ##  
    //  ##  
    // #####
    //  ##  
    //  ##  
    //  ##  
    //  ##  
    //  ##  
    //  ##  
    //   ###
    //      
    //      
    //      
    0x20, 0xF8, 0xF8, 0x20, 0x20, 
    0x00, 0x0F, 0x1F, 0x10, 0x10, 
    
    // @916 'u' (6 pixels wide)
    //       
    //       
    //       
    //       
    //       
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    // ##   #
    //  #   #
    //  #####
    //       
    //       
    //       
    0xE0, 0xE0, 0x00, 0x00, 0x00, 0xE0, 
    0x07, 0x1F, 0x10, 0x10, 0x10, 0x1F, 
    
    // @928 'v' (7 pixels wide)
    //        
    //        
    //        
    //        
    //        
    // ##   ##
    // ##   # 
    //  #   # 
    //  #  ## 
    //  ## #  
    //   # #  
    //   ###  
    //   ##   
    //        
    //        
    //        
    0x60, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x20, 
    0x00, 0x03, 0x1E, 0x18, 0x0F, 0x01, 0x00, 
    
    // @942 'w' (7 pixels wide)
    //        
    //        
    //        
    //        
    //        
    // #     #
    // #  #  #
    // #  # ##
    // # ## # 
    // ###### 
    //  ## ## 
    //  ## ## 
    //  ## ## 
    //        
    //        
    //        
    0xE0, 0x00, 0x00, 0xC0, 0x00, 0x80, 0xE0, 
    0x03, 0x1E, 0x1F, 0x03, 0x1E, 0x1F, 0x00, 
    
    // @956 'x' (7 pixels wide)
    //        
    //        
    //        
    //        
    //        
    // ##   # 
    //  ## #  
    //   ###  
    //   ##   
    //   ##   
    //   # #  
    //  #  ## 
    // ##   ##
    //        
    //        
    //        
    0x20, 0x60, 0xC0, 0x80, 0xC0, 0x20, 0x00, 
    0x10, 0x18, 0x07, 0x03, 0x0C, 0x18, 0x10, 
    
    // @970 'y' (7 pixels wide)
    //        
    //        
    //        
    //        
    //        
    // ##   ##
    //  #   # 
    //  #   # 
    //  ## ## 
    //  ## #  
    //   # #  
    //   # #  
    //   ###  
    //    #   
    //    #   
    //  ##    
    0x20, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x20, 
    0x00, 0x83, 0x9F, 0x70, 0x1F, 0x01, 0x00, 
    
    // @984 'z' (5 pixels wide)
    //      
    //      
    //      
    //      
    //      
    // #####
    //    ##
    //    # 
    //   ## 
    //  ##  
    //  #   
    // #    
    // #####
    //      
    //      
    //      
    0x20, 0x20, 0x20, 0xE0, 0x60, 
    0x18, 0x16, 0x13, 0x11, 0x10, 
    
    // @994 '{' (4 pixels wide)
    //   ##
    //   # 
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    // ##  
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    //  ## 
    //   ##
    //     
    0x80, 0xFC, 0x7F, 0x01, 
    0x00, 0x3F, 0x7F, 0x40, 
    
    // @1002 '|' (1 pixels wide)
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    // #
    //  
    0xFF, 
    0x7F, 
    
    // @1004 '}' (4 pixels wide)
    // ### 
    //   # 
    //   # 
    //   # 
    //   # 
    //   # 
    //   # 
    //    #
    //   # 
    //   # 
    //   # 
    //   # 
    //   # 
    //   # 
    // ### 
    //     
    0x01, 0x01, 0x7F, 0x80, 
    0x40, 0x40, 0x7F, 0x00, 
    
    // @1012 '~' (5 pixels wide)
    //      
    //      
    //      
    //      
    //      
    //      
    //      
    // ##  #
    // # ###
    //      
    //      
    //      
    //      
    //      
    //      
    //      
    0x80, 0x80, 0x00, 0x00, 0x80, 
    0x01, 0x00, 0x01, 0x01, 0x01, 
};

#endif