MAINS = src/test/main.c
SRC_DIR = src
SRC_MAIN = $(filter-out $(MAINS),$(wildcard $(SRC_DIR)/main/**/*.c $(SRC_DIR)/main/*.c))
SRC_TEST = $(filter-out $(MAINS),$(wildcard $(SRC_DIR)/test/**/*.c $(SRC_DIR)/test/*.c))

OUT_DIR = out
OUT = $(patsubst $(SRC_DIR)/%.c,$(OUT_DIR)/%,$(SRC_MAIN) $(SRC_TEST))

CC=gcc
CFLAGS=-I$(SRC_DIR) -Wall -std=c99 -g

# $(info SRC_MAIN: ${SRC_MAIN})
# $(info SRC_TEST: ${SRC_TEST})
# $(info OUT: ${OUT})

.PHONY:	all\
		pre-build\
		build\
		build-test\
		test\
		valgrind\
		clean\

all: build build-test

%: %.c
	$(CC) $(CFLAGS) -o $(patsubst $(SRC_DIR)/%,$(OUT_DIR)/%,$@) $<

out/test: ${SRC_TEST} ${SRC_MAIN} src/test/main.c
	$(CC) $(CFLAGS) -o out/test ${SRC_TEST} ${SRC_MAIN} src/test/main.c

pre-build:
	mkdir -p out
	@echo PRE-BUILD done

build: pre-build
	# TODO: build library
	@echo BUILD done

build-test: pre-build out/test
	@echo BUILD-TEST done

test: out/test
	out/test

valgrind: build-test
	valgrind --leak-check=full out/test

clean:
	rm -rf $(OUT_DIR) vgcore*
