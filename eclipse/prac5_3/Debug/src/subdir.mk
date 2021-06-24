################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/leon3_bprint.c \
../src/leon3_ev_handling.c \
../src/leon3_hw_irqs.c \
../src/leon3_monotonic_clk.c \
../src/leon3_timer_unit_drv.c \
../src/leon3_timing_service_config.c \
../src/leon3_ttre.c \
../src/leon3_uart.c \
../src/prac5_3.c 

S_UPPER_SRCS += \
../src/leon3_ev_handling_asm.S 

OBJS += \
./src/leon3_bprint.o \
./src/leon3_ev_handling.o \
./src/leon3_ev_handling_asm.o \
./src/leon3_hw_irqs.o \
./src/leon3_monotonic_clk.o \
./src/leon3_timer_unit_drv.o \
./src/leon3_timing_service_config.o \
./src/leon3_ttre.o \
./src/leon3_uart.o \
./src/prac5_3.o 

S_UPPER_DEPS += \
./src/leon3_ev_handling_asm.d 

C_DEPS += \
./src/leon3_bprint.d \
./src/leon3_ev_handling.d \
./src/leon3_hw_irqs.d \
./src/leon3_monotonic_clk.d \
./src/leon3_timer_unit_drv.d \
./src/leon3_timing_service_config.d \
./src/leon3_ttre.d \
./src/leon3_uart.d \
./src/prac5_3.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C Compiler'
	sparc-rtems-gcc -I/opt/rtems-4.6/sparc-rtems/leon3/lib/include -I"/home/cesar/workspace/prac5_3/include" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C Compiler'
	sparc-rtems-gcc -I/opt/rtems-4.6/sparc-rtems/leon3/lib/include -I"/home/cesar/workspace/prac5_3/include" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


