DIRECTORY_GUARD=@mkdir -p $(@D)
BUILD_DIRECTORY=build

CC = gcc 
CFLAGS = 					\
	-g3						\
	-ansi 					\
	-pedantic				\
	-Wpedantic 				\
	-Werror					\
	-Wextra					\
	-Wall					\
	-fsanitize=undefined 	\
	-fsanitize=address 		\
	-I.						\

LDFLAGS =					\
	-fsanitize=undefined 	\
	-fsanitize=address 		

SRC	= 						\
	$(wildcard *.c)			\
	$(wildcard */*.c)		

OBJ	= $(patsubst %.c, $(BUILD_DIRECTORY)/%.o, $(SRC))
TARGET = test

$(BUILD_DIRECTORY)/%.o: %.c
	$(DIRECTORY_GUARD)
	@echo [LIBEASY] [CC] $<
	@$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(DIRECTORY_GUARD)
	@echo [LIBEASY] [LD] $@
	@$(CC) $(LDFLAGS) $^ -lm -o $@ 

clean:
	rm $(TARGET)
	rm -r $(BUILD_DIRECTORY)

all:$(TARGET)
re: clean all 

.PHONY: all clean re
.DEFAULT: all