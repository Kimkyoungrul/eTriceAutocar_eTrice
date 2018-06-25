################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/common/messaging/etMessage.c \
../src/common/messaging/etMessageQueue.c \
../src/common/messaging/etMessageService.c \
../src/common/messaging/etSystemProtocol.c 

OBJS += \
./src/common/messaging/etMessage.o \
./src/common/messaging/etMessageQueue.o \
./src/common/messaging/etMessageService.o \
./src/common/messaging/etSystemProtocol.o 

C_DEPS += \
./src/common/messaging/etMessage.d \
./src/common/messaging/etMessageQueue.d \
./src/common/messaging/etMessageService.d \
./src/common/messaging/etSystemProtocol.d 


# Each subdirectory must supply rules for building sources it contributes
src/common/messaging/%.o: ../src/common/messaging/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\common" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\config" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\util" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\platforms\MT_POSIX_GENERIC_GCC" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


