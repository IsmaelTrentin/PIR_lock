#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIR_lock.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIR_lock.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/libmc/timer.c src/libmc/gpio.c src/libmc/interrupts.c src/libmc/lcd.c src/libmc/uart.c src/libmc/rgb.c src/libmc/audio.c src/libmc/pwm.c src/main.c src/modules/servo.c src/modules/pir.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/libmc/timer.o ${OBJECTDIR}/src/libmc/gpio.o ${OBJECTDIR}/src/libmc/interrupts.o ${OBJECTDIR}/src/libmc/lcd.o ${OBJECTDIR}/src/libmc/uart.o ${OBJECTDIR}/src/libmc/rgb.o ${OBJECTDIR}/src/libmc/audio.o ${OBJECTDIR}/src/libmc/pwm.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/modules/servo.o ${OBJECTDIR}/src/modules/pir.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/libmc/timer.o.d ${OBJECTDIR}/src/libmc/gpio.o.d ${OBJECTDIR}/src/libmc/interrupts.o.d ${OBJECTDIR}/src/libmc/lcd.o.d ${OBJECTDIR}/src/libmc/uart.o.d ${OBJECTDIR}/src/libmc/rgb.o.d ${OBJECTDIR}/src/libmc/audio.o.d ${OBJECTDIR}/src/libmc/pwm.o.d ${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/src/modules/servo.o.d ${OBJECTDIR}/src/modules/pir.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/libmc/timer.o ${OBJECTDIR}/src/libmc/gpio.o ${OBJECTDIR}/src/libmc/interrupts.o ${OBJECTDIR}/src/libmc/lcd.o ${OBJECTDIR}/src/libmc/uart.o ${OBJECTDIR}/src/libmc/rgb.o ${OBJECTDIR}/src/libmc/audio.o ${OBJECTDIR}/src/libmc/pwm.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/modules/servo.o ${OBJECTDIR}/src/modules/pir.o

# Source Files
SOURCEFILES=src/libmc/timer.c src/libmc/gpio.c src/libmc/interrupts.c src/libmc/lcd.c src/libmc/uart.c src/libmc/rgb.c src/libmc/audio.c src/libmc/pwm.c src/main.c src/modules/servo.c src/modules/pir.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PIR_lock.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX370F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/libmc/timer.o: src/libmc/timer.c  .generated_files/flags/default/f7ab65f47ce7241c664e49f7c35e72a55e1bbba .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/timer.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/timer.o.d" -o ${OBJECTDIR}/src/libmc/timer.o src/libmc/timer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/gpio.o: src/libmc/gpio.c  .generated_files/flags/default/4cba15767386b74147153acaef065df189d78ee2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/gpio.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/gpio.o.d" -o ${OBJECTDIR}/src/libmc/gpio.o src/libmc/gpio.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/interrupts.o: src/libmc/interrupts.c  .generated_files/flags/default/4bef6c78df43bd0fe6f5ef8f324e26e157c66271 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/interrupts.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/interrupts.o.d" -o ${OBJECTDIR}/src/libmc/interrupts.o src/libmc/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/lcd.o: src/libmc/lcd.c  .generated_files/flags/default/b838cca378f99b2533a4487ce75bf22ef32d4b94 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/lcd.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/lcd.o.d" -o ${OBJECTDIR}/src/libmc/lcd.o src/libmc/lcd.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/uart.o: src/libmc/uart.c  .generated_files/flags/default/b5e53aa5adaff9eed0654098348acd4c2b4e3a69 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/uart.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/uart.o.d" -o ${OBJECTDIR}/src/libmc/uart.o src/libmc/uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/rgb.o: src/libmc/rgb.c  .generated_files/flags/default/d17648c2f79910896edf5b8d613f0a132cc32e8f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/rgb.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/rgb.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/rgb.o.d" -o ${OBJECTDIR}/src/libmc/rgb.o src/libmc/rgb.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/audio.o: src/libmc/audio.c  .generated_files/flags/default/704c7b2115f5776432dcde45a45a60904edc0bd9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/audio.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/audio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/audio.o.d" -o ${OBJECTDIR}/src/libmc/audio.o src/libmc/audio.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/pwm.o: src/libmc/pwm.c  .generated_files/flags/default/3bdba2650c99adaf7dc358a024cdccbfd2a2ca5f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/pwm.o.d" -o ${OBJECTDIR}/src/libmc/pwm.o src/libmc/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/d38a2e17375a1a753e966510b51a86e6dddc9b6c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/modules/servo.o: src/modules/servo.c  .generated_files/flags/default/3c13894a8c92c5f0bfb0486c16ab9faf17b6892b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/servo.o.d 
	@${RM} ${OBJECTDIR}/src/modules/servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/modules/servo.o.d" -o ${OBJECTDIR}/src/modules/servo.o src/modules/servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/modules/pir.o: src/modules/pir.c  .generated_files/flags/default/afa713de9672ce5cb42f2cb4bebd622585ac8bda .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/pir.o.d 
	@${RM} ${OBJECTDIR}/src/modules/pir.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/modules/pir.o.d" -o ${OBJECTDIR}/src/modules/pir.o src/modules/pir.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/src/libmc/timer.o: src/libmc/timer.c  .generated_files/flags/default/b1e2d17a3c25ecb4ce05dac4c954e2163a10c2e3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/timer.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/timer.o.d" -o ${OBJECTDIR}/src/libmc/timer.o src/libmc/timer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/gpio.o: src/libmc/gpio.c  .generated_files/flags/default/7253dbf5c478b1a6c2cc618e7e1f07c5cc96ca31 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/gpio.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/gpio.o.d" -o ${OBJECTDIR}/src/libmc/gpio.o src/libmc/gpio.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/interrupts.o: src/libmc/interrupts.c  .generated_files/flags/default/8b5ea1fe08b97cad1c9bcb9f41c51641948ed5ae .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/interrupts.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/interrupts.o.d" -o ${OBJECTDIR}/src/libmc/interrupts.o src/libmc/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/lcd.o: src/libmc/lcd.c  .generated_files/flags/default/13df8b4823bf401e27873ccca62334d69d378d5a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/lcd.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/lcd.o.d" -o ${OBJECTDIR}/src/libmc/lcd.o src/libmc/lcd.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/uart.o: src/libmc/uart.c  .generated_files/flags/default/a72501470244ebd141048a834c1eb9c095df35dd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/uart.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/uart.o.d" -o ${OBJECTDIR}/src/libmc/uart.o src/libmc/uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/rgb.o: src/libmc/rgb.c  .generated_files/flags/default/2551941d616fd1ca4f268a1fff31af6d912724e3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/rgb.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/rgb.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/rgb.o.d" -o ${OBJECTDIR}/src/libmc/rgb.o src/libmc/rgb.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/audio.o: src/libmc/audio.c  .generated_files/flags/default/328c3bcbbfdcba6cb7e9824bdd1a2a4391baced5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/audio.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/audio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/audio.o.d" -o ${OBJECTDIR}/src/libmc/audio.o src/libmc/audio.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/libmc/pwm.o: src/libmc/pwm.c  .generated_files/flags/default/ef86105da3caf721cd8e3421f14c4ca7030fbc3c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/libmc" 
	@${RM} ${OBJECTDIR}/src/libmc/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/libmc/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/libmc/pwm.o.d" -o ${OBJECTDIR}/src/libmc/pwm.o src/libmc/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/37b674c85579a1b99c83c71e35eb9d6c6c33413a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/main.o.d" -o ${OBJECTDIR}/src/main.o src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/modules/servo.o: src/modules/servo.c  .generated_files/flags/default/8307272dd9b55505dacec3d41bf25c6e450f58f5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/servo.o.d 
	@${RM} ${OBJECTDIR}/src/modules/servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/modules/servo.o.d" -o ${OBJECTDIR}/src/modules/servo.o src/modules/servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/src/modules/pir.o: src/modules/pir.c  .generated_files/flags/default/88966cccc625d9f275e09cb0d9c5dd15b3664a4f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src/modules" 
	@${RM} ${OBJECTDIR}/src/modules/pir.o.d 
	@${RM} ${OBJECTDIR}/src/modules/pir.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"include" -fno-common -MP -MMD -MF "${OBJECTDIR}/src/modules/pir.o.d" -o ${OBJECTDIR}/src/modules/pir.o src/modules/pir.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PIR_lock.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/PIR_lock.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC0275F  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/PIR_lock.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/PIR_lock.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex ${DISTDIR}/PIR_lock.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
