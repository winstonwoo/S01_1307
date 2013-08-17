//*****************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Mailbox.h>

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "driverlib/can.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "utils/uartstdio.h"

//*****************************************************************************




void init_low_can( void )
{


     //CAN0 initialization
     //For JTA1043T configuration on CAN1 port
     SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOA ) ;
     SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOE ) ;
     SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOH ) ;

     GPIOPinConfigure( GPIO_PE4_CAN0RX ) ;
     GPIOPinConfigure( GPIO_PE5_CAN0TX ) ;

     GPIOPinTypeCAN( GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5) ;

     //PH3 work as CAN_ERR_N
     GPIOPinTypeGPIOInput(GPIO_PORTH_BASE, GPIO_PIN_3) ;

       //Disable Bypass
     GPIOPinTypeGPIOOutput( GPIO_PORTA_BASE, GPIO_PIN_5) ;
      GPIOPinWrite( GPIO_PORTA_BASE, GPIO_PIN_5, GPIO_PIN_5) ;

       //Enable CAN0 port
       SysCtlPeripheralEnable( SYSCTL_PERIPH_CAN0 ) ;

       CANInit( CAN0_BASE ) ;
       CANBitRateSet( CAN0_BASE, SysCtlClockGet(), 100000) ;
       //HWREG(CAN0_BASE + CAN_O_CTL) |= CAN_CTL_TEST ;
       //HWREG(CAN0_BASE + CAN_O_TST) |= CAN_TST_LBACK ;

       CANIntEnable( CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS) ;
       IntEnable( INT_CAN0 ) ;

       CANEnable( CAN0_BASE ) ;

}



void init_high_can( void )
{


     //For JTA1043T configuration on CAN1 port
     SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOA ) ;

     GPIOPinConfigure( GPIO_PA0_CAN1RX ) ;
     GPIOPinConfigure( GPIO_PA1_CAN1TX ) ;

     GPIOPinTypeCAN( GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1) ;

     //PA2 work as CAN_ERR_N
     GPIOPinTypeGPIOInput( GPIO_PORTA_BASE, GPIO_PIN_2) ;

     //PA3 work as CAN_EN
     GPIOPinTypeGPIOOutput( GPIO_PORTA_BASE, GPIO_PIN_3) ;
     GPIOPinTypeGPIOOutput( GPIO_PORTA_BASE, GPIO_PIN_4) ;

     //Enable TJA1043T U3004 part
     GPIOPinWrite( GPIO_PORTA_BASE, GPIO_PIN_3 | GPIO_PIN_4, GPIO_PIN_3 | GPIO_PIN_4) ;

     //Enable CAN0 port
     SysCtlPeripheralEnable( SYSCTL_PERIPH_CAN1 ) ;
     CANInit( CAN1_BASE ) ;
     CANBitRateSet( CAN1_BASE, SysCtlClockGet(), 250000) ;

     //HWREG(CAN1_BASE + CAN_O_CTL) |= CAN_CTL_TEST ;
     //HWREG(CAN1_BASE + CAN_O_TST) |= CAN_TST_LBACK ;

     CANIntEnable( CAN1_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS) ;
     IntEnable( INT_CAN1 ) ;
     CANEnable( CAN1_BASE ) ;

}




