#include "screen.h"
#include "color.h"
#include "main.h"
#include "status.h"
#include <stdio.h>

extern Screen_Status status;

void screen_home(void)
{
	ST7789_FillScreen(COLOR_WHITE);
    screen_home_top();
    screen_home_level();
    screen_home_speed();
    screen_home_uint();
    screen_home_battery();
    screen_home_deep();
}

void screen_home_top(void)
{   
    char buffer[4];
    ST7789_FillRectangle(0, 0, 171, 47, COLOR_GRAY);

    if(status.topBluetooth){
        // bluetooth connected
        ST7789_DrawImage(5, 8, 30, 30, bluetooth30);
    } else {
        // bluetooth disconnect
        ST7789_DrawImage(5, 8, 30, 30, bluetooth30r);
    }

    sprintf(buffer, "%d", status.topBatery);
    if (status.topBatery >= 50)
    {
        if(status.topBatery < 100){
            ST7789_WriteString(90, 10, buffer, &Inter26, COLOR_GRAY, COLOR_BLACK);
        }else {
            ST7789_WriteString(65, 10, buffer, &Inter26, COLOR_GRAY, COLOR_BLACK);
        }
        ST7789_DrawImage(135, 8, 30, 30, battery30);
    } else if (status.topBatery < 20)
    {
        ST7789_WriteString(90, 10, buffer, &Inter26, COLOR_GRAY, COLOR_RED);
        ST7789_DrawImage(135, 8, 30, 30, battery30r);
    } else {
        ST7789_WriteString(90, 10, buffer, &Inter26, COLOR_GRAY, COLOR_ORANGE);
        ST7789_DrawImage(135, 8, 30, 30, battery30o);
    }
}

void screen_home_level(void)
{
    switch (status.homeLevel)
    {
    case 0:
        ST7789_FillRectangle(6, 60, 26, 6, COLOR_GRAY);
        ST7789_FillRectangle(38, 60, 26, 6, COLOR_GRAY);
        ST7789_FillRectangle(70, 60, 26, 6, COLOR_GRAY);
        ST7789_FillRectangle(102, 60, 26, 6, COLOR_GRAY);
        ST7789_FillRectangle(134, 60, 26, 6, COLOR_GRAY);
        break;
    case 1:
        ST7789_FillRectangle(6, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(38, 60, 26, 6, COLOR_GRAY);
        ST7789_FillRectangle(70, 60, 26, 6, COLOR_GRAY);
        ST7789_FillRectangle(102, 60, 26, 6, COLOR_GRAY);
        ST7789_FillRectangle(134, 60, 26, 6, COLOR_GRAY);
        break;
    case 2:
        ST7789_FillRectangle(6, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(38, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(70, 60, 26, 6, COLOR_GRAY);
        ST7789_FillRectangle(102, 60, 26, 6, COLOR_GRAY);
        ST7789_FillRectangle(134, 60, 26, 6, COLOR_GRAY);
        break;
    case 3:
        ST7789_FillRectangle(6, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(38, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(70, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(102, 60, 26, 6, COLOR_GRAY);
        ST7789_FillRectangle(134, 60, 26, 6, COLOR_GRAY);
        break;
    case 4:
        ST7789_FillRectangle(6, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(38, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(70, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(102, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(134, 60, 26, 6, COLOR_GRAY);
        break;
    case 5:
        ST7789_FillRectangle(6, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(38, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(70, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(102, 60, 26, 6, COLOR_BLACK);
        ST7789_FillRectangle(134, 60, 26, 6, COLOR_BLACK);
        break;
    }
}

void screen_home_speed(void)
{
    uint8_t a0 = status.homeSpeed%10;
    uint8_t a1 = status.homeSpeed/10;
    switch (a0)
    {
    case 0:
        ST7789_DrawImage(96, 75, 56, 106, num0);
        break;
    case 1:
        ST7789_DrawImage(96, 75, 56, 106, num1);
        break;
    case 2:
        ST7789_DrawImage(96, 75, 56, 106, num2);
        break;
    case 3:
        ST7789_DrawImage(96, 75, 56, 106, num3);
        break;
    case 4:
        ST7789_DrawImage(96, 75, 56, 106, num4);
        break;
    case 5:
        ST7789_DrawImage(96, 75, 56, 106, num5);
        break;
    case 6:
        ST7789_DrawImage(96, 75, 56, 106, num6);
        break;
    case 7:
        ST7789_DrawImage(96, 75, 56, 106, num7);
        break;
    case 8:
        ST7789_DrawImage(96, 75, 56, 106, num8);
        break;
    case 9:
        ST7789_DrawImage(96, 75, 56, 106, num9);
        break;
    }

    switch (a1)
    {
    case 0:
        ST7789_DrawImage(20, 75, 56, 106, num0);
        break;
    case 1:
        ST7789_DrawImage(20, 75, 56, 106, num1);
        break;
    case 2:
        ST7789_DrawImage(20, 75, 56, 106, num2);
        break;
    case 3:
        ST7789_DrawImage(20, 75, 56, 106, num3);
        break;
    case 4:
        ST7789_DrawImage(20, 75, 56, 106, num4);
        break;
    case 5:
        ST7789_DrawImage(20, 75, 56, 106, num5);
        break;
    case 6:
        ST7789_DrawImage(20, 75, 56, 106, num6);
        break;
    case 7:
        ST7789_DrawImage(20, 75, 56, 106, num7);
        break;
    case 8:
        ST7789_DrawImage(20, 75, 56, 106, num8);
        break;
    case 9:
        ST7789_DrawImage(20, 75, 56, 106, num9);
        break;
    }
}

void screen_home_uint(void)
{
    if (status.uint)
    {
        ST7789_WriteString(52, 190, "kph", &Inter24, COLOR_WHITE, COLOR_BLACK);
    } else
    {
        ST7789_WriteString(52, 190, "km/h", &Inter24, COLOR_WHITE, COLOR_BLACK);
    }
}

void screen_home_battery(void)
{
    char buffer[4];
    sprintf(buffer, "%d%%", status.homeBatery);
    if (status.homeBatery > 50){
        ST7789_FillRoundRect(3, 220, 166, 42, 8, COLOR_GRAY);
        ST7789_DrawImage(10, 221, 40, 40, battery40);
        if(status.homeBatery < 100){
            ST7789_WriteString(85, 226, buffer, &Inter26, COLOR_GRAY, COLOR_BLACK);
        }else {
            ST7789_WriteString(60, 226, buffer, &Inter26, COLOR_GRAY, COLOR_BLACK);
        }
    } else if (status.homeBatery < 20){
        ST7789_FillRoundRect(3, 220, 166, 42, 8, COLOR_RED);
        ST7789_DrawImage(10, 221, 40, 40, battery40r);
        ST7789_WriteString(85, 226, buffer, &Inter26, COLOR_RED, COLOR_WHITE);
    } else {
        ST7789_FillRoundRect(3, 220, 166, 42, 8, COLOR_ORANGE);
        ST7789_DrawImage(10, 221, 40, 40, battery40o);
        ST7789_WriteString(85, 226, buffer, &Inter26, COLOR_ORANGE, COLOR_WHITE);
    }
}

void screen_home_deep(void)
{
    char buffer[6];
    uint8_t a0 = status.homeDeep%10;
    uint8_t a1 = status.homeDeep/10;
    sprintf(buffer, "%d.%dm", a1, a0);

    if (status.homeDeep > 20){
        ST7789_FillRoundRect(3, 270, 166, 42, 8, COLOR_GRAY);
        ST7789_DrawImage(10, 271, 40, 40, deep40);
        ST7789_WriteString(60, 276, buffer, &Inter26, COLOR_GRAY, COLOR_BLACK);
    } else if (status.homeDeep < 15){
        ST7789_FillRoundRect(3, 270, 166, 42, 8, COLOR_RED);
        ST7789_DrawImage(10, 271, 40, 40, deep40r);
        ST7789_WriteString(60, 276, buffer, &Inter26, COLOR_RED, COLOR_WHITE);
    } else {
        ST7789_FillRoundRect(3, 270, 166, 42, 8, COLOR_ORANGE);
        ST7789_DrawImage(10, 271, 40, 40, deep40o);
        ST7789_WriteString(60, 276, buffer, &Inter26, COLOR_ORANGE, COLOR_WHITE);
    }
}

///////////
void screen_setting(void)
{
    ST7789_FillScreen(COLOR_WHITE);
    screen_home_top();
    screen_setting_pair();
    screen_setting_unit();
    screen_setting_system();
    screen_setting_bottom();
}

void screen_setting_pair(void)
{
    if(status.settingIndex == 0){
        ST7789_FillRectangle(0, 60, 172, 40, COLOR_BLACK);
        ST7789_WriteString(4, 70, "Pair remote", &Font20, COLOR_BLACK, COLOR_WHITE);
    } else {
        ST7789_FillRectangle(0, 60, 172, 40, COLOR_WHITE);
        ST7789_WriteString(4, 70, "Pair remote", &Font20, COLOR_WHITE, COLOR_BLACK);
    }
    ST7789_DrawLine(5, 105, 163, 105, COLOR_GRAY);
    
}

void screen_setting_unit(void)
{
    if(status.settingIndex == 1){
        ST7789_FillRectangle(0, 110, 172, 40, COLOR_BLACK);
        if (status.uint){
            ST7789_WriteString(4, 120, "Unit: kph", &Font20, COLOR_BLACK, COLOR_WHITE);
        } else {
            ST7789_WriteString(4, 120, "Unit: km/h", &Font20, COLOR_BLACK, COLOR_WHITE);
        }
    } else {
        ST7789_FillRectangle(0, 110, 172, 40, COLOR_WHITE);
        if (status.uint){
            ST7789_WriteString(4, 120, "Unit: kph", &Font20, COLOR_WHITE, COLOR_BLACK);
        } else {
            ST7789_WriteString(4, 120, "Unit: km/h", &Font20, COLOR_WHITE, COLOR_BLACK);
        }
    }
    ST7789_DrawLine(5, 155, 163, 155, COLOR_GRAY);
}

void screen_setting_system(void)
{
    if(status.settingIndex == 2){
        ST7789_FillRectangle(0, 160, 172, 40, COLOR_BLACK);
        ST7789_WriteString(4, 170, "System info", &Font20, COLOR_BLACK, COLOR_WHITE);
    } else {
        ST7789_FillRectangle(0, 160, 172, 40, COLOR_WHITE);
        ST7789_WriteString(4, 170, "System info", &Font20, COLOR_WHITE, COLOR_BLACK);
    } 
}

void screen_setting_bottom(void)
{
    ST7789_FillRectangle(0, 272, 172, 48, COLOR_GRAY);
    switch (status.botIndex)
    {
    case 0:
        ST7789_WriteString(43, 284, "Find", &Inter24, COLOR_GRAY, COLOR_BLACK);
        break;
    case 1:
        ST7789_WriteString(22, 284, "Change", &Inter24, COLOR_GRAY, COLOR_BLACK);
        break;
    case 2:
        ST7789_WriteString(43, 284, "Open", &Inter24, COLOR_GRAY, COLOR_BLACK);
        break;
    case 3:
        ST7789_WriteString(43, 284, "Pair", &Inter24, COLOR_GRAY, COLOR_BLACK);
        break;
    case 4:
        ST7789_WriteString(43, 284, "Back", &Inter24, COLOR_GRAY, COLOR_BLACK);
        break;
    case 5:
        ST7789_WriteString(12, 284, "Pairing", &Inter24, COLOR_GRAY, COLOR_BLACK);
        break;
    case 6:
        ST7789_WriteString(22, 284, "Paired", &Inter24, COLOR_GRAY, COLOR_BLACK);
        break;
    default:
        break;
    }
}


///

void screen_pair(void)
{
    ST7789_FillScreen(COLOR_WHITE);
    screen_home_top();
    screen_pair_device1(1, "Skua 1");
    screen_pair_device2(0, "Skua 2");
    screen_setting_bottom();
}

void screen_pair_device1(uint8_t select, char *text)
{
    if(status.pairDevice == 0){
        ST7789_FillRectangle(0, 60, 172, 40, COLOR_BLACK);
        ST7789_WriteString(4, 70, text, &Font20, COLOR_BLACK, COLOR_WHITE);
    } else {
        ST7789_FillRectangle(0, 60, 172, 40, COLOR_WHITE);
        ST7789_WriteString(4, 70, text, &Font20, COLOR_WHITE, COLOR_BLACK);
    }
    
}

void screen_pair_device2(uint8_t select, char *text)
{
    if(status.pairDevice == 1){
        ST7789_FillRectangle(0, 110, 172, 40, COLOR_BLACK);
        ST7789_WriteString(4, 120, text, &Font20, COLOR_BLACK, COLOR_WHITE);
    } else {
        ST7789_FillRectangle(0, 110, 172, 40, COLOR_WHITE);
        ST7789_WriteString(4, 120, text, &Font20, COLOR_WHITE, COLOR_BLACK);
    }
}

///

void screen_info(void)
{
    ST7789_FillScreen(COLOR_WHITE);
    screen_home_top();
    ST7789_WriteString(5, 60, "ID", &Font24, COLOR_WHITE, COLOR_BLACK);
    ST7789_WriteString(5, 85, "000 000000", &Font16, COLOR_WHITE, COLOR_BLACK);
    ST7789_WriteString(5, 110, "Version", &Font24, COLOR_WHITE, COLOR_BLACK);
    ST7789_WriteString(5, 135, "1.0.2", &Font16, COLOR_WHITE, COLOR_BLACK);
    ST7789_WriteString(5, 160, "SN", &Font24, COLOR_WHITE, COLOR_BLACK);
    ST7789_WriteString(5, 185, "000000", &Font16, COLOR_WHITE, COLOR_BLACK);
    screen_setting_bottom();
}

void screen_pairing(void)
{
    ST7789_FillScreen(COLOR_WHITE);
    screen_home_top();
    screen_setting_bottom();
    for(uint8_t i = 0; i <8; i++){
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
    ST7789_FillScreen(COLOR_WHITE);
    screen_home_top();
    ST7789_DrawImage(47, 121, 78, 78, done78);
    screen_setting_bottom();
}
