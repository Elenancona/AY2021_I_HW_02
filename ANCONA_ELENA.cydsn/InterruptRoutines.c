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
    
    switch(counter)
    {
        
        case(1):
        PWM_1_SetCompareMode1(2);
        PWM_1_SetCompareMode2(2);
        PWM_1_WritePeriod(DUE_SEC);
        PWM_1_WriteCompare1(0);
        PWM_1_WriteCompare2(0);
        break;
        
        case(2):
        PWM_1_SetCompareMode1(2);
        PWM_1_SetCompareMode2(2);
        PWM_1_WritePeriod(DUE_SEC);
        PWM_1_WriteCompare1(128);
        PWM_1_WriteCompare2(0);
        break;
        
        case(3):
        PWM_1_SetCompareMode1(2);
        PWM_1_SetCompareMode2(3);
        PWM_1_WritePeriod(DUE_SEC);
        PWM_1_WriteCompare1(0);
        PWM_1_WriteCompare2(128);
        break;
        
        case(4):
        PWM_1_SetCompareMode1(3);
        PWM_1_SetCompareMode2(2);
        PWM_1_WritePeriod(UN_SEC);
        PWM_1_WriteCompare1(64);
        PWM_1_WriteCompare2(64);
        break;
        
        case(5):
        PWM_1_SetCompareMode1(2);
        PWM_1_SetCompareMode2(3);
        PWM_1_WritePeriod(MEZZO_SEC);
        PWM_1_WriteCompare1(32);
        PWM_1_WriteCompare2(32);
        break;
        
        case(6):
        PWM_1_SetCompareMode1(2);
        PWM_1_SetCompareMode2(2);
        PWM_1_WritePeriod(DUE_SEC);
        PWM_1_WriteCompare1(128);
        PWM_1_WriteCompare2(64);
        break;
        
        case(7):
        PWM_1_SetCompareMode1(2);
        PWM_1_SetCompareMode2(3);
        PWM_1_WritePeriod(UN_SEC);
        PWM_1_WriteCompare1(192);
        PWM_1_WriteCompare2(128);
       
        
        counter=0;
        break;
    }
  
   
}
    



    
    
// Toggle The LED
//Red_LED_Write(Green_LED_Read());
//Green_LED_Write(~Green_LED_Read());
//}

/* [] END OF FILE */
