################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/Program Files/Texas Instruments/ccsv5/tools/compiler/arm_5.0.4

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: configPkg/linker.cmd

# Tool invocations
configPkg/linker.cmd: $(CFG_SRCS)
	@echo 'Building target: $@'
	@echo 'Invoking: XDCtools'
	"C:/Program Files/Texas Instruments/xdctools_3_25_00_48/xs" --xdcpath="C:/Program Files/Texas Instruments/bios_6_35_01_29/packages;C:/Program Files/Texas Instruments/ccsv5/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M4F -p ti.platforms.stellaris:LM4F232H5QD -r release -c "C:/Program Files/Texas Instruments/ccsv5/tools/compiler/arm_5.0.4" --compileOptions "-g --optimize_with_debug" $(CFG_SRCS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_SRCS__QUOTED)$(GEN_MISC_FILES__QUOTED)$(GEN_CMDS__QUOTED)$(GEN_OPTS__QUOTED) "configPkg\linker.cmd"
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
