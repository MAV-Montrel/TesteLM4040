
#include "ServiceTimer.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"



volatile uint32_t *count_aux = NULL;

volatile uint32_t tickRate = 0;

void SRV_TIMER_Init(void)
{
     
    count_aux = &tickRate;
    TMR0_SetInterruptHandler(SRV_TIMER_TickInterrupt);
}

void SRV_TIMER_Run(void)
{
    
}


void SRV_TIMER_TickInterrupt(void)
{
    tickRate++;
}

uint32_t SRV_TIMER_GetTick(void)
{
    
    return *count_aux;
}

/*
 * exemplos de uso
void APP_Run()
{

	static uint32_t tick = 0;
	static uint32_t tickLast = 0;
	
	tick = SRV_TIMER_GetTick();
	if(tick >= (uint32_t)(tickLast + 10))
	{
		tickLast = tick;
		
		
	}
	
	APP_LeituraTempo();
	APP_AcionamentoRele();
	
}

void APP_LeituraTempo()
{
	static uint32_t tick = 0;
	static uint32_t tickLast = 0;
	
	tick = SRV_TIMER_GetTick();
	if(tick >= (uint32_t)(tickLast + 10))
	{
		tickLast = tick;
		
		
	}	

}
*/
