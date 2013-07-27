/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-z44
 */

#include <xdc/std.h>

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle hwi_UART0_handle;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle swi_UART0_handle;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle tsk_GPRS_handle;

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle hwi_UART1_handle;

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle hwi_UART2_handle;

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle hwi_UART3_handle;

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle hwi_I2C1_handle;

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle hwi_SPI0_handle;

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle hwi_SPI1_handle;

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle hwi_SPI2_handle;

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle hwi_CAN0_handle;

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle hwi_CAN1_handle;

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle hwi_GPIOBoot_handle;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle swi_UART1_handle;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle swi_UART2_handle;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle swi_UART3_handle;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle swi_I2C1_handle;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle swi_SPI0_handle;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle swi_SPI1_handle;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle swi_SPI2_handle;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle swi_CAN0_handle;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle swi_CAN1_handle;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle swi_GPIOBoot_handle;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle tsk_bootloader_handle;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle tsk_diagnosis_handle;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle tsk_GPS_handle;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle tsk_battery_hanlde;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle tsk_FS_handle;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle tsk_CAN3_handle;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle tsk_CAN4_handle;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle tsk_CAN1_handle;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle tsk_CAN2_handle;

extern int xdc_runtime_Startup__EXECFXN__C;

extern int xdc_runtime_Startup__RESETFXN__C;

#ifndef ti_sysbios_knl_Task__include
#ifndef __nested__
#define __nested__
#include <ti/sysbios/knl/Task.h>
#undef __nested__
#else
#include <ti/sysbios/knl/Task.h>
#endif
#endif

extern ti_sysbios_knl_Task_Struct TSK_idle;

