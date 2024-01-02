#ifndef __SCREEN_H_
#define __SCREEN_H_

#include <stdint.h>
#include "image.h"
#include "fonts.h"
#include "st7789.h"

void screen_splash(void);

void screen_home(void);
void screen_home_top(char *title, char *bat, uint8_t blue);
void screen_home_level(uint8_t level);
void screen_home_speed(char *speed);
void screen_home_uint(char *unit);
void screen_home_deep(char *met, uint16_t color);
void screen_home_battery(char *bat, uint16_t color);

void screen_setting(void);
void screen_setting_pair(uint8_t select);
void screen_setting_unit(uint8_t select, char *unit);
void screen_setting_bottom(uint8_t select);
void screen_setting_system(uint8_t select);

void screen_pair(void);
void screen_pair_device1(uint8_t select, char *text);
void screen_pair_device2(uint8_t select, char *text);

void screen_info(void);
void screen_pairing(void);
void screen_paired(void);

#endif /* __SCREEN_H_ */
