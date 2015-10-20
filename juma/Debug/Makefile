################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../demo.c \
../mb.c \
../mbascii.c \
../mbcrc.c \
../mbfunccoils.c \
../mbfuncdiag.c \
../mbfuncdisc.c \
../mbfuncholding.c \
../mbfuncinput.c \
../mbfuncother.c \
../mbrtu.c \
../mbutils.c \
../portevent.c \
../portserial.c \
../porttimer.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
demo.o \
mb.o \
mbascii.o \
mbcrc.o \
mbfunccoils.o \
mbfuncdiag.o \
mbfuncdisc.o \
mbfuncholding.o \
mbfuncinput.o \
mbfuncother.o \
mbrtu.o \
mbutils.o \
portevent.o \
portserial.o \
porttimer.o

OBJS_AS_ARGS +=  \
demo.o \
mb.o \
mbascii.o \
mbcrc.o \
mbfunccoils.o \
mbfuncdiag.o \
mbfuncdisc.o \
mbfuncholding.o \
mbfuncinput.o \
mbfuncother.o \
mbrtu.o \
mbutils.o \
portevent.o \
portserial.o \
porttimer.o

C_DEPS +=  \
demo.d \
mb.d \
mbascii.d \
mbcrc.d \
mbfunccoils.d \
mbfuncdiag.d \
mbfuncdisc.d \
mbfuncholding.d \
mbfuncinput.d \
mbfuncother.d \
mbrtu.d \
mbutils.d \
portevent.d \
portserial.d \
porttimer.d

C_DEPS_AS_ARGS +=  \
demo.d \
mb.d \
mbascii.d \
mbcrc.d \
mbfunccoils.d \
mbfuncdiag.d \
mbfuncdisc.d \
mbfuncholding.d \
mbfuncinput.d \
mbfuncother.d \
mbrtu.d \
mbutils.d \
portevent.d \
portserial.d \
porttimer.d

OUTPUT_FILE_PATH +=juma.elf

OUTPUT_FILE_PATH_AS_ARGS +=juma.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler































./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=8000000  -I"../../../freemodbus-v1.5.0/modbus/include" -I"../../../freemodbus-v1.5.0/demo/AVR" -I"../../../freemodbus-v1.5.0/demo/AVR/port" -I"../../../freemodbus-v1.5.0/modbus/ascii"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega128 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="juma.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,-L".."  -Wl,--gc-sections -mrelax -mmcu=atmega128  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "juma.elf" "juma.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "juma.elf" "juma.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "juma.elf" > "juma.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "juma.elf" "juma.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-size.exe" "juma.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "juma.elf" "juma.a" "juma.hex" "juma.lss" "juma.eep" "juma.map" "juma.srec" "juma.usersignatures"
	