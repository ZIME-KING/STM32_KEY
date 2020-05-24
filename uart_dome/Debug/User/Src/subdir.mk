################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Src/key_function.c \
../User/Src/uart.c 

OBJS += \
./User/Src/key_function.o \
./User/Src/uart.o 

C_DEPS += \
./User/Src/key_function.d \
./User/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
User/Src/key_function.o: ../User/Src/key_function.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I"C:/Users/Administrator/Desktop/CubeIDE workspace/uart_dome/User/Inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User/Src/key_function.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
User/Src/uart.o: ../User/Src/uart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I"C:/Users/Administrator/Desktop/CubeIDE workspace/uart_dome/User/Inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User/Src/uart.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

