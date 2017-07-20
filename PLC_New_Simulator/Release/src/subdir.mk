################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/PLC_Device.c \
../src/PLC_DeviceExecutor.c \
../src/PLC_DeviceStack.c \
../src/PLC_ExecFunctions.c \
../src/PLC_IL_Task.c \
../src/PLC_InterruptionModule.c \
../src/PLC_ListOfTestSuite.c \
../src/PLC_Log.c \
../src/PLC_NEW_Simulator.c \
../src/PLC_Operand.c \
../src/PLC_OperandDictionary.c \
../src/PLC_Operator.c \
../src/PLC_OperatorDictionary.c \
../src/PLC_Point.c \
../src/PLC_PointTable.c \
../src/PLC_PreExecFunctions.c \
../src/PLC_Register.c \
../src/PLC_Register_Log.c 

OBJS += \
./src/PLC_Device.o \
./src/PLC_DeviceExecutor.o \
./src/PLC_DeviceStack.o \
./src/PLC_ExecFunctions.o \
./src/PLC_IL_Task.o \
./src/PLC_InterruptionModule.o \
./src/PLC_ListOfTestSuite.o \
./src/PLC_Log.o \
./src/PLC_NEW_Simulator.o \
./src/PLC_Operand.o \
./src/PLC_OperandDictionary.o \
./src/PLC_Operator.o \
./src/PLC_OperatorDictionary.o \
./src/PLC_Point.o \
./src/PLC_PointTable.o \
./src/PLC_PreExecFunctions.o \
./src/PLC_Register.o \
./src/PLC_Register_Log.o 

C_DEPS += \
./src/PLC_Device.d \
./src/PLC_DeviceExecutor.d \
./src/PLC_DeviceStack.d \
./src/PLC_ExecFunctions.d \
./src/PLC_IL_Task.d \
./src/PLC_InterruptionModule.d \
./src/PLC_ListOfTestSuite.d \
./src/PLC_Log.d \
./src/PLC_NEW_Simulator.d \
./src/PLC_Operand.d \
./src/PLC_OperandDictionary.d \
./src/PLC_Operator.d \
./src/PLC_OperatorDictionary.d \
./src/PLC_Point.d \
./src/PLC_PointTable.d \
./src/PLC_PreExecFunctions.d \
./src/PLC_Register.d \
./src/PLC_Register_Log.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-linux-gnueabi-gcc-4.7 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


