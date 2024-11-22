/*
 * 7Segs.c
 *
 *  Created on: Oct 25, 2024
 *      Author: admin
 */


#include "7Segs.h"
#include "software_timer.h"

void off_all_Seg() {
    // Turn off all segments for the first 7-segment display
    HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_SET);
    
    // Turn off all segments for the second 7-segment display
    HAL_GPIO_WritePin(SEG_0b_GPIO_Port, SEG_0b_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_1b_GPIO_Port, SEG_1b_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_2b_GPIO_Port, SEG_2b_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_3b_GPIO_Port, SEG_3b_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_4b_GPIO_Port, SEG_4b_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_5b_GPIO_Port, SEG_5b_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_6b_GPIO_Port, SEG_6b_Pin, GPIO_PIN_SET);
}

  void display7SEG(int num) {
    if (num < 0 || num > 9) return; // Ensure the number is between 0 and 9
    switch (num) {
        case 0:
            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_SET);
            break;
        case 1:
            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
            break;
        case 5:
            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
            break;
        case 6:
            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
            break;
        case 7:
            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_SET);
            break;
        case 8:
            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
            break;
        case 9:
            HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, GPIO_PIN_RESET);
            break;
        default:
            // Handle invalid input
            break;
    }
  }

  void display7SEG2(int num) {
    if (num < 0 || num > 9) return; // Ensure the number is between 0 and 9
    switch (num) {
        case 0:
            HAL_GPIO_WritePin(SEG_0b_GPIO_Port, SEG_0b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1b_GPIO_Port, SEG_1b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2b_GPIO_Port, SEG_2b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3b_GPIO_Port, SEG_3b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4b_GPIO_Port, SEG_4b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_5b_GPIO_Port, SEG_5b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_6b_GPIO_Port, SEG_6b_Pin, GPIO_PIN_SET);
            break;
        case 1:
            HAL_GPIO_WritePin(SEG_0b_GPIO_Port, SEG_0b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_1b_GPIO_Port, SEG_1b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2b_GPIO_Port, SEG_2b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3b_GPIO_Port, SEG_3b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_4b_GPIO_Port, SEG_4b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_5b_GPIO_Port, SEG_5b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_6b_GPIO_Port, SEG_6b_Pin, GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(SEG_0b_GPIO_Port, SEG_0b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1b_GPIO_Port, SEG_1b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2b_GPIO_Port, SEG_2b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_3b_GPIO_Port, SEG_3b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4b_GPIO_Port, SEG_4b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_5b_GPIO_Port, SEG_5b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_6b_GPIO_Port, SEG_6b_Pin, GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(SEG_0b_GPIO_Port, SEG_0b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1b_GPIO_Port, SEG_1b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2b_GPIO_Port, SEG_2b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3b_GPIO_Port, SEG_3b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4b_GPIO_Port, SEG_4b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_5b_GPIO_Port, SEG_5b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_6b_GPIO_Port, SEG_6b_Pin, GPIO_PIN_RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(SEG_0b_GPIO_Port, SEG_0b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_1b_GPIO_Port, SEG_1b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2b_GPIO_Port, SEG_2b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3b_GPIO_Port, SEG_3b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_4b_GPIO_Port, SEG_4b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_5b_GPIO_Port, SEG_5b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_6b_GPIO_Port, SEG_6b_Pin, GPIO_PIN_RESET);
            break;
        case 5:
            HAL_GPIO_WritePin(SEG_0b_GPIO_Port, SEG_0b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1b_GPIO_Port, SEG_1b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_2b_GPIO_Port, SEG_2b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3b_GPIO_Port, SEG_3b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4b_GPIO_Port, SEG_4b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_5b_GPIO_Port, SEG_5b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_6b_GPIO_Port, SEG_6b_Pin, GPIO_PIN_RESET);
            break;
        case 6:
            HAL_GPIO_WritePin(SEG_0b_GPIO_Port, SEG_0b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1b_GPIO_Port, SEG_1b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_2b_GPIO_Port, SEG_2b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3b_GPIO_Port, SEG_3b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4b_GPIO_Port, SEG_4b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_5b_GPIO_Port, SEG_5b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_6b_GPIO_Port, SEG_6b_Pin, GPIO_PIN_RESET);
            break;
        case 7:
            HAL_GPIO_WritePin(SEG_0b_GPIO_Port, SEG_0b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1b_GPIO_Port, SEG_1b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2b_GPIO_Port, SEG_2b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3b_GPIO_Port, SEG_3b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_4b_GPIO_Port, SEG_4b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_5b_GPIO_Port, SEG_5b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_6b_GPIO_Port, SEG_6b_Pin, GPIO_PIN_SET);
            break;
        case 8:
            HAL_GPIO_WritePin(SEG_0b_GPIO_Port, SEG_0b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1b_GPIO_Port, SEG_1b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2b_GPIO_Port, SEG_2b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3b_GPIO_Port, SEG_3b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4b_GPIO_Port, SEG_4b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_5b_GPIO_Port, SEG_5b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_6b_GPIO_Port, SEG_6b_Pin, GPIO_PIN_RESET);
            break;
        case 9:
            HAL_GPIO_WritePin(SEG_0b_GPIO_Port, SEG_0b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_1b_GPIO_Port, SEG_1b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_2b_GPIO_Port, SEG_2b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_3b_GPIO_Port, SEG_3b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_4b_GPIO_Port, SEG_4b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(SEG_5b_GPIO_Port, SEG_5b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(SEG_6b_GPIO_Port, SEG_6b_Pin, GPIO_PIN_RESET);
            break;
        default:
            // Handle invalid input
            break;
    }
  }


void display2DigitNumberWay1(int number) {
    static int digit = 0; // 0 for tens, 1 for units
    static int firstCall = 1; // Track if it's the first call
    if (number < 0 || number > 99) return; // Ensure the number is between 0 and 99

    if (firstCall || timer5_flag == 1) {
        firstCall = 0; // Set to false after the first call
        setTimer5(101); // Reset the timer for multiplexing

        if (number <= 9) {
            // For numbers less than or equal to 9, display the same number on both segments
            HAL_GPIO_WritePin(EN1_1_GPIO_Port, EN1_1_Pin, GPIO_PIN_RESET); // Enable first segment
            HAL_GPIO_WritePin(EN1_2_GPIO_Port, EN1_2_Pin, GPIO_PIN_RESET); // Enable second segment (same digit)
            display7SEG(number); // Display the same number on both segments
        } else {
            if (digit == 0) {
                // Display tens digit
                int tens = number / 10; // Get the tens digit
                HAL_GPIO_WritePin(EN1_1_GPIO_Port, EN1_1_Pin, GPIO_PIN_RESET); // Enable tens
                HAL_GPIO_WritePin(EN1_2_GPIO_Port, EN1_2_Pin, GPIO_PIN_SET);   // Disable units
                display7SEG(tens); // Display the tens digit on the 7-segment
                digit = 1; // Switch to units digit next
            } else {
                // Display units digit
                int units = number % 10; // Get the units digit
                HAL_GPIO_WritePin(EN1_2_GPIO_Port, EN1_2_Pin, GPIO_PIN_RESET); // Enable units
                HAL_GPIO_WritePin(EN1_1_GPIO_Port, EN1_1_Pin, GPIO_PIN_SET);   // Disable tens
                display7SEG(units); // Display the units digit on the 7-segment
                digit = 0; // Switch to tens digit next
            }
        }
    }
}


void display2DigitNumberWay2(int number) {
    static int digit = 0; // 0 for tens, 1 for units
    static int firstCall = 1; // Track if it's the first call
    if (number < 0 || number > 99) return; // Ensure the number is between 0 and 99

    if (firstCall || timer4_flag == 1) {
        firstCall = 0; // Set to false after the first call
        setTimer4(101); // Reset the timer for multiplexing
        
        if (number <= 9) {
            // For numbers less than or equal to 9, display the same number on both segments
            
            HAL_GPIO_WritePin(EN2_1_GPIO_Port, EN2_1_Pin, GPIO_PIN_RESET); // Enable first segment
            HAL_GPIO_WritePin(EN2_2_GPIO_Port, EN2_2_Pin, GPIO_PIN_RESET); // Enable second segment (same digit)
            display7SEG2(number); // Display the same number for both segments
        } else {
            if (digit == 0) {
                // Display tens digit
                int tens = number / 10; // Get the tens digit
                
                HAL_GPIO_WritePin(EN2_1_GPIO_Port, EN2_1_Pin, GPIO_PIN_RESET); // Enable tens
                HAL_GPIO_WritePin(EN2_2_GPIO_Port, EN2_2_Pin, GPIO_PIN_SET);   // Disable units
                display7SEG2(tens); // Display the tens digit on the 7-segment
                digit = 1; // Switch to units digit next
            } else {
                // Display units digit
                int units = number % 10; // Get the units digit

                HAL_GPIO_WritePin(EN2_2_GPIO_Port, EN2_2_Pin, GPIO_PIN_RESET); // Enable units
                HAL_GPIO_WritePin(EN2_1_GPIO_Port, EN2_1_Pin, GPIO_PIN_SET);   // Disable tens
                display7SEG2(units); // Display the units digit on the 7-segment
                digit = 0; // Switch to tens digit next
            }
        }
    }
}

