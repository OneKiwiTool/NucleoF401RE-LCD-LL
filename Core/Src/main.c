#include "main.h"
#include "board.h"
#include "status.h"
#include "screen.h"
#include <stdio.h>

uint8_t page = 0;
uint8_t render = 0;
extern volatile uint32_t SysTick_counter;
volatile uint32_t time;
int main(void)
{
    board_init();
    time = SysTick_counter;
    
    screen_status_init();

    screen_splash();
    screen_home();

#if 0
    LL_mDelay(2000);
    test_home_status1();
    screen_home();

    LL_mDelay(2000);
    test_home_status2();
    screen_home();

    LL_mDelay(2000);
    test_setting_status1();
    screen_setting();

    LL_mDelay(2000);
    test_setting_status2();
    screen_setting();

    LL_mDelay(2000);
    test_setting_status3();
    screen_setting();

    LL_mDelay(2000);
    test_pair_status1();
    screen_pair();

    LL_mDelay(2000);
    test_pair_status2();
    screen_pair();

    LL_mDelay(2000);
    test_info_status();
    screen_info();

    LL_mDelay(2000);
    test_pairing_status();
    screen_pairing();

    test_paired_status();
    screen_paired();
#endif
    while (1)
    {
        if (render)
        {
            render = 0;
            switch (page)
            {
            case 0:
                screen_status_init();
                screen_home();
                break;
            case 1:
                test_home_status1();
                screen_home();
                break;
            case 2:
                test_home_status1();
                screen_home();
                break;
            case 3:
                test_setting_status1();
                screen_setting();
                break;
            case 4:
                test_setting_status2();
                screen_setting();
                break;
            case 5:
                test_setting_status3();
                screen_setting();
                break;
            case 6:
                test_pair_status1();
                screen_pair();
                break;
            case 7:
                test_pair_status2();
                screen_pair();
                break;
            case 8:
                test_info_status();
                screen_info();
                break;
            case 9:
                test_pairing_status();
                screen_pairing();
                break;
            case 10:
                test_paired_status();
                screen_paired();
                break;
            default:
                break;
            }
        }
    }
}

void UserButton_Callback(void)
{
    if((SysTick_counter-time) > 1000){
        time = SysTick_counter;
        page++;
        render = 1;
        if (page >10)
        {
            page = 0;
        }
    }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
