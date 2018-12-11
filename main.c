/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F25K83
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include <xc.h>
#include <time.h>

const double resolution = 5.0/1023.0;

void led_high(void) {led_green_SetHigh();}
void led_low(void)  {led_green_SetLow();}

void mcc_blinky(void (*set_high)(void), void (*set_low)(void), const uint8_t num_flashes) {
    for (uint8_t i=0 ; i<num_flashes ; i++) {
        set_high();
        _delay(5000000);
        set_low();
        _delay(5000000);
    }
    return;
}

static inline bool set_channel(const uint8_t channel) {
    static uint8_t current_channel;
    
    if (channel == current_channel) return true;
    
    // Return zero if an erroneous channel number is asked for
    if (channel > 16) return 0;

    // Disable the MAX306 common output
    en_SetLow();
    
    switch (channel) {
        case 1:
            add0_SetLow();
            add1_SetLow();
            add2_SetLow();
            add3_SetLow();
            break;
        case 2:
            add0_SetHigh();
            add1_SetLow();
            add2_SetLow();
            add3_SetLow();
            break;   
        case 3:
            add0_SetLow();
            add1_SetHigh();
            add2_SetLow();
            add3_SetLow();
            break;   
        case 4:
            add0_SetHigh();
            add1_SetHigh();
            add2_SetLow();
            add3_SetLow();
            break;   
        case 5:
            add0_SetLow();
            add1_SetLow();
            add2_SetHigh();
            add3_SetLow();
            break;   
        case 6:
            add0_SetHigh();
            add1_SetLow();
            add2_SetHigh();
            add3_SetLow();
            break;   
        case 7:
            add0_SetLow();
            add1_SetHigh();
            add2_SetHigh();
            add3_SetLow();
            break;   
        case 8:
            add0_SetHigh();
            add1_SetHigh();
            add2_SetHigh();
            add3_SetLow();
            break;   
        case 9:
            add0_SetLow();
            add1_SetLow();
            add2_SetLow();
            add3_SetHigh();
            break;  
        case 10:
            add0_SetHigh();
            add1_SetLow();
            add2_SetLow();
            add3_SetHigh();
            break;  
        case 11:
            add0_SetLow();
            add1_SetHigh();
            add2_SetLow();
            add3_SetHigh();
            break;  
        case 12:
            add0_SetHigh();
            add1_SetHigh();
            add2_SetLow();
            add3_SetHigh();
            break;  
        case 13:
            add0_SetLow();
            add1_SetLow();
            add2_SetHigh();
            add3_SetHigh();
            break;  
        case 14:
            add0_SetHigh();
            add1_SetLow();
            add2_SetHigh();
            add3_SetHigh();
            break;  
        case 15:
            add0_SetLow();
            add1_SetHigh();
            add2_SetHigh();
            add3_SetHigh();
            break;  
        case 16:
            add0_SetHigh();
            add1_SetHigh();
            add2_SetHigh();
            add3_SetHigh();
            break;  
        default:
            return 0;
            break;
    }
    /*
    // Set the correct address pins on MAX306
    if (channel % 2 == 0) add0_SetHigh();
    else add0_SetLow();
    
    if ((channel == 3)||(channel == 4)) add1_SetHigh();
    else if ((channel == 7)||(channel == 8)) add1_SetHigh();
    else if ((channel == 11)||(channel == 12)) add1_SetHigh();
    else if ((channel == 15)||(channel == 16)) add1_SetHigh();
    else add1_SetLow();
    
    if ((channel == 5)||(channel == 6)) add2_SetHigh();
    else if ((channel == 7)||(channel == 8)) add2_SetHigh();
    else if ((channel == 13)||(channel == 14)) add2_SetHigh();
    else if ((channel == 15)||(channel == 16)) add2_SetHigh();
    else add2_SetLow();
    
    if (channel > 8) add3_SetHigh();
    else add2_SetLow();
    */
    // Enable the MAX306 common output
    en_SetHigh();
    
    current_channel = channel;
    
    // If we get here, all ok, return true
    // TODO:  Add a readback check on address outputs
    return true;
}

static inline uint16_t get_adc(const uint8_t channel) {
    // Allocate some persistent memory for the output register
    static uint16_t out_val;
    
    // Set channel to user request, return -1 if failed to set channel
    if (!set_channel(channel)) return -1;
    
    // Arbitrary delay to allow the MAX306 to switch
    _delay(10000);
    
    // Tell the ADCC module to take a reading
    ADCC_StartConversion(adc0);
    
    // Blocking function to wait for ADCC module to complete a sample
    while(!ADCC_IsConversionDone());
    
    // Assign result to local output register
    out_val = (uint16_t)(ADCC_GetConversionResult()) & 0xfff; // 12-bit result
    //uint16_t out_val = (ADCC_GetSingleConversion(adc));// & 0x3ff; // 10-bit result
    
    // Tell ADCC to stop taking a reading
    ADCC_StopConversion();
    
    
    return out_val;
}

/*
                         Main application
 */
void main(void)
{
    // Initialise the device
    SYSTEM_Initialize();
    
    // Blink the led
    mcc_blinky(led_high, led_low, 6);
    
    en_SetLow(); // **************** TODO REMOVE THIS LINE! ****************

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    
    ADCC_DisableContinuousConversion();

    while (1)
    {
        led_yellow_Toggle();
        
        static char channels[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

        for (uint8_t i=0 ; i<sizeof(channels) ; i++) {
            
            uint16_t result = get_adc(channels[i]);
            
            if (result < 0) continue;
            
            set_buffer_16(i, (uint16_t)result);
            
            //_delay(2000000);
        }
    }
}




/**
 End of File
*/