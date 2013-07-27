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



Void hwi_UART0_fxn(UArg arg)
{

}


Void hwi_UART1_fxn(UArg arg)
{

}


Void hwi_UART2_fxn(UArg arg)
{

}


Void hwi_UART3_fxn(UArg arg)
{

}


Void hwi_I2C1_fxn(UArg arg)
{

}

Void hwi_SPI0_fxn(UArg arg)
{

}


Void hwi_SPI1_fxn(UArg arg)
{

}


Void hwi_SPI2_fxn(UArg arg)
{

}


Void hwi_CAN0_fxn(UArg arg)
{

}


Void hwi_CAN1_fxn(UArg arg)
{

}


Void hwi_GPIOBoot_fxn(UArg arg)
{

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
Void tsk_bootloader_fxn(UArg arg0, UArg arg1)
{

}

Void tsk_diagnosis_fxn(UArg arg0, UArg arg1)
{

}

Void tsk_GPRS_fxn(UArg arg0, UArg arg1)
{

}

Void tsk_GPS_fxn(UArg arg0, UArg arg1)
{

}


Void tsk_battery_fxn(UArg arg0, UArg arg1)
{

}

Void tsk_FS_fxn(UArg arg0, UArg arg1)
{

}

Void tsk_CAN3_fxn(UArg arg0, UArg arg1)
{

}

Void tsk_CAN4_fxn(UArg arg0, UArg arg1)
{

}

Void tsk_CAN2_fxn(UArg arg0, UArg arg1)
{

}

Void tsk_CAN1_fxn(UArg arg0, UArg arg1)
{

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
