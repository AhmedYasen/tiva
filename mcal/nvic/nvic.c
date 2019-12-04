/*
 * nvic.c
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */


#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"
/*TODO include processor.h*/

#include "../../utils/processor/processor.h"
#include "../../config/nvic_cfg.h"
#include "../mcu_hw.h"
#include "nvic_types.h"
#include "nvic.h"


extern NVIC_CfgType NVIC_CfgArr[];


void NVIC_init(void)
{
    uint16  au_LoopCounter;
    uint8   au_InterruptEnReg;
    uint8   au_InterruptEnBit;
    uint8   au_InterruptPriReg;
    uint8   au_InterruptPriBit;
    uint8   au_ArrayShiftValueForPriority[4]={5,13,21,29};
    /*TODO : switch to privilege mode - use switch function in processor.h*/


    /*TODO :loop for NVIC_CfgArr configure each Interrupt
     *  as stated in Cfg (Enable/Priority/sub-priority)
     *  */
for(au_LoopCounter = 0 ; au_LoopCounter < NVIC_NUM_OF_ENABLED_INT ; au_LoopCounter++)
{
    /*                  Select Interrupt Register                  */
    au_InterruptEnReg = NVIC_CfgArr[au_LoopCounter].InterruptNum/32;
    /*                  Select Interrupt Bit                      */
    au_InterruptEnBit = NVIC_CfgArr[au_LoopCounter].InterruptNum%32;
    /*                  Setting the Interrupt Enable               */
    *(INTERRUPT_ENABLE_REG(au_InterruptEnReg))  |= (1<<au_InterruptEnBit);

    /*                  Select Priority Register                  */
    au_InterruptPriReg = NVIC_CfgArr[au_LoopCounter].InterruptNum/4;
    /*                  Select Priority Bit                       */
    au_InterruptPriBit = NVIC_CfgArr[au_LoopCounter].InterruptNum%4;
    /*                  Setting Priority Group                   */
    *(INTERRUPT_PRI_REG(au_InterruptPriReg))    |= ((NVIC_CfgArr[au_LoopCounter].Groups_SubgroupsPiriorty)<< au_ArrayShiftValueForPriority[au_InterruptPriBit]);


}


    /*TODO : return to non-privilege mode */

}



