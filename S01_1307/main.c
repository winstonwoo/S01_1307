/*
 *  ======== main.c ========
 */

#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Mailbox.h>

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_can.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/rom.h"
#include "driverlib/timer.h"
#include "driverlib/can.h"
#include "uartstdio.h"



extern Swi_Handle swi_UART7_handle ;
extern Swi_Handle swi_UART2_handle ;
extern Swi_Handle swi_UART3_handle ;
extern Swi_Handle swi_I2C1_handle ;
extern Swi_Handle swi_SPI0_handle ;
extern Swi_Handle swi_SPI1_handle ;
extern Swi_Handle swi_SPI2_handle ;
extern Swi_Handle swi_CAN0_handle ;
extern Swi_Handle swi_CAN1_handle ;
extern Swi_Handle swi_GPIOBoot_handle ;

extern Mailbox_Handle Mb_uart2_handle ;

volatile unsigned long g_ulMsgCount = 0;

//*****************************************************************************
//
// A flag to indicate that some transmission error occurred.
//
//*****************************************************************************
volatile unsigned long g_bErrFlag = 0;


void UARTSend(const unsigned char *pucBuffer, unsigned long ulCount) ;



Void hwi_UART7_fxn(UArg arg)
{
     unsigned long ulStatus;
     unsigned char ucMsg[8] ;
     int i = 0 ;

     //
     // Get the interrrupt status.
     //

     ulStatus = ROM_UARTIntStatus(UART7_BASE, true);

     //
     // Clear the asserted interrupts.
     //

     ROM_UARTIntClear(UART7_BASE, ulStatus);


     Swi_post(swi_UART7_handle) ;

}



Void hwi_UART2_fxn(UArg arg)
{
     unsigned long ulStatus;
     unsigned char ucMsg[8] ;
     int i = 0 ;

     //
     // Get the interrrupt status.
     //

     ulStatus = ROM_UARTIntStatus(UART2_BASE, true);

     //
     // Clear the asserted interrupts.
     //

     ROM_UARTIntClear(UART2_BASE, ulStatus);

     memset(ucMsg, 0x0, sizeof(ucMsg)) ;
     //
     // Loop while there are characters in the receive FIFO.
     //
     while(ROM_UARTCharsAvail(UART2_BASE))
     {
          //
          // Read the next character from the UART and write it back to the UART.
          //
          // ROM_UARTCharPutNonBlocking(UART0_BASE,
          //                          ROM_UARTCharGetNonBlocking(UART0_BASE));
          ucMsg[i++] = ROM_UARTCharGetNonBlocking(UART2_BASE) ;
          if (i>=8) 	break ;  //If the amount of characters is big than 20;

     }

     Mailbox_post(Mb_uart2_handle, ucMsg, BIOS_NO_WAIT) ;


     Swi_post(swi_UART2_handle) ;
}


Void hwi_UART3_fxn(UArg arg)
{
     unsigned long ulStatus;

     //
     // Get the interrrupt status.
     //

     ulStatus = ROM_UARTIntStatus(UART3_BASE, true);

     //
     // Clear the asserted interrupts.
     //

     ROM_UARTIntClear(UART3_BASE, ulStatus);


     Swi_post(swi_UART3_handle) ;
}


Void hwi_I2C1_fxn(UArg arg)
{
	Swi_post(swi_I2C1_handle) ;
}

Void hwi_SPI0_fxn(UArg arg)
{
	Swi_post(swi_SPI0_handle) ;
}


Void hwi_SPI1_fxn(UArg arg)
{
	Swi_post(swi_SPI1_handle) ;
}


Void hwi_SPI2_fxn(UArg arg)
{
	Swi_post(swi_SPI2_handle) ;
}


Void hwi_CAN0_fxn(UArg arg)
{
#if 0
	unsigned long ulStatus;

		    //
		    // Read the CAN interrupt status to find the cause of the interrupt
		    //
		    ulStatus = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE);

		    //
		    // If the cause is a controller status interrupt, then get the status
		    //
		    if(ulStatus == CAN_INT_INTID_STATUS)
		    {
		        //
		        // Read the controller status.  This will return a field of status
		        // error bits that can indicate various errors.  Error processing
		        // is not done in this example for simplicity.  Refer to the
		        // API documentation for details about the error status bits.
		        // The act of reading this status will clear the interrupt.  If the
		        // CAN peripheral is not connected to a CAN bus with other CAN devices
		        // present, then errors will occur and will be indicated in the
		        // controller status.
		        //
		        ulStatus = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);

		        //
		        // Set a flag to indicate some errors may have occurred.
		        //
		        //g_bErrFlag = 1;
		    }

		    //
		    // Check if the cause is message object 1, which is used for sending
		    // message 1.
		    //
		    else if(ulStatus == 1)
		    {
		        //
		        // Getting to this point means that the TX interrupt occurred on
		        // message object 1, and the message TX is complete.  Clear the
		        // message object interrupt.
		        //
		        CANIntClear(CAN0_BASE, 1);

		        //
		        // Increment a counter to keep track of how many messages have been
		        // sent.  In a real application this could be used to set flags to
		        // indicate when a message is sent.
		        //
		        //g_ulMsg1Count++;

		        //
		        // Since the message was sent, clear any error flags.
		        //
		        //g_bErrFlag = 0;
		    }

		    //
		    // Check if the cause is message object 2, which is used for sending
		    // message 2.
		    //
		    else if(ulStatus == 2)
		    {
		        //
		        // Getting to this point means that the TX interrupt occurred on
		        // message object 2, and the message TX is complete.  Clear the
		        // message object interrupt.
		        //
		        CANIntClear(CAN0_BASE, 2);

		        //
		        // Increment a counter to keep track of how many messages have been
		        // sent.  In a real application this could be used to set flags to
		        // indicate when a message is sent.
		        //
		       // g_ulMsg2Count++;

		        //
		        // Since the message was sent, clear any error flags.
		        //
		        //g_bErrFlag = 0;
		    }

		    //
		    // Check if the cause is message object 3, which is used for sending
		    // messages 3 and 4.
		    //
		    else if(ulStatus == 3)
		    {
		        //
		        // Getting to this point means that the TX interrupt occurred on
		        // message object , and a message TX is complete.  Clear the
		        // message object interrupt.
		        //
		        CANIntClear(CAN0_BASE, 3);

		        //
		        // Increment a counter to keep track of how many messages have been
		        // sent.  In a real application this could be used to set flags to
		        // indicate when a message is sent.
		        //
		        //g_ulMsg3Count++;

		        //
		        // Set the flag indicating that a message was sent using message
		        // object 3.  The program main loop uses this to know when to send
		        // another message using message object 3.
		        //g_bMsgObj3Sent = 1;

		        //
		        // Since the message was sent, clear any error flags.
		        //
		        //g_bErrFlag = 0;
		    }

		    //
		    // Otherwise, something unexpected caused the interrupt.  This should
		    // never happen.
		    //
		    else
		    {
		        //
		        // Spurious interrupt handling can go here.
		        //
		    }
		    CANIntClear(CAN0_BASE, ulStatus);
		    Swi_post(swi_CAN0_handle) ;
#else

		    unsigned long ulStatus;

		    //
		    // Read the CAN interrupt status to find the cause of the interrupt
		    //
		    ulStatus = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE);

		    //
		    // If the cause is a controller status interrupt, then get the status
		    //
		    if(ulStatus == CAN_INT_INTID_STATUS)
		    {
		        //
		        // Read the controller status.  This will return a field of status
		        // error bits that can indicate various errors.  Error processing
		        // is not done in this example for simplicity.  Refer to the
		        // API documentation for details about the error status bits.
		        // The act of reading this status will clear the interrupt.  If the
		        // CAN peripheral is not connected to a CAN bus with other CAN devices
		        // present, then errors will occur and will be indicated in the
		        // controller status.
		        //
		        ulStatus = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);

		        //
		        // Set a flag to indicate some errors may have occurred.
		        //
		        g_bErrFlag = 1;
		    }

		    //
		    // Check if the cause is message object 1, which what we are using for
		    // sending messages.
		    //
		    else if(ulStatus == 1)
		    {
		        //
		        // Getting to this point means that the TX interrupt occurred on
		        // message object 1, and the message TX is complete.  Clear the
		        // message object interrupt.
		        //
		        CANIntClear(CAN0_BASE, 1);

		        //
		        // Increment a counter to keep track of how many messages have been
		        // sent.  In a real application this could be used to set flags to
		        // indicate when a message is sent.
		        //
		        g_ulMsgCount++;

		        //
		        // Since the message was sent, clear any error flags.
		        //
		        g_bErrFlag = 0;
		    }

		    //
		    // Otherwise, something unexpected caused the interrupt.  This should
		    // never happen.
		    //
		    else
		    {
		        //
		        // Spurious interrupt handling can go here.
		        //
		    }
#endif
}


Void hwi_CAN1_fxn(UArg arg)
{
	  unsigned long ulStatus;

	    //
	    // Read the CAN interrupt status to find the cause of the interrupt
	    //
	    ulStatus = CANIntStatus(CAN1_BASE, CAN_INT_STS_CAUSE);


	    //
	    // If the cause is a controller status interrupt, then get the status
	    //
	    if(ulStatus == CAN_INT_INTID_STATUS)
	    {
	        //
	        // Read the controller status.  This will return a field of status
	        // error bits that can indicate various errors.  Error processing
	        // is not done in this example for simplicity.  Refer to the
	        // API documentation for details about the error status bits.
	        // The act of reading this status will clear the interrupt.  If the
	        // CAN peripheral is not connected to a CAN bus with other CAN devices
	        // present, then errors will occur and will be indicated in the
	        // controller status.
	        //
	        ulStatus = CANStatusGet(CAN1_BASE, CAN_STS_CONTROL);

	        //
	        // Set a flag to indicate some errors may have occurred.
	        //
	        //g_bErrFlag = 1;
	    }

	    //
	    // Check if the cause is message object 1, which is used for sending
	    // message 1.
	    //
	    else if(ulStatus == 1)
	    {
	        //
	        // Getting to this point means that the TX interrupt occurred on
	        // message object 1, and the message TX is complete.  Clear the
	        // message object interrupt.
	        //
	        CANIntClear(CAN1_BASE, 1);

	        //
	        // Increment a counter to keep track of how many messages have been
	        // sent.  In a real application this could be used to set flags to
	        // indicate when a message is sent.
	        //
	        //g_ulMsg1Count++;

	        //
	        // Since the message was sent, clear any error flags.
	        //
	        //g_bErrFlag = 0;
	    }

	    //
	    // Check if the cause is message object 2, which is used for sending
	    // message 2.
	    //
	    else if(ulStatus == 2)
	    {
	        //
	        // Getting to this point means that the TX interrupt occurred on
	        // message object 2, and the message TX is complete.  Clear the
	        // message object interrupt.
	        //
	        CANIntClear(CAN1_BASE, 2);

	        //
	        // Increment a counter to keep track of how many messages have been
	        // sent.  In a real application this could be used to set flags to
	        // indicate when a message is sent.
	        //
	       // g_ulMsg2Count++;

	        //
	        // Since the message was sent, clear any error flags.
	        //
	        //g_bErrFlag = 0;
	    }

	    //
	    // Check if the cause is message object 3, which is used for sending
	    // messages 3 and 4.
	    //
	    else if(ulStatus == 3)
	    {
	        //
	        // Getting to this point means that the TX interrupt occurred on
	        // message object , and a message TX is complete.  Clear the
	        // message object interrupt.
	        //
	        CANIntClear(CAN1_BASE, 3);

	        //
	        // Increment a counter to keep track of how many messages have been
	        // sent.  In a real application this could be used to set flags to
	        // indicate when a message is sent.
	        //
	        //g_ulMsg3Count++;

	        //
	        // Set the flag indicating that a message was sent using message
	        // object 3.  The program main loop uses this to know when to send
	        // another message using message object 3.
	        //g_bMsgObj3Sent = 1;

	        //
	        // Since the message was sent, clear any error flags.
	        //
	        //g_bErrFlag = 0;
	    }

	    //
	    // Otherwise, something unexpected caused the interrupt.  This should
	    // never happen.
	    //
	    else
	    {
	        //
	        // Spurious interrupt handling can go here.
	        //
	    }

	    CANIntClear(CAN0_BASE, ulStatus);

	//Swi_post(swi_CAN1_handle) ;
}


Void hwi_GPIOBoot_fxn(UArg arg)
{
	long lIntSts ;

	//store the interrupt flag into lIntSts
	lIntSts = ROM_GPIOPinIntStatus(GPIO_PORTM_BASE, false) ;

	//
	// Clear the GPIO interrupt.
	//
	ROM_GPIOPinIntClear(GPIO_PORTM_BASE, GPIO_PIN_4);



	Swi_post(swi_GPIOBoot_handle) ;
}


//*****************************************************************************
//
// This is the handler for this SysTick interrupt.  FatFs requires a timer tick
// every 10 ms for internal timing purposes.
//
//*****************************************************************************
void
hwi_TIMER2_fxn(void)
{
    //
    // Clear the timer interrupt.
    //
	ROM_TimerIntClear(TIMER2_BASE, TIMER_TIMA_TIMEOUT);


	// ROM_IntMasterDisable();
	//
	// Call the FatFs tick timer.
	//
    //disk_timerproc();

     // ROM_IntMasterEnable();

}


//SWI section
Void swi_UART7_fxn(UArg arg0, UArg arg1)
{


}


Void swi_UART2_fxn(UArg arg0, UArg arg1)
{


}

Void swi_UART3_fxn(UArg arg0, UArg arg1)
{


}

Void swi_I2C1_fxn(UArg arg0, UArg arg1)
{


}

Void swi_SPI0_fxn(UArg arg0, UArg arg1)
{


}

Void swi_SPI1_fxn(UArg arg0, UArg arg1)
{


}

Void swi_SPI2_fxn(UArg arg0, UArg arg1)
{


}

Void swi_CAN0_fxn(UArg arg0, UArg arg1)
{


}

Void swi_CAN1_fxn(UArg arg0, UArg arg1)
{


}

Void swi_GPIOBoot_fxn(UArg arg0, UArg arg1)
{


}

//Task section
Void tsk_manage_fxn(UArg arg0, UArg arg1)
{
	unsigned char ucMsg[20] ;
	for(;;)
	{
		// UARTSend((unsigned char *)"tsk_manage_fxn \n ", 20);
		//Mailbox_pend(Mb_uart2_handle, ucMsg, BIOS_WAIT_FOREVER) ;
		//UARTprintf("uart output!!!\n") ;
		Task_sleep(1000) ;
	}

}

Void tsk_bootloader_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		System_printf("tsk_bootloader_fxn \n") ;
		Task_sleep(2000) ;
	}

}

Void tsk_diagnosis_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		UARTprintf("tsk_diagnosis_fxn \n") ;
		Task_sleep(3000) ;
	}

}

Void tsk_GPRS_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		//UARTprintf("UARTprintf tsk_GPRS_fxn \n") ;
	    System_printf("tsk_GPRS_fxn \n") ;
		Task_sleep(3000) ;
	}

}

Void tsk_GPS_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		System_printf("tsk_GPS_fxn \n") ;
		UARTSend((unsigned char *)"tsk_GPS_fxn \n", 12);
		Task_sleep(3000) ;
	}

}


Void tsk_battery_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		System_printf("tsk_battery_fxn \n") ;
		Task_sleep(3000) ;
	}

}

Void tsk_FS_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		System_printf("tsk_FS_fxn \n") ;
		sdcard_main() ;
		Task_sleep(3000) ;
	}

}

Void tsk_CAN3_fxn(UArg arg0, UArg arg1)
{

	for(;;)
	{
		 //UARTSend((unsigned char *)"tsk_manage_fxn \n ", 20);
		Task_sleep(3000) ;
	}
}

Void tsk_CAN4_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		// UARTSend((unsigned char *)"tsk_manage_fxn \n ", 20);
		Task_sleep(3000) ;
	}

}

Void tsk_CAN2_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		//UARTprintf("tsk_CAN2_fxn \n") ;
		Task_sleep(3000) ;
	}

}

Void tsk_CAN1_fxn(UArg arg0, UArg arg1)
{

   UARTprintf( " tsk_can entered \n" ) ;
   tsk_can() ;
}


/*
 *  ======== taskFxn ========
 */
Void taskFxn(UArg a0, UArg a1)
{
  //  UARTprintf("enter taskFxn()\n");

    Task_sleep(1000);

  //  UARTprintf("exit taskFxn()\n");
}

/**/
Void init_gpio()
{
#if 0  //There isn't the bootloader tringer at eastsoft board
	  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);

	  ROM_GPIOPinTypeGPIOInput(GPIO_PORTM_BASE, GPIO_PIN_4) ;
	  ROM_GPIOPadConfigSet(GPIO_PORTM_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU) ;
	  ROM_GPIOIntTypeSet(GPIO_PORTM_BASE, GPIO_PIN_4, GPIO_FALLING_EDGE) ;
#endif

	  //Add 5V5_EN function to enable 5V5_OUT for CAN trancever with H4 pin
	  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH) ;
	  ROM_GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_2) ;
	  ROM_GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_2, GPIO_PIN_2) ;

}

/**/
Void init_uart()
{
#if 1
    	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    	//UART2 initialization with 115200, 8, N, 1
        //
        // Enable the peripherals used by this example.
        //
//
		// Change PD7 into hardware (NMI) pins.  First open the
		// lock and select the bits we want to modify in the GPIO commit
		// register.
		//
		HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY_DD;
		HWREG(GPIO_PORTD_BASE + GPIO_O_CR) = 0xC0;

		//
		// Now modify the configuration of the pins that we unlocked.
		//
	        //
        // Set GPIO D6 and D7 as UART2 pins.
        GPIOPinConfigure( GPIO_PD6_U2RX ) ;
        GPIOPinConfigure( GPIO_PD7_U2TX ) ;
        GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);

        ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);

        //

        /*
        ROM_UARTConfigSetExpClk(UART2_BASE, ROM_SysCtlClockGet(), 115200,
                                (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                                 UART_CONFIG_PAR_NONE));
                                 */

        UARTStdioInit(2) ;

		// Finally, clear the commit register and the lock to prevent
		// the pin configuration from being changed accidentally later.
		// Note that the lock is closed whenever we write to the GPIO_O_CR
		// register so we need to reopen it here.
		//
		HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY_DD;
		HWREG(GPIO_PORTD_BASE + GPIO_O_CR) = 0x00;
		HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = 0;

        //
        // Enable the UART interrupt.
        //
        ROM_IntEnable(INT_UART2);
        ROM_UARTIntEnable(UART2_BASE, UART_INT_RX | UART_INT_RT);



     //UART3 initialization with 115200, 8, N, 1
         //
         // Enable the peripherals used by this example.
         //
         ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
         ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART3);

         //
         // Set GPIO D6 and D7 as UART2 pins.
         GPIOPinConfigure( GPIO_PC6_U3RX ) ;
         GPIOPinConfigure( GPIO_PC7_U3TX ) ;
         GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_6 | GPIO_PIN_7);

         //
         ROM_UARTConfigSetExpClk(UART3_BASE, ROM_SysCtlClockGet(), 115200,
                                 (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                                  UART_CONFIG_PAR_NONE));

         //
         // Enable the UART interrupt.
         //
         ROM_IntEnable(INT_UART3);
         ROM_UARTIntEnable(UART3_BASE, UART_INT_RX | UART_INT_RT);


         //UART2 initialization with 115200, 8, N, 1
		 //
		 // Enable the peripherals used by this example.
		 //
		 ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
		 ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7);

		 //
		 // Set GPIO D6 and D7 as UART2 pins.
		 GPIOPinConfigure( GPIO_PE0_U7RX ) ;
		 GPIOPinConfigure( GPIO_PE1_U7TX ) ;
		 GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_0 | GPIO_PIN_1);

		 //
		 ROM_UARTConfigSetExpClk(UART7_BASE, ROM_SysCtlClockGet(), 115200,
								 (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
								  UART_CONFIG_PAR_NONE));

		 //
		 // Enable the UART interrupt.
		 //
		 ROM_IntEnable(INT_UART7);
		 ROM_UARTIntEnable(UART7_BASE, UART_INT_RX | UART_INT_RT);



#endif

}

Void cfg_interrupt()
{


     // Enable processor interrupts.
     //
     ROM_IntMasterEnable();

#if 0           //Delete this GPIO trigger function
		//Enable GPIOM4 for boot trigger
     ROM_GPIOPinIntEnable(GPIO_PORTM_BASE, GPIO_PIN_4) ;
#endif

}

Void init_sdcard()
{
#if 1
     //Adopt PH4,5,6,7 for SSI2 as SDCARD signals

     ROM_SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOH ) ;

     ROM_GPIOPinConfigure(GPIO_PH4_SSI2CLK) ;
     ROM_GPIOPinConfigure(GPIO_PH5_SSI2FSS) ;
     ROM_GPIOPinConfigure(GPIO_PH6_SSI2RX) ;
     ROM_GPIOPinConfigure(GPIO_PH7_SSI2TX) ;

     ROM_GPIOPinTypeSSI( GPIO_PORTH_BASE, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7  ) ;

     ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI2);
#endif     

     ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
     //
     // Configure the two 32-bit periodic timers.
     //
     ROM_TimerConfigure(TIMER2_BASE, TIMER_CFG_PERIODIC);
     ROM_TimerLoadSet(TIMER2_BASE, TIMER_A, ROM_SysCtlClockGet()/100);


     //
     // Setup the interrupts for the timer timeouts.
     //
     ROM_IntEnable(INT_TIMER2A);
     ROM_TimerIntEnable(TIMER2_BASE, TIMER_TIMA_TIMEOUT);

     //
     // Enable the timers.
     //
     ROM_TimerEnable(TIMER2_BASE, TIMER_A);
	
}

Void init_spi()
{

}

Void init_sys()
{
	//GPIOM initialization for bootloader
	init_gpio() ;

	//UART0 initialization
	init_uart() ;


	//UART1 initialization
/*
	init_sdcard() ;

	//CAN initialization
	init_can() ;


	//SPI initialization for CAN2 ,3
	init_spi() ;
*/
    //interrupt setting for system
	cfg_interrupt() ;

}


//*****************************************************************************
//
// Send a string to the UART.
//
//*****************************************************************************
void
UARTSend(const unsigned char *pucBuffer, unsigned long ulCount)
{
    //
    // Loop while there are more characters to send.
    //
    while(ulCount--)
    {
        //
        // Write the next character to the UART.
        //
        ROM_UARTCharPutNonBlocking(UART7_BASE, *pucBuffer++);
    }
}


int
sub_main(void)
{
    tCANMsgObject sCANMessage;
    unsigned char ucMsgData[4];

    //
    // Set the clocking to run directly from the external crystal/oscillator.
    // TODO: The SYSCTL_XTAL_ value must be changed to match the value of the
    // crystal on your board.
    //
/*
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_16MHZ);
*/
    //
    // Set up the serial console to use for displaying messages.  This is
    // just for this example program and is not needed for CAN operation.
    //
   // InitConsole();

    //
    // For this example CAN0 is used with RX and TX pins on port D0 and D1.
    // The actual port and pins used may be different on your part, consult
    // the data sheet for more information.
    // GPIO port D needs to be enabled so these pins can be used.
    // TODO: change this to whichever GPIO port you are using
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);

    //
    // Configure the GPIO pin muxing to select CAN0 functions for these pins.
    // This step selects which alternate function is available for these pins.
    // This is necessary if your part supports GPIO pin function muxing.
    // Consult the data sheet to see which functions are allocated per pin.
    // TODO: change this to select the port/pin you are using
    //
    GPIOPinConfigure(GPIO_PE4_CAN0RX);
    GPIOPinConfigure(GPIO_PE5_CAN0TX);

    //
    // Enable the alternate function on the GPIO pins.  The above step selects
    // which alternate function is available.  This step actually enables the
    // alternate function instead of GPIO for these pins.
    // TODO: change this to match the port/pin you are using
    //
    GPIOPinTypeCAN(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);

    //
    // The GPIO port and pins have been set up for CAN.  The CAN peripheral
    // must be enabled.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);

    //
    // Initialize the CAN controller
    //
    CANInit(CAN0_BASE);

    //
    // Set up the bit rate for the CAN bus.  This function sets up the CAN
    // bus timing for a nominal configuration.  You can achieve more control
    // over the CAN bus timing by using the function CANBitTimingSet() instead
    // of this one, if needed.
    // In this example, the CAN bus is set to 500 kHz.  In the function below,
    // the call to SysCtlClockGet() is used to determine the clock rate that
    // is used for clocking the CAN peripheral.  This can be replaced with a
    // fixed value if you know the value of the system clock, saving the extra
    // function call.  For some parts, the CAN peripheral is clocked by a fixed
    // 8 MHz regardless of the system clock in which case the call to
    // SysCtlClockGet() should be replaced with 8000000.  Consult the data
    // sheet for more information about CAN peripheral clocking.
    //
    CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);

    //
    // Enable interrupts on the CAN peripheral.  This example uses static
    // allocation of interrupt handlers which means the name of the handler
    // is in the vector table of startup code.  If you want to use dynamic
    // allocation of the vector table, then you must also call CANIntRegister()
    // here.
    //
    // CANIntRegister(CAN0_BASE, CANIntHandler); // if using dynamic vectors
    //
    CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);

    //
    // Enable the CAN interrupt on the processor (NVIC).
    //
    IntEnable(INT_CAN0);

    //
    // Enable the CAN for operation.
    //
    CANEnable(CAN0_BASE);

    //
    // Initialize the message object that will be used for sending CAN
    // messages.  The message will be 4 bytes that will contain an incrementing
    // value.  Initially it will be set to 0.
    //
    *(unsigned long *)ucMsgData = 0;
    sCANMessage.ulMsgID = 1;                        // CAN message ID - use 1
    sCANMessage.ulMsgIDMask = 0;                    // no mask needed for TX
    sCANMessage.ulFlags = MSG_OBJ_TX_INT_ENABLE;    // enable interrupt on TX
    sCANMessage.ulMsgLen = sizeof(ucMsgData);       // size of message is 4
    sCANMessage.pucMsgData = ucMsgData;             // ptr to message content

    //
    // Enter loop to send messages.  A new message will be sent once per
    // second.  The 4 bytes of message content will be treated as an unsigned
    // long and incremented by one each time.
    //
    for(;;)
    {
        //
        // Print a message to the console showing the message count and the
        // contents of the message being sent.
        //
        UARTprintf("Sending msg: 0x%02X %02X %02X %02X",
                   ucMsgData[0], ucMsgData[1], ucMsgData[2], ucMsgData[3]);

        //
        // Send the CAN message using object number 1 (not the same thing as
        // CAN ID, which is also 1 in this example).  This function will cause
        // the message to be transmitted right away.
        //
        CANMessageSet(CAN0_BASE, 1, &sCANMessage, MSG_OBJ_TYPE_TX);

        //
        // Now wait 1 second before continuing
        //
        //SimpleDelay();
        SysCtlDelay(SysCtlClockGet()/3) ;

        //
        // Check the error flag to see if errors occurred
        //
        if(g_bErrFlag)
        {
            UARTprintf(" error - cable connected?\n");
        }
        else
        {
            //
            // If no errors then print the count of message sent
            //
            UARTprintf(" total count = %u\n", g_ulMsgCount);
        }

        //
        // Increment the value in the message data.
        //
        (*(unsigned long *)ucMsgData)++;
    }

    //
    // Return no errors
    //
    return(0);
}

/*
 *  ======== main ========
 */
Void main()
{ 
    Task_Handle task;
    Error_Block eb;

    System_printf("enter main()\n");

    Error_init(&eb);


    //System driver initialization
    init_sys() ;

    sub_main() ;

    //
    // Prompt for text to be entered.
    //
    /*
    for( ;; )
    UARTSend((unsigned char *)"Enter text: ", 12);
    */

    task = Task_create(taskFxn, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    BIOS_start();     /* enable interrupts and start SYS/BIOS */
}
