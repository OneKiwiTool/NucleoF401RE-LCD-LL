#include "screen.h"
#include "color.h"
#include "main.h"

void screen_splash(void)
{
    ST7789_Init();
    ST7789_SetRotation(2);
    ST7789_FillScreen(COLOR_WHITE);
    LL_mDelay(200);

    ST7789_DrawImage(25, 111, 120, 96, skua0);
    LL_mDelay(200);
    ST7789_DrawImage(25, 111, 120, 96, skua1);
    LL_mDelay(200);
    ST7789_DrawImage(25, 111, 120, 96, skua2);
    LL_mDelay(200);
    ST7789_DrawImage(25, 111, 120, 96, skua3);
    LL_mDelay(200);
    ST7789_DrawImage(25, 111, 120, 96, skua4);
    LL_mDelay(200);
    ST7789_DrawImage(25, 111, 120, 96, skua5);
    LL_mDelay(200);
    ST7789_DrawImage(25, 111, 120, 96, skua6);
    LL_mDelay(200);
    ST7789_DrawImage(25, 111, 120, 96, skua7);
    LL_mDelay(200);
    ST7789_DrawImage(25, 111, 120, 96, skua8);
    LL_mDelay(200);
    ST7789_DrawImage(25, 111, 120, 96, skua9);
    LL_mDelay(1000);
}
