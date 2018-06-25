################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src-gen/room/basic/service/tcp/ATcpClient.c \
../src-gen/room/basic/service/tcp/ATcpServer.c \
../src-gen/room/basic/service/tcp/DTcpControl.c \
../src-gen/room/basic/service/tcp/DTcpPayload.c \
../src-gen/room/basic/service/tcp/PTcpControl.c \
../src-gen/room/basic/service/tcp/PTcpPayload.c 

OBJS += \
./src-gen/room/basic/service/tcp/ATcpClient.o \
./src-gen/room/basic/service/tcp/ATcpServer.o \
./src-gen/room/basic/service/tcp/DTcpControl.o \
./src-gen/room/basic/service/tcp/DTcpPayload.o \
./src-gen/room/basic/service/tcp/PTcpControl.o \
./src-gen/room/basic/service/tcp/PTcpPayload.o 

C_DEPS += \
./src-gen/room/basic/service/tcp/ATcpClient.d \
./src-gen/room/basic/service/tcp/ATcpServer.d \
./src-gen/room/basic/service/tcp/DTcpControl.d \
./src-gen/room/basic/service/tcp/DTcpPayload.d \
./src-gen/room/basic/service/tcp/PTcpControl.d \
./src-gen/room/basic/service/tcp/PTcpPayload.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/room/basic/service/tcp/%.o: ../src-gen/room/basic/service/tcp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\common" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\config" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\platforms\MT_POSIX_GENERIC_GCC" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.runtime.c\src\util" -I"C:\Users\kyoung\workspace\org.eclipse.etrice.modellib.c\src-gen" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


