################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/common/modelbase/etActor.c \
../src/common/modelbase/etPort.c 

OBJS += \
./src/common/modelbase/etActor.o \
./src/common/modelbase/etPort.o 

C_DEPS += \
./src/common/modelbase/etActor.d \
./src/common/modelbase/etPort.d 


# Each subdirectory must supply rules for building sources it contributes
src/common/modelbase/%.o: ../src/common/modelbase/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\common" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\config" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\util" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\platforms\MT_POSIX_GENERIC_GCC" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


