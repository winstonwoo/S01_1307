//*****************************************************************************

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "driverlib/can.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "utils/uartstdio.h"

#if 0
//*****************************************************************************


void init_can( void )
{
     SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOF ) ;
     GPIOPinTypeCAN( GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN3 ) ;

     SysCtlPeripheralEnable( SYSCTL_PERIPH_CAN0 ) ;
     CANInit( CAN0_BASE ) ;
     CANBitRateSet( CAN0_BASE, SysCtlClockGet(), 250000 ) ;

     CANIntEnable( CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS ) ;
     IntEnable( INT_CAN0 ) ;

     CANEnable( CAN0_BASE )
     

}

void tsk_can( void )
{
     tCANMsgObject sCANMsgObject1 ;
     unsigned char ucCANData1[8] = {1, 2, 3, 4, 5, 6, 7, 8} ;
     unsigned char ucCANData2[5] = { 2, 2, 2, 2, 2 };
     unsigned char ucCANData3[6] = { 3, 3, 3, 3, 3, 3 };
     unsigned char ucCANData4[8] = { 4, 4, 4, 4, 5, 5, 5, 5 };

         
     sCANMsgObject1.ulMsgID = 0x1001 ;
     sCANMsgObject1.ulMsgIDMask = 0 ;
     sCANMsgObject1.ulFlags = MSG_OBJ_TX_INT_ENABLE ;
     sCANMsgObject1.ulMsgLen = sizeof( ucCANData1 ) ;
     sCANMsgObject1.pucMsgData = ucCANData1 ;

      
     sCANMsgObject2.ulMsgID = 0x2001 ;
     sCANMsgObject2.ulMsgIDMask = 0 ;
     sCANMsgObject2.ulFlags = MSG_OBJ_TX_INT_ENABLE ;
     sCANMsgObject2.ulMsgLen = sizeof( ucCANData2 ) ;
     sCANMsgObject2.pucMsgData = ucCANData2 ;


     sCANMsgObject3.ulMsgID = 0x3001 ;
     sCANMsgObject3.ulMsgIDMask = 0 ;
     sCANMsgObject3.ulFlags = MSG_OBJ_TX_INT_ENABLE ;
     sCANMsgObject3.ulMsgLen = sizeof( ucCANData3 ) ;
     sCANMsgObject3.pucMsgData = ucCANData3 ;

     for( ;; )
     {
          CANMessageSet( CAN0_BASE, 1, &sCANMsgObject1, MSG_OBJ_TYPE_TX ) ;
          CANMessageSet( CAN0_BASE, 2, &sCANMsgObject2, MSG_OBJ_TYPE_TX ) ;
          CANMessageSet( CAN0_BASE, 3, &sCANMsgObject3, MSG_OBJ_TYPE_TX ) ;
        //
        // Change the value in the message data for each of the messages.
        //
        (*(unsigned long *)g_ucMsg1)++;
        (*(unsigned long *)g_ucMsg2)++;
        (*(unsigned long *)g_ucMsg3)++;

        task_sleep( 1000 ) ;
     }

}

#endif