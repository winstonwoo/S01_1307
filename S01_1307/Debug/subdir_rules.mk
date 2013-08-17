################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
cmdline.obj: ../cmdline.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_TM4C123GH6PGE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="cmdline.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Tiva/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ff.obj: ../ff.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_TM4C123GH6PGE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="ff.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Tiva/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_TM4C123GH6PGE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="main.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Tiva/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

mycan.obj: ../mycan.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_TM4C123GH6PGE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="mycan.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Tiva/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

myfram.obj: ../myfram.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_TM4C123GH6PGE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="myfram.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Tiva/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

mymmc.obj: ../mymmc.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_TM4C123GH6PGE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="mymmc.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Tiva/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

mysdcard.obj: ../mysdcard.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_TM4C123GH6PGE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="mysdcard.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Tiva/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

myspican3.obj: ../myspican3.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_TM4C123GH6PGE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="myspican3.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Tiva/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

myspican4.obj: ../myspican4.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_TM4C123GH6PGE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="myspican4.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Tiva/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

myuart.obj: ../myuart.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_TM4C123GH6PGE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="myuart.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Tiva/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

uartstdio.obj: ../uartstdio.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0" --include_path="J:/WorkHouse2013/SWRf2013/StellarisTiVa/TiVa/TivaWare_C_Series-1.0/third_party" --define=TARGET_IS_BLIZZARD_RA1 --define=PART_TM4C123GH6PGE --define=ccs --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="uartstdio.pp" --cmd_file="J:/WorkHouse2013/SW2013/S01_1307_VTDR_Tiva/S01_Repository/S01_1307_configuration/Default/configPkg/compiler.opt" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


