#include "config.h"

#define _(cg,cw) (TARGET == cg ? cg : cw)

void keyupdate(void);
int keydownlast(int basic_keycode);
int keydownhold(int basic_keycode);

#define KEY_EXE 31
#define KEY_VARS _(58,57)
#define KEY_PLUS 42
#define KEY_MINUS 32

#define KEY_PRGM_ACON 10
#define KEY_PRGM_DOWN _(37,47)
#define KEY_PRGM_EXIT _(47,68)
#define KEY_PRGM_F1 79
#define KEY_PRGM_F2 69
#define KEY_PRGM_F3 59
#define KEY_PRGM_F4 _(49,29)
#define KEY_PRGM_F5 _(39,28)
#define KEY_PRGM_F6 _(29,39)
#define KEY_PRGM_LEFT _(38,58)
#define KEY_PRGM_NONE 0
#define KEY_PRGM_RETURN 31
#define KEY_PRGM_RIGHT _(27,38)
#define KEY_PRGM_UP _(28,49)
#define KEY_PRGM_0 71
#define KEY_PRGM_1 72
#define KEY_PRGM_2 62
#define KEY_PRGM_3 52
#define KEY_PRGM_4 73
#define KEY_PRGM_5 63
#define KEY_PRGM_6 53
#define KEY_PRGM_7 74
#define KEY_PRGM_8 64
#define KEY_PRGM_9 54
#define KEY_PRGM_A 76
#define KEY_PRGM_F 26
#define KEY_PRGM_ALPHA _(77,67)
#define KEY_PRGM_SHIFT _(78,77)
#define KEY_PRGM_OPTN _(68,48)
#define KEY_PRGM_MENU _(48,78)