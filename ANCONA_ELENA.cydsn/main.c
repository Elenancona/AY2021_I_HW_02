/* ========================================
 *
// Author: ELENA ANCONA
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h"
#include "InterruptRoutines.h"




int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    

    
    PWM_RED_LED_Start();
    PWM_GREEN_LED_Start();
      
    
    Button_isr_1_StartEx(Custom_LED_ISR);
    
    // To have the system at state 1 at power-on 
    
        PWM_GREEN_LED_SetCompareMode(2); 
        PWM_RED_LED_SetCompareMode(2);
        PWM_GREEN_LED_WritePeriod(255);
        PWM_RED_LED_WritePeriod(255);
        PWM_GREEN_LED_WriteCompare(0); 
        PWM_RED_LED_WriteCompare(0);

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
