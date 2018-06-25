################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src-gen/room/basic/service/pinterrupt/PInterrupt.c 

OBJS += \
./src-gen/room/basic/service/pinterrupt/PInterrupt.o 

C_DEPS += \
./src-gen/room/basic/service/pinterrupt/PInterrupt.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/room/basic/service/pinterrupt/%.o: ../src-gen/room/basic/service/pinterrupt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\common" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\config" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\platforms\MT_POSIX_GENERIC_GCC" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\util" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.modellib.c\src-gen" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


