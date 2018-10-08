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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F25K83
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set en aliases
#define en_TRIS                 TRISAbits.TRISA0
#define en_LAT                  LATAbits.LATA0
#define en_PORT                 PORTAbits.RA0
#define en_WPU                  WPUAbits.WPUA0
#define en_OD                   ODCONAbits.ODCA0
#define en_ANS                  ANSELAbits.ANSELA0
#define en_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define en_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define en_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define en_GetValue()           PORTAbits.RA0
#define en_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define en_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define en_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define en_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define en_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define en_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define en_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define en_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set add0 aliases
#define add0_TRIS                 TRISAbits.TRISA1
#define add0_LAT                  LATAbits.LATA1
#define add0_PORT                 PORTAbits.RA1
#define add0_WPU                  WPUAbits.WPUA1
#define add0_OD                   ODCONAbits.ODCA1
#define add0_ANS                  ANSELAbits.ANSELA1
#define add0_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define add0_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define add0_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define add0_GetValue()           PORTAbits.RA1
#define add0_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define add0_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define add0_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define add0_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define add0_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define add0_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define add0_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define add0_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set add1 aliases
#define add1_TRIS                 TRISAbits.TRISA2
#define add1_LAT                  LATAbits.LATA2
#define add1_PORT                 PORTAbits.RA2
#define add1_WPU                  WPUAbits.WPUA2
#define add1_OD                   ODCONAbits.ODCA2
#define add1_ANS                  ANSELAbits.ANSELA2
#define add1_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define add1_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define add1_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define add1_GetValue()           PORTAbits.RA2
#define add1_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define add1_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define add1_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define add1_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define add1_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define add1_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define add1_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define add1_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set add2 aliases
#define add2_TRIS                 TRISAbits.TRISA3
#define add2_LAT                  LATAbits.LATA3
#define add2_PORT                 PORTAbits.RA3
#define add2_WPU                  WPUAbits.WPUA3
#define add2_OD                   ODCONAbits.ODCA3
#define add2_ANS                  ANSELAbits.ANSELA3
#define add2_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define add2_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define add2_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define add2_GetValue()           PORTAbits.RA3
#define add2_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define add2_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define add2_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define add2_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define add2_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define add2_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define add2_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define add2_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set add3 aliases
#define add3_TRIS                 TRISAbits.TRISA4
#define add3_LAT                  LATAbits.LATA4
#define add3_PORT                 PORTAbits.RA4
#define add3_WPU                  WPUAbits.WPUA4
#define add3_OD                   ODCONAbits.ODCA4
#define add3_ANS                  ANSELAbits.ANSELA4
#define add3_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define add3_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define add3_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define add3_GetValue()           PORTAbits.RA4
#define add3_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define add3_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define add3_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define add3_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define add3_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define add3_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define add3_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define add3_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set led aliases
#define led_TRIS                 TRISBbits.TRISB0
#define led_LAT                  LATBbits.LATB0
#define led_PORT                 PORTBbits.RB0
#define led_WPU                  WPUBbits.WPUB0
#define led_OD                   ODCONBbits.ODCB0
#define led_ANS                  ANSELBbits.ANSELB0
#define led_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define led_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define led_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define led_GetValue()           PORTBbits.RB0
#define led_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define led_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define led_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define led_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define led_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define led_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define led_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define led_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

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

// get/set adc aliases
#define adc_TRIS                 TRISCbits.TRISC7
#define adc_LAT                  LATCbits.LATC7
#define adc_PORT                 PORTCbits.RC7
#define adc_WPU                  WPUCbits.WPUC7
#define adc_OD                   ODCONCbits.ODCC7
#define adc_ANS                  ANSELCbits.ANSELC7
#define adc_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define adc_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define adc_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define adc_GetValue()           PORTCbits.RC7
#define adc_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define adc_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define adc_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define adc_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define adc_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define adc_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define adc_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define adc_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

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