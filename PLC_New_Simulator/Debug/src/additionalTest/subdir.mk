################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/additionalTest/AT_SpecialTest.c \
../src/additionalTest/AT_Srch.c \
../src/additionalTest/AddTest.c 

OBJS += \
./src/additionalTest/AT_SpecialTest.o \
./src/additionalTest/AT_Srch.o \
./src/additionalTest/AddTest.o 

C_DEPS += \
./src/additionalTest/AT_SpecialTest.d \
./src/additionalTest/AT_Srch.d \
./src/additionalTest/AddTest.d 


# Each subdirectory must supply rules for building sources it contributes
src/additionalTest/%.o: ../src/additionalTest/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DUSE_CUNIT_TEST_DEF -DUSE_CUNIT_DEF -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


