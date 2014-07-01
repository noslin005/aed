PROGRAM	= program
SRC 	= $(wildcard *.c)
OBJ	= $(SRC:.c=.o)
CC	= gcc

WARINGS	=-g -Wall
CFLAGS	=-O2 $(WARINGS)
LDFLAGS	=

$(PROGRAM): $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJ)
	$(RM) $(PROGRAM)
