################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/Src/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
uart_dome.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
uart_dome.list \

OBJCOPY_BIN += \
uart_dome.bin \


# All Target
all: uart_dome.elf secondary-outputs

# Tool invocations
uart_dome.elf: $(OBJS) $(USER_OBJS) C:\Users\Administrator\Desktop\CubeIDE\ workspace\uart_dome\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "uart_dome.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\Administrator\Desktop\CubeIDE workspace\uart_dome\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="uart_dome.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

uart_dome.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "uart_dome.list"
	@echo 'Finished building: $@'
	@echo ' '

uart_dome.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "uart_dome.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
