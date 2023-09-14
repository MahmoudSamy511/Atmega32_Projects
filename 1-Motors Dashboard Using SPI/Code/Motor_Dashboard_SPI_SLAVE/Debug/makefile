################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 4-APP/subdir.mk
-include 2-HAL/Switch/subdir.mk
-include 2-HAL/Stepper_Motor/subdir.mk
-include 2-HAL/SevenSegment/subdir.mk
-include 2-HAL/Servo_Motor/subdir.mk
-include 2-HAL/LCD/subdir.mk
-include 2-HAL/Keypad/subdir.mk
-include 2-HAL/EEPROM/subdir.mk
-include 2-HAL/DC_Motor/subdir.mk
-include 1-MCAL/WDT/subdir.mk
-include 1-MCAL/UART/subdir.mk
-include 1-MCAL/Timers/subdir.mk
-include 1-MCAL/SPI/subdir.mk
-include 1-MCAL/I2C/subdir.mk
-include 1-MCAL/GI/subdir.mk
-include 1-MCAL/EXTI/subdir.mk
-include 1-MCAL/DIO/subdir.mk
-include 1-MCAL/ADC/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Motor_Dashboard_SPI_SLAVE.lss \

FLASH_IMAGE += \
Motor_Dashboard_SPI_SLAVE.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Motor_Dashboard_SPI_SLAVE.elf secondary-outputs

# Tool invocations
Motor_Dashboard_SPI_SLAVE.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Motor_Dashboard_SPI_SLAVE.map -mmcu=atmega32 -o "Motor_Dashboard_SPI_SLAVE.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Motor_Dashboard_SPI_SLAVE.lss: Motor_Dashboard_SPI_SLAVE.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Motor_Dashboard_SPI_SLAVE.elf  >"Motor_Dashboard_SPI_SLAVE.lss"
	@echo 'Finished building: $@'
	@echo ' '

Motor_Dashboard_SPI_SLAVE.hex: Motor_Dashboard_SPI_SLAVE.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Motor_Dashboard_SPI_SLAVE.elf  "Motor_Dashboard_SPI_SLAVE.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Motor_Dashboard_SPI_SLAVE.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Motor_Dashboard_SPI_SLAVE.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Motor_Dashboard_SPI_SLAVE.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
