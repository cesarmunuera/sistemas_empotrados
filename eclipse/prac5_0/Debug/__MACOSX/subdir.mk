################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../__MACOSX/._prac5_0.c 

OBJS += \
./__MACOSX/._prac5_0.o 

C_DEPS += \
./__MACOSX/._prac5_0.d 


# Each subdirectory must supply rules for building sources it contributes
__MACOSX/%.o: ../__MACOSX/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C Compiler'
	sparc-rtems-gcc -I/opt/rtems-4.6/sparc-rtems/leon3/lib/include -I"/home/cesar/workspace/prac5_0" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


