#include "status.h"

Screen_Status status;

void screen_status_init(void)
{
    status.top.iconBluetooth = 0;
    status.top.bateryPercent = 90;

    status.home.level = 0;
    status.home.speed = 00;
    status.home.uint = 0;
    status.home.batery = 75;
    status.home.deep = 31;
}

void test_home_status1(void)
{
    status.top.iconBluetooth = 1;
    status.top.bateryPercent = 45;

    status.home.level = 3;
    status.home.speed = 45;
    status.home.uint = 1;
    status.home.batery = 25;
    status.home.deep = 19;
}

void test_home_status2(void)
{
    status.top.iconBluetooth = 1;
    status.top.bateryPercent = 12;

    status.home.level = 5;
    status.home.speed = 12;
    status.home.uint = 0;
    status.home.batery = 18;
    status.home.deep = 14;
}