################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../edroomsl_types_swr/src/edroomsl_types.cpp 

OBJS += \
./edroomsl_types_swr/src/edroomsl_types.o 

CPP_DEPS += \
./edroomsl_types_swr/src/edroomsl_types.d 


# Each subdirectory must supply rules for building sources it contributes
edroomsl_types_swr/src/%.o: ../edroomsl_types_swr/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"/home/osboxes/workspace/edroom_ej2_project/components/example2/include" -I/opt/rtems-4.6/sparc-rtems/leon3/lib/include -I"/home/osboxes/workspace/edroom_ej2_project/components/ccserver/include" -I"/home/osboxes/workspace/edroom_ej2_project/components/ccclient/include" -I"/home/osboxes/workspace/edroom_ej2_project/config/include" -I"/home/osboxes/workspace/edroom_ej2_project/edroom_glue/include" -I"/home/osboxes/workspace/edroom_ej2_project/edroombp_swr/include" -I"/home/osboxes/workspace/edroom_ej2_project/edroomsl_swr/include" -I"/home/osboxes/workspace/edroom_ej2_project/edroomsl_types_swr/include" -I"/home/osboxes/workspace/edroom_ej2_project/rtems_osswr/include" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


