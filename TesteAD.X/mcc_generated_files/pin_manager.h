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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC18F46K80
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.30 and above
        MPLAB 	          :  MPLAB X 5.40	
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

// get/set channel_AN2 aliases
#define channel_AN2_TRIS                 TRISAbits.TRISA2
#define channel_AN2_LAT                  LATAbits.LATA2
#define channel_AN2_PORT                 PORTAbits.RA2
#define channel_AN2_ANS                  ANCON0bits.ANSEL2
#define channel_AN2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define channel_AN2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define channel_AN2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define channel_AN2_GetValue()           PORTAbits.RA2
#define channel_AN2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define channel_AN2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define channel_AN2_SetAnalogMode()      do { ANCON0bits.ANSEL2 = 1; } while(0)
#define channel_AN2_SetDigitalMode()     do { ANCON0bits.ANSEL2 = 0; } while(0)

// get/set channel_AN3 aliases
#define channel_AN3_TRIS                 TRISAbits.TRISA3
#define channel_AN3_LAT                  LATAbits.LATA3
#define channel_AN3_PORT                 PORTAbits.RA3
#define channel_AN3_ANS                  ANCON0bits.ANSEL3
#define channel_AN3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define channel_AN3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define channel_AN3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define channel_AN3_GetValue()           PORTAbits.RA3
#define channel_AN3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define channel_AN3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define channel_AN3_SetAnalogMode()      do { ANCON0bits.ANSEL3 = 1; } while(0)
#define channel_AN3_SetDigitalMode()     do { ANCON0bits.ANSEL3 = 0; } while(0)

// get/set RS aliases
#define RS_TRIS                 TRISDbits.TRISD1
#define RS_LAT                  LATDbits.LATD1
#define RS_PORT                 PORTDbits.RD1
#define RS_ANS                  ANCON1bits.ANSEL12
#define RS_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RS_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RS_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RS_GetValue()           PORTDbits.RD1
#define RS_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RS_SetAnalogMode()      do { ANCON1bits.ANSEL12 = 1; } while(0)
#define RS_SetDigitalMode()     do { ANCON1bits.ANSEL12 = 0; } while(0)

// get/set RW aliases
#define RW_TRIS                 TRISDbits.TRISD2
#define RW_LAT                  LATDbits.LATD2
#define RW_PORT                 PORTDbits.RD2
#define RW_ANS                  ANCON1bits.ANSEL13
#define RW_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define RW_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define RW_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define RW_GetValue()           PORTDbits.RD2
#define RW_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define RW_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define RW_SetAnalogMode()      do { ANCON1bits.ANSEL13 = 1; } while(0)
#define RW_SetDigitalMode()     do { ANCON1bits.ANSEL13 = 0; } while(0)

// get/set EN aliases
#define EN_TRIS                 TRISDbits.TRISD3
#define EN_LAT                  LATDbits.LATD3
#define EN_PORT                 PORTDbits.RD3
#define EN_ANS                  ANCON1bits.ANSEL14
#define EN_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define EN_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define EN_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define EN_GetValue()           PORTDbits.RD3
#define EN_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define EN_SetAnalogMode()      do { ANCON1bits.ANSEL14 = 1; } while(0)
#define EN_SetDigitalMode()     do { ANCON1bits.ANSEL14 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS                 TRISDbits.TRISD4
#define D4_LAT                  LATDbits.LATD4
#define D4_PORT                 PORTDbits.RD4
#define D4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define D4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define D4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define D4_GetValue()           PORTDbits.RD4
#define D4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)

// get/set D5 aliases
#define D5_TRIS                 TRISDbits.TRISD5
#define D5_LAT                  LATDbits.LATD5
#define D5_PORT                 PORTDbits.RD5
#define D5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define D5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define D5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define D5_GetValue()           PORTDbits.RD5
#define D5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)

// get/set D6 aliases
#define D6_TRIS                 TRISDbits.TRISD6
#define D6_LAT                  LATDbits.LATD6
#define D6_PORT                 PORTDbits.RD6
#define D6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define D6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define D6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define D6_GetValue()           PORTDbits.RD6
#define D6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS                 TRISDbits.TRISD7
#define D7_LAT                  LATDbits.LATD7
#define D7_PORT                 PORTDbits.RD7
#define D7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define D7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define D7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define D7_GetValue()           PORTDbits.RD7
#define D7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)

// get/set Tecla1 aliases
#define Tecla1_TRIS                 TRISEbits.TRISE0
#define Tecla1_LAT                  LATEbits.LATE0
#define Tecla1_PORT                 PORTEbits.RE0
#define Tecla1_ANS                  ANCON0bits.ANSEL5
#define Tecla1_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define Tecla1_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define Tecla1_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define Tecla1_GetValue()           PORTEbits.RE0
#define Tecla1_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define Tecla1_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define Tecla1_SetAnalogMode()      do { ANCON0bits.ANSEL5 = 1; } while(0)
#define Tecla1_SetDigitalMode()     do { ANCON0bits.ANSEL5 = 0; } while(0)

// get/set Teste aliases
#define Teste_TRIS                 TRISEbits.TRISE1
#define Teste_LAT                  LATEbits.LATE1
#define Teste_PORT                 PORTEbits.RE1
#define Teste_ANS                  ANCON0bits.ANSEL6
#define Teste_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define Teste_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define Teste_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define Teste_GetValue()           PORTEbits.RE1
#define Teste_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define Teste_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define Teste_SetAnalogMode()      do { ANCON0bits.ANSEL6 = 1; } while(0)
#define Teste_SetDigitalMode()     do { ANCON0bits.ANSEL6 = 0; } while(0)

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



#endif // PIN_MANAGER_H
/**
 End of File
*/