/*
 * SysCtr.c
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../config/SysCtr_cfg.h"
#include "../mcu_hw.h"
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"

/*TODO include SysCtr_cfg.h*/


void SysCtr_init(void)
{
    /*TODO Enable configured Peripherals CLock gates*/


    /*TODO Set System CLock Source as configured*/

    /*TODO set CLock Frequency as configured -
     * use Figure 5-5. Main Clock Tree Page.222 in DATASHEET as reference.
     * */

    RCGCGPIO_REG.R0 = GPIOA_CONTROL_STATE;
    RCGCGPIO_REG.R1 = GPIOB_CONTROL_STATE;
    RCGCGPIO_REG.R2 = GPIOC_CONTROL_STATE;
    RCGCGPIO_REG.R3 = GPIOD_CONTROL_STATE;
    RCGCGPIO_REG.R4 = GPIOE_CONTROL_STATE;
    RCGCGPIO_REG.R5 = GPIOF_CONTROL_STATE;
}

uint32 SysCtr_getSysClockFreq(void)
{
    /*TODO return the current system clock frequency */
    return 0;
}

