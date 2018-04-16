#include "fourier.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_FN1 MO(_FN1)
#define KC_FN2 MO(_FN2)
#define KC_SPFN1 LT(_FN1, KC_SPACE)
#define KC_SPFN2 LT(_FN2, KC_SPACE)
#define KC_BSFN1 LT(_FN1, KC_BSPC)
#define KC_BSFN2 LT(_FN2, KC_BSPC)
#define KC_RST RESET
#define KC_DBUG DEBUG
#define KC_CAD LCTL(LALT(KC_DEL))
#define KC_TSK LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = KC_KEYMAP(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    TAB , Q  , W  , F  , P  , G  , J  , L  , U  , Y  ,SCLN,DEL ,BSPC,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
    LCTL , A  , R  , S  , T  , D  , H  , N  , E  , I  ,  O ,  QUOT  ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    LSPO   , Z  , X  , C  , V  , B  , K  , M  ,COMM,DOT ,SLSH, RSPC ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    LCTL , LGUI , LALT, FN1, BSFN2, SPFN1  ,RALT ,RGUI , RTCL, ENTER
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),

  [_FN1] = KC_KEYMAP(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    ESC , 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,MINS,EQL ,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
     F1  , F2 , F3 , F4 , F5 ,LBRC,RBRC, 4  , 5  , 6  ,    ,  CAD   ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
          , F6 , F7 , F8, F9 ,LCBR,RCBR, 1  , 2  , 3  , UP ,  TSK   ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
	 F10 , F11, F12 ,    ,   DEL    ,        ,  0  ,LEFT ,DOWN , RGHT
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),

  [_FN2] = KC_KEYMAP(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    TILD,EXLM, AT ,HASH,DLR ,PERC,CIRC,AMPR,ASTR,LPRN,RPRN,UNDS,PLUS,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
    GRV  ,    ,    ,INS ,PGUP,HOME,UNDS,MINS,    ,ASDN,ASUP,  ASRP  ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
           ,    ,    ,DEL ,PGDN,END ,PLUS, EQL,    ,    ,MPLY, MUTE ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    RST  ,ASTG,   ,    ,        ,  ENTER  ,     , MPRV,     , MNXT
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  )

};

