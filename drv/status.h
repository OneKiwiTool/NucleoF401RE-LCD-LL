#ifndef __STATUS_H_
#define __STATUS_H_

#include <stdint.h>

typedef struct
{
    uint8_t page;
    uint8_t uint; // 0: km/h 1: kph
    uint8_t topBluetooth; // 0: disconnect 1: connected
    uint8_t topBatery; // 0 <= bateryPercent <= 100
    uint8_t homeLevel;
    uint8_t homeSpeed;
    uint8_t homeBatery;
    uint8_t homeDeep; // 10xm
    uint8_t settingIndex;
    uint8_t pairDevice;
    uint8_t botIndex;
} Screen_Status;

void screen_status_init(void);

void test_home_status1(void);
void test_home_status2(void);
void test_setting_status1(void);
void test_setting_status2(void);
void test_setting_status3(void);
void test_pair_status1(void);
void test_pair_status2(void);
void test_info_status(void);
void test_pairing_status(void);
void test_paired_status(void);

#endif /* __STATUS_H_ */
