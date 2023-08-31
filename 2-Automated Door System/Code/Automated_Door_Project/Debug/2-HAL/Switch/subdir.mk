################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../2-HAL/Switch/Switcg_Config.c \
../2-HAL/Switch/Switch_Program.c 

OBJS += \
./2-HAL/Switch/Switcg_Config.o \
./2-HAL/Switch/Switch_Program.o 

C_DEPS += \
./2-HAL/Switch/Switcg_Config.d \
./2-HAL/Switch/Switch_Program.d 


# Each subdirectory must supply rules for building sources it contributes
2-HAL/Switch/%.o: ../2-HAL/Switch/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g3 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


