################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
led.obj: ../led.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/antiaegis/OneDrive/HCMUT/SEMESTER VI/Embedded Programming/exercise/2.TIVAlabTODO/example09-Task-SysTick1" --include_path="/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --include_path="/home/antiaegis/ti/SW-TM4C-2.1.4.178" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="led.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

ledGreenStateMachine.obj: ../ledGreenStateMachine.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/antiaegis/OneDrive/HCMUT/SEMESTER VI/Embedded Programming/exercise/2.TIVAlabTODO/example09-Task-SysTick1" --include_path="/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --include_path="/home/antiaegis/ti/SW-TM4C-2.1.4.178" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="ledGreenStateMachine.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

ledRedStateMachine.obj: ../ledRedStateMachine.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/antiaegis/OneDrive/HCMUT/SEMESTER VI/Embedded Programming/exercise/2.TIVAlabTODO/example09-Task-SysTick1" --include_path="/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --include_path="/home/antiaegis/ti/SW-TM4C-2.1.4.178" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="ledRedStateMachine.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/antiaegis/OneDrive/HCMUT/SEMESTER VI/Embedded Programming/exercise/2.TIVAlabTODO/example09-Task-SysTick1" --include_path="/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --include_path="/home/antiaegis/ti/SW-TM4C-2.1.4.178" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="main.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

switches.obj: ../switches.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/antiaegis/OneDrive/HCMUT/SEMESTER VI/Embedded Programming/exercise/2.TIVAlabTODO/example09-Task-SysTick1" --include_path="/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --include_path="/home/antiaegis/ti/SW-TM4C-2.1.4.178" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="switches.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

tm4c123gh6pm_startup_ccs.obj: ../tm4c123gh6pm_startup_ccs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/antiaegis/OneDrive/HCMUT/SEMESTER VI/Embedded Programming/exercise/2.TIVAlabTODO/example09-Task-SysTick1" --include_path="/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --include_path="/home/antiaegis/ti/SW-TM4C-2.1.4.178" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="tm4c123gh6pm_startup_ccs.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

uartstdio.obj: ../uartstdio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/antiaegis/OneDrive/HCMUT/SEMESTER VI/Embedded Programming/exercise/2.TIVAlabTODO/example09-Task-SysTick1" --include_path="/home/antiaegis/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --include_path="/home/antiaegis/ti/SW-TM4C-2.1.4.178" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="uartstdio.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


