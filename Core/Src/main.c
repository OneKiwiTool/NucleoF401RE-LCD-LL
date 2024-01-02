#include "main.h"
#include "board.h"
#include "screen.h"
#include <stdio.h>

uint8_t page = 0;
uint8_t render = 0;

int main(void)
{
    board_init();
    //printf("\nStart Program!\n");

    screen_splash();
    screen_home();

    LL_mDelay(2000);
    screen_setting();

    LL_mDelay(2000);
    screen_pair();

    LL_mDelay(2000);
    screen_info();

    LL_mDelay(2000);
    screen_pairing();

    screen_paired();

    while (1)
    {
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