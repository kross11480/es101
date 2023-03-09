/* ***************************************************************************************
 *  Project:    task1 - running LED
 *  File:       main.c
 *
 *  Language:   C
 *
 *  Hardware:   STefi v1.0b
 *  Processor:  STM32L476RG
 *
 *  Author:     Manuel Lederhofer
 *  Datum:      02.09.2019
 *
 *  Version:    0.1
 *  History:
 *      02.09.2019  ML  create project, implement LED blinker example
 *
 *  Status:     under development
 *
 *  Description:
 *      Change this code example to a running LED.
 *      See the description and requirements of the requested application
 *      in the lab exercise guide.
 *
 *
 *  Notes:
 *      - default MCU speed at startup is ~ 4 MHz.
 *
 ************************************************************************************** */

/* ------------------------------------ INCLUDES -------------------------------------- */
#include "STefi_Stud.h"
#include "stm32l476xx.h"
#include "core_cm4.h"


/* ------------------------------------ DEFINES --------------------------------------- */
/* ------------------------------------ TYPE DEFINITIONS ------------------------------ */
/* ------------------------------------ GLOBAL VARIABLES ------------------------------ */
/* ------------------------------------ PRIVATE VARIABLES ----------------------------- */


/* ------------------------------------ PROTOTYPES ------------------------------------ */
void delay(const uint16_t ms);
static void GPIO_init(void);


/* ------------------------------------ MAIN ------------------------------------------ */
int main(void)
{
    /* --- initialization --- */
    __disable_irq();

    GPIO_init();        // LEDs and buttons

    __enable_irq();


    /* --- one time tasks --- */
    // none

    /* --- infinite processing loop --- */
    while (1)
    {
        /* blink a LED */
        GPIOC->ODR &= ~MASK_LED3;
        delay(500);
        GPIOC->ODR |= MASK_LED3;
        delay(500);
    }

    return 1;
}


/* ------------------------------------ GLOBAL FUNCTIONS ------------------------------ */

/* ------------------------------------------------------------------------------------ *\
 * method:  void delay(const uint16_t ms)
 *
 * It realizes a millisecond delay by very bad busy-wait.
 *
 * requires:    - nothing -
 * parameters:  ms - delay time in milliseconds
 * returns:     - nothing -
\* ------------------------------------------------------------------------------------ */
void delay(const uint16_t ms)
{
    for (uint16_t i = 0; i < ms; ++i)
    {
        for (uint16_t j = 0; j < 400; ++j)
        {
            __asm("NOP");
        }
    }
}


/* ------------------------------------ PRIVATE FUNCTIONS ----------------------------- */

/* ------------------------------------------------------------------------------------ *\
 * method:  static void GPIO_init(void)
 *
 * Initializes GPIOs on STefi for pins with peripherals attached.
 * LED0 (red) on PC4
 * LED1 (yellow) on PC5
 * LED2 (green) on PC6
 * LED3 (blue) on PC7
 *
 * requires:    - nothing -
 * parameters:  - none -
 * returns:     - nothing -
\* ------------------------------------------------------------------------------------ */
static void GPIO_init(void)
{
    /* enable port clocks */
    RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

    /* LED3 init */
    GPIOC -> ODR |= MASK_LED3;
    GPIOC->MODER &= ~(1<<15) ;		// PC7 is output (LED3)
}

/* ************************************ E O F ***************************************** */
