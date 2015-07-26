################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cashiersystem.cpp \
../main.cpp \
../product.cpp \
../shoppingcart.cpp 

OBJS += \
./cashiersystem.o \
./main.o \
./product.o \
./shoppingcart.o 

CPP_DEPS += \
./cashiersystem.d \
./main.d \
./product.d \
./shoppingcart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


