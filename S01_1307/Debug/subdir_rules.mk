################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
can.obj: ../can.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/Stellaris/StellarisWare" --include_path="/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_LM4F232H5QD --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="can.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Stellaris/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cmdline.obj: ../cmdline.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/Stellaris/StellarisWare" --include_path="/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_LM4F232H5QD --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="cmdline.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Stellaris/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ff.obj: ../ff.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/Stellaris/StellarisWare" --include_path="/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_LM4F232H5QD --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="ff.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Stellaris/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/Stellaris/StellarisWare" --include_path="/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_LM4F232H5QD --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="main.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Stellaris/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

mmc-ek-lm4f232h5qd.obj: ../mmc-ek-lm4f232h5qd.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/Stellaris/StellarisWare" --include_path="/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_LM4F232H5QD --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="mmc-ek-lm4f232h5qd.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Stellaris/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

sd_card.obj: ../sd_card.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/Stellaris/StellarisWare" --include_path="/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_LM4F232H5QD --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="sd_card.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Stellaris/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

uartstdio.obj: ../uartstdio.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/Stellaris/StellarisWare" --include_path="/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_LM4F232H5QD --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="uartstdio.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Stellaris/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


