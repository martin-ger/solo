/*
 * app.h
 *
 *  Created on: Jun 26, 2018
 *      Author: conor
 */

#ifndef SRC_APP_H_
#define SRC_APP_H_

#define DEBUG_LEVEL 1

#define PRINTING_USE_VCOM

#define USING_DEV_BOARD

//#define BRIDGE_TO_WALLET

//#define DISABLE_CTAPHID_PING
//#define DISABLE_CTAPHID_WINK
//#define DISABLE_CTAPHID_CBOR

void printing_init();

#define TEST
#define TEST_POWER

// GPIO assignments
#define NFC_DEV_SS	gpioPortF,2

#endif /* SRC_APP_H_ */