//*****************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_uart.h"
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "driverlib/can.h"
#include "driverlib/interrupt.h"
#include "driverlib/uart.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "utils/uartstdio.h"

//*****************************************************************************

void init_gpio()
{

     //Add 5V5_EN function to enable 5V5_OUT for CAN trancever with H4 pin
     ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH) ;
     ROM_GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_2) ;
     ROM_GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_2, GPIO_PIN_2) ;

}

void set_PE6_INT()
{
     //PE6 work as interrupt, Low lever trigger, for CAN2
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE) ;
     GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_6) ;
     //GPIOIntTypeSet(GPIO_PORTE_BASE, GPIO_PIN_6, GPIO_LOW_LEVEL) ;// GPIO_FALLING_EDGE
     GPIOIntTypeSet(GPIO_PORTE_BASE, GPIO_PIN_6, GPIO_FALLING_EDGE) ;
     GPIOIntEnable(GPIO_PORTE_BASE, GPIO_PIN_6) ;
     IntEnable(INT_GPIOE) ;
     ROM_IntPrioritySet(INT_GPIOE, 0x00);
}

void cfg_interrupt()
{
     // Enable processor interrupts.
     //
     ROM_IntMasterEnable();
}


void init_uart()
{

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
     HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
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

     UARTStdioConfig(2, 115200, SysCtlClockGet()) ;

     // Finally, clear the commit register and the lock to prevent
     // the pin configuration from being changed accidentally later.
     // Note that the lock is closed whenever we write to the GPIO_O_CR
     // register so we need to reopen it here.
     //
     HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
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

}



