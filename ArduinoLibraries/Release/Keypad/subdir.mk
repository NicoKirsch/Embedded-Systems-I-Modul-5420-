################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Keypad/Keypad.cpp 

OBJS += \
./Keypad/Keypad.o 

CPP_DEPS += \
./Keypad/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Keypad/%.o: ../Keypad/%.cpp Keypad/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/nico/eclipse-workspace/ArduinoCore" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


