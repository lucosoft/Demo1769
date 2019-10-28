################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LCD.c \
../src/LED.c \
../src/Pulsador.c \
../src/RTC.c \
../src/UART.c 

OBJS += \
./src/LCD.o \
./src/LED.o \
./src/Pulsador.o \
./src/RTC.o \
./src/UART.o 

C_DEPS += \
./src/LCD.d \
./src/LED.d \
./src/Pulsador.d \
./src/RTC.d \
./src/UART.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_LPCOPEN -D__LPC17XX__ -I"G:\TD2_UNLaM - Repositorio\Programas\2016\Demo1769_20161024\lib_ModuloSim908\inc" -I"G:\TD2_UNLaM - Repositorio\Programas\2016\Demo1769_20161024\lpc_board_nxp_lpcxpresso_1769\inc" -I"G:\TD2_UNLaM - Repositorio\Programas\2016\Demo1769_20161024\lpc_chip_175x_6x\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


