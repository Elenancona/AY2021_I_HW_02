/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

// Include header
#include "InterruptRoutines.h"
#include "isr_1.h"
#include "project.h"
#include "PWM_1.h"

#define DUE_SEC 255
#define UN_SEC 127
#define MEZZO_SEC 63
#define QUARTO_SEC 32


int counter=0;


CY_ISR(Custom_LED_ISR)
{
  counter ++;
 
    
    if (counter==1)
    {
        PWM_1_WritePeriod(DUE_SEC);
        PWM_1_WriteCompare1(0); // Green LED is active 
        PWM_1_WriteCompare2(0); // Red LED is active
    
    }
    if (counter==2)
    {
        PWM_1_WritePeriod (DUE_SEC);
        PWM_1_WriteCompare1(128); // Green LED is active for half period
        PWM_1_WriteCompare2(0); //Red LED is active for the whole period
       
    }
    
    if (counter==3) // Is the opposite of condition 2
    {   PWM_1_WritePeriod (DUE_SEC);
        PWM_1_WriteCompare1(0);
        PWM_1_WriteCompare2(128);
        
    }
    if (counter==4)
    {   PWM_1_WritePeriod (UN_SEC);
        PWM_1_WriteCompare1(64);
        PWM_1_WriteCompare2(64);
        
    }
    
     if (counter==5)
    {   PWM_1_WritePeriod (QUARTO_SEC);
        PWM_1_WriteCompare1(32);
        PWM_1_WriteCompare2(32);
        
    }
    
     if (counter==6)
    {   PWM_1_WritePeriod (DUE_SEC);
        PWM_1_WriteCompare1(128);
        PWM_1_WriteCompare2(192);
        
    }
    
    if (counter==7)
    {   PWM_1_WritePeriod (DUE_SEC);
        PWM_1_WriteCompare1(64);
        PWM_1_WriteCompare2(128);
        
    }
    
    
    counter=1;
    
}



    
    
// Toggle The LED
//Red_LED_Write(Green_LED_Read());
//Green_LED_Write(~Green_LED_Read());
//}

/* [] END OF FILE */
