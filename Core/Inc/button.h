/*
 * button.h
 *
 *  Created on: Oct 5, 2023
 *      Author: KAI
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

// Button 1 state variables
extern int button1_flag;
extern int button1_long_pressed_flag;
extern int button1_pressed;

// Button 2 state variables
extern int button2_flag;
extern int button2_long_pressed_flag;
extern int button2_pressed;

// Button 3 state variables
extern int button3_flag;
extern int button3_long_pressed_flag;
extern int button3_pressed;

// Function prototypes for Button 1
int isButton1Pressed();
int isButton1LongPressed();

// Function prototypes for Button 2
int isButton2Pressed();
int isButton2LongPressed();

// Function prototypes for Button 3
int isButton3Pressed();
int isButton3LongPressed();

// Function prototype for getting key input
void getKeyInput();

#endif /* INC_BUTTON_H_ */