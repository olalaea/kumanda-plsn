################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/system_stm32f4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32f4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32f4xx.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/system_stm32f4xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT�$@� -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


