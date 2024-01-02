#ifndef __STATUS_H_
#define __STATUS_H_

#include <stdint.h>

typedef struct
{
    uint8_t iconBluetooth; // 0: disconnect 1: connected
    uint8_t bateryPercent; // 0 <= bateryPercent <= 100
} Top_Status;

typedef struct
{
    uint8_t BaudRate;
} Bot_Status;

typedef struct
{
    uint8_t level;
    uint8_t speed;
    uint8_t uint; // 0: km/h 1: kph
    uint8_t batery;
    uint8_t deep; // 10xm
} Home_Status;

typedef struct
{
    Top_Status top;
    Home_Status home;
} Screen_Status;

void screen_status_init(void);

void test_home_status1(void);
void test_home_status2(void);

#endif /* __STATUS_H_ */
