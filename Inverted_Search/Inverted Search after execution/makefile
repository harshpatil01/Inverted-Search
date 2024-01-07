SRC:= $(wildcard *.c)
OBJ:= $(patsubst %.c, %.o, $(SRC))

final: $(OBJ)
	gcc -o $@ $^

clean:
	rm *.o
