################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/app_ethernet.c \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/can.c \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/definition.c \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/ethernetif.c \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/main.c \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/stm32f4xx_it.c \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/udp_echoserver.c 

OBJS += \
./Application/User/app_ethernet.o \
./Application/User/can.o \
./Application/User/definition.o \
./Application/User/ethernetif.o \
./Application/User/main.o \
./Application/User/stm32f4xx_it.o \
./Application/User/udp_echoserver.o 

C_DEPS += \
./Application/User/app_ethernet.d \
./Application/User/can.d \
./Application/User/definition.d \
./Application/User/ethernetif.d \
./Application/User/main.d \
./Application/User/stm32f4xx_it.d \
./Application/User/udp_echoserver.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/app_ethernet.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/app_ethernet.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/can.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/can.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/definition.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/definition.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/ethernetif.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/ethernetif.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/main.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_it.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/stm32f4xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/udp_echoserver.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Src/udp_echoserver.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


