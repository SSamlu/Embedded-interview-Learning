/*
 * 	File: slave.h
 *  Created on: Jun 13, 2023
 *  Author: NGUYEN DINH DIEN
 */

#ifndef INC_SLAVE_H_
#define INC_SLAVE_H_

#define MOSI 4
#define MISO 5
#define CLK 7
#define SELECT_SERIAL 6

// #define MODE_HIGH 1
// #define MODE_LOW 0

if(CLK == MODE_HIGH) {
  HAL_GPIO_ReadPin(GPIOA, MOSI);
}

#endif /* INC_SLAVE_H_ */
