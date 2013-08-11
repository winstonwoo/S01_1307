//*****************************************************************************

//*****************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <stddef.h>
#include <string.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/i2c.h"
#include "driverlib/rom.h"
#include "driverlib/debug.h"
#include "driverlib/rom_map.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/pin_map.h"
#include "utils/uartstdio.h"
#include "utils/ustdlib.h"
#include "utils/cmdline.h"



#define ID_I2C_ADDR                0x50


static bool
WaitI2CFinished(void)
{
    //
    // Wait until the current byte has been transferred.
    //
    while(ROM_I2CMasterIntStatus(I2C4_BASE, false) == 0)
    {
    }

    if(I2CMasterErr(I2C4_BASE) != I2C_MASTER_ERR_NONE)
    {
        ROM_I2CMasterIntClear(I2C4_BASE);
        return(false);
    }

    //
    // Clear any interrupts set.
    //
    while(ROM_I2CMasterIntStatus(I2C4_BASE, false))
    {
        ROM_I2CMasterIntClear(I2C4_BASE);
    }

    return(true);

}

//*****************************************************************************
//
//
//
// \param pucData points to storage for the data read from the EEPROM.
// \param ulOffset is the EEPROM address of the first byte to read.
// \param ulCount is the number of bytes of data to read from the EEPROM.
//
//
// \return Returns \b true on success of \b false on failure.
//
//*****************************************************************************
static bool
EEPROMReadPolled(unsigned char *pucData, unsigned long ulOffset,
                 unsigned long ulCount)
{
    unsigned long ulToRead;

    //
    // Clear any previously signalled interrupts.
    //
    ROM_I2CMasterIntClear(I2C4_BASE);

    //
    // Start with a dummy write to get the address set in the EEPROM.
    //
    ROM_I2CMasterSlaveAddrSet(I2C4_BASE, ID_I2C_ADDR, false);

    //
    // Place the address to be written in the data register.
    //
    ROM_I2CMasterDataPut(I2C4_BASE, 0x0);

    //
    // Perform a single send, writing the address as the only byte.
    //
    ROM_I2CMasterControl(I2C4_BASE, I2C_MASTER_CMD_BURST_SEND_START);

    //
    // Wait until the current byte has been transferred.
    //
    if(!WaitI2CFinished())
    {
        return(false);
    }

    //
    // Place the address to be written in the data register.
    //
    ROM_I2CMasterDataPut(I2C4_BASE, ulOffset);

    //
    // Perform a single send, writing the address as the only byte.
    //
    ROM_I2CMasterControl(I2C4_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);

    //
    // Wait until the current byte has been transferred.
    //
    if(!WaitI2CFinished())
    {
        return(false);
    }

    //
    // Put the I2C master into receive mode.
    //
    ROM_I2CMasterSlaveAddrSet(I2C4_BASE, ID_I2C_ADDR, true);

    //
    // Start the receive.
    //
    ROM_I2CMasterControl(I2C4_BASE,
                         ((ulCount > 1) ? I2C_MASTER_CMD_BURST_RECEIVE_START :
                         I2C_MASTER_CMD_SINGLE_RECEIVE));

    //
    // Receive the required number of bytes.
    //
    ulToRead = ulCount;

    while(ulToRead)
    {
        //
        // Wait until the current byte has been read.
        //
        while(ROM_I2CMasterIntStatus(I2C4_BASE, false) == 0)
        {
        }

        //
        // Clear pending interrupt notification.
        //
        ROM_I2CMasterIntClear(I2C4_BASE);

        //
        // Read the received character.
        //
        *pucData++ = ROM_I2CMasterDataGet(I2C4_BASE);
        ulToRead--;

        //
        // Set up for the next byte if any more remain.
        //
        if(ulToRead)
        {
            ROM_I2CMasterControl(I2C4_BASE,
                                 ((ulToRead == 1) ?
                                  I2C_MASTER_CMD_BURST_RECEIVE_FINISH :
                                  I2C_MASTER_CMD_BURST_RECEIVE_CONT));
        }
    }

    //
    // Tell the caller we read the required data.
    //
    return(true);
}

//*****************************************************************************
// \param ucAddr is the EEPROM address to write.
// \param ucData is the data byte to write.
//
// This function writes a single byte to the I2C-attached EEPROM on the
// daughter board.  The location to write is passed in parameter \e ucAddr
// where values 0 to 127 are valid (this is a 128 byte EEPROM).
//
// This is not used in this particular application but is included for
// completeness.
//
// \return Returns \b true on success of \b false on failure.
//
//*****************************************************************************
static bool
EEPROMWritePolled(unsigned char ucAddr, unsigned char ucData)
{

    //
    // Start with a dummy write to get the address set in the EEPROM.
    //
    ROM_I2CMasterSlaveAddrSet(I2C4_BASE, ID_I2C_ADDR, false);

    //
    // Place the address to be written in the data register.
    //
    ROM_I2CMasterDataPut(I2C4_BASE, 0x0);

    //
    // Start a burst send, sending the device address as the first byte.
    //
    ROM_I2CMasterControl(I2C4_BASE, I2C_MASTER_CMD_BURST_SEND_START);

    //
    // Wait until the current byte has been transferred.
    //
    if(!WaitI2CFinished())
    {
        return(false);
    }

    //
    // Place the address to be written in the data register.
    //
    ROM_I2CMasterDataPut(I2C4_BASE, ucAddr);

    //
    // Start a burst send, sending the device address as the first byte.
    //
    ROM_I2CMasterControl(I2C4_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);

    //
    // Wait until the current byte has been transferred.
    //
    if(!WaitI2CFinished())
    {
        return(false);
    }


    //
    // Write the value to be written to the flash.
    //
    ROM_I2CMasterDataPut(I2C4_BASE, ucData);

    //
    // Send the data byte.
    //
    ROM_I2CMasterControl(I2C4_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);

    //
    // Wait until the current byte has been transferred.
    //
    if(!WaitI2CFinished())
    {
        return(false);
    }

    //
    // Delay 5mS to allow the write to complete.  We should really poll the
    // device waiting for an ACK but this is easier (and this code is only
    // for testcase use so this should be safe).
    //
    SysCtlDelay(ROM_SysCtlClockGet() / (200 * 3));

    //
    // Tell the caller we wrote the required data.
    //
    return(true);

}

#if 0
void test(void)
{
    //
    // Write the structure to flash, one byte at a time.
    //
    for(ulIndex = 0; ulIndex < ulLength; ulIndex++)
    {
        bRetcode = EEPROMWritePolled((unsigned char)ulIndex,
                                     pucBuffer[ulIndex]);
        if(!bRetcode)
        {
            //
            // There was an error - abort the operation.
            //
            UARTprintf("Error writing ID block byte %d!\n", ulIndex);
            return(COMMAND_OK);
        }
    }
}

#endif


//*****************************************************************************
//
// Main application entry function.
//
//*****************************************************************************
int test_fram(void)
{
    int nStatus;
    unsigned char ucIndex ;
    unsigned char ucStore[20] ;



    bool bRetcode;

   SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG) ;

   SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C4) ;
   SysCtlDelay(1);
   ROM_I2CMasterEnable(I2C4_BASE);
   SysCtlDelay(1);
   ROM_SysCtlPeripheralReset(SYSCTL_PERIPH_I2C4);

   GPIOPinConfigure( GPIO_PG2_I2C4SCL ) ;
   GPIOPinConfigure( GPIO_PG3_I2C4SDA ) ;

   GPIOPinTypeI2C(GPIO_PORTG_BASE, GPIO_PIN_3) ;
   GPIOPinTypeI2CSCL(GPIO_PORTG_BASE, GPIO_PIN_2) ;

   I2CMasterInitExpClk(I2C4_BASE, SysCtlClockGet(), true);

   for(;;)
   {
   //
   // Read the ID information from the I2C EEPROM.
   //
   for(ucIndex=0; ucIndex<20; ucIndex++)
   EEPROMWritePolled(ucIndex, ucIndex) ;
   memset(ucStore, 0x0, sizeof(ucStore)) ;
   EEPROMReadPolled((unsigned char *)ucStore, 0,
                               sizeof(ucStore));
   }


    //
    //
    // Fall into the command line processing loop.
    //

}