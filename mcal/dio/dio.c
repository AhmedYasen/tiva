/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "dio_types.h"
#include "dio.h"
#include "../mcu_hw.h"
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"

Std_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Std_levelType ret = STD_error;
    Dio_PortType PortId = (Dio_PortType)(ChannelId / 8);
    Dio_ChannelType ChannelPos = (Dio_ChannelType)(ChannelId % 8);

    /*Return the level value of given Channel */

    switch(PortId)
    {
    case Dio_Port_A:
        ret = (Std_levelType)(GET_BIT(PORTA_BaseAddr->GPIODATA,ChannelPos));
        break;

    case Dio_Port_B:
        ret = (Std_levelType)(GET_BIT(PORTB_BaseAddr->GPIODATA,ChannelPos));
        break;

    case Dio_Port_C:
        ret = (Std_levelType)(GET_BIT(PORTC_BaseAddr->GPIODATA,ChannelPos));
        break;
    case Dio_Port_D:
        ret = (Std_levelType)(GET_BIT(PORTD_BaseAddr->GPIODATA,ChannelPos));
        break;
    case Dio_Port_E:
        ret = (Std_levelType)(GET_BIT(PORTE_BaseAddr->GPIODATA,ChannelPos));
        break;
    case Dio_Port_F:
        ret = (Std_levelType)(GET_BIT(PORTF_BaseAddr->GPIODATA,ChannelPos));
        break;
    default:
        /*error*/
        break;
    }
    return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Std_levelType Level)
{
    Dio_PortType PortId        =  (Dio_PortType)(ChannelId / 8);
    Dio_ChannelType ChannelPos =  (Dio_ChannelType)(ChannelId % 8);

    /* Write the input value in the corresponding ChannelId */

    switch(PortId)
    {
    case Dio_Port_A:
        if(Level == STD_low)
        {
            CLR_BIT(PORTA_BaseAddr->GPIODATA,ChannelPos);
        }
        else
        {
            SET_BIT(PORTA_BaseAddr->GPIODATA,ChannelPos);
        }
        break;

    case Dio_Port_B:
        if(Level == STD_low)
        {
            CLR_BIT(PORTB_BaseAddr->GPIODATA,ChannelPos);
        }
        else
        {
            SET_BIT(PORTB_BaseAddr->GPIODATA,ChannelPos);
        }
        break;

    case Dio_Port_C:
        if(Level == STD_low)
        {
            CLR_BIT(PORTC_BaseAddr->GPIODATA,ChannelPos);
        }
        else
        {
            SET_BIT(PORTC_BaseAddr->GPIODATA,ChannelPos);
        }
        break;
    case Dio_Port_D:
        if(Level == STD_low)
        {
            CLR_BIT(PORTD_BaseAddr->GPIODATA,ChannelPos);
        }
        else
        {
            SET_BIT(PORTD_BaseAddr->GPIODATA,ChannelPos);
        }
        break;
    case Dio_Port_E:
        if(Level == STD_low)
        {
            CLR_BIT(PORTE_BaseAddr->GPIODATA,ChannelPos);
        }
        else
        {
            SET_BIT(PORTE_BaseAddr->GPIODATA,ChannelPos);
        }
        break;
    case Dio_Port_F:
        if(Level == STD_low)
        {
            CLR_BIT((PORTF_BaseAddr->GPIODATA),ChannelPos);
        }
        else
        {
            SET_BIT((PORTF_BaseAddr->GPIODATA),ChannelPos);
        }
        break;
    default:
        /*error*/
        break;
    }
}
uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;

    switch(PortId)
    {
    case Dio_Port_A:

        ret = PORTA_BaseAddr->GPIODATA;
        break;

    case Dio_Port_B:

        ret = PORTB_BaseAddr->GPIODATA;
        break;

    case Dio_Port_C:

        ret = PORTC_BaseAddr->GPIODATA;
        break;
    case Dio_Port_D:

        ret = PORTD_BaseAddr->GPIODATA;
        break;
    case Dio_Port_E:

        ret = PORTE_BaseAddr->GPIODATA;
        break;
    case Dio_Port_F:

        ret = PORTF_BaseAddr->GPIODATA;
        break;
    default:
        /*error*/
        break;
    }


    return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{
    /* Write the input value in the corresponding PortId */


    switch(PortId)
    {
    case Dio_Port_A:

        PORTA_BaseAddr->GPIODATA = value;
        break;

    case Dio_Port_B:

        PORTB_BaseAddr->GPIODATA = value;

        break;

    case Dio_Port_C:

        PORTC_BaseAddr->GPIODATA = value;

        break;
    case Dio_Port_D:

        PORTD_BaseAddr->GPIODATA = value;
        break;
    case Dio_Port_E:

        PORTE_BaseAddr->GPIODATA = value;
        break;
    case Dio_Port_F:

        PORTF_BaseAddr->GPIODATA = value;
        break;
    default:
        /*error*/
        break;
    }

}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    /* toggle the corresponding ChannelId */
    Dio_PortType PortId        =  (Dio_PortType)(ChannelId / 8);
    Dio_ChannelType ChannelPos =  (Dio_ChannelType)(ChannelId % 8);

    switch(PortId)
    {
    case Dio_Port_A:

        TOGGLE_BIT(PORTA_BaseAddr->GPIODATA,ChannelPos);

        break;

    case Dio_Port_B:

        TOGGLE_BIT(PORTB_BaseAddr->GPIODATA,ChannelPos);

        break;

    case Dio_Port_C:

        TOGGLE_BIT(PORTC_BaseAddr->GPIODATA,ChannelPos);

        break;
    case Dio_Port_D:

        TOGGLE_BIT(PORTD_BaseAddr->GPIODATA,ChannelPos);

        break;
    case Dio_Port_E:

        TOGGLE_BIT(PORTE_BaseAddr->GPIODATA,ChannelPos);

        break;
    case Dio_Port_F:

        TOGGLE_BIT(PORTF_BaseAddr->GPIODATA,ChannelPos);

        break;
    default:
        /*error*/
        break;
    }


}
void Dio_FlipPort(Dio_PortType PortId)
{
    /* toggle the port value */


    switch(PortId)
    {
    case Dio_Port_A:

        PORTA_BaseAddr->GPIODATA ^= 1;
        break;

    case Dio_Port_B:

        PORTB_BaseAddr->GPIODATA ^= 1;

        break;

    case Dio_Port_C:

        PORTC_BaseAddr->GPIODATA ^= 1;

        break;
    case Dio_Port_D:

        PORTD_BaseAddr->GPIODATA ^= 1;
        break;
    case Dio_Port_E:

        PORTE_BaseAddr->GPIODATA ^= 1;
        break;
    case Dio_Port_F:

        PORTF_BaseAddr->GPIODATA ^= 1;
        break;
    default:
        /*error*/
        break;
    }
}
