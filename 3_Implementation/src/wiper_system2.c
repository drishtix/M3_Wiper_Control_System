#include"wiper_system_1.h"             
                             
#include"wiper_system_2.h"            

#include<stdio.h>           

#include<stdint.h>         

#define START_SRAM           0x20000000UL
#define SIZE_SRAM            (128U * 1024U) 
#define END_SRAM             ((START_SRAM) + (SIZE_SRAM))

#define START_SRAM   END_SRAM

extern uint32_t _sdata;

extern uint32_t _data;

extern uint32_t _edata;

uint32_t vector_table[] __attribute__((section(".isr_vector")))   = {
START_STACK ,
             (uint32_t)Reset_Handler,
	         (uint32_t)NMI_Handler,
	         (uint32_t)HardFault_Handler,
             (uint32_t)MemManage_Handler,
             0,
             0,
             0,
             0,
             0,
             0,
	         (uint32_t)TIM1_CC_IRQHandler,     
	         (uint32_t)TIM2_IRQHandler,        
	         (uint32_t)TIM3_IRQHandler,        
	         (uint32_t)TIM4_IRQHandler,  
             0,
            (uint32_t)I2C1_EV_IRQHandler,     
	        (uint32_t)I2C1_ER_IRQHandler,     
	        (uint32_t)I2C2_EV_IRQHandler,     
	        (uint32_t)I2C2_ER_IRQHandler,   
            0,
            (uint32_t)SPI1_IRQHandler,        
	        (uint32_t)SPI2_IRQHandler,        
	        (uint32_t)USART1_IRQHandler, 
            (uint32_t)UART4_IRQHandler,       
	        (uint32_t)UART5_IRQHandler,
            (uint32_t)USART6_IRQHandler,      
	        (uint32_t)I2C3_EV_IRQHandler,     
	        (uint32_t)I2C3_ER_IRQHandler, 
	        (uint32_t)FPU_IRQHandler,     
            };

            void Dummy_Handler(void)
{
	while(1);
}



void Reset_Handler(void)
{
	uint32_t total_size_of_data = (uint32_t)&_edata - (uint32_t)&_sdata;
	
	uint8_t *source = (uint8_t*)&_data; 

	uint8_t *data = (uint8_t*)&_sdata; 
	
	for(uint32_t i =0 ; i < total_size_of_data ; i++)
	{
		*data++ = *source++;
	}
	total_size_of_data = (uint32_t)&_ebss - (uint32_t)&_sbss;
	data = (uint8_t*)&_sbss;
	for(uint32_t k =0 ; k < total_size_of_data ; i++)
	{
		*data++ = 0;
	}
	
    
    
    main();
}

