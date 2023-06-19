/*
 * 	File: master.h
 *  Created on: Jun 13, 2023
 *  Author: NGUYEN DINH DIEN
 */

#ifndef INC_MASTER_H_
#define INC_MASTER_H_

#define MOSI 12
#define MISO 11
#define CLK 8
#define SELECT_SERIAL 9

#define MODE_HIGH 1
#define MODE_LOW 0
//
///*
// * Function: digitalWirte
// * Description: set mode in signal pin for port A
// * Input:
// * 	  pinMode - uint8_t
// * 	  value - uint8_t
// * Output:
// * 	  None
// */
//void digitalWirte(uint8_t pinMode, uint8_t value);
//
///*
// * Function: SPIInit
// * Description: init status of signal port
// * Input:
// * 	  None
// * Output:
// * 	  None
// */
//void SPIInit();
//
///*
// * Function: clockSPIGenerate
// * Description: Generate clock for SPI
// * Input:
// * 	  None
// * Output:
// * 	  None
// */
//void clockSPIGenerate();
//
///*
// * Function: SPITransmitData
// * Description: transmit data from master to slave
// * Input:
// * 	  data - uint8_t
// * Output:
// * 	  None
// */
//void SPITransmitData(uint8_t data);
//
///*
// * Function: SPIReceiveData
// * Description: Receive data from slave to master
// * Input:
// * 	  None
// * Output:
// * 	  Return: Rx_data from slave
// */
//uint8_t SPIReceiveData();
///*
// * Function: SPISlaveStatus
// * Description: set status for slave to transmit or receive data
// * Input:
// * 	  mode - uint8_t
// * Output:
// * 	  None
// */
//void SPISlaveStatus(uint8_t mode);
#endif /* INC_MASTER_H_ */
