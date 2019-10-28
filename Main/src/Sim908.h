/*
 * Sim908.h
 *
 *  Created on: 15/1/2016
 *      Author: Cacciola11
 */

#include <stdlib.h>
#include "chip.h"
#include "board.h"
#include "string.h"
#include "UART.h"


#ifndef SIM908_H_
#define SIM908_H_

//#define SIM908_PWR_ON_PORT	00
//#define SIM908_PWR_ON_BIT	01
//
//#define SIM908_GSM_SEL_PORT	00
//#define SIM908_GSM_SEL_BIT	02
//
//#define SIM908_GPS_SEL_PORT	00
//#define SIM908_GPS_SEL_BIT	03

// LPC1114
//#define SIM908_PWR_ON_PORT	1
//#define SIM908_PWR_ON_BIT	2
//
//#define SIM908_GSM_SEL_PORT	1
//#define SIM908_GSM_SEL_BIT	4
//
//#define SIM908_GPS_SEL_PORT	1
//#define SIM908_GPS_SEL_BIT	5

// LPC1769
#define SIM908_PWR_ON_PORT	2
#define SIM908_PWR_ON_BIT	2

#define SIM908_GSM_SEL_PORT	2
#define SIM908_GSM_SEL_BIT	3

#define SIM908_GPS_SEL_PORT	2
#define SIM908_GPS_SEL_BIT	4



//Puertos de LEDs

//LPC1114
//#define LED_GSM_PORT	01
//#define LED_GSM_BIT		00
//
//#define LED_GPS_PORT	01
//#define LED_GPS_BIT		01

//LPC1769
#define LED_GSM_PORT	2
#define LED_GSM_BIT		10

#define LED_GPS_PORT	2
#define LED_GPS_BIT		11

#define OUTPUT	true
#define INPUT 	false

#define GPS_BUF_SIZE        1024
#define GSM_SIGNAL          10

#define GGA     2
#define RMC     32


typedef enum {
	RMC_STATEMENT,
	GGA_STATEMENT,
	DONE,
} NMEA;

typedef enum {
	AT_OK,
	AT_ERROR,
	AT_GPS_READY,
	AT_POWER_DOWN,
	AT_CPIN_READY,
	AT_REGISTER_OK,
	AT_REGISTER_SEARCHING,
	AT_SIGNAL,
	AT_SERIAL,
	AT_CURSOR,
	AT_SEND,
	AT_CONECT_OK,
	AT_CONECT_FAIL,
	AT_RECEIVE,
	AT_CLOSE,
	AT_CIPRXGET,

} AT_RESPONSES;

/**
 * @brief	Inicializa la funcion y direccion del bit SIM908_PWR_ON
 * @return	None
 */
void SIM908_PWR_ON_PIN_INIT();

/**
 * @brief	Inicializa la funcion y direccion del bit SIM908_GSM_SEL
 * @return	None
 */
void SIM908_GSM_SEL_PIN_INIT();

/**
 * @brief	Inicializa la funcion y direccion del bit SIM908_GPS_SEL
 * @return	None
 */
void SIM908_GPS_SEL_PIN_INIT();

/**
 * @brief	Inicializa la funcion y direccion del bit LED_GSM
 * @return	None
 */
void LED_GSM_PIN_INIT();

/**
 * @brief	Inicializa la funcion y direccion del bit LED_GPS
 * @return	None
 */
void LED_GPS_PIN_INIT();

/**
 * @brief	Inicializa los pines necesarios para el funcionamiento del modulo
 * @return	None
 */
void SIM_GPIO_Init();


/**
 * @brief	LLeva a nivel bajo el pin SIM908_PWR_ON
 * @return	None
 */
void Sim_ON();

/**
 * @brief	LLeva a nivel alto el pin SIM908_PWR_ON
 * @return	None
 */
void Sim_OFF();


/**
 * @brief	LLeva a nivel bajo el pin SIM908_GPS_SEL
 * @return	None
 */
void gps_enable();

/**
 * @brief	LLeva a nivel alto el pin SIM908_GPS_SEL
 * @return	None
 */
void gps_disable();


/**
 * @brief	LLeva a nivel alto el pin SIM908_GSM_SEL
 * @return	None
 */
void gsm_enable();

/**
 * @brief	LLeva a nivel alto el pin SIM908_GSM_SEL
 * @return	None
 */
void gsm_disable();


/**
 * @brief	Enciende el led de GSM
 * @return	None
 */
void LED_GSM_ON();

/**
 * @brief	Apaga el led de GSM
 * @return	None
 */
void LED_GSM_OFF();

/**
 * @brief	togglea el led de GSM
 * @return	None
 */
void LED_GSM_TOGGLE();


/**
 * @brief	Enciende el led de GPS
 * @return	None
 */
void LED_GPS_ON();

/**
 * @brief	Enciende el led de GPS
 * @return	None
 */
void LED_GPS_OFF();

/**
 * @brief	Enciende el led de GPS
 * @return	None
 */
void LED_GPS_TOGGLE();


/**
 * @brief	Verifica que en el buffer de la UART se encuentre el comnado expected
 * @param	expected	: Comando que se espera recibir
 * @return	true		: El comando expected se recibio
 * 			false		: El comando expected no se encontro en el buffer
 */
bool AT_Response(AT_RESPONSES expected);

/**
 * @brief	Lee la UART y separa las tramas NMEA en los vectores NMEA_GGA y NMEA_RMC (Solo para UART GPS)
 * @param	NMEA_GGA	: Puntero a un vector donde se guardara la trama GGA
 * @param	NMEA_RMC	: Puntero a un vector donde se guardara la trama RMC
 * @return	true		: Las tramas fueron separadas correctamente
 * 			false		: Las tramas no se encuentran en el buffer de la UART, o no se pudieron separar correctamente
 */
bool NMEA_get(char* NMEA_GGA,char* NMEA_RMC);

/**
 * @brief	Lee la UART y guarda la trama deseada (StatmentToGet) en el vector NMEA
 * @param	StatmentToGet	: Trama que se desea Obtener. GGA o RMC
 * @param	NMEA			: Puntero a un vector donde se guardara la trama RMC
 * @return	true			: La tramas fue leida y copiada correctamente
 * 			false			: La trama no se encuentra en el buffer de la UART, o no se pudo copiar correctamente
 */
bool NMEA_get_gsm(uint8_t StatmentToGet,char *NMEA );

#endif /* SIM908_H_ */
