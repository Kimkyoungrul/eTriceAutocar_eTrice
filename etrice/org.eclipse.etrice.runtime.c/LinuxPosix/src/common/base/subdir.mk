################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/common/base/etMemory_FixedSize.c \
../src/common/base/etMemory_FreeList.c \
../src/common/base/etQueue.c 

OBJS += \
./src/common/base/etMemory_FixedSize.o \
./src/common/base/etMemory_FreeList.o \
./src/common/base/etQueue.o 

C_DEPS += \
./src/common/base/etMemory_FixedSize.d \
./src/common/base/etMemory_FreeList.d \
./src/common/base/etQueue.d 


# Each subdirectory must supply rules for building sources it contributes
src/common/base/%.o: ../src/common/base/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\common" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\config" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\util" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\platforms\MT_POSIX_GENERIC_GCC" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


