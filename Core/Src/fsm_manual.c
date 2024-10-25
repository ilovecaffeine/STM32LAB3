///*
// * fsm_manual.c
// *
// *  Created on: Oct 19, 2024
// *      Author: admin
// */
//#include "fsm_manual.h"
//
//void fsm_manual_run(){
//
//	switch (status){
//
//		case MAN_RED:
//			HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_RESET);
//
//            if (timer0_flag == 1){
//				status = AUTO_RED_WAY1_GREEN_WAY2;
//				setTimer0(5000);
//			}
//
//			if (isButton1Pressed() == 1){
//				status = MAN_GREEN;
//				setTimer0(10000);
//			}
//			break;
//		case MAN_GREEN:
//			HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_RESET);
//
//            if (timer0_flag == 1){
//				status = AUTO_GREEN_WAY1_RED_WAY2;
//				setTimer0(3000);
//			}
//
//			if (isButton1Pressed() == 1){
//				status = MAN_YELLOW;
//				setTimer0(10000);
//			}
//			break;
//		case MAN_YELLOW:
//			HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_SET);
//
//            if (timer0_flag == 1){
//				status = AUTO_YELLOW_WAY1_RED_WAY2;
//				setTimer0(2000);
//			}
//
//			if (isButton1Pressed() == 1){
//				status = MAN_RED;
//				setTimer0(10000);
//			}
//			break;
//		default:
//
//			break;
//
//	}
//
//
//}
