CC = gcc

TASK1_PROG = calc
CALC_LIB = libcalc.a
CALC_LIB_DIR = ./task1/libcalc
CALC_LIB_HEADERS = ./task1/libcalc/inc
CALC_LIB_SOURCES = ./task1/libcalc/src
TASK1_DIR = ./task1

SOURCES_CALC := $(wildcard $(CALC_LIB_SOURCES)/*.c)
OBJ_CALC=$(patsubst %.c, %.o, $(SOURCES_CALC))
SRCS_TASK1 = $(wildcard $(TASK1_DIR)/*.c)

TASK2_PROG = converter
CONV_LIB = libconverter.so
CONV_LIB_DIR = ./task2/libconverter
CONV_LIB_HEADERS = ./task2/libconverter/inc
CONV_LIB_SOURCES = ./task2/libconverter/src
TASK2_DIR = ./task2

SOURCES_CONVERTOR := $(wildcard $(CONV_LIB_SOURCES)/*.c)
OBJ_CONV=$(patsubst %.c, %.o, $(SOURCES_CONVERTOR))
SRCS_TASK2 = $(wildcard $(TASK2_DIR)/*.c)


all: ${TASK1_PROG} ${TASK2_PROG} | converter_install

#TASK 1
#######################################
$(TASK1_PROG): $(CALC_LIB)
	$(CC) $(SRCS_TASK1) -L $(CALC_LIB_DIR) -l $(TASK1_PROG) -I $(CALC_LIB_HEADERS) -o $(TASK1_PROG)

$(CALC_LIB): $(OBJ_CALC)
	ar -rc $(CALC_LIB_DIR)/$(CALC_LIB) $(OBJ_CALC)
	ranlib $(CALC_LIB_DIR)/$(CALC_LIB)

$(OBJ_CALC): $(SOURCES_CALC)
	$(CC) -c $< -I $(CALC_LIB_HEADERS) -o $@
#######################################


#TASK 2

######################################
$(TASK2_PROG): $(OBJ_CONV)
	$(CC) -shared -o $(CONV_LIB) $(OBJ_CONV)

$(OBJ_CONV): $(SOURCES_CONVERTOR)
	echo "obj = $(OBJ_CONV)"
	$(CC)  -Wall -Werror -Wextra -fpic -c $< -I $(CONV_LIB_HEADERS) -o $@

converter_install: $(CONV_LIB) $(SRCS_TASK2)
	cp $(CONV_LIB) /usr/lib
	chmod 0755 /usr/lib/$(CONV_LIB)
	ldconfig
	gcc $(SRCS_TASK2) -l $(TASK2_PROG) -Wall -I $(CONV_LIB_HEADERS) -o $(TASK2_PROG)
#####################################




clean:
	rm -rf $(TASK1_PROG)
	rm -rf $(OBJ_CALC)
	rm -rf $(CALC_LIB_DIR)/$(CALC_LIB)
	rm -rf $(TASK2_PROG)
	rm -rf $(OBJ_CONV)
	rm -rf $(CONV_LIB)
	rm -rf /usr/lib/$(CONV_LIB)