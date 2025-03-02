################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PID_v1/PID_v1.cpp 

OBJS += \
./PID_v1/PID_v1.o 

CPP_DEPS += \
./PID_v1/PID_v1.d 


# Each subdirectory must supply rules for building sources it contributes
PID_v1/%.o: ../PID_v1/%.cpp PID_v1/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/nico/eclipse-workspace/ArduinoCore" -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


