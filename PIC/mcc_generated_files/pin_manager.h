/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18LF27K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set PB1 aliases
#define PB1_TRIS                 TRISAbits.TRISA1
#define PB1_LAT                  LATAbits.LATA1
#define PB1_PORT                 PORTAbits.RA1
#define PB1_WPU                  WPUAbits.WPUA1
#define PB1_OD                   ODCONAbits.ODCA1
#define PB1_ANS                  ANSELAbits.ANSELA1
#define PB1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define PB1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define PB1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define PB1_GetValue()           PORTAbits.RA1
#define PB1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define PB1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define PB1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define PB1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define PB1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define PB1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define PB1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define PB1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set PB2 aliases
#define PB2_TRIS                 TRISAbits.TRISA2
#define PB2_LAT                  LATAbits.LATA2
#define PB2_PORT                 PORTAbits.RA2
#define PB2_WPU                  WPUAbits.WPUA2
#define PB2_OD                   ODCONAbits.ODCA2
#define PB2_ANS                  ANSELAbits.ANSELA2
#define PB2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define PB2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define PB2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define PB2_GetValue()           PORTAbits.RA2
#define PB2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define PB2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define PB2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define PB2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define PB2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define PB2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define PB2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define PB2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISAbits.TRISA3
#define LED1_LAT                  LATAbits.LATA3
#define LED1_PORT                 PORTAbits.RA3
#define LED1_WPU                  WPUAbits.WPUA3
#define LED1_OD                   ODCONAbits.ODCA3
#define LED1_ANS                  ANSELAbits.ANSELA3
#define LED1_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LED1_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LED1_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LED1_GetValue()           PORTAbits.RA3
#define LED1_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LED1_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISAbits.TRISA5
#define LED2_LAT                  LATAbits.LATA5
#define LED2_PORT                 PORTAbits.RA5
#define LED2_WPU                  WPUAbits.WPUA5
#define LED2_OD                   ODCONAbits.ODCA5
#define LED2_ANS                  ANSELAbits.ANSELA5
#define LED2_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED2_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED2_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED2_GetValue()           PORTAbits.RA5
#define LED2_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED2_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS                 TRISAbits.TRISA7
#define LED3_LAT                  LATAbits.LATA7
#define LED3_PORT                 PORTAbits.RA7
#define LED3_WPU                  WPUAbits.WPUA7
#define LED3_OD                   ODCONAbits.ODCA7
#define LED3_ANS                  ANSELAbits.ANSELA7
#define LED3_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define LED3_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define LED3_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define LED3_GetValue()           PORTAbits.RA7
#define LED3_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define LED3_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set DIR aliases
#define DIR_TRIS                 TRISBbits.TRISB0
#define DIR_LAT                  LATBbits.LATB0
#define DIR_PORT                 PORTBbits.RB0
#define DIR_WPU                  WPUBbits.WPUB0
#define DIR_OD                   ODCONBbits.ODCB0
#define DIR_ANS                  ANSELBbits.ANSELB0
#define DIR_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define DIR_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define DIR_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define DIR_GetValue()           PORTBbits.RB0
#define DIR_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define DIR_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define DIR_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define DIR_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define DIR_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define DIR_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define DIR_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define DIR_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set CSN aliases
#define CSN_TRIS                 TRISBbits.TRISB4
#define CSN_LAT                  LATBbits.LATB4
#define CSN_PORT                 PORTBbits.RB4
#define CSN_WPU                  WPUBbits.WPUB4
#define CSN_OD                   ODCONBbits.ODCB4
#define CSN_ANS                  ANSELBbits.ANSELB4
#define CSN_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define CSN_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define CSN_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define CSN_GetValue()           PORTBbits.RB4
#define CSN_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define CSN_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define CSN_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define CSN_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define CSN_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define CSN_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define CSN_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define CSN_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSELC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF1 pin functionality
 * @Example
    IOCAF1_ISR();
 */
void IOCAF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF1_SetInterruptHandler() method.
    This handler is called every time the IOCAF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF1_SetInterruptHandler(IOCAF1_InterruptHandler);

*/
extern void (*IOCAF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF1_SetInterruptHandler() method.
    This handler is called every time the IOCAF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF1_SetInterruptHandler(IOCAF1_DefaultInterruptHandler);

*/
void IOCAF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF2 pin functionality
 * @Example
    IOCAF2_ISR();
 */
void IOCAF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF2_SetInterruptHandler() method.
    This handler is called every time the IOCAF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(IOCAF2_InterruptHandler);

*/
extern void (*IOCAF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF2_SetInterruptHandler() method.
    This handler is called every time the IOCAF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(IOCAF2_DefaultInterruptHandler);

*/
void IOCAF2_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/