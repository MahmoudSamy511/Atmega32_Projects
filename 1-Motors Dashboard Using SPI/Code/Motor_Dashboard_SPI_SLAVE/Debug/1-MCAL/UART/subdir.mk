################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../1-MCAL/UART/UART_Program.c 

OBJS += \
./1-MCAL/UART/UART_Program.o 

C_DEPS += \
./1-MCAL/UART/UART_Program.d 


# Each subdirectory must supply rules for building sources it contributes
1-MCAL/UART/%.o: ../1-MCAL/UART/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


