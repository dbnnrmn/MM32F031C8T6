#include <stdio.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "hal_gpio.h"
#include "hal_rcc.h"
#include "task.h"
#include "types.h"



void my_func() {
  static uint8_t a = 0;
  while (1) { a++; }
}

int main() {
  TaskHandle_t xHandle = NULL;
  xTaskCreate(my_func, "task", 300, (void*)1, tskIDLE_PRIORITY, &xHandle);

  RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOB, ENABLE);

  GPIO_InitTypeDef mypin = {.GPIO_Pin = GPIO_Pin_6,
                            .GPIO_Speed = GPIO_Speed_20MHz,
                            .GPIO_Mode = GPIO_Mode_Out_PP};

  GPIO_Init(GPIOB, &mypin);

  vTaskStartScheduler();

}
