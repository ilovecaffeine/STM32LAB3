#include "button.h"

// Button 1 state variables
int KeyReg0_1 = NORMAL_STATE;
int KeyReg1_1 = NORMAL_STATE;
int KeyReg2_1 = NORMAL_STATE;
int KeyReg3_1 = NORMAL_STATE;

int TimeOutForKeyPress_1 = 500;
int button1_pressed = 0;
int button1_long_pressed_flag = 0;
int button1_flag = 0;

// Button 2 state variables
int KeyReg0_2 = NORMAL_STATE;
int KeyReg1_2 = NORMAL_STATE;
int KeyReg2_2 = NORMAL_STATE;
int KeyReg3_2 = NORMAL_STATE;

int TimeOutForKeyPress_2 = 500;
int button2_pressed = 0;
int button2_long_pressed_flag = 0;
int button2_flag = 0;

// Button 3 state variables
int KeyReg0_3 = NORMAL_STATE;
int KeyReg1_3 = NORMAL_STATE;
int KeyReg2_3 = NORMAL_STATE;
int KeyReg3_3 = NORMAL_STATE;

int TimeOutForKeyPress_3 = 500;
int button3_pressed = 0;
int button3_long_pressed_flag = 0;
int button3_flag = 0;

// Button 1 functions
int isButton1Pressed() {
    if (button1_flag == 1) {
        button1_flag = 0;
        return 1;
    }
    return 0;
}

int isButton1LongPressed() {
    if (button1_long_pressed_flag == 1) {
        button1_long_pressed_flag = 0;
        return 1;
    }
    return 0;
}

// Button 2 functions
int isButton2Pressed() {
    if (button2_flag == 1) {
        button2_flag = 0;
        return 1;
    }
    return 0;
}

int isButton2LongPressed() {
    if (button2_long_pressed_flag == 1) {
        button2_long_pressed_flag = 0;
        return 1;
    }
    return 0;
}

// Button 3 functions
int isButton3Pressed() {
    if (button3_flag == 1) {
        button3_flag = 0;
        return 1;
    }
    return 0;
}

int isButton3LongPressed() {
    if (button3_long_pressed_flag == 1) {
        button3_long_pressed_flag = 0;
        return 1;
    }
    return 0;
}

void subKeyProcess() {
    // TODO
    // HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
}

void getKeyInput() {
    // Button 1
    KeyReg0_1 = KeyReg1_1;
    KeyReg1_1 = KeyReg2_1;
    KeyReg2_1 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);

    if ((KeyReg1_1 == KeyReg0_1) && (KeyReg1_1 == KeyReg2_1)) {
        if (KeyReg2_1 != KeyReg3_1) {  // Button press detected
            KeyReg3_1 = KeyReg2_1;

            if (KeyReg3_1 == PRESSED_STATE) {
                TimeOutForKeyPress_1 = 500;
                button1_flag = 1;
            }
        } else {
            TimeOutForKeyPress_1--;  // Long press detection
            if (TimeOutForKeyPress_1 == 0) {
                TimeOutForKeyPress_1 = 500;
                if (KeyReg3_1 == PRESSED_STATE) {
                    button1_long_pressed_flag = 1;
                }
            }
        }
    }

    // Button 2
    KeyReg0_2 = KeyReg1_2;
    KeyReg1_2 = KeyReg2_2;
    KeyReg2_2 = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);

    if ((KeyReg1_2 == KeyReg0_2) && (KeyReg1_2 == KeyReg2_2)) {
        if (KeyReg2_2 != KeyReg3_2) {  // Button press detected
            KeyReg3_2 = KeyReg2_2;

            if (KeyReg3_2 == PRESSED_STATE) {
                TimeOutForKeyPress_2 = 500;
                button2_flag = 1;
            }
        } else {
            TimeOutForKeyPress_2--;  // Long press detection
            if (TimeOutForKeyPress_2 == 0) {
                TimeOutForKeyPress_2 = 500;
                if (KeyReg3_2 == PRESSED_STATE) {
                    button2_long_pressed_flag = 1;
                }
            }
        }
    }

    // Button 3
    KeyReg0_3 = KeyReg1_3;
    KeyReg1_3 = KeyReg2_3;
    KeyReg2_3 = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);

    if ((KeyReg1_3 == KeyReg0_3) && (KeyReg1_3 == KeyReg2_3)) {
        if (KeyReg2_3 != KeyReg3_3) {  // Button press detected
            KeyReg3_3 = KeyReg2_3;

            if (KeyReg3_3 == PRESSED_STATE) {
                TimeOutForKeyPress_3 = 500;
                button3_flag = 1;
            }
        } else {
            TimeOutForKeyPress_3--;  // Long press detection
            if (TimeOutForKeyPress_3 == 0) {
                TimeOutForKeyPress_3 = 500;
                if (KeyReg3_3 == PRESSED_STATE) {
                    button3_long_pressed_flag = 1;
                }
            }
        }
    }
}