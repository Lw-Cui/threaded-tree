SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, %.o, $(SRC)}
TAR = ${patsubst %.o, %.out, $(OBJ)}
FLAG = -g -c
CC = gcc

all: $(TAR)

$(TAR): %.out: %.o
	$(CC) $^ -o $@

$(OBJ): %.o: %.c
	$(CC) $^ -o $@ $(FLAG)

clean:
	rm $(TAR) $(OBJ)

.PHONY: all clean