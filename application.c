/* 
 * File     : application.c
 * Author   : Mohamed Ahmed Abdel Wahab
 * LinkedIn : https://www.linkedin.com/in/mohamed-abdel-wahab-162413253/
 * Github   : https://github.com/moabdelwahab6611
 * Created on May 21, 2023, 5:38 PM
 */

/**************************Includes-Section*****************************/
#include "application.h"
/***********************************************************************/

/***********************************************************************/
dc_motor_t dc_motor_1 =
{
    .dc_motor_pin[0].port = PORTC_INDEX,
    .dc_motor_pin[0].pin = GPIO_PIN0,
    .dc_motor_pin[0].logic = DC_MOTOR_STATUS_OFF,
    .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_pin[1].port = PORTC_INDEX,
    .dc_motor_pin[1].pin = GPIO_PIN1,
    .dc_motor_pin[1].logic = DC_MOTOR_STATUS_OFF,
    .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT        
};

dc_motor_t dc_motor_2 =
{
    .dc_motor_pin[0].port = PORTC_INDEX,
    .dc_motor_pin[0].pin = GPIO_PIN2,
    .dc_motor_pin[0].logic = DC_MOTOR_STATUS_OFF,
    .dc_motor_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor_pin[1].port = PORTC_INDEX,
    .dc_motor_pin[1].pin = GPIO_PIN3,
    .dc_motor_pin[1].logic = DC_MOTOR_STATUS_OFF,
    .dc_motor_pin[1].direction = GPIO_DIRECTION_OUTPUT
};
/***********************************************************************/

/***********************Main Function-Section***************************/
int main() 
{ 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
    
    while(1)
    {
        ret = dc_motor_move_right(&dc_motor_1);
        ret = dc_motor_move_right(&dc_motor_2);
        __delay_ms(3000);
        ret = dc_motor_move_left(&dc_motor_1);
        ret = dc_motor_move_left(&dc_motor_2);
        __delay_ms(3000);
        ret = dc_motor_stop(&dc_motor_1);
        ret = dc_motor_stop(&dc_motor_2);
        __delay_ms(3000);
        ret = dc_motor_move_right(&dc_motor_1);
        ret = dc_motor_move_left(&dc_motor_2);
        __delay_ms(3000);
        ret = dc_motor_stop(&dc_motor_1);
        ret = dc_motor_stop(&dc_motor_2);
        __delay_ms(3000);
        ret = dc_motor_move_left(&dc_motor_1);
        ret = dc_motor_move_right(&dc_motor_2);
        __delay_ms(3000);
    }
    return (EXIT_SUCCESS);
}
/***********************************************************************/

/*************************Functions-Section*****************************/
void application_intialize(void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = dc_motor_initialize(&dc_motor_1);
    ret = dc_motor_initialize(&dc_motor_2);
}
/***********************************************************************/