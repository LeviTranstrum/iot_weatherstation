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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47Q10
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

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"

// Variables

uint8_t temp_raw_1 = 0;
uint8_t temp_raw_2 = 0;
uint16_t temp_raw = 0;
float temp = 0.0;

uint8_t hum_raw_1 = 0;
uint8_t hum_raw_2 = 0;
uint16_t hum_raw = 0;
float hum = 0;

uint8_t fan_speed = 0;
uint8_t min_fan_speed = 20;
uint8_t fan_set=101;

uint8_t menu = 1;

void button_cb(void)
{
    __delay_ms(5);
    if(PB1_GetValue())
    {
        return;
    }
    menu = menu+1;
    if (menu > 2)
    {
        menu = 1;
    }
    
}

// Software debounce counts button presses lasting longer than 0.1 seconds
uint8_t debounce(void)
{   
    uint8_t i;
    for (i = 0; i < 100; ++i)
        {
        if(PB1_GetValue())
            {
            return 0;
            }
        __delay_ms(1);
        }
    return 1;
}

void main(void)
{

SYSTEM_Initialize();

// Motor Subsystem Initialization
CSN_SetLow();
PWM4_Initialize(); // Uncomment for PWM/DIR testing
TMR2_Initialize(); // Uncomment for PWM/DIR testing
SPI2_Open(SPI2_DEFAULT); //Activate SPI

// Controller Initialization
INTERRUPT_GlobalInterruptEnable();
INTERRUPT_PeripheralInterruptEnable();
IOCAF1_SetInterruptHandler(button_cb);

//Temp Sensor Initialization
EUSART1_Initialize();
I2C1_Initialize();

uint8_t temp_sensor_address = 0b1000000;
uint8_t temp_register_lower = 0x00;
uint8_t temp_register_upper = 0x01;

uint8_t hum_sensor_address = 0b1000000;
uint8_t hum_register_lower = 0x02;
uint8_t hum_register_upper = 0x03;

uint8_t device_config_register = 0x0E;
uint8_t device_config_setting = 0b01010000;
uint8_t device_command_register = 0x0F;
uint8_t measure_command = 0b00000001;

LED1_SetLow();
LED2_SetLow();

//Set the sensor to continuous measurement mode
I2C1_Write1ByteRegister(temp_sensor_address, device_config_register, device_config_setting);
I2C1_Write1ByteRegister(temp_sensor_address, device_command_register, measure_command);
__delay_ms(10);

printf("w"); // Print the welcome screen on startup
__delay_ms(1000);

while (1){
    // Blink the LED every loop so we know we're running
    LED1_Toggle(); 
    
    // Read from the temperature sensor
    temp_raw_1 = I2C1_Read1ByteRegister(temp_sensor_address, temp_register_lower);
    temp_raw_2 = I2C1_Read1ByteRegister(temp_sensor_address, temp_register_upper);   
    temp_raw = temp_raw_2 << 8 | temp_raw_1;
    temp = (((float) temp_raw)/(65536.0))*165.0 - 40.0;
    printf("%ft", temp);
    if (temp_raw!= 0)
    {
        LED2_Toggle();
        __delay_ms(100);
        LED2_Toggle();
        __delay_ms(100);
        LED2_Toggle();
        __delay_ms(100);
        LED2_Toggle();
    }

    __delay_ms(10);

    // Read from the humidity sensor
    hum_raw_1 = I2C1_Read1ByteRegister(hum_sensor_address, hum_register_lower);
    hum_raw_2 = I2C1_Read1ByteRegister(hum_sensor_address, hum_register_upper);
    hum_raw = hum_raw_2 << 8 | hum_raw_1;
    hum = (((float) hum_raw)/(65536.0))*100.0;
    printf("%fh", hum);
    __delay_ms(10);
    
        if (hum_raw!= 0)
    {
        LED2_Toggle();
        __delay_ms(100);
        LED2_Toggle();
        __delay_ms(100);
        LED2_Toggle();
        __delay_ms(100);
        LED2_Toggle();
    }

    // Menu control
    
    if (!PB1_GetValue())
        {
        menu = menu + debounce();    
        }
    if (menu > 3)
        {
        menu = 1;
        }
    
    printf("%dm", menu);
    
    // Fan Control
    if (EUSART1_is_rx_ready())
    {
        fan_set = EUSART1_Read(); // Get the fan setting from ESP32

        LED2_Toggle();
        __delay_ms(10);
        LED2_Toggle();
        
    }
    
    if (fan_set > 100) // If fan setting is greater than 100,
    {
        fan_speed = min_fan_speed + 2*temp; // Use temperature control
        if (fan_speed > 100) // But cap the speed at 100
        {
            fan_speed = 100; // 
        }
    }
    else
    {
        fan_speed = fan_set; // If fan setting is between 0 and 100, then set the speed to that
    }
     
    fan_speed = fan_set;
    PWM4_LoadDutyValue(fan_speed * 65535 / 100);
    printf("%df",fan_speed);
   
    
    __delay_ms(500);
}
}
/**
 End of File
*/