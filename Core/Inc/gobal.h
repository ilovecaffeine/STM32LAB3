/*
 * gobal.h
 *
 *  Created on: Oct 19, 2024
 *      Author: admin
 */

#ifndef INC_GOBAL_H_
#define INC_GOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
// #include "fsm_select_mode.h"
#include "7Segs.h"


#define INIT_1 0
#define AUTO_RED_WAY1 1
#define AUTO_GREEN_WAY1 2
#define AUTO_YELLOW_WAY1 3

#define INIT_2 4
#define AUTO_RED_WAY2 5
#define AUTO_GREEN_WAY2 6
#define AUTO_YELLOW_WAY2 7

#define INIT_mode 10
#define SELECT_MODE_1 11
#define SELECT_MODE_2 12
#define SELECT_MODE_3 13
#define SELECT_MODE_4 14

#define MAN_RED 12
#define MAN_GREEN 13
#define MAN_YELLOW 14

extern int status_way1;
extern int status_way2;
extern int red_led_duration;
extern int green_led_duration;
extern int yellow_led_duration;

#endif /* INC_GOBAL_H_ */
