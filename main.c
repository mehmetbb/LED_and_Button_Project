#include "stm32f10x.h"                  // Device header

GPIO_InitTypeDef GPIO_struct;

void GPIO_Config(){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_struct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_struct.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9; // PC8: Blue, PC9: Green
	GPIO_struct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOC,&GPIO_struct);
	
	GPIO_struct.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_struct.GPIO_Pin = GPIO_Pin_10; // Button
	GPIO_struct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOC,&GPIO_struct);

}


int main(){

GPIO_Config();
	
while(1){
	
	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_10)){    // If the button is pressed 	
		GPIO_SetBits(GPIOC,GPIO_Pin_9);		 // Green LED on
		GPIO_ResetBits(GPIOC,GPIO_Pin_8);	 // Blue LED off
	}
	else {																				   // If the button is not pressed
		GPIO_SetBits(GPIOC,GPIO_Pin_8);		 // Blue LED on
		GPIO_ResetBits(GPIOC,GPIO_Pin_9);	 // Green LED off
	}
	
}

}
