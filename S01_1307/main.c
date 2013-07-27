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





Void hwi_UART0_fxn(UArg arg)
{
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
		System_printf("tsk_manage_fxn \n") ;
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
		System_printf("tsk_CAN3_fxn \n") ;
		Task_sleep(3) ;
	}
}

Void tsk_CAN4_fxn(UArg arg0, UArg arg1)
{
	for(;;)
	{
		System_printf("tsk_CAN4_fxn \n") ;
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

/*
 *  ======== main ========
 */
Void main()
{ 
    Task_Handle task;
    Error_Block eb;

    System_printf("enter main()\n");

    Error_init(&eb);
    task = Task_create(taskFxn, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    BIOS_start();     /* enable interrupts and start SYS/BIOS */
}
