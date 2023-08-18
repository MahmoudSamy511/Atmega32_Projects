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
-include 2-HAL/DC_Motor/subdir.mk
-include 1-MCAL/WDT/subdir.mk
-include 1-MCAL/Timers/subdir.mk
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
Modified_DashBoard_UsingTimers.lss \

FLASH_IMAGE += \
Modified_DashBoard_UsingTimers.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Modified_DashBoard_UsingTimers.elf secondary-outputs

# Tool invocations
Modified_DashBoard_UsingTimers.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Modified_DashBoard_UsingTimers.map -mmcu=atmega32 -o "Modified_DashBoard_UsingTimers.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Modified_DashBoard_UsingTimers.lss: Modified_DashBoard_UsingTimers.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Modified_DashBoard_UsingTimers.elf  >"Modified_DashBoard_UsingTimers.lss"
	@echo 'Finished building: $@'
	@echo ' '

Modified_DashBoard_UsingTimers.hex: Modified_DashBoard_UsingTimers.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Modified_DashBoard_UsingTimers.elf  "Modified_DashBoard_UsingTimers.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Modified_DashBoard_UsingTimers.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Modified_DashBoard_UsingTimers.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Modified_DashBoard_UsingTimers.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
