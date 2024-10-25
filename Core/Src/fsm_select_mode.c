/*
* fsm_select_mode.c
*
*  Created on: Oct 25, 2024
*      Author: admin
*/


#include "fsm_select_mode.h"
int red_duration = 1;
int green_duration = 1;
int yellow_duration = 1;

void setRedLEDDuration(int duration) {
  red_led_duration  = duration;
}

void setGreenLEDDuration(int duration) {
   green_led_duration = duration;
}

void setYellowLEDDuration(int duration) {
   yellow_led_duration = duration;
}

void fsm_select_mode_run() {
   switch (status_way1) {
       case INIT_mode:
           // Initialize the state to SELECT_MODE_1
           // Initialize all LEDs to off
           HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
           HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_RESET);
           HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_RESET);
           HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
           HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
           HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);

            // off all SEGb
                HAL_GPIO_WritePin(EN2_1_GPIO_Port, EN2_1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(EN2_2_GPIO_Port, EN2_2_Pin, GPIO_PIN_SET);

            // ON all SEG
                HAL_GPIO_WritePin(EN1_1_GPIO_Port, EN1_1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(EN1_2_GPIO_Port, EN1_2_Pin, GPIO_PIN_RESET);


           status_way1 = SELECT_MODE_1;
           setTimer0(3000);
             setTimer1(500); //Blinking
 
           break;
       case SELECT_MODE_1:

           display7SEG(1); // Display mode

           if (isButton1Pressed() == 1) {
           status_way1 = SELECT_MODE_2;
           setTimer0(10000);
            setTimer1(500); //Blinking
           setTimer4(10);
           }



           if (timer0_flag == 1) {
                status_way1 = INIT_1;
                status_way2 = INIT_2;
                HAL_GPIO_WritePin(EN2_1_GPIO_Port, EN2_1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(EN2_2_GPIO_Port, EN2_2_Pin, GPIO_PIN_RESET);
           }
           break;
       case SELECT_MODE_2:
           display7SEG(2); // Display mode
// Blinking red LEDs at 2 Hz
           if (timer1_flag == 1) {
               HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
               HAL_GPIO_TogglePin(LED_4_GPIO_Port, LED_4_Pin);
               // Reset other LEDs
               HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
               HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
               HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_RESET);
               HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_RESET);
               setTimer1(500); // 0.5 seconds for 2 Hz blinking
           }


           if (isButton1Pressed() == 1) {
               status_way1 = SELECT_MODE_3;
               setTimer0(10000);
            setTimer1(500); //Blinking
           setTimer4(10);
           }
           // Increment duration with Button 2
           if (isButton2Pressed() == 1) {
               red_duration++;
               if (red_duration > 99) {
                   red_duration = 1; // Wrap around to 1 if it exceeds 9
               }
               setTimer0(10000);
           }
            // display7SEG2(red_duration);
            display2DigitNumberWay2(red_duration);
           // Set duration with Button 3
           if (isButton3Pressed() == 1) {
               // Save the duration value and exit Mode 2
               setRedLEDDuration(red_duration);
                status_way1 = INIT_1;
                status_way2 = INIT_2;
           }

           if (timer0_flag == 1) {
                status_way1 = INIT_1;
                status_way2 = INIT_2;
           }
           break;
       case SELECT_MODE_3:
           display7SEG(3); // Display mode
           // Blinking yellow LEDs at 2 Hz
           if (timer1_flag == 1) {
               HAL_GPIO_TogglePin(LED_3_GPIO_Port, LED_3_Pin);
               HAL_GPIO_TogglePin(LED_12_GPIO_Port, LED_12_Pin);
               // Reset other LEDs
               HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
               HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
               HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
               HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_RESET);
               setTimer1(500); // 0.5 seconds for 2 Hz blinking
           }

           if (isButton1Pressed() == 1) {
               status_way1 = SELECT_MODE_4;
               setTimer0(10000);
              setTimer1(500); //Blinking
           setTimer4(10);
           
           }
           // Increment duration with Button 2
           if (isButton2Pressed() == 1) {
               yellow_duration++;
               if (yellow_duration > 99) {
                   yellow_duration = 1; // Wrap around to 1 if it exceeds 9
               }
           setTimer0(10000);
           }


        //    display7SEG2(yellow_duration);
            display2DigitNumberWay2(yellow_duration);
           // Set duration with Button 3
           if (isButton3Pressed() == 1) {
               // Save the duration value and exit Mode 2
               setYellowLEDDuration(yellow_duration);
                status_way1 = INIT_1;
                status_way2 = INIT_2;
           }
           if (timer0_flag == 1) {
                status_way1 = INIT_1;
                status_way2 = INIT_2;
           }
           break;
       case SELECT_MODE_4:
           display7SEG(4); // Display mode

            // Blinking red LEDs at 2 Hz
           if (timer1_flag == 1) {
               HAL_GPIO_TogglePin(LED_11_GPIO_Port, LED_11_Pin);
               HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
               // Reset other LEDs
               HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
               HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
               HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
               HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_RESET);

               setTimer1(500); // 0.5 seconds for 2 Hz blinking
           }

           if (isButton1Pressed() == 1) {
               status_way1 = INIT_mode;
               setTimer0(3000);

           }
           // Increment duration with Button 2
           if (isButton2Pressed() == 1) {
               green_duration++;
               if (green_duration > 99) {
                   green_duration = 1; // Wrap around to 1 if it exceeds 9
               }
           setTimer0(10000);
           }

        //    display7SEG2(green_duration);
            display2DigitNumberWay2(green_duration);
           // Set duration with Button 3
           if (isButton3Pressed() == 1) {
               // Save the duration value and exit Mode 2
               setGreenLEDDuration(green_duration);
                status_way1 = INIT_1;
                status_way2 = INIT_2;
           }
           if (timer0_flag == 1) {
               status_way1 = INIT_1;
               status_way2 = INIT_2;
           }
           break;
       default:
           // status_way1 = INIT;
           break;
   }
}


