#include "keymap_common.h"

/* HHKB PD-KB02 layout
 * ,-----------------------------------------------------------.
 * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
 * |-----------------------------------------------------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Del  |
 * |-----------------------------------------------------------|
 * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |
 * |-----------------------------------------------------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift |Fn |
 * '-----------------------------------------------------------'
 *      |Alt |MHEN|         Space        |HENK |Alt |Happy
 *      `-------------------------------------------'   Hacking
 */
#define KEYMAP_HHKB_PD_KB02( \
    K76,K16,K1E,K26,K25,K2E,K36,K3D,K3E,K46,K45,K4E,K55,K5D,K0E, \
    K0D,K15,K1D,K24,K2D,K2C,K35,K3C,K43,K44,K4D,K54,K5B,KF1, \
    K14,K1C,K1B,K23,K2B,K34,K33,K3B,K42,K4B,K4C,K52,    K5A, \
    K12,K1A,K22,K21,K2A,K32,K31,K3A,K41,K49,K4A,    K59, \
        K11,K67,        K29,            K64,K91 \
) \
KEYMAP_FULL( \
         F13,F14,F15,F16,F17,F18,F19,F20,F21,F22,F23,F24, \
    K76, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10,F11,F12,          PSCR,SLCK,BRK,  VOLD,VOLU,MUTE, \
    K0E, K16,K1E,K26,K25,K2E,K36,K3D,K3E,K46,K45,K4E,K55,JPY,BSPC, INS, HOME,PGUP, NLCK,PSLS,PAST,PMNS, \
    K0D, K15,K1D,K24,K2D,K2C,K35,K3C,K43,K44,K4D,K54,K5B,    K5D,  KF1, END, PGDN, P7,  P8,  P9,  PPLS, \
    CAPS,K1C,K1B,K23,K2B,K34,K33,K3B,K42,K4B,K4C,K52,        K5A,                  P4,  P5,  P6,  PCMM,\
    K12, NUBS,K1A,K22,K21,K2A,K32,K31,K3A,K41,K49,K4A,   RO, K59,       UP,        P1,  P2,  P3,  PENT, \
    K14, LGUI,K11,K67,    K29,         K64,KANA,K91,RGUI,APP,RCTL, LEFT,DOWN,RGHT, PWR, P0,  PDOT,PEQL \
)

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* default
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Del  |
     * |-----------------------------------------------------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|Fn1|  '|Return  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|Fn0|Shift     |
     * '-----------------------------------------------------------'
     *      |Alt |Fn1 |         Space         |Gui |Alt |Happy
     *      `-------------------------------------------'   Hacking
     */
    [0] = KEYMAP_HHKB_PD_KB02(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,DEL,
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, FN0,      RSFT,
             LALT,FN1,           SPC,                RGUI,RALT
    ),
    /* Extended mode
     * - Mouse mode
     * - Support RO and JPY keys when using jp keyboard layout.
     * ,-----------------------------------------------------------.
     * |  `|   |   |   |   |   |   |   |   |   |   | RO|   |JPY|<@>|
     * |-----------------------------------------------------------|
     * |     |   |MwU|   |   |   |   |   |McU|   |   |<[>|<]>|Bs   |
     * |-----------------------------------------------------------|
     * |      |MwL|MwD|MwR|   |   |   |McL|McD|McR|   |   |        |
     * |-----------------------------------------------------------|
     * |        |Ac0|Ac1|Ac2|   |   |Mb2|Mb1|   |   |   |          |
     * |-----------------------------------------------------------|
     *      |    |    |          Mb1          |App |    |Happy
     *      `-------------------------------------------'   Hacking
     */
    [1] = KEYMAP_HHKB_PD_KB02(
        GRV, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  RO,  NO,  JPY, LBRC,
        TRNS,NO,  WH_U,NO,  NO,  NO,  NO,  NO,  MS_U,NO,  NO,  RBRC,BSLS,BSPC,
        TRNS,WH_L,WH_D,WH_R,NO,  NO,  NO,  MS_L,MS_D,MS_R,NO,  NO,       NO,
        TRNS,ACL0,ACL1,ACL2,NO,  NO,  BTN2,BTN1,NO,  NO,  NO,       TRNS,
             NO,  NO,            BTN1,               APP, NO 
    ),
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(1, KC_SLASH),
    [1] = ACTION_LAYER_TAP_KEY(1, KC_LGUI),
};
