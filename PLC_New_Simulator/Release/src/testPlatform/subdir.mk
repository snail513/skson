################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/testPlatform/PLC_Platform.c 

OBJS += \
./src/testPlatform/PLC_Platform.o 

C_DEPS += \
./src/testPlatform/PLC_Platform.d 


# Each subdirectory must supply rules for building sources it contributes
src/testPlatform/%.o: ../src/testPlatform/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-linux-gnueabi-gcc-4.7 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


