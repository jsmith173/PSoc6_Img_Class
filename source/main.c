#include "cyhal.h"
#include "cybsp.h"
#include "main_functions.h"

volatile int a1, current_case, result;

int main(void)
{
    cy_rslt_t result;

#if defined (CY_DEVICE_SECURE)
    cyhal_wdt_t wdt_obj;

    /* Clear watchdog timer so that it doesn't trigger a reset */
    result = cyhal_wdt_init(&wdt_obj, cyhal_wdt_get_max_timeout_ms());
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    cyhal_wdt_free(&wdt_obj);
#endif

    /* Initialize the device and board peripherals */
    result = cybsp_init();

    /* Board init failed. Stop program execution */
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    ai_setup(); 
	
    current_case = 1;
    result = ai_loop(current_case);
	
	a1=result;
	
    /* Enable global interrupts */
    __enable_irq();

    for (;;)
    {
    }
}

/* [] END OF FILE */
