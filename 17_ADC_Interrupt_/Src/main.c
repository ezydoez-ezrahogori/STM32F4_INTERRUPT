#include<stdio.h>
#include<stm32f4xx.h>
#include<stdint.h>
#include<uart.h>
#include  "adc.h"

uint32_t sensor_value;
static void adc_callback(void);

int  main(void){



	void uart2_tx_init();
	pa1_adc_interrupt_init();

	start_conversion();


	while(1)
	{


	}
}

static void adc_callback(void)
{
	sensor_value = ADC1->DR;
	printf("Sensor Value : %d\n\r", (int)sensor_value);
}

void ADC_IRQHandler(void)
{
	/**check for EOC in SR(Status Register)*/
	if((ADC1->SR &  SR_EOC) !=0)
	{
		/*Clear the EOC*/
		ADC1->SR &=~SR_EOC;

		//Do S=something
		adc_callback();
	}
}








