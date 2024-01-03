#include "status.h"

Screen_Status status;

void screen_status_init(void)
{
    status.topBluetooth = 0;
    status.topBatery = 90;

    status.homeLevel = 0;
    status.homeSpeed = 00;
    status.uint = 1;
    status.homeBatery = 75;
    status.homeDeep = 31;
}

void test_home_status1(void)
{
    status.topBluetooth = 1;
    status.topBatery = 45;

    status.homeLevel = 3;
    status.homeSpeed = 45;
    status.uint = 1;
    status.homeBatery = 25;
    status.homeDeep = 19;
}

void test_home_status2(void)
{
    status.topBluetooth = 1;
    status.topBatery = 12;

    status.homeLevel = 5;
    status.homeSpeed = 12;
    status.uint = 0;
    status.homeBatery = 18;
    status.homeDeep = 14;
}

void test_setting_status1(void)
{
    status.settingIndex = 0;
    status.uint = 0;
    status.botIndex = 0;
}

void test_setting_status2(void)
{
    status.settingIndex = 1;
    status.uint = 1;
    status.botIndex = 1;
}

void test_setting_status3(void)
{
    status.settingIndex = 2;
    status.uint = 0;
    status.botIndex = 2;
}

void test_pair_status1(void)
{
    status.pairDevice = 0;
    status.botIndex = 3;
}

void test_pair_status2(void)
{
    status.pairDevice = 1;
    status.botIndex = 3;
}

void test_info_status(void)
{
    status.botIndex = 4;
}

void test_pairing_status(void)
{
    status.botIndex = 5;
}

void test_paired_status(void)
{
    status.botIndex = 6;
}
