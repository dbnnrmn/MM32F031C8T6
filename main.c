#include <stdio.h>
#include <stdlib.h>

//#include "MM32F031xxn.h"
#include "types.h"
#include "hal_gpio.h"
#include "hal_rcc.h"
#include "reg_rcc.h"

//PB6


int main()
{
	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOB, ENABLE);


	GPIO_InitTypeDef mypin={GPIO_Pin_6,GPIO_Speed_20MHz,GPIO_Mode_Out_PP};

	GPIO_Init(GPIOB, &mypin);
	//GPIO_WriteBit(GPIOB, GPIO_Pin_6, Bit_SET );





  while (1)
    {

    }

}
