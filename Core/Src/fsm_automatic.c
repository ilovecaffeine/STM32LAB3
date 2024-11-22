/*
 * fsm_automatic.c
 *
 *  Created on: Oct 19, 2024
 *      Author: admin
 */

#include "fsm_automatic.h"

void fsm_automatic_run_way1() {
	    static int countdown_way1;
switch (status_way1) {
        case INIT_1:
            // Initialize all LEDs to off
            HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_RESET);
            
            HAL_GPIO_WritePin(EN1_1_GPIO_Port, EN1_1_Pin, GPIO_PIN_RESET); 
            HAL_GPIO_WritePin(EN1_2_GPIO_Port, EN1_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(EN2_1_GPIO_Port, EN2_1_Pin, GPIO_PIN_RESET); 
            HAL_GPIO_WritePin(EN2_2_GPIO_Port, EN2_2_Pin, GPIO_PIN_RESET);  
            
            status_way1 = AUTO_RED_WAY1;


            countdown_way1 = red_led_duration ;

            display2DigitNumberWay1(countdown_way1);

            setTimer0(red_led_duration*1000);
            setTimer1(1000); // Start the countdown timer

            break;
        case AUTO_RED_WAY1:
            // Way 1 Red, Way 2 Green
            HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_RESET);

            display2DigitNumberWay1(countdown_way1);
            if (timer1_flag == 1) {
                setTimer1(1000); // Reset the countdown timer

                countdown_way1--;



            }


            if (isButton1Pressed() == 1) {
                status_way1 = INIT_mode;
                status_way2 = INIT_mode;

            }

            if (timer0_flag == 1) {
                status_way1 = AUTO_GREEN_WAY1;
                setTimer0(green_led_duration*1000);
				countdown_way1 = green_led_duration; // Reset countdown for next cycle

            display2DigitNumberWay1(countdown_way1);
				setTimer1(1000); // Start the countdown timer for the next state

            }
            break;
        case AUTO_GREEN_WAY1:
            // Way 1 Red, Way 2 Yellow
            HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_RESET);

            display2DigitNumberWay1(countdown_way1);
            if (timer1_flag == 1) {
                setTimer1(1000); // Reset the countdown timer
                countdown_way1--;

            }



            if (isButton1Pressed() == 1) {
                status_way1 = INIT_mode;
                status_way2 = INIT_mode;
  
            }

            if (timer0_flag == 1) {
                status_way1 = AUTO_YELLOW_WAY1;
                setTimer0(yellow_led_duration*1000);
				countdown_way1 = yellow_led_duration; // Reset countdown for next cycle
            display2DigitNumberWay1(countdown_way1);
			    setTimer1(1000); // Start the countdown timer for the next state

            }
            break;
        case AUTO_YELLOW_WAY1:
            // Way 1 Green, Way 2 Red
            HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_SET);



            display2DigitNumberWay1(countdown_way1);
            if (timer1_flag == 1) {
                setTimer1(1000); // Reset the countdown timer
                countdown_way1--;
  
                
            }

            if (isButton1Pressed() == 1) {
                status_way1 = INIT_mode;
                status_way2 = INIT_mode;

            }

            if (timer0_flag == 1) {
                status_way1 = AUTO_RED_WAY1;
                setTimer0(red_led_duration*1000);
				countdown_way1 = red_led_duration; // Reset countdown for next cycle
                
            display2DigitNumberWay1(countdown_way1);
				setTimer1(1000); // Start the countdown timer for the next state

            }
            break;
       

		
		default:
            break;
    }
}

void fsm_automatic_run_way2() {
    static int countdown_way2;
    switch (status_way2) {
        case INIT_2:
            // Initialize all LEDs to off
            HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
            status_way2 = AUTO_GREEN_WAY2;
            countdown_way2 = green_led_duration;

            display2DigitNumberWay2(countdown_way2);

            setTimer2(green_led_duration * 1000);
            setTimer3(1000); // Start the countdown timer

            break;
        case AUTO_GREEN_WAY2:
           
            HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);

            if (timer3_flag == 1) {
                setTimer3(1000); // Reset the countdown timer

                countdown_way2--;


            }
            display2DigitNumberWay2(countdown_way2);
            // if (isButton1Pressed() == 1) {
            //     status_way2 = INIT_mode;
            //     status_way2 = INIT_mode;

            // }

            if (timer2_flag == 1) {
                status_way2 = AUTO_YELLOW_WAY2;
                setTimer2(yellow_led_duration * 1000);
                countdown_way2 = yellow_led_duration; // Reset countdown for next cycle
            
            display2DigitNumberWay2(countdown_way2);
                setTimer3(1000); // Start the countdown timer for the next state
            

            }
            break;
        case AUTO_YELLOW_WAY2:
            // Way 2 Green, Way 1 Yellow
            HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);

            if (timer3_flag == 1) {
                setTimer3(1000); // Reset the countdown timer
                countdown_way2--;


            }
            display2DigitNumberWay2(countdown_way2);
            // if (isButton1Pressed() == 1) {
            //     status_way2 = INIT_mode;
            //     status_way2 = INIT_mode;
            // }

            if (timer2_flag == 1) {
                status_way2 = AUTO_RED_WAY2;
                setTimer2(red_led_duration * 1000);
                countdown_way2 = red_led_duration; // Reset countdown for next cycle
            display2DigitNumberWay2(countdown_way2);
                setTimer3(1000); // Start the countdown timer for the next state
            

            }
            break;
        case AUTO_RED_WAY2:
            // Way 2 Yellow, Way 1 Red
            HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET);

            if (timer3_flag == 1) {
                setTimer3(1000); // Reset the countdown timer
                countdown_way2--;

            }
            display2DigitNumberWay2(countdown_way2);
            // if (isButton1Pressed() == 1) {
            //     status_way2 = INIT_mode;

            // }

            if (timer2_flag == 1) {
                status_way2 = AUTO_GREEN_WAY2;
                setTimer2(green_led_duration * 1000);
                countdown_way2 = green_led_duration; // Reset countdown for next cycle

            display2DigitNumberWay2(countdown_way2);
                setTimer3(1000); // Start the countdown timer for the next state
            

            }
            break;
        default:
            break;
    }
}