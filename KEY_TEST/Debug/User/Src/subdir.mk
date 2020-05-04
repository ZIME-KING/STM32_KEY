################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Src/key_function.c 

OBJS += \
./User/Src/key_function.o 

C_DEPS += \
./User/Src/key_function.d 


# Each subdirectory must supply rules for building sources it contributes
User/Src/key_function.o: ../User/Src/key_function.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/GIT_ALL/STM32_KEY/KEY_TEST/User/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User/Src/key_function.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

