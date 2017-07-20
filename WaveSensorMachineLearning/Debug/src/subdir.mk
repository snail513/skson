################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/JudgeModel.c \
../src/WaveSensor.c \
../src/WaveSensorMachineLearning.c \
../src/fft.c 

OBJS += \
./src/JudgeModel.o \
./src/WaveSensor.o \
./src/WaveSensorMachineLearning.o \
./src/fft.o 

C_DEPS += \
./src/JudgeModel.d \
./src/WaveSensor.d \
./src/WaveSensorMachineLearning.d \
./src/fft.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


