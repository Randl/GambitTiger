
// square.h

#ifndef SQUARE_H
#define SQUARE_H

// includes

#include "colour.h"
#include "util.h"

// constants

const int_fast32_t FileNb = 16;
const int_fast32_t RankNb = 16;

const int_fast32_t SquareNb = FileNb * RankNb;

const int_fast32_t FileInc = +1;
const int_fast32_t RankInc = +16;

const int_fast32_t FileNone = 0;

const int_fast32_t FileA = 0x4;
const int_fast32_t FileB = 0x5;
const int_fast32_t FileC = 0x6;
const int_fast32_t FileD = 0x7;
const int_fast32_t FileE = 0x8;
const int_fast32_t FileF = 0x9;
const int_fast32_t FileG = 0xA;
const int_fast32_t FileH = 0xB;

const int_fast32_t RankNone = 0;

const int_fast32_t Rank1 = 0x4;
const int_fast32_t Rank2 = 0x5;
const int_fast32_t Rank3 = 0x6;
const int_fast32_t Rank4 = 0x7;
const int_fast32_t Rank5 = 0x8;
const int_fast32_t Rank6 = 0x9;
const int_fast32_t Rank7 = 0xA;
const int_fast32_t Rank8 = 0xB;

const int_fast32_t SquareNone = 0;

const int_fast32_t A1=0x44, B1=0x45, C1=0x46, D1=0x47, E1=0x48, F1=0x49, G1=0x4A, H1=0x4B;
const int_fast32_t A2=0x54, B2=0x55, C2=0x56, D2=0x57, E2=0x58, F2=0x59, G2=0x5A, H2=0x5B;
const int_fast32_t A3=0x64, B3=0x65, C3=0x66, D3=0x67, E3=0x68, F3=0x69, G3=0x6A, H3=0x6B;
const int_fast32_t A4=0x74, B4=0x75, C4=0x76, D4=0x77, E4=0x78, F4=0x79, G4=0x7A, H4=0x7B;
const int_fast32_t A5=0x84, B5=0x85, C5=0x86, D5=0x87, E5=0x88, F5=0x89, G5=0x8A, H5=0x8B;
const int_fast32_t A6=0x94, B6=0x95, C6=0x96, D6=0x97, E6=0x98, F6=0x99, G6=0x9A, H6=0x9B;
const int_fast32_t A7=0xA4, B7=0xA5, C7=0xA6, D7=0xA7, E7=0xA8, F7=0xA9, G7=0xAA, H7=0xAB;
const int_fast32_t A8=0xB4, B8=0xB5, C8=0xB6, D8=0xB7, E8=0xB8, F8=0xB9, G8=0xBA, H8=0xBB;

const int_fast32_t Dark  = 0;
const int_fast32_t Light = 1;

// macros

#define SQUARE_IS_OK(square)        ((((square)-0x44)&~0x77)==0)

#define SQUARE_MAKE(file,rank)      (((rank)<<4)|(file))

#define SQUARE_FILE(square)         ((square)&0xF)
#define SQUARE_RANK(square)         ((square)>>4)

#define SQUARE_FROM_64(square)      (SquareFrom64[square])
#define SQUARE_TO_64(square)        (SquareTo64[square])

#define SQUARE_IS_PROMOTE(square)   (SquareIsPromote[square])
#define SQUARE_EP_DUAL(square)      ((square)^16)

#define SQUARE_COLOUR(square)       (((square)^((square)>>4))&1)

#define SQUARE_FILE_MIRROR(square)  ((square)^0x0F)
#define SQUARE_RANK_MIRROR(square)  ((square)^0xF0)

#define FILE_OPP(file)              ((file)^0xF)
#define RANK_OPP(rank)              ((rank)^0xF)

#define PAWN_RANK(square,colour)    (SQUARE_RANK(square)^RankMask[colour])
#define PAWN_PROMOTE(square,colour) (PromoteRank[colour]|((square)&0xF))

// types

typedef int_fast32_t sq_t;

// "constants"

extern const int_fast32_t SquareFrom64[64];
extern const int_fast32_t RankMask[ColourNb];
extern const int_fast32_t PromoteRank[ColourNb];

// variables

extern int_fast32_t SquareTo64[SquareNb];
extern bool SquareIsPromote[SquareNb];

// functions

extern void square_init        ();

extern int_fast32_t  file_from_char     (int_fast32_t c);
extern int_fast32_t  rank_from_char     (int_fast32_t c);

extern int_fast32_t  file_to_char       (int_fast32_t file);
extern int_fast32_t  rank_to_char       (int_fast32_t rank);

extern bool square_to_string   (int_fast32_t square, char string[], int_fast32_t size);
extern int_fast32_t  square_from_string (const char string[]);

#endif // !defined SQUARE_H

// end of square.h

