################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../FreeRTOS2/variantHooks.cpp 

C_SRCS += \
../FreeRTOS2/event_groups.c \
../FreeRTOS2/heap_3.c \
../FreeRTOS2/list.c \
../FreeRTOS2/port.c \
../FreeRTOS2/queue.c \
../FreeRTOS2/stream_buffer.c \
../FreeRTOS2/tasks.c \
../FreeRTOS2/timers.c 

C_DEPS += \
./FreeRTOS2/event_groups.d \
./FreeRTOS2/heap_3.d \
./FreeRTOS2/list.d \
./FreeRTOS2/port.d \
./FreeRTOS2/queue.d \
./FreeRTOS2/stream_buffer.d \
./FreeRTOS2/tasks.d \
./FreeRTOS2/timers.d 

OBJS += \
./FreeRTOS2/event_groups.o \
./FreeRTOS2/heap_3.o \
./FreeRTOS2/list.o \
./FreeRTOS2/port.o \
./FreeRTOS2/queue.o \
./FreeRTOS2/stream_buffer.o \
./FreeRTOS2/tasks.o \
./FreeRTOS2/timers.o \
./FreeRTOS2/variantHooks.o 

CPP_DEPS += \
./FreeRTOS2/variantHooks.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS2/%.o: ../FreeRTOS2/%.c FreeRTOS2/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/nico/eclipse-workspace/ArduinoCore" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS2/%.o: ../FreeRTOS2/%.cpp FreeRTOS2/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/nico/eclipse-workspace/ArduinoCore" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


