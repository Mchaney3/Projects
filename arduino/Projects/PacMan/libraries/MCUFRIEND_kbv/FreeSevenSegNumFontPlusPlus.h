// generate FreeFont from UTFT font
const uint8_t FreeSevenSegNumFontPlusPlusBitmaps[] PROGMEM = {
    // 7x7 [0x2E '.']
    0x38, 0xFB, 0xFF, 0xFF, 0xEF, 0x8E, 0x00,
    // 0x0 [0x2F '/']

    // 27x46 [0x30 '0']
    0x03, 0xFF, 0xF8, 0x00, 0xFF, 0xFF, 0x80, 0x3F, 0xFF, 0xF8, 0x03, 0xFF, 0xFE, 0xC3, 0x3F, 0xFF,
    0xBC, 0xF0, 0x00, 0x0F, 0xFF, 0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0xFC, 0x00, 0x07, 0xFF, 0x80,
    0x00, 0xFF, 0xF0, 0x00, 0x1F, 0xFE, 0x00, 0x03, 0xFF, 0xC0, 0x00, 0x7F, 0xF8, 0x00, 0x0F, 0xFF,
    0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0xFC, 0x00, 0x07, 0xFF, 0x80, 0x00, 0xFF, 0xF0, 0x00, 0x1F,
    0xFC, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00,
    0x00, 0xE0, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x3F, 0xF0, 0x00, 0x1F, 0xFE, 0x00, 0x03, 0xFF, 0xC0,
    0x00, 0x7F, 0xF8, 0x00, 0x0F, 0xFF, 0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0xFC, 0x00, 0x07, 0xFF,
    0x80, 0x00, 0xFF, 0xF0, 0x00, 0x1F, 0xFE, 0x00, 0x03, 0xFF, 0xC0, 0x00, 0x7F, 0xF8, 0x00, 0x0F,
    0xFF, 0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0x78, 0x00, 0x03, 0xC6, 0x7F, 0xFF, 0x30, 0x1F, 0xFF,
    0xF0, 0x07, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0xC0, 0x07, 0xFF, 0xF0, 0x00,
    // 6x39 [0x31 '1']
    0x31, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3C, 0x30, 0x40, 0x00,
    0x33, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xE3, 0x00,
    // 27x46 [0x32 '2']
    0x03, 0xFF, 0xF8, 0x00, 0xFF, 0xFF, 0x80, 0x3F, 0xFF, 0xF8, 0x03, 0xFF, 0xFE, 0xC0, 0x3F, 0xFF,
    0xBC, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x07, 0xE0, 0x00,
    0x00, 0xFC, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x03, 0xF0, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x0F, 0xC0,
    0x00, 0x01, 0xF8, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x1F,
    0x80, 0x00, 0x00, 0xF0, 0x7F, 0xFF, 0x86, 0x1F, 0xFF, 0xFC, 0x4F, 0xFF, 0xFF, 0xE4, 0xFF, 0xFF,
    0xF8, 0xE7, 0xFF, 0xFC, 0x1F, 0x00, 0x00, 0x03, 0xF0, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x0F, 0xC0,
    0x00, 0x01, 0xF8, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x1F,
    0x80, 0x00, 0x03, 0xF0, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x01, 0xF8, 0x00, 0x00,
    0x3F, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x78, 0x00, 0x00, 0x06, 0x7F, 0xFF, 0x00, 0x1F, 0xFF,
    0xF0, 0x07, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0xC0, 0x07, 0xFF, 0xF0, 0x00,
    // 25x46 [0x33 '3']
    0x0F, 0xFF, 0xE0, 0x0F, 0xFF, 0xF8, 0x0F, 0xFF, 0xFE, 0x03, 0xFF, 0xFE, 0xC0, 0xFF, 0xFE, 0xF0,
    0x00, 0x00, 0xFC, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x0F, 0xC0,
    0x00, 0x07, 0xE0, 0x00, 0x03, 0xF0, 0x00, 0x01, 0xF8, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x7E, 0x00,
    0x00, 0x3F, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x0F, 0xC0, 0x00, 0x07, 0xE0, 0x00, 0x00, 0xF1, 0xFF,
    0xFE, 0x19, 0xFF, 0xFF, 0xC7, 0xFF, 0xFF, 0xF8, 0xFF, 0xFF, 0xF8, 0x1F, 0xFF, 0xF1, 0x80, 0x00,
    0x03, 0xC0, 0x00, 0x07, 0xE0, 0x00, 0x03, 0xF0, 0x00, 0x01, 0xF8, 0x00, 0x00, 0xFC, 0x00, 0x00,
    0x7E, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x0F, 0xC0, 0x00, 0x07, 0xE0, 0x00, 0x03,
    0xF0, 0x00, 0x01, 0xF8, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x0F,
    0x07, 0xFF, 0xF3, 0x07, 0xFF, 0xFC, 0x07, 0xFF, 0xFF, 0x01, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0x00,
    // 27x39 [0x34 '4']
    0x00, 0x00, 0x01, 0x86, 0x00, 0x00, 0x79, 0xE0, 0x00, 0x1F, 0xFE, 0x00, 0x03, 0xFF, 0xC0, 0x00,
    0x7F, 0xF8, 0x00, 0x0F, 0xFF, 0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0xFC, 0x00, 0x07, 0xFF, 0x80,
    0x00, 0xFF, 0xF0, 0x00, 0x1F, 0xFE, 0x00, 0x03, 0xFF, 0xC0, 0x00, 0x7F, 0xF8, 0x00, 0x0F, 0xFF,
    0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0xF8, 0x00, 0x01, 0xFC, 0xFF, 0xFF, 0x0E, 0x3F, 0xFF, 0xF8,
    0x9F, 0xFF, 0xFF, 0xC1, 0xFF, 0xFF, 0xF0, 0x0F, 0xFF, 0xF8, 0xC0, 0x00, 0x00, 0x78, 0x00, 0x00,
    0x3F, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x03, 0xF0, 0x00,
    0x00, 0x7E, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x07, 0xE0,
    0x00, 0x00, 0xFC, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x03, 0xF0, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x07,
    0x80, 0x00, 0x00, 0x60,
    // 27x46 [0x35 '5']
    0x03, 0xFF, 0xF8, 0x00, 0xFF, 0xFF, 0x80, 0x3F, 0xFF, 0xF8, 0x03, 0xFF, 0xFE, 0x03, 0x3F, 0xFF,
    0x80, 0xF0, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x1F, 0x80,
    0x00, 0x03, 0xF0, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x3F,
    0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x03, 0xF0, 0x00, 0x00,
    0x7C, 0x00, 0x00, 0x0E, 0x7F, 0xFF, 0x81, 0x1F, 0xFF, 0xFC, 0x0F, 0xFF, 0xFF, 0xE0, 0xFF, 0xFF,
    0xF8, 0x07, 0xFF, 0xFC, 0x60, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x03, 0xF0, 0x00,
    0x00, 0x7E, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x07, 0xE0,
    0x00, 0x00, 0xFC, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x03, 0xF0, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x0F,
    0xC0, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x03, 0xC0, 0x7F, 0xFF, 0x30, 0x1F, 0xFF,
    0xF0, 0x07, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0xC0, 0x07, 0xFF, 0xF0, 0x00,
    // 27x46 [0x36 '6']
    0x03, 0xFF, 0xF8, 0x00, 0xFF, 0xFF, 0x80, 0x3F, 0xFF, 0xF8, 0x03, 0xFF, 0xFE, 0x03, 0x3F, 0xFF,
    0x80, 0xF0, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x1F, 0x80,
    0x00, 0x03, 0xF0, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x3F,
    0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x03, 0xF0, 0x00, 0x00,
    0x7C, 0x00, 0x00, 0x0E, 0x7F, 0xFF, 0x81, 0x1F, 0xFF, 0xFC, 0x0F, 0xFF, 0xFF, 0xE4, 0xFF, 0xFF,
    0xF8, 0xE7, 0xFF, 0xFC, 0x7F, 0x00, 0x00, 0x3F, 0xF0, 0x00, 0x1F, 0xFE, 0x00, 0x03, 0xFF, 0xC0,
    0x00, 0x7F, 0xF8, 0x00, 0x0F, 0xFF, 0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0xFC, 0x00, 0x07, 0xFF,
    0x80, 0x00, 0xFF, 0xF0, 0x00, 0x1F, 0xFE, 0x00, 0x03, 0xFF, 0xC0, 0x00, 0x7F, 0xF8, 0x00, 0x0F,
    0xFF, 0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0x78, 0x00, 0x03, 0xC6, 0x7F, 0xFF, 0x30, 0x1F, 0xFF,
    0xF0, 0x07, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0xC0, 0x07, 0xFF, 0xF0, 0x00,
    // 23x42 [0x37 '7']
    0x3F, 0xFF, 0x80, 0xFF, 0xFF, 0x83, 0xFF, 0xFF, 0x83, 0xFF, 0xFE, 0xC3, 0xFF, 0xFB, 0xC0, 0x00,
    0x0F, 0xC0, 0x00, 0x1F, 0x80, 0x00, 0x3F, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xFC, 0x00, 0x01, 0xF8,
    0x00, 0x03, 0xF0, 0x00, 0x07, 0xE0, 0x00, 0x0F, 0xC0, 0x00, 0x1F, 0x80, 0x00, 0x3F, 0x00, 0x00,
    0x7E, 0x00, 0x00, 0xFC, 0x00, 0x01, 0xF8, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x60, 0x00, 0x00, 0x40,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x3C, 0x00, 0x01, 0xF8, 0x00, 0x03,
    0xF0, 0x00, 0x07, 0xE0, 0x00, 0x0F, 0xC0, 0x00, 0x1F, 0x80, 0x00, 0x3F, 0x00, 0x00, 0x7E, 0x00,
    0x00, 0xFC, 0x00, 0x01, 0xF8, 0x00, 0x03, 0xF0, 0x00, 0x07, 0xE0, 0x00, 0x0F, 0xC0, 0x00, 0x1F,
    0x80, 0x00, 0x3F, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x30,
    // 27x46 [0x38 '8']
    0x03, 0xFF, 0xF8, 0x00, 0xFF, 0xFF, 0x80, 0x3F, 0xFF, 0xF8, 0x03, 0xFF, 0xFE, 0xC3, 0x3F, 0xFF,
    0xBC, 0xF0, 0x00, 0x0F, 0xFF, 0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0xFC, 0x00, 0x07, 0xFF, 0x80,
    0x00, 0xFF, 0xF0, 0x00, 0x1F, 0xFE, 0x00, 0x03, 0xFF, 0xC0, 0x00, 0x7F, 0xF8, 0x00, 0x0F, 0xFF,
    0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0xFC, 0x00, 0x07, 0xFF, 0x80, 0x00, 0xFF, 0xF0, 0x00, 0x1F,
    0xFC, 0x00, 0x00, 0xFE, 0x7F, 0xFF, 0x87, 0x1F, 0xFF, 0xFC, 0x4F, 0xFF, 0xFF, 0xE4, 0xFF, 0xFF,
    0xF8, 0xE7, 0xFF, 0xFC, 0x7F, 0x00, 0x00, 0x3F, 0xF0, 0x00, 0x1F, 0xFE, 0x00, 0x03, 0xFF, 0xC0,
    0x00, 0x7F, 0xF8, 0x00, 0x0F, 0xFF, 0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0xFC, 0x00, 0x07, 0xFF,
    0x80, 0x00, 0xFF, 0xF0, 0x00, 0x1F, 0xFE, 0x00, 0x03, 0xFF, 0xC0, 0x00, 0x7F, 0xF8, 0x00, 0x0F,
    0xFF, 0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0x78, 0x00, 0x03, 0xC6, 0x7F, 0xFF, 0x30, 0x1F, 0xFF,
    0xF0, 0x07, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0xC0, 0x07, 0xFF, 0xF0, 0x00,
    // 27x46 [0x39 '9']
    0x03, 0xFF, 0xF8, 0x00, 0xFF, 0xFF, 0x80, 0x3F, 0xFF, 0xF8, 0x03, 0xFF, 0xFE, 0xC3, 0x3F, 0xFF,
    0xBC, 0xF0, 0x00, 0x0F, 0xFF, 0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0xFC, 0x00, 0x07, 0xFF, 0x80,
    0x00, 0xFF, 0xF0, 0x00, 0x1F, 0xFE, 0x00, 0x03, 0xFF, 0xC0, 0x00, 0x7F, 0xF8, 0x00, 0x0F, 0xFF,
    0x00, 0x01, 0xFF, 0xE0, 0x00, 0x3F, 0xFC, 0x00, 0x07, 0xFF, 0x80, 0x00, 0xFF, 0xF0, 0x00, 0x1F,
    0xFC, 0x00, 0x00, 0xFE, 0x7F, 0xFF, 0x87, 0x1F, 0xFF, 0xFC, 0x4F, 0xFF, 0xFF, 0xE0, 0xFF, 0xFF,
    0xF8, 0x07, 0xFF, 0xFC, 0x60, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x03, 0xF0, 0x00,
    0x00, 0x7E, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x07, 0xE0,
    0x00, 0x00, 0xFC, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x03, 0xF0, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x0F,
    0xC0, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x03, 0xC0, 0x7F, 0xFF, 0x30, 0x1F, 0xFF,
    0xF0, 0x07, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0xC0, 0x07, 0xFF, 0xF0, 0x00,
    // 7x28 [0x3A ':']
    0x38, 0xFB, 0xFF, 0xFF, 0xEF, 0x8E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x07, 0x1F, 0x7F, 0xFF, 0xFD, 0xF1, 0xC0,
};
// strip blank pixels: top = 0, bot = 2, left = 2, rt = 0, adv = 32, desc = 0
const GFXglyph FreeSevenSegNumFontPlusPlusGlyphs[] PROGMEM = {
    {   0,  7,  7, 32, 14, -12 }, // 0x2E '.'
    {   7,  0,  0, 32, 32, -50 }, // 0x2F '/'
    {   7, 27, 46, 32,  2, -48 }, // 0x30 '0'
    { 163,  6, 39, 32, 23, -45 }, // 0x31 '1'
    { 193, 27, 46, 32,  2, -48 }, // 0x32 '2'
    { 349, 25, 46, 32,  4, -48 }, // 0x33 '3'
    { 493, 27, 39, 32,  2, -45 }, // 0x34 '4'
    { 625, 27, 46, 32,  2, -48 }, // 0x35 '5'
    { 781, 27, 46, 32,  2, -48 }, // 0x36 '6'
    { 937, 23, 42, 32,  6, -48 }, // 0x37 '7'
    {1058, 27, 46, 32,  2, -48 }, // 0x38 '8'
    {1214, 27, 46, 32,  2, -48 }, // 0x39 '9'
    {1370,  7, 28, 32, 14, -38 }, // 0x3A ':'
};
const GFXfont FreeSevenSegNumFontPlusPlus PROGMEM = {
    (uint8_t  *)FreeSevenSegNumFontPlusPlusBitmaps,
    (GFXglyph *)FreeSevenSegNumFontPlusPlusGlyphs,
    46, 59, 50
};
// FreeSevenSegNumFontPlusPlus bitmap size = 1395 [1525] [2617]

