// generated by hersh2pddi - do not edit!
// built on Apr 17 2002 at 11:24:58

struct Stroke
{
    signed int x;
    signed int y;
};

struct Glyph
{
    unsigned short firstStroke;
    unsigned char nStroke;
    unsigned char nVerts;
};

static Stroke StrokeTable[] =
{
    /*   */    {-8,8},
    /* ! */    {-5,5},{0,-12},{0,2},{-50,0},{0,7},{-1,8},{0,9},{1,8},{0,7},
    /* " */    {-8,8},{-4,-12},{-4,-5},{-50,0},{4,-12},{4,-5},
    /* # */    {-10,11},{1,-16},{-6,16},{-50,0},{7,-16},{0,16},{-50,0},{-6,-3},{8,-3},{-50,0},{-7,3},{7,3},
    /* $ */    {-10,10},{-2,-16},{-2,13},{-50,0},{2,-16},{2,13},{-50,0},{7,-9},{5,-11},{2,-12},{-2,-12},{-5,-11},{-7,-9},{-7,-7},{-6,-5},{-5,-4},{-3,-3},{3,-1},{5,0},{6,1},{7,3},{7,6},{5,8},{2,9},{-2,9},{-5,8},{-7,6},
    /* % */    {-12,12},{9,-12},{-9,9},{-50,0},{-4,-12},{-2,-10},{-2,-8},{-3,-6},{-5,-5},{-7,-5},{-9,-7},{-9,-9},{-8,-11},{-6,-12},{-4,-12},{-2,-11},{1,-10},{4,-10},{7,-11},{9,-12},{-50,0},{5,2},{3,3},{2,5},{2,7},{4,9},{6,9},{8,8},{9,6},{9,4},{7,2},{5,2},
    /* & */    {-13,13},{10,-3},{10,-4},{9,-5},{8,-5},{7,-4},{6,-2},{4,3},{2,6},{0,8},{-2,9},{-6,9},{-8,8},{-9,7},{-10,5},{-10,3},{-9,1},{-8,0},{-1,-4},{0,-5},{1,-7},{1,-9},{0,-11},{-2,-12},{-4,-11},{-5,-9},{-5,-7},{-4,-4},{-2,-1},{3,6},{5,8},{7,9},{9,9},{10,8},{10,7},
    /* ' */    {-5,5},{0,-10},{-1,-11},{0,-12},{1,-11},{1,-9},{0,-7},{-1,-6},
    /* ( */    {-7,7},{4,-16},{2,-14},{0,-11},{-2,-7},{-3,-2},{-3,2},{-2,7},{0,11},{2,14},{4,16},
    /* ) */    {-7,7},{-4,-16},{-2,-14},{0,-11},{2,-7},{3,-2},{3,2},{2,7},{0,11},{-2,14},{-4,16},
    /* * */    {-8,8},{0,-12},{0,0},{-50,0},{-5,-9},{5,-3},{-50,0},{5,-9},{-5,-3},
    /* + */    {-13,13},{0,-9},{0,9},{-50,0},{-9,0},{9,0},
    /* , */    {-5,5},{1,8},{0,9},{-1,8},{0,7},{1,8},{1,10},{0,12},{-1,13},
    /* - */    {-13,13},{-9,0},{9,0},
    /* . */    {-5,5},{0,7},{-1,8},{0,9},{1,8},{0,7},
    /* / */    {-11,11},{9,-16},{-9,16},
    /* 0 */    {-10,10},{-1,-12},{-4,-11},{-6,-8},{-7,-3},{-7,0},{-6,5},{-4,8},{-1,9},{1,9},{4,8},{6,5},{7,0},{7,-3},{6,-8},{4,-11},{1,-12},{-1,-12},
    /* 1 */    {-10,10},{-4,-8},{-2,-9},{1,-12},{1,9},
    /* 2 */    {-10,10},{-6,-7},{-6,-8},{-5,-10},{-4,-11},{-2,-12},{2,-12},{4,-11},{5,-10},{6,-8},{6,-6},{5,-4},{3,-1},{-7,9},{7,9},
    /* 3 */    {-10,10},{-5,-12},{6,-12},{0,-4},{3,-4},{5,-3},{6,-2},{7,1},{7,3},{6,6},{4,8},{1,9},{-2,9},{-5,8},{-6,7},{-7,5},
    /* 4 */    {-10,10},{3,-12},{-7,2},{8,2},{-50,0},{3,-12},{3,9},
    /* 5 */    {-10,10},{5,-12},{-5,-12},{-6,-3},{-5,-4},{-2,-5},{1,-5},{4,-4},{6,-2},{7,1},{7,3},{6,6},{4,8},{1,9},{-2,9},{-5,8},{-6,7},{-7,5},
    /* 6 */    {-10,10},{6,-9},{5,-11},{2,-12},{0,-12},{-3,-11},{-5,-8},{-6,-3},{-6,2},{-5,6},{-3,8},{0,9},{1,9},{4,8},{6,6},{7,3},{7,2},{6,-1},{4,-3},{1,-4},{0,-4},{-3,-3},{-5,-1},{-6,2},
    /* 7 */    {-10,10},{7,-12},{-3,9},{-50,0},{-7,-12},{7,-12},
    /* 8 */    {-10,10},{-2,-12},{-5,-11},{-6,-9},{-6,-7},{-5,-5},{-3,-4},{1,-3},{4,-2},{6,0},{7,2},{7,5},{6,7},{5,8},{2,9},{-2,9},{-5,8},{-6,7},{-7,5},{-7,2},{-6,0},{-4,-2},{-1,-3},{3,-4},{5,-5},{6,-7},{6,-9},{5,-11},{2,-12},{-2,-12},
    /* 9 */    {-10,10},{6,-5},{5,-2},{3,0},{0,1},{-1,1},{-4,0},{-6,-2},{-7,-5},{-7,-6},{-6,-9},{-4,-11},{-1,-12},{0,-12},{3,-11},{5,-9},{6,-5},{6,0},{5,5},{3,8},{0,9},{-2,9},{-5,8},{-6,6},
    /* : */    {-5,5},{0,-5},{-1,-4},{0,-3},{1,-4},{0,-5},{-50,0},{0,7},{-1,8},{0,9},{1,8},{0,7},
    /* ; */    {-5,5},{0,-5},{-1,-4},{0,-3},{1,-4},{0,-5},{-50,0},{1,8},{0,9},{-1,8},{0,7},{1,8},{1,10},{0,12},{-1,13},
    /* < */    {-12,12},{8,-9},{-8,0},{8,9},
    /* = */    {-13,13},{-9,-3},{9,-3},{-50,0},{-9,3},{9,3},
    /* > */    {-12,12},{-8,-9},{8,0},{-8,9},
    /* ? */    {-9,9},{-6,-7},{-6,-8},{-5,-10},{-4,-11},{-2,-12},{2,-12},{4,-11},{5,-10},{6,-8},{6,-6},{5,-4},{4,-3},{0,-1},{0,2},{-50,0},{0,7},{-1,8},{0,9},{1,8},{0,7},
    /* @ */    {-13,14},{5,-4},{4,-6},{2,-7},{-1,-7},{-3,-6},{-4,-5},{-5,-2},{-5,1},{-4,3},{-2,4},{1,4},{3,3},{4,1},{-50,0},{-1,-7},{-3,-5},{-4,-2},{-4,1},{-3,3},{-2,4},{-50,0},{5,-7},{4,1},{4,3},{6,4},{8,4},{10,2},{11,-1},{11,-3},{10,-6},{9,-8},{7,-10},{5,-11},{2,-12},{-1,-12},{-4,-11},{-6,-10},{-8,-8},{-9,-6},{-10,-3},{-10,0},{-9,3},{-8,5},{-6,7},{-4,8},{-1,9},{2,9},{5,8},{7,7},{8,6},{-50,0},{6,-7},{5,1},{5,3},{6,4},
    /* A */    {-9,9},{0,-12},{-8,9},{-50,0},{0,-12},{8,9},{-50,0},{-5,2},{5,2},
    /* B */    {-11,10},{-7,-12},{-7,9},{-50,0},{-7,-12},{2,-12},{5,-11},{6,-10},{7,-8},{7,-6},{6,-4},{5,-3},{2,-2},{-50,0},{-7,-2},{2,-2},{5,-1},{6,0},{7,2},{7,5},{6,7},{5,8},{2,9},{-7,9},
    /* C */    {-10,11},{8,-7},{7,-9},{5,-11},{3,-12},{-1,-12},{-3,-11},{-5,-9},{-6,-7},{-7,-4},{-7,1},{-6,4},{-5,6},{-3,8},{-1,9},{3,9},{5,8},{7,6},{8,4},
    /* D */    {-11,10},{-7,-12},{-7,9},{-50,0},{-7,-12},{0,-12},{3,-11},{5,-9},{6,-7},{7,-4},{7,1},{6,4},{5,6},{3,8},{0,9},{-7,9},
    /* E */    {-10,9},{-6,-12},{-6,9},{-50,0},{-6,-12},{7,-12},{-50,0},{-6,-2},{2,-2},{-50,0},{-6,9},{7,9},
    /* F */    {-10,8},{-6,-12},{-6,9},{-50,0},{-6,-12},{7,-12},{-50,0},{-6,-2},{2,-2},
    /* G */    {-10,11},{8,-7},{7,-9},{5,-11},{3,-12},{-1,-12},{-3,-11},{-5,-9},{-6,-7},{-7,-4},{-7,1},{-6,4},{-5,6},{-3,8},{-1,9},{3,9},{5,8},{7,6},{8,4},{8,1},{-50,0},{3,1},{8,1},
    /* H */    {-11,11},{-7,-12},{-7,9},{-50,0},{7,-12},{7,9},{-50,0},{-7,-2},{7,-2},
    /* I */    {-4,4},{0,-12},{0,9},
    /* J */    {-8,8},{4,-12},{4,4},{3,7},{2,8},{0,9},{-2,9},{-4,8},{-5,7},{-6,4},{-6,2},
    /* K */    {-11,10},{-7,-12},{-7,9},{-50,0},{7,-12},{-7,2},{-50,0},{-2,-3},{7,9},
    /* L */    {-10,7},{-6,-12},{-6,9},{-50,0},{-6,9},{6,9},
    /* M */    {-12,12},{-8,-12},{-8,9},{-50,0},{-8,-12},{0,9},{-50,0},{8,-12},{0,9},{-50,0},{8,-12},{8,9},
    /* N */    {-11,11},{-7,-12},{-7,9},{-50,0},{-7,-12},{7,9},{-50,0},{7,-12},{7,9},
    /* O */    {-11,11},{-2,-12},{-4,-11},{-6,-9},{-7,-7},{-8,-4},{-8,1},{-7,4},{-6,6},{-4,8},{-2,9},{2,9},{4,8},{6,6},{7,4},{8,1},{8,-4},{7,-7},{6,-9},{4,-11},{2,-12},{-2,-12},
    /* P */    {-11,10},{-7,-12},{-7,9},{-50,0},{-7,-12},{2,-12},{5,-11},{6,-10},{7,-8},{7,-5},{6,-3},{5,-2},{2,-1},{-7,-1},
    /* Q */    {-11,11},{-2,-12},{-4,-11},{-6,-9},{-7,-7},{-8,-4},{-8,1},{-7,4},{-6,6},{-4,8},{-2,9},{2,9},{4,8},{6,6},{7,4},{8,1},{8,-4},{7,-7},{6,-9},{4,-11},{2,-12},{-2,-12},{-50,0},{1,5},{7,11},
    /* R */    {-11,10},{-7,-12},{-7,9},{-50,0},{-7,-12},{2,-12},{5,-11},{6,-10},{7,-8},{7,-6},{6,-4},{5,-3},{2,-2},{-7,-2},{-50,0},{0,-2},{7,9},
    /* S */    {-10,10},{7,-9},{5,-11},{2,-12},{-2,-12},{-5,-11},{-7,-9},{-7,-7},{-6,-5},{-5,-4},{-3,-3},{3,-1},{5,0},{6,1},{7,3},{7,6},{5,8},{2,9},{-2,9},{-5,8},{-7,6},
    /* T */    {-8,8},{0,-12},{0,9},{-50,0},{-7,-12},{7,-12},
    /* U */    {-11,11},{-7,-12},{-7,3},{-6,6},{-4,8},{-1,9},{1,9},{4,8},{6,6},{7,3},{7,-12},
    /* V */    {-9,9},{-8,-12},{0,9},{-50,0},{8,-12},{0,9},
    /* W */    {-12,12},{-10,-12},{-5,9},{-50,0},{0,-12},{-5,9},{-50,0},{0,-12},{5,9},{-50,0},{10,-12},{5,9},
    /* X */    {-10,10},{-7,-12},{7,9},{-50,0},{7,-12},{-7,9},
    /* Y */    {-9,9},{-8,-12},{0,-2},{0,9},{-50,0},{8,-12},{0,-2},
    /* Z */    {-10,10},{7,-12},{-7,9},{-50,0},{-7,-12},{7,-12},{-50,0},{-7,9},{7,9},
    /* [ */    {-7,7},{-3,-16},{-3,16},{-50,0},{-2,-16},{-2,16},{-50,0},{-3,-16},{4,-16},{-50,0},{-3,16},{4,16},
    /* \ */    {-7,7},{-7,-12},{7,12},
    /* ] */    {-7,7},{2,-16},{2,16},{-50,0},{3,-16},{3,16},{-50,0},{-4,-16},{3,-16},{-50,0},{-4,16},{3,16},
    /* ^ */    {-8,8},{-2,-6},{0,-9},{2,-6},{-50,0},{-5,-3},{0,-8},{5,-3},{-50,0},{0,-8},{0,9},
    /* _ */    {-8,8},{-8,11},{8,11},
    /* ` */    {-5,5},{1,-12},{0,-11},{-1,-9},{-1,-7},{0,-6},{1,-7},{0,-8},
    /* a */    {-9,10},{6,-5},{6,9},{-50,0},{6,-2},{4,-4},{2,-5},{-1,-5},{-3,-4},{-5,-2},{-6,1},{-6,3},{-5,6},{-3,8},{-1,9},{2,9},{4,8},{6,6},
    /* b */    {-10,9},{-6,-12},{-6,9},{-50,0},{-6,-2},{-4,-4},{-2,-5},{1,-5},{3,-4},{5,-2},{6,1},{6,3},{5,6},{3,8},{1,9},{-2,9},{-4,8},{-6,6},
    /* c */    {-9,9},{6,-2},{4,-4},{2,-5},{-1,-5},{-3,-4},{-5,-2},{-6,1},{-6,3},{-5,6},{-3,8},{-1,9},{2,9},{4,8},{6,6},
    /* d */    {-9,10},{6,-12},{6,9},{-50,0},{6,-2},{4,-4},{2,-5},{-1,-5},{-3,-4},{-5,-2},{-6,1},{-6,3},{-5,6},{-3,8},{-1,9},{2,9},{4,8},{6,6},
    /* e */    {-9,9},{-6,1},{6,1},{6,-1},{5,-3},{4,-4},{2,-5},{-1,-5},{-3,-4},{-5,-2},{-6,1},{-6,3},{-5,6},{-3,8},{-1,9},{2,9},{4,8},{6,6},
    /* f */    {-5,7},{5,-12},{3,-12},{1,-11},{0,-8},{0,9},{-50,0},{-3,-5},{4,-5},
    /* g */    {-9,10},{6,-5},{6,11},{5,14},{4,15},{2,16},{-1,16},{-3,15},{-50,0},{6,-2},{4,-4},{2,-5},{-1,-5},{-3,-4},{-5,-2},{-6,1},{-6,3},{-5,6},{-3,8},{-1,9},{2,9},{4,8},{6,6},
    /* h */    {-9,10},{-5,-12},{-5,9},{-50,0},{-5,-1},{-2,-4},{0,-5},{3,-5},{5,-4},{6,-1},{6,9},
    /* i */    {-4,4},{-1,-12},{0,-11},{1,-12},{0,-13},{-1,-12},{-50,0},{0,-5},{0,9},
    /* j */    {-5,5},{0,-12},{1,-11},{2,-12},{1,-13},{0,-12},{-50,0},{1,-5},{1,12},{0,15},{-2,16},{-4,16},
    /* k */    {-9,8},{-5,-12},{-5,9},{-50,0},{5,-5},{-5,5},{-50,0},{-1,1},{6,9},
    /* l */    {-4,4},{0,-12},{0,9},
    /* m */    {-15,15},{-11,-5},{-11,9},{-50,0},{-11,-1},{-8,-4},{-6,-5},{-3,-5},{-1,-4},{0,-1},{0,9},{-50,0},{0,-1},{3,-4},{5,-5},{8,-5},{10,-4},{11,-1},{11,9},
    /* n */    {-9,10},{-5,-5},{-5,9},{-50,0},{-5,-1},{-2,-4},{0,-5},{3,-5},{5,-4},{6,-1},{6,9},
    /* o */    {-9,10},{-1,-5},{-3,-4},{-5,-2},{-6,1},{-6,3},{-5,6},{-3,8},{-1,9},{2,9},{4,8},{6,6},{7,3},{7,1},{6,-2},{4,-4},{2,-5},{-1,-5},
    /* p */    {-10,9},{-6,-5},{-6,16},{-50,0},{-6,-2},{-4,-4},{-2,-5},{1,-5},{3,-4},{5,-2},{6,1},{6,3},{5,6},{3,8},{1,9},{-2,9},{-4,8},{-6,6},
    /* q */    {-9,10},{6,-5},{6,16},{-50,0},{6,-2},{4,-4},{2,-5},{-1,-5},{-3,-4},{-5,-2},{-6,1},{-6,3},{-5,6},{-3,8},{-1,9},{2,9},{4,8},{6,6},
    /* r */    {-7,6},{-3,-5},{-3,9},{-50,0},{-3,1},{-2,-2},{0,-4},{2,-5},{5,-5},
    /* s */    {-8,9},{6,-2},{5,-4},{2,-5},{-1,-5},{-4,-4},{-5,-2},{-4,0},{-2,1},{3,2},{5,3},{6,5},{6,6},{5,8},{2,9},{-1,9},{-4,8},{-5,6},
    /* t */    {-5,7},{0,-12},{0,5},{1,8},{3,9},{5,9},{-50,0},{-3,-5},{4,-5},
    /* u */    {-9,10},{-5,-5},{-5,5},{-4,8},{-2,9},{1,9},{3,8},{6,5},{-50,0},{6,-5},{6,9},
    /* v */    {-8,8},{-6,-5},{0,9},{-50,0},{6,-5},{0,9},
    /* w */    {-11,11},{-8,-5},{-4,9},{-50,0},{0,-5},{-4,9},{-50,0},{0,-5},{4,9},{-50,0},{8,-5},{4,9},
    /* x */    {-8,9},{-5,-5},{6,9},{-50,0},{6,-5},{-5,9},
    /* y */    {-8,8},{-6,-5},{0,9},{-50,0},{6,-5},{0,9},{-2,13},{-4,15},{-6,16},{-7,16},
    /* z */    {-8,9},{6,-5},{-5,9},{-50,0},{-5,-5},{6,-5},{-50,0},{-5,9},{6,9},
    /* { */    {-7,7},{2,-16},{0,-15},{-1,-14},{-2,-12},{-2,-10},{-1,-8},{0,-7},{1,-5},{1,-3},{-1,-1},{-50,0},{0,-15},{-1,-13},{-1,-11},{0,-9},{1,-8},{2,-6},{2,-4},{1,-2},{-3,0},{1,2},{2,4},{2,6},{1,8},{0,9},{-1,11},{-1,13},{0,15},{-50,0},{-1,1},{1,3},{1,5},{0,7},{-1,8},{-2,10},{-2,12},{-1,14},{0,15},{2,16},
    /* | */    {-4,4},{0,-16},{0,16},
    /* } */    {-7,7},{-2,-16},{0,-15},{1,-14},{2,-12},{2,-10},{1,-8},{0,-7},{-1,-5},{-1,-3},{1,-1},{-50,0},{0,-15},{1,-13},{1,-11},{0,-9},{-1,-8},{-2,-6},{-2,-4},{-1,-2},{3,0},{-1,2},{-2,4},{-2,6},{-1,8},{0,9},{1,11},{1,13},{0,15},{-50,0},{1,1},{-1,3},{-1,5},{0,7},{1,8},{2,10},{2,12},{1,14},{0,15},{-2,16},
    /* ~ */    {-12,12},{-9,3},{-9,1},{-8,-2},{-6,-3},{-4,-3},{-2,-2},{2,1},{4,2},{6,2},{8,1},{9,-1},{-50,0},{-9,1},{-8,-1},{-6,-2},{-4,-2},{-2,-1},{2,2},{4,3},{6,3},{8,2},{9,-1},{9,-3},
    /*  */    {-7,7},{-1,-12},{-3,-11},{-4,-9},{-4,-7},{-3,-5},{-1,-4},{1,-4},{3,-5},{4,-7},{4,-9},{3,-11},{1,-12},{-1,-12}
};

static Glyph GlyphTable[] = 
{
    {   0,  1,  0},    /*   */
    {   1,  9, 10},    /* ! */
    {  10,  6,  4},    /* " */
    {  16, 12,  8},    /* # */
    {  28, 27, 42},    /* $ */
    {  55, 32, 52},    /* % */
    {  87, 35, 66},    /* & */
    { 122,  8, 12},    /* ' */
    { 130, 11, 18},    /* ( */
    { 141, 11, 18},    /* ) */
    { 152,  9,  6},    /* * */
    { 161,  6,  4},    /* + */
    { 167,  9, 14},    /* , */
    { 176,  3,  2},    /* - */
    { 179,  6,  8},    /* . */
    { 185,  3,  2},    /* / */
    { 188, 18, 32},    /* 0 */
    { 206,  5,  6},    /* 1 */
    { 211, 15, 26},    /* 2 */
    { 226, 16, 28},    /* 3 */
    { 242,  7,  6},    /* 4 */
    { 249, 18, 32},    /* 5 */
    { 267, 24, 44},    /* 6 */
    { 291,  6,  4},    /* 7 */
    { 297, 30, 56},    /* 8 */
    { 327, 24, 44},    /* 9 */
    { 351, 12, 16},    /* : */
    { 363, 15, 22},    /* ; */
    { 378,  4,  4},    /* < */
    { 382,  6,  4},    /* = */
    { 388,  4,  4},    /* > */
    { 392, 21, 34},    /* ? */
    { 413, 56, 96},    /* @ */
    { 469,  9,  6},    /* A */
    { 478, 24, 36},    /* B */
    { 502, 19, 34},    /* C */
    { 521, 16, 24},    /* D */
    { 537, 12,  8},    /* E */
    { 549,  9,  6},    /* F */
    { 558, 23, 38},    /* G */
    { 581,  9,  6},    /* H */
    { 590,  3,  2},    /* I */
    { 593, 11, 18},    /* J */
    { 604,  9,  6},    /* K */
    { 613,  6,  4},    /* L */
    { 619, 12,  8},    /* M */
    { 631,  9,  6},    /* N */
    { 640, 22, 40},    /* O */
    { 662, 14, 20},    /* P */
    { 676, 25, 42},    /* Q */
    { 701, 17, 22},    /* R */
    { 718, 21, 38},    /* S */
    { 739,  6,  4},    /* T */
    { 745, 11, 18},    /* U */
    { 756,  6,  4},    /* V */
    { 762, 12,  8},    /* W */
    { 774,  6,  4},    /* X */
    { 780,  7,  6},    /* Y */
    { 787,  9,  6},    /* Z */
    { 796, 12,  8},    /* [ */
    { 808,  3,  2},    /* \ */
    { 811, 12,  8},    /* ] */
    { 823, 11, 10},    /* ^ */
    { 834,  3,  2},    /* _ */
    { 837,  8, 12},    /* ` */
    { 845, 18, 28},    /* a */
    { 863, 18, 28},    /* b */
    { 881, 15, 26},    /* c */
    { 896, 18, 28},    /* d */
    { 914, 18, 32},    /* e */
    { 932,  9, 10},    /* f */
    { 941, 23, 38},    /* g */
    { 964, 11, 14},    /* h */
    { 975,  9, 10},    /* i */
    { 984, 12, 16},    /* j */
    { 996,  9,  6},    /* k */
    {1005,  3,  2},    /* l */
    {1008, 19, 26},    /* m */
    {1027, 11, 14},    /* n */
    {1038, 18, 32},    /* o */
    {1056, 18, 28},    /* p */
    {1074, 18, 28},    /* q */
    {1092,  9, 10},    /* r */
    {1101, 18, 32},    /* s */
    {1119,  9, 10},    /* t */
    {1128, 11, 14},    /* u */
    {1139,  6,  4},    /* v */
    {1145, 12,  8},    /* w */
    {1157,  6,  4},    /* x */
    {1163, 10, 12},    /* y */
    {1173,  9,  6},    /* z */
    {1182, 40, 68},    /* { */
    {1222,  3,  2},    /* | */
    {1225, 40, 68},    /* } */
    {1265, 24, 40},    /* ~ */
    {1289, 14, 24}    /*  */
};