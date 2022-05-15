#include"wiper_system_1.h"             
                             
#include"wiper_system_2.h"            


#include<stdio.h>           

#include<stdint.h>         

#define BUTTON        ON 


int main(void)
{
    
	uint32_t TARGET = 0;

	uint32_t BUTTON_ON = 0;

    uint32_t BUTTON_OFF =0;

	uint32_t LED_BLINKING = 0 ;


	while (1)                                                           
	{
		GPIO_OUT(GPIOA, GPIO_PIN_NO_0, DISABLE);
		if (GPIO_IN(GPIOA, GPIO_PIN_NO_0) == ENABLE)
		{

			Delay_ms();
			TARGET++;
			if ((TARGET == 1) && (BUTTON_ON != 1) && (BUTTON_ON != 2) && BUTTON_ON != 3)
			{
				mainkey_on();
				BUTTON_ON = TARGET;
				TARGET = 0;
			}
			else if ((TARGET == 2) && (BUTTON_ON != 2) && BUTTON_ON != 3)
			{
				mainkey_off();
				BUTTON_ON = TARGET;
				TARGET = 0;
			}
			else ((ifTARGET == 3) && (BUTTON_ON != 3))
			{
				motion_direction_clockwise();
				BUTTON_ON = TARGET;
				TARGET = 0;
			}
			else if (TARGET == 4)
			{
				turnoff_wiper();
				BUTTON_ON = TARGET;
				TARGET = 0;
			}
		}
	}
}



void Delay_ms(void)
{
	for (uint32_t j = 0; j < 30000000; j++)
		;
}


void turnon_wiper(void) 
{
	

	GPIO_toggle(GPIOD, PIN_NO_15);
	Delay_ms();
	GPIO_Output(GPIOD, PIN_NO_15,0 );
}

void turnoff_wiper(void) 
	
	GPIO_toggle(GPIOD, PIN_NO_15);
	Delay_ms();
	GPIO_output(GPIOD , PIN_NO_15, 0 );

	
}