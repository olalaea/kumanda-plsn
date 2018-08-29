################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/api_lib.c \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/api_msg.c \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/err.c \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/netbuf.c \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/netdb.c \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/netifapi.c \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/sockets.c \
C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/tcpip.c 

OBJS += \
./Middlewares/LwIP/Api/api_lib.o \
./Middlewares/LwIP/Api/api_msg.o \
./Middlewares/LwIP/Api/err.o \
./Middlewares/LwIP/Api/netbuf.o \
./Middlewares/LwIP/Api/netdb.o \
./Middlewares/LwIP/Api/netifapi.o \
./Middlewares/LwIP/Api/sockets.o \
./Middlewares/LwIP/Api/tcpip.o 

C_DEPS += \
./Middlewares/LwIP/Api/api_lib.d \
./Middlewares/LwIP/Api/api_msg.d \
./Middlewares/LwIP/Api/err.d \
./Middlewares/LwIP/Api/netbuf.d \
./Middlewares/LwIP/Api/netdb.d \
./Middlewares/LwIP/Api/netifapi.d \
./Middlewares/LwIP/Api/sockets.d \
./Middlewares/LwIP/Api/tcpip.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LwIP/Api/api_lib.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/api_lib.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/LwIP/Api/api_msg.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/api_msg.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/LwIP/Api/err.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/err.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/LwIP/Api/netbuf.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/netbuf.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/LwIP/Api/netdb.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/netdb.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/LwIP/Api/netifapi.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/netifapi.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/LwIP/Api/sockets.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/sockets.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/LwIP/Api/tcpip.o: C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/api/tcpip.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_STM324xG_EVAL -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Projects/STM324xG_EVAL/Applications/LwIP/LwIP_UDP_Echo_Server_withCAN/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/CMSIS/Include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/STM324xG_EVAL" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Drivers/BSP/Components" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/src/include" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Middlewares/Third_Party/LwIP/system" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities" -I"C:/Users/Ugur/Desktop/STM32Cube_FW_F4_V1.21.0/Utilities/Log"  -O0 -g3 -Wall -fmessage-length=0 -MT”$@” -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


