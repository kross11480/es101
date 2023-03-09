/* ***************************************************************************************
 *  Project:    task1 - running LED
 *  File:       STefi.h
 *
 *  Language:   C
 *
 *  Hardware:   STefi v1.0b
 *  Processor:  STM32L476RG
 *
 *  Author:     Manuel Lederhofer
 *  Datum:      02.09.2019
 *
 *  Version:    0.2
 *  History:
 *      02.09.2019  ML  create project, implement LED blinker example
 *      20.12.2019  HL  #define MASK_KEYx    (MASK_Sx) changed to
 *                      #define MASK_TASx    (MASK_Sx) according to schematic
 *  Status:     under development
 *
 *  Description:
 *          Definitions and declarations related to STefi hardware
 *          extended by application related elements.
 *
 *
 *  Notes:
 *      - default MCU speed at startup is ~ 4 MHz.
 *
 *  ToDo:
 *      - change the code example to match the description of the program
 *          (see header of main.c)
 ************************************************************************************** */
#ifndef STEFI_STUD_H_
#define STEFI_STUD_H_
/* ==================================================================================== */

/* ------------------------------------ INCLUDES -------------------------------------- */


/* ------------------------------------ DEFINES --------------------------------------- */

/* --- STefi peripherals related definitions --- */
#define MASK_LED0           (1 << 4)
#define MASK_LED1           (1 << 5)
#define MASK_LED2           (1 << 6)
#define MASK_LED3           (1 << 7)

#define MASK_LED_RED        (MASK_LED0)
#define MASK_LED_YELLOW     (MASK_LED1)
#define MASK_LED_GREEN      (MASK_LED2)
#define MASK_LED_BLUE       (MASK_LED3)

#define MASK_LED_ALL        (MASK_LED0 | MASK_LED1 | MASK_LED2 | MASK_LED3)

#define MASK_S0             (1 << 0)
#define MASK_S1             (1 << 1)
#define MASK_S2             (1 << 2)
#define MASK_S3             (1 << 3)

#define MASK_TAS0           (MASK_S0)
#define MASK_TAS1           (MASK_S1)
#define MASK_TAS2           (MASK_S2)
#define MASK_TAS3           (MASK_S3)


/* ------------------------------------ TYPE DEFINITIONS ------------------------------ */
/* ------------------------------------ GLOBAL VARIABLES ------------------------------ */
/* ------------------------------------ PROTOTYPES ------------------------------------ */
/* ------------------------------------ GLOBAL FUNCTIONS ------------------------------ */


/* ==================================================================================== */
#endif /* STEFI_STUD_H_ */
/* ************************************ E O F ***************************************** */
