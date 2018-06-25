################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/platforms/MT_POSIX_GENERIC_GCC/etLogger.c \
../src/platforms/MT_POSIX_GENERIC_GCC/etMutex.c \
../src/platforms/MT_POSIX_GENERIC_GCC/etPlatformLifecycle.c \
../src/platforms/MT_POSIX_GENERIC_GCC/etSema.c \
../src/platforms/MT_POSIX_GENERIC_GCC/etTcpSockets.c \
../src/platforms/MT_POSIX_GENERIC_GCC/etThread.c \
../src/platforms/MT_POSIX_GENERIC_GCC/etTime.c \
../src/platforms/MT_POSIX_GENERIC_GCC/etTimer.c 

OBJS += \
./src/platforms/MT_POSIX_GENERIC_GCC/etLogger.o \
./src/platforms/MT_POSIX_GENERIC_GCC/etMutex.o \
./src/platforms/MT_POSIX_GENERIC_GCC/etPlatformLifecycle.o \
./src/platforms/MT_POSIX_GENERIC_GCC/etSema.o \
./src/platforms/MT_POSIX_GENERIC_GCC/etTcpSockets.o \
./src/platforms/MT_POSIX_GENERIC_GCC/etThread.o \
./src/platforms/MT_POSIX_GENERIC_GCC/etTime.o \
./src/platforms/MT_POSIX_GENERIC_GCC/etTimer.o 

C_DEPS += \
./src/platforms/MT_POSIX_GENERIC_GCC/etLogger.d \
./src/platforms/MT_POSIX_GENERIC_GCC/etMutex.d \
./src/platforms/MT_POSIX_GENERIC_GCC/etPlatformLifecycle.d \
./src/platforms/MT_POSIX_GENERIC_GCC/etSema.d \
./src/platforms/MT_POSIX_GENERIC_GCC/etTcpSockets.d \
./src/platforms/MT_POSIX_GENERIC_GCC/etThread.d \
./src/platforms/MT_POSIX_GENERIC_GCC/etTime.d \
./src/platforms/MT_POSIX_GENERIC_GCC/etTimer.d 


# Each subdirectory must supply rules for building sources it contributes
src/platforms/MT_POSIX_GENERIC_GCC/%.o: ../src/platforms/MT_POSIX_GENERIC_GCC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\common" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\config" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\util" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\platforms\MT_POSIX_GENERIC_GCC" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


