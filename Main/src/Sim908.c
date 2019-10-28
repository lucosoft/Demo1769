/*
 * Sim908.c
 *
 *  Created on: 15/1/2016
 *      Author: Cacciola11
 */

#include "Sim908.h"

char gps_buf[GPS_BUF_SIZE];
char IMEI[16] = "";

//char *Start = NULL, *End = NULL;
//char N_GGA[128] = "", N_RMC[128] = "";

int buff = 0, readed = 0;

NMEA NMEA_state = GGA_STATEMENT;

void SIM908_PWR_ON_PIN_INIT() {
#if (defined(BOARD_NXP_XPRESSO_11C24) || defined(BOARD_MCORE48_1125))
	switch (SIM908_PWR_ON_PORT) {
	case 0: {
		switch (SIM908_PWR_ON_BIT) {
		case 1: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_1, IOCON_FUNC0);
			break;
		}
		case 2: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_2, IOCON_FUNC0);
			break;
		}
		case 3: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_3, IOCON_FUNC0);
			break;
		}
		case 4: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_4, IOCON_FUNC0);
			break;
		}
		case 5: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_5, IOCON_FUNC0);
			break;
		}
		case 6: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_6, IOCON_FUNC0);
			break;
		}
		case 7: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_7, IOCON_FUNC0);
			break;
		}
		case 8: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_8, IOCON_FUNC0);
			break;
		}
		case 9: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_9, IOCON_FUNC0);
			break;
		}
		case 11: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_11, IOCON_FUNC1);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 1: {
		switch (SIM908_PWR_ON_BIT) {
		case 0: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_0, IOCON_FUNC1);
			break;
		}
		case 1: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_1, IOCON_FUNC1);
			break;
		}
		case 2: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_2, IOCON_FUNC1);
			break;
		}
		case 4: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_4, IOCON_FUNC0);
			break;
		}
		case 5: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_5, IOCON_FUNC0);
			break;
		}
		case 6: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_6, IOCON_FUNC0);
			break;
		}
		case 7: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_7, IOCON_FUNC0);
			break;
		}
		case 8: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_8, IOCON_FUNC0);
			break;
		}
		case 9: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_9, IOCON_FUNC0);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}

#endif

	Chip_GPIO_SetPinDIR(LPC_GPIO, SIM908_PWR_ON_PORT, SIM908_PWR_ON_BIT, OUTPUT);
}

void SIM908_GSM_SEL_PIN_INIT() {


#if (defined(BOARD_NXP_XPRESSO_11C24) || defined(BOARD_MCORE48_1125))
	switch (SIM908_GSM_SEL_PORT) {
	case 0: {
		switch (SIM908_GSM_SEL_BIT) {
		case 1: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_1, IOCON_FUNC0);
			break;
		}
		case 2: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_2, IOCON_FUNC0);
			break;
		}
		case 3: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_3, IOCON_FUNC0);
			break;
		}
		case 4: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_4, IOCON_FUNC0);
			break;
		}
		case 5: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_5, IOCON_FUNC0);
			break;
		}
		case 6: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_6, IOCON_FUNC0);
			break;
		}
		case 7: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_7, IOCON_FUNC0);
			break;
		}
		case 8: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_8, IOCON_FUNC0);
			break;
		}
		case 9: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_9, IOCON_FUNC0);
			break;
		}
		case 11: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_11, IOCON_FUNC1);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 1: {
		switch (SIM908_GSM_SEL_BIT) {
		case 0: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_0, IOCON_FUNC1);
			break;
		}
		case 1: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_1, IOCON_FUNC1);
			break;
		}
		case 2: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_2, IOCON_FUNC1);
			break;
		}
		case 4: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_4, IOCON_FUNC0);
			break;
		}
		case 5: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_5, IOCON_FUNC0);
			break;
		}
		case 6: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_6, IOCON_FUNC0);
			break;
		}
		case 7: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_7, IOCON_FUNC0);
			break;
		}
		case 8: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_8, IOCON_FUNC0);
			break;
		}
		case 9: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_9, IOCON_FUNC0);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}

#endif

	Chip_GPIO_SetPinDIR(LPC_GPIO, SIM908_GSM_SEL_PORT, SIM908_GSM_SEL_BIT,
			OUTPUT);
}

void SIM908_GPS_SEL_PIN_INIT() {


#if (defined(BOARD_NXP_XPRESSO_11C24) || defined(BOARD_MCORE48_1125))
	switch (SIM908_GPS_SEL_PORT) {
	case 0: {
		switch (SIM908_GPS_SEL_BIT) {
		case 1: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_1, IOCON_FUNC0);
			break;
		}
		case 2: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_2, IOCON_FUNC0);
			break;
		}
		case 3: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_3, IOCON_FUNC0);
			break;
		}
		case 4: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_4, IOCON_FUNC0);
			break;
		}
		case 5: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_5, IOCON_FUNC0);
			break;
		}
		case 6: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_6, IOCON_FUNC0);
			break;
		}
		case 7: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_7, IOCON_FUNC0);
			break;
		}
		case 8: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_8, IOCON_FUNC0);
			break;
		}
		case 9: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_9, IOCON_FUNC0);
			break;
		}
		case 11: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_11, IOCON_FUNC1);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 1: {
		switch (SIM908_GPS_SEL_BIT) {
		case 0: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_0, IOCON_FUNC1);
			break;
		}
		case 1: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_1, IOCON_FUNC1);
			break;
		}
		case 2: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_2, IOCON_FUNC1);
			break;
		}
		case 4: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_4, IOCON_FUNC0);
			break;
		}
		case 5: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_5, IOCON_FUNC0);
			break;
		}
		case 6: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_6, IOCON_FUNC0);
			break;
		}
		case 7: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_7, IOCON_FUNC0);
			break;
		}
		case 8: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_8, IOCON_FUNC0);
			break;
		}
		case 9: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_9, IOCON_FUNC0);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}

#endif

	Chip_GPIO_SetPinDIR(LPC_GPIO, SIM908_GPS_SEL_PORT, SIM908_GPS_SEL_BIT,
			OUTPUT);
}

void LED_GSM_PIN_INIT() {

#if (defined(BOARD_NXP_XPRESSO_11C24) || defined(BOARD_MCORE48_1125))
	switch (LED_GSM_PORT) {
	case 0: {
		switch (LED_GSM_BIT) {
		case 1: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_1, IOCON_FUNC0);
			break;
		}
		case 2: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_2, IOCON_FUNC0);
			break;
		}
		case 3: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_3, IOCON_FUNC0);
			break;
		}
		case 4: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_4, IOCON_FUNC0);
			break;
		}
		case 5: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_5, IOCON_FUNC0);
			break;
		}
		case 6: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_6, IOCON_FUNC0);
			break;
		}
		case 7: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_7, IOCON_FUNC0);
			break;
		}
		case 8: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_8, IOCON_FUNC0);
			break;
		}
		case 9: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_9, IOCON_FUNC0);
			break;
		}
		case 11: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_11, IOCON_FUNC1);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 1: {
		switch (LED_GSM_BIT) {
		case 0: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_0, IOCON_FUNC1);
			break;
		}
		case 1: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_1, IOCON_FUNC1);
			break;
		}
		case 2: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_2, IOCON_FUNC1);
			break;
		}
		case 4: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_4, IOCON_FUNC0);
			break;
		}
		case 5: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_5, IOCON_FUNC0);
			break;
		}
		case 6: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_6, IOCON_FUNC0);
			break;
		}
		case 7: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_7, IOCON_FUNC0);
			break;
		}
		case 8: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_8, IOCON_FUNC0);
			break;
		}
		case 9: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_9, IOCON_FUNC0);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}

#endif

	Chip_GPIO_SetPinDIR(LPC_GPIO, LED_GSM_PORT, LED_GSM_BIT, OUTPUT);
}

void LED_GPS_PIN_INIT() {

#if (defined(BOARD_NXP_XPRESSO_11C24) || defined(BOARD_MCORE48_1125))

	switch (LED_GPS_PORT) {
	case 0: {
		switch (LED_GPS_BIT) {
		case 1: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_1, IOCON_FUNC0);
			break;
		}
		case 2: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_2, IOCON_FUNC0);
			break;
		}
		case 3: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_3, IOCON_FUNC0);
			break;
		}
		case 4: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_4, IOCON_FUNC0);
			break;
		}
		case 5: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_5, IOCON_FUNC0);
			break;
		}
		case 6: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_6, IOCON_FUNC0);
			break;
		}
		case 7: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_7, IOCON_FUNC0);
			break;
		}
		case 8: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_8, IOCON_FUNC0);
			break;
		}
		case 9: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_9, IOCON_FUNC0);
			break;
		}
		case 11: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_11, IOCON_FUNC1);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 1: {
		switch (LED_GPS_BIT) {
		case 0: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_0, IOCON_FUNC1);
			break;
		}
		case 1: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_1, IOCON_FUNC1);
			break;
		}
		case 2: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_2, IOCON_FUNC1);
			break;
		}
		case 4: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_4, IOCON_FUNC0);
			break;
		}
		case 5: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_5, IOCON_FUNC0);
			break;
		}
		case 6: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_6, IOCON_FUNC0);
			break;
		}
		case 7: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_7, IOCON_FUNC0);
			break;
		}
		case 8: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_8, IOCON_FUNC0);
			break;
		}
		case 9: {
			Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_9, IOCON_FUNC0);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}



#endif

	Chip_GPIO_SetPinDIR(LPC_GPIO, LED_GPS_PORT, LED_GPS_BIT, OUTPUT);
}

void SIM_GPIO_Init() {

// SIM
	SIM908_PWR_ON_PIN_INIT();
// GSM
	SIM908_GSM_SEL_PIN_INIT();
// GPS
	SIM908_GPS_SEL_PIN_INIT();
// LED GSM
	LED_GSM_PIN_INIT();
// LED GPS
	LED_GPS_PIN_INIT();
// ENTRADAS
//	Chip_GPIO_SetPinDIR(LPC_GPIO, LPC_IN1_PORT, LPC_IN1_BIT, INPUT);
//	Chip_GPIO_SetPinDIR(LPC_GPIO, LPC_IN2_PORT, LPC_IN2_BIT, INPUT);
//	Chip_GPIO_SetPinDIR(LPC_GPIO, LPC_IN3_PORT, LPC_IN3_BIT, INPUT);
//	Chip_GPIO_SetPinDIR(LPC_GPIO, LPC_IN4_PORT, LPC_IN4_BIT, INPUT);
//SALIDAS
//	Chip_GPIO_SetPinDIR(LPC_GPIO, LPC_OUT1_PORT, LPC_OUT1_BIT, OUTPUT);
//	Chip_GPIO_SetPinDIR(LPC_GPIO, LPC_OUT2_PORT, LPC_OUT2_BIT, OUTPUT);
//	Chip_GPIO_SetPinDIR(LPC_GPIO, LPC_OUT3_PORT, LPC_OUT3_BIT, OUTPUT);
}

// Pines del SIM
void Sim_ON() {
	Chip_GPIO_WritePortBit(LPC_GPIO, SIM908_PWR_ON_PORT, SIM908_PWR_ON_BIT, 0);
}
void Sim_OFF() {
	Chip_GPIO_WritePortBit(LPC_GPIO, SIM908_PWR_ON_PORT, SIM908_PWR_ON_BIT, 1);
}

void gps_enable() {
	Chip_GPIO_WritePortBit(LPC_GPIO, SIM908_GPS_SEL_PORT, SIM908_GPS_SEL_BIT,
			0);
}
void gps_disable() {
	Chip_GPIO_WritePortBit(LPC_GPIO, SIM908_GPS_SEL_PORT, SIM908_GPS_SEL_BIT,
			1);
}

void gsm_enable() {
	Chip_GPIO_WritePortBit(LPC_GPIO, SIM908_GSM_SEL_PORT, SIM908_GSM_SEL_BIT,
			0);
}
void gsm_disable() {
	Chip_GPIO_WritePortBit(LPC_GPIO, SIM908_GSM_SEL_PORT, SIM908_GSM_SEL_BIT,
			1);
}

//LEDs
void LED_GSM_OFF() {
	Chip_GPIO_WritePortBit(LPC_GPIO, LED_GSM_PORT, LED_GSM_BIT, 1);
}
void LED_GSM_ON() {
	Chip_GPIO_WritePortBit(LPC_GPIO, LED_GSM_PORT, LED_GSM_BIT, 0);
}
void LED_GSM_TOGGLE() {
	Chip_GPIO_WritePortBit(LPC_GPIO, LED_GSM_PORT, LED_GSM_BIT,
			!Chip_GPIO_ReadPortBit(LPC_GPIO, LED_GSM_PORT, LED_GSM_BIT));
}

void LED_GPS_OFF() {
	Chip_GPIO_WritePortBit(LPC_GPIO, LED_GPS_PORT, LED_GPS_BIT, 1);
}
void LED_GPS_ON() {
	Chip_GPIO_WritePortBit(LPC_GPIO, LED_GPS_PORT, LED_GPS_BIT, 0);
}
void LED_GPS_TOGGLE() {
	Chip_GPIO_WritePortBit(LPC_GPIO, LED_GPS_PORT, LED_GPS_BIT,
			!Chip_GPIO_ReadPortBit(LPC_GPIO, LED_GPS_PORT,
			LED_GPS_BIT));
}

bool AT_Response(AT_RESPONSES expected) {
	char substr[10] = "";
	char *Start = NULL;//, *End = NULL;
	int val = 0;
	strncpy(substr, "", 10);
	readed = UART_Read(&gps_buf[buff], GPS_BUF_SIZE);

	if (strlen(gps_buf) > 2) {
		switch (expected) {
		case AT_OK: {
			Start = NULL;
			if ((Start = strstr(gps_buf, "OK\r\n")) != NULL) {
				buff = 0;
				strncpy(gps_buf, "", GPS_BUF_SIZE);
				return (true);
			}
			break;
		}
		case AT_ERROR: {
			Start = NULL;
			if ((Start = strstr(gps_buf, "ERROR\r\n")) != NULL) {
				buff = 0;
				strncpy(gps_buf, "", GPS_BUF_SIZE);
				return (true);
			}
			break;
		}
		case AT_GPS_READY: {
			Start = NULL;
			if ((Start = strstr(gps_buf, "GPS Ready\r\n")) != NULL) {
				buff = 0;
				strncpy(gps_buf, "", GPS_BUF_SIZE);
				return (true);
			}
			break;
		}
		case AT_POWER_DOWN: {
			Start = NULL;
			if ((Start = strstr(gps_buf, "NORMAL POWER DOWN\r\n")) != NULL) {
				buff = 0;
				strncpy(gps_buf, "", GPS_BUF_SIZE);
				return (true);
			}
			break;
		}
		case AT_CPIN_READY: {
			Start = NULL;
			if ((Start = strstr(gps_buf, "+CPIN: READY\r\n\r\nOK\r\n"))
					!= NULL) {
				buff = 0;
				strncpy(gps_buf, "", GPS_BUF_SIZE);
				return (true);
			}
			break;
		}
		case AT_REGISTER_OK: {
			Start = NULL;
			if (strstr(gps_buf, "OK\r\n") != NULL) {
				if ((Start = strstr(gps_buf, "+CREG: 0,1")) != NULL) {
					buff = 0;
					strncpy(gps_buf, "", GPS_BUF_SIZE);
					return (true);
				}
			}
			break;
		}
		case AT_REGISTER_SEARCHING: {
			Start = NULL;
			if (strstr(gps_buf, "OK\r\n") != NULL) {
				if ((Start = strstr(gps_buf, "+CREG: 0,2")) != NULL) {
					buff = 0;
					strncpy(gps_buf, "", GPS_BUF_SIZE);
					return (true);
				}
			}
			break;
		}
		case AT_SIGNAL: {
			Start = NULL;
			if (strstr(gps_buf, "OK\r\n") != NULL) {
				if (strstr(gps_buf, "+CSQ:") != NULL) {
					Start = strpbrk(gps_buf, "1234567890");
					strncpy(substr, Start, strcspn(Start, ","));
					val = atoi(substr);
					if (val >= GSM_SIGNAL) {
						buff = 0;
						strncpy(gps_buf, "", GPS_BUF_SIZE);
						return (true);
					}
				}
			}
			break;
		}
		case AT_SERIAL: {
			strncpy(IMEI, "", 14);
			Start = NULL;
			if (strstr(gps_buf, "OK\r\n")) {
				if ((Start = strstr(gps_buf, "+CGSN")) != NULL) {
					Start = strpbrk(gps_buf, "1234567890");
					strncpy(IMEI, Start, 15);
					if (atol(IMEI) != 0) {
						buff = 0;
						strncpy(gps_buf, "", GPS_BUF_SIZE);
						return (true);
					}
				}
			}
			break;
		}
		case AT_CURSOR: {
			if (strstr(gps_buf, "> ")) {
				buff = 0;
				strncpy(gps_buf, "", GPS_BUF_SIZE);
				return (true);
			}
			break;
		}
		case AT_SEND: {
			Start = NULL;
			if ((Start = strstr(gps_buf, "SEND OK\r\n")) != NULL) {
				buff = 0;
				strncpy(gps_buf, "", GPS_BUF_SIZE);
				return (true);
			}
			break;
		}
		case AT_CONECT_OK: {
			Start = NULL;
			if ((Start = strstr(gps_buf, "CONNECT OK\r\n")) != NULL) {
				buff = 0;
				strncpy(gps_buf, "", GPS_BUF_SIZE);
				return (true);
			}

			break;
		}
		case AT_CONECT_FAIL: {
			Start = NULL;
			if ((Start = strstr(gps_buf, "CONNECT FAIL\r\n")) != NULL) {
				buff = 0;
				strncpy(gps_buf, "", GPS_BUF_SIZE);
				return (true);
			}
			break;
		}
		case AT_RECEIVE: {
			Start = NULL;
			if ((Start = strstr(gps_buf, "+CIPRXGET:")) != NULL) {
				if (strstr(gps_buf, "OK\r\n") != NULL) {
					if ((Start = strstr(Start, ",")) != NULL)
						if (!memcmp(Start + 1, "15", 2)) {
							if ((Start = strstr(Start, "\n")) != NULL)
								if (!memcmp(Start + 1, IMEI, 15)) {
									buff = 0;
									strncpy(gps_buf, "", GPS_BUF_SIZE);
									return (true);
								}
						}
				}
			}
			break;
		}
		case AT_CLOSE: {
			Start = NULL;
			if ((Start = strstr(gps_buf, "CLOSE OK\r\n")) != NULL) {
				buff = 0;
				strncpy(gps_buf, "", GPS_BUF_SIZE);
				return (true);
			}
			break;
		}
		case AT_CIPRXGET: {
			Start = NULL;
			if ((Start = strstr(gps_buf, "CIPRXGET:1\r\n")) != NULL) {
				buff = 0;
				strncpy(gps_buf, "", GPS_BUF_SIZE);
				return (true);
			}
			break;
		}
		default:
			break;
		}
	}
	buff += readed;
	if (buff > 0) {
	}
	return (false);
}

bool NMEA_get(char *N_GGA, char *N_RMC) {
	char *Start = NULL, *End = NULL;
	readed = UART_Read(&gps_buf[buff], GPS_BUF_SIZE);

	if (readed > 0) {

		if ((Start = strstr(gps_buf, "*")) != NULL)
			if ((Start = strstr(Start + 1, "*")) != NULL)
				if ((Start = strstr(Start + 1, "\r\n")) != NULL)
					if ((Start = strstr(Start + 1, "\r\n")) != NULL) {

						Start = NULL;
						End = NULL;
						if ((Start = strstr(gps_buf, "$GPGGA")) != NULL)
							if ((End = strstr(Start, "\r\n")) != NULL)
								strncpy(N_GGA, Start, (End - Start));

						Start = NULL;
						End = NULL;
						if ((Start = strstr(gps_buf, "$GPRMC")) != NULL)
							if ((End = strstr(Start, "\r\n")) != NULL)
								strncpy(N_RMC, Start, (End - Start));

						buff = 0;
						strncpy(gps_buf, "", GPS_BUF_SIZE);
						return (true);
					}
		buff += readed;
	}
	return (false);
}

bool NMEA_get_gsm(uint8_t statement_NMEA, char* NMEA_Obtained) {
	bool done = false;
	char *Start = NULL, *End = NULL;
//	readed = UART_Read(&gps_buf[buff], GPS_BUF_SIZE);
	readed = UART_Read(&gps_buf, GPS_BUF_SIZE);

	if (statement_NMEA != GGA && statement_NMEA != RMC) {
		statement_NMEA = 0;
	}

	if (readed > 0) {
		switch (statement_NMEA) {
		case GGA: {
			Start = NULL;
			End = NULL;
			if ((Start = strstr(gps_buf, "+CGPSINF=2\r\n")) != NULL) {
				if ((End = strstr(Start, "OK\r\n")) != NULL) {
					strncpy(NMEA_Obtained, Start, (End - Start));
					done = true;
				}
			}
			break;
		}

		case RMC: {
			Start = NULL;
			End = NULL;
			if ((Start = strstr(gps_buf, "AT+CGPSINF=32\r\n")) != NULL) {
				if ((End = strstr(Start, "OK\r\n")) != NULL) {
					strncpy(NMEA_Obtained, Start, (End - Start));
					done = true;
				}
			}
			break;
		}
		default:
			break;
		}
		buff += readed;

		if (done) {
			buff = 0;
			strncpy(gps_buf, "", GPS_BUF_SIZE);
			return (true);
		}
	}
	return (false);
}
