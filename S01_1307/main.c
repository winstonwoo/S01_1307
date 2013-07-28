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

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/rom.h"
#include "grlib/grlib.h"


extern Swi_Handle swi_UART0_handle ;
extern Swi_Handle swi_UART1_handle ;
extern Swi_Handle swi_UART2_handle ;
extern Swi_Handle swi_UART3_handle ;
extern Swi_Handle swi_I2C1_handle ;
extern Swi_Handle swi_SPI0_handle ;
extern Swi_Handle swi_SPI1_handle ;
extern Swi_Handle swi_SPI2_handle ;
extern Swi_Handle swi_CAN0_handle ;
extern Swi_Handle swi_CAN1_handle ;
extern Swi_Handle swi_GPIOBoot_handle ;

void UARTSend(const unsigned char *pucBuffer, unsigned long ulCount) ;



Void hwi_UART0_fxn(UArg arg)
{
	  unsigned long ulStatus;

	    //
	    // Get the interrrupt status.
	    //
	    ulStatus = ROM_UARTIntStatus(UART0_BASE, true);

	    //
	    // Clear the asserted interrupts.
	    //
	    ROM_UARTIntClear(UART0_BASE, ulStatus);

	    //
	    // Loop while there are characters in the receive FIFO.
	    //
	    while(ROM_UARTCharsAvail(UART0_BASE))
	    {
	        //
	        // Read the next character from the UART and write it back to the UART.
	        //
	        ROM_UARTCharPutNonBlocking(UART0_BASE,
	                                   ROM_UARTCharGetNonBlocking(UART0_BASE));
	    }

	    Swi_post(swi_UART0_handle) ;

}


Void hwi_UART1_fxn(UArg arg)
{
	Swi_post(swi_UART1_handle) ;
}


Void hwi_UART2_fxn(UArg arg)
{
	Swi_post(swi_UART2_handle) ;
}


Void hwi_UART3_fxn(UArg arg)
{
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
	Swi_post(swi_CAN0_handle) ;
}


Void hwi_CAN1_fxn(UArg arg)
{
	Swi_post(swi_CAN1_handle) ;
}


Void hwi_GPIOBoot_fxn(UArg arg)
{
	Swi_post(swi_GPIOBoot_handle) ;
}


//SWI section
Void swi_UART0_fxn(UArg arg0, UArg arg1)
{


}

Void swi_UART1_fxn(UArg arg0, UArg arg1)
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
	for(;;)
	{
		 UARTSend((unsigned char *)"tsk_manage_fxn \n ", 20);
		Task_sleep(1) ;
	}

}

Void tsk_bootloader_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		System_printf("tsk_bootloader_fxn \n") ;
		Task_sleep(2) ;
	}

}

Void tsk_diagnosis_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		System_printf("tsk_diagnosis_fxn \n") ;
		Task_sleep(3) ;
	}

}

Void tsk_GPRS_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		System_printf("tsk_GPRS_fxn \n") ;
		Task_sleep(3) ;
	}

}

Void tsk_GPS_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		System_printf("tsk_GPS_fxn \n") ;
		Task_sleep(3) ;
	}

}


Void tsk_battery_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		System_printf("tsk_battery_fxn \n") ;
		Task_sleep(3) ;
	}

}

Void tsk_FS_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		System_printf("tsk_FS_fxn \n") ;
		Task_sleep(3) ;
	}

}

Void tsk_CAN3_fxn(UArg arg0, UArg arg1)
{

	for(;;)
	{
		 UARTSend((unsigned char *)"tsk_manage_fxn \n ", 20);
		Task_sleep(3) ;
	}
}

Void tsk_CAN4_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		 UARTSend((unsigned char *)"tsk_manage_fxn \n ", 20);
		Task_sleep(3) ;
	}

}

Void tsk_CAN2_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		System_printf("tsk_CAN2_fxn \n") ;
		Task_sleep(3) ;
	}

}

Void tsk_CAN1_fxn(UArg arg0, UArg arg1)
{

	for(;;)
	{
		System_printf("tsk_CAN1_fxn \n") ;
		Task_sleep(3) ;
	}

}


/*
 *  ======== taskFxn ========
 */
Void taskFxn(UArg a0, UArg a1)
{
    System_printf("enter taskFxn()\n");

    Task_sleep(10);

    System_printf("exit taskFxn()\n");
}

/**/
Void init_uart()
{
  //UART0 initialization with 115200, 8, N, 1
  //
  // Enable the peripherals used by this example.
  //
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);


	//
	// Set GPIO A0 and A1 as UART pins.
	//
	ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	//
	// Configure the UART for 115,200, 8-N-1 operation.
	//
	ROM_UARTConfigSetExpClk(UART0_BASE, ROM_SysCtlClockGet(), 115200,
							(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
							 UART_CONFIG_PAR_NONE));


	//
	// Enable processor interrupts.
	//
	ROM_IntMasterEnable();
	//
	// Enable the UART interrupt.
	//
	ROM_IntEnable(INT_UART0);
	ROM_UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);

}

Void init_sys()
{
	//UART0 initialization
	init_uart() ;


	//UART1 initialization

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
        ROM_UARTCharPutNonBlocking(UART0_BASE, *pucBuffer++);
    }
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

    //
    // Prompt for text to be entered.
    //
    UARTSend((unsigned char *)"Enter text: ", 12);

    task = Task_create(taskFxn, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    BIOS_start();     /* enable interrupts and start SYS/BIOS */
}
