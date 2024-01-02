#include "screen.h"
#include "color.h"

void screen_home(void)
{
    ST7789_Fill_Color(WHITE);
    screen_home_top("Home", "100", 1);
    screen_home_level(3);
    screen_home_speed("78");
    screen_home_uint("km/h");
    screen_home_battery("100%", COLOR_GRAY);
    screen_home_deep(">10m", COLOR_GRAY);
}

void screen_home_top(char *title, char *bat, uint8_t blue)
{
    ST7789_Fill(0, 0, 171, 47, COLOR_GRAY);

    if(blue > 0){
        ST7789_DrawImage(5, 8, 30, 30, bluetooth30);
    }
    ST7789_WriteString(80, 10, bat, &Ubuntu24B, COLOR_GRAY, BLACK);
    ST7789_DrawImage(135, 8, 30, 30, battery30);
    
}

void screen_home_level(uint8_t level)
{
    switch (level)
    {
    case 1:
        ST7789_DrawFilledRectangle(6, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(38, 60, 26, 6, COLOR_GRAY);
        ST7789_DrawFilledRectangle(70, 60, 26, 6, COLOR_GRAY);
        ST7789_DrawFilledRectangle(102, 60, 26, 6, COLOR_GRAY);
        ST7789_DrawFilledRectangle(134, 60, 26, 6, COLOR_GRAY);
        break;
    
    case 2:
        ST7789_DrawFilledRectangle(6, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(38, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(70, 60, 26, 6, COLOR_GRAY);
        ST7789_DrawFilledRectangle(102, 60, 26, 6, COLOR_GRAY);
        ST7789_DrawFilledRectangle(134, 60, 26, 6, COLOR_GRAY);
        break;
    case 3:
        ST7789_DrawFilledRectangle(6, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(38, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(70, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(102, 60, 26, 6, COLOR_GRAY);
        ST7789_DrawFilledRectangle(134, 60, 26, 6, COLOR_GRAY);
        break;
    case 4:
        ST7789_DrawFilledRectangle(6, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(38, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(70, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(102, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(134, 60, 26, 6, COLOR_GRAY);
        break;
    case 5:
        ST7789_DrawFilledRectangle(6, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(38, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(70, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(102, 60, 26, 6, BLACK);
        ST7789_DrawFilledRectangle(134, 60, 26, 6, BLACK);
        break;
    }
}

void screen_home_speed(char *speed)
{
    ST7789_WriteString(22, 70, speed, &Ubuntu100B, WHITE, BLACK);
}

void screen_home_uint(char *unit)
{
    ST7789_WriteString(52, 190, unit, &Ubuntu24B, WHITE, BLACK);
}

void screen_home_battery(char *bat, uint16_t color)
{
    ST7789_DrawFilledRectangle(3, 220, 166, 42, color);
    ST7789_DrawImage(5, 221, 40, 40, battery40);
    ST7789_WriteString(82, 229, bat, &Ubuntu24B, color, BLACK);
}

void screen_home_deep(char *met, uint16_t color)
{
    ST7789_DrawFilledRectangle(3, 270, 166, 42, color);
    ST7789_DrawImage(5, 271, 40, 40, deep40);
    ST7789_WriteString(82, 279, met, &Ubuntu24B, color, BLACK);
}

///////////

void screen_setting(void)
{
    ST7789_Fill_Color(WHITE);
    screen_home_top("Setting", "98", 1);
    screen_setting_pair(1);
    screen_setting_unit(0, "Unit: Km/h");
    screen_setting_system(0);
    screen_setting_bottom(0);
}

void screen_setting_pair(uint8_t select)
{
    if(select > 0){
        ST7789_DrawFilledRectangle(0, 60, 172, 40, BLACK);
        ST7789_WriteString(4, 70, "Pair remote", &Font20, BLACK, WHITE);
    } else {
        ST7789_DrawFilledRectangle(0, 60, 172, 40, WHITE);
        ST7789_WriteString(4, 70, "Pair remote", &Font20, WHITE, BLACK);
    }
    ST7789_DrawLine(5, 105, 163, 105, COLOR_GRAY);
    
}

void screen_setting_unit(uint8_t select, char *unit)
{
    if(select > 0){
        ST7789_DrawFilledRectangle(0, 110, 172, 40, BLACK);
        ST7789_WriteString(4, 120, "Unit: Km/h", &Font20, BLACK, WHITE);
    } else {
        ST7789_DrawFilledRectangle(0, 110, 172, 40, WHITE);
        ST7789_WriteString(4, 120, "Unit: Km/h", &Font20, WHITE, BLACK);
    }
    ST7789_DrawLine(5, 155, 163, 155, COLOR_GRAY);
}

void screen_setting_system(uint8_t select)
{
    if(select > 0){
        ST7789_DrawFilledRectangle(0, 160, 172, 40, BLACK);
        ST7789_WriteString(4, 170, "System info", &Font20, BLACK, WHITE);
    } else {
        ST7789_DrawFilledRectangle(0, 160, 172, 40, WHITE);
        ST7789_WriteString(4, 170, "System info", &Font20, WHITE, BLACK);
    }
    //ST7789_DrawLine(5, 205, 163, 205, COLOR_GRAY);
    
}

void screen_setting_bottom(uint8_t select)
{
    ST7789_DrawFilledRectangle(0, 272, 172, 48, COLOR_GRAY);
    switch (select)
    {
    case 0:
        ST7789_WriteString(40, 284, "Find", &Font24, COLOR_GRAY, BLACK);
        break;
    case 1:
        ST7789_WriteString(40, 284, "Change", &Font24, COLOR_GRAY, BLACK);
        break;
    case 2:
        ST7789_WriteString(40, 284, "Open", &Font24, COLOR_GRAY, BLACK);
        break;
    case 3:
        ST7789_WriteString(40, 284, "Pair", &Font24, COLOR_GRAY, BLACK);
        break;
    case 4:
        ST7789_WriteString(40, 284, "Back", &Font24, COLOR_GRAY, BLACK);
        break;
    case 5:
        ST7789_WriteString(40, 284, "Pairing", &Font24, COLOR_GRAY, BLACK);
        break;
    case 6:
        ST7789_WriteString(40, 284, "Paired", &Font24, COLOR_GRAY, BLACK);
        break;
    default:
        break;
    }
}


///

void screen_pair(void)
{
    ST7789_Fill_Color(WHITE);
    screen_home_top("Pair", "98", 1);
    screen_pair_device1(1, "Skua 1");
    screen_pair_device2(0, "Skua 2");
    screen_setting_bottom(3);
}

void screen_pair_device1(uint8_t select, char *text)
{
    if(select > 0){
        ST7789_DrawFilledRectangle(0, 60, 172, 40, BLACK);
        ST7789_WriteString(4, 70, text, &Font20, BLACK, WHITE);
    } else {
        ST7789_DrawFilledRectangle(0, 60, 172, 40, WHITE);
        ST7789_WriteString(4, 70, text, &Font20, WHITE, BLACK);
    }
    
}

void screen_pair_device2(uint8_t select, char *text)
{
    if(select > 0){
        ST7789_DrawFilledRectangle(0, 110, 172, 40, BLACK);
        ST7789_WriteString(4, 120, text, &Font20, BLACK, WHITE);
    } else {
        ST7789_DrawFilledRectangle(0, 110, 172, 40, WHITE);
        ST7789_WriteString(4, 120, text, &Font20, WHITE, BLACK);
    }
}

///

void screen_info(void)
{
    ST7789_Fill_Color(WHITE);
    screen_home_top("Info", "88", 1);
    ST7789_WriteString(5, 60, "ID", &Font24, WHITE, BLACK);
    ST7789_WriteString(5, 85, "000 000000", &Font16, WHITE, BLACK);
    ST7789_WriteString(5, 110, "Version", &Font24, WHITE, BLACK);
    ST7789_WriteString(5, 135, "1.0.2", &Font16, WHITE, BLACK);
    ST7789_WriteString(5, 160, "SN", &Font24, WHITE, BLACK);
    ST7789_WriteString(5, 185, "000000", &Font16, WHITE, BLACK);
    screen_setting_bottom(4);
}

void screen_pairing(void)
{
    ST7789_Fill_Color(WHITE);
    screen_home_top("Pairing", "88", 0);
    screen_setting_bottom(5);
    for(uint8_t i = 0; i <10; i++){
        ST7789_DrawImage(37, 111, 98, 98, loading000);
        LL_mDelay(100);
        ST7789_DrawImage(37, 111, 98, 98, loading090);
        LL_mDelay(100);
        ST7789_DrawImage(37, 111, 98, 98, loading180);
        LL_mDelay(100);
        ST7789_DrawImage(37, 111, 98, 98, loading270);
        LL_mDelay(100);
    }
}


void screen_paired(void)
{
    ST7789_Fill_Color(WHITE);
    screen_home_top("Pairing", "88", 1);
    ST7789_DrawImage(47, 121, 78, 78, done78);
    screen_setting_bottom(6);
}
