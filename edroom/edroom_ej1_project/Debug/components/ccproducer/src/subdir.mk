################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/ccproducer/src/CCProducerB.cpp \
../components/ccproducer/src/CCProducerS.cpp 

OBJS += \
./components/ccproducer/src/CCProducerB.o \
./components/ccproducer/src/CCProducerS.o 

CPP_DEPS += \
./components/ccproducer/src/CCProducerB.d \
./components/ccproducer/src/CCProducerS.d 


# Each subdirectory must supply rules for building sources it contributes
components/ccproducer/src/%.o: ../components/ccproducer/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I/opt/rtems-4.6/sparc-rtems/leon3/lib/include -I"/home/cesar/workspace/edroom_ej1_project/dataclasses/CDAux/include" -I"/home/cesar/workspace/edroom_ej1_project/components/ccconsumer/include" -I"/home/cesar/workspace/edroom_ej1_project/components/ccproducer/include" -I"/home/cesar/workspace/edroom_ej1_project/components/example1/include" -I"/home/cesar/workspace/edroom_ej1_project/config/include" -I"/home/cesar/workspace/edroom_ej1_project/edroom_glue/include" -I"/home/cesar/workspace/edroom_ej1_project/edroombp_swr/include" -I"/home/cesar/workspace/edroom_ej1_project/edroomsl_swr/include" -I"/home/cesar/workspace/edroom_ej1_project/edroomsl_types_swr/include" -I"/home/cesar/workspace/edroom_ej1_project/rtems_osswr/include" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


