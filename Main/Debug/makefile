################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Main.axf

# Tool invocations
Main.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"G:\TD2_UNLaM - Repositorio\Programas\2016\Demo1769_20161024\lib_ModuloSim908\Debug" -L"G:\TD2_UNLaM - Repositorio\Programas\2016\Demo1769_20161024\lpc_board_nxp_lpcxpresso_1769\Debug" -L"G:\TD2_UNLaM - Repositorio\Programas\2016\Demo1769_20161024\lpc_chip_175x_6x\Debug" -Xlinker -Map="Main.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "Main_Debug.ld" -o "Main.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) Main.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Main.axf"; # arm-none-eabi-objcopy -v -O binary "Main.axf" "Main.bin" ; # checksum -p LPC1769 -d "Main.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
