#ifndef __BOARD_H_
#define __BOARD_H_

#define CS_PIN      LL_GPIO_PIN_6
#define CS_PORT     GPIOB
#define DC_PIN      LL_GPIO_PIN_7
#define DC_PORT     GPIOC
#define RST_PIN     LL_GPIO_PIN_9
#define RST_PORT    GPIOA

void board_init(void);

#endif /* __BOARD_H_ */
