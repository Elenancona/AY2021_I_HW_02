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
#include "PWM_RED_LED.h"
#include "PWM_GREEN_LED.h" 


#define DUE_SEC 255
#define UN_SEC 127
#define MEZZO_SEC 63


int counter=1;



CY_ISR(Custom_LED_ISR)

{
      
  counter ++;
    
    switch(counter)
    {
        
        case(1):
        PWM_GREEN_LED_SetCompareMode(2); //CMP type is less than or equal
        PWM_RED_LED_SetCompareMode(2);
        PWM_GREEN_LED_WritePeriod(DUE_SEC);
        PWM_RED_LED_WritePeriod(DUE_SEC);
        PWM_GREEN_LED_WriteCompare(0); // LED is always on 
        PWM_RED_LED_WriteCompare(0);
        break;
        
        case(2):
        PWM_GREEN_LED_SetCompareMode(2);
        PWM_RED_LED_SetCompareMode(2);
        PWM_GREEN_LED_WritePeriod(DUE_SEC);
        PWM_RED_LED_WritePeriod(DUE_SEC);
        PWM_GREEN_LED_WriteCompare(128);
        PWM_RED_LED_WriteCompare(0);        
        break;
        
        case(3):
        PWM_GREEN_LED_SetCompareMode(2);
        PWM_RED_LED_SetCompareMode(4); //CMP type is grater than or equal
        PWM_GREEN_LED_WritePeriod(DUE_SEC);
        PWM_RED_LED_WritePeriod(DUE_SEC);
        PWM_GREEN_LED_WriteCompare(0);
        PWM_RED_LED_WriteCompare(128);        
        break;
        
        case(4):
        PWM_GREEN_LED_SetCompareMode(4);
        PWM_RED_LED_SetCompareMode(2);
        PWM_GREEN_LED_WritePeriod(UN_SEC);
        PWM_RED_LED_WritePeriod(UN_SEC);
        PWM_GREEN_LED_WriteCompare(64);
        PWM_RED_LED_WriteCompare(64);
        break;
        
        case(5):
        PWM_GREEN_LED_SetCompareMode(2);
        PWM_RED_LED_SetCompareMode(4);
        PWM_GREEN_LED_WritePeriod(MEZZO_SEC);
        PWM_RED_LED_WritePeriod(MEZZO_SEC);
        PWM_GREEN_LED_WriteCompare(32);
        PWM_RED_LED_WriteCompare(32);
        break;
        
        case(6):
        PWM_GREEN_LED_SetCompareMode(2);
        PWM_RED_LED_SetCompareMode(2);
        PWM_GREEN_LED_WritePeriod(DUE_SEC);
        PWM_RED_LED_WritePeriod(DUE_SEC);
        PWM_GREEN_LED_WriteCompare(128);
        PWM_RED_LED_WriteCompare(64);
        break;
        
        case(7):
        PWM_GREEN_LED_SetCompareMode(2);
        PWM_RED_LED_SetCompareMode(3);
        PWM_GREEN_LED_WritePeriod(UN_SEC);
        PWM_RED_LED_WritePeriod(DUE_SEC);
        PWM_GREEN_LED_WriteCompare(64);
        PWM_RED_LED_WriteCompare(128);           
        
        counter=0; //Counter 0 so the next time I push it I will be in case 1
        break;
    }
  
   
}

/* [] END OF FILE */
