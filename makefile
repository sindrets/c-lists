SRC_DIR = src
SRC_MAIN = $(wildcard $(SRC_DIR)/main/**/*.c $(SRC_DIR)/main/*.c)
SRC_TEST = $(wildcard $(SRC_DIR)/test/**/*.c $(SRC_DIR)/test/*.c)
OUT_DIR = build
OBJ = $(patsubst $(SRC_DIR)/main/%.c,$(OUT_DIR)/obj/%.o,$(SRC_MAIN))

LIB_NAME = liblists
CC=gcc
CFLAGS= -Wall -std=c99 -g

# $(info SRC_MAIN: ${SRC_MAIN})
# $(info SRC_TEST: ${SRC_TEST})
# $(info OBJ: ${OBJ})

.PHONY:	all\
		pre-build\
		build\
		build-test\
		test\
		valgrind\
		clean\

all: build build-test test

$(OUT_DIR)/bin/test: ${SRC_TEST}
	$(CC) $(CFLAGS) -o $(OUT_DIR)/bin/test ${SRC_TEST} -L$(OUT_DIR)/lib -l$(patsubst lib%,%,$(LIB_NAME))

$(OUT_DIR)/lib/$(LIB_NAME).so: $(SRC_MAIN)
	$(CC) -c $(CFLAGS) -fpic $(SRC_MAIN)
	mv *.o $(OUT_DIR)/obj
	$(CC) $(CFLAGS) -shared -o $(OUT_DIR)/lib/$(LIB_NAME).so $(OBJ)

pre-build:
	mkdir -p $(OUT_DIR)/bin $(OUT_DIR)/lib $(OUT_DIR)/obj
	@echo PRE-BUILD done

build: pre-build $(OUT_DIR)/lib/$(LIB_NAME).so
	@echo BUILD done

build-test: pre-build build $(OUT_DIR)/bin/test
	@echo BUILD-TEST done

test: pre-build build build-test
	LD_LIBRARY_PATH=$(OUT_DIR)/lib $(OUT_DIR)/bin/test

valgrind: build-test
	LD_LIBRARY_PATH=$(OUT_DIR)/lib valgrind --leak-check=full $(OUT_DIR)/bin/test

clean:
	rm -rf $(OUT_DIR) vgcore.*
