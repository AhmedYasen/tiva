/*
 * nvic_lcfg.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "nvic_cfg.h"
#include "../mcal/nvic/nvic_types.h"



const NVIC_CfgType NVIC_CfgArr[NVIC_NUM_OF_ENABLED_INT]={

   /* Configure each Enabled Interrupt */
                     {GPIOA_IRQn,Groups0_SubGroup0_E},
                     {GPIOB_IRQn,Groups1_SubGroup0_E},
                     {GPIOC_IRQn,Groups0_SubGroup0_E},
};
