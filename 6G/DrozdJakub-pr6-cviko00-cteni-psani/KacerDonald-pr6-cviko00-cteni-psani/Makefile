
NAME=pr6-cviko00-cteni-psani
OBJFILES=main.o vektor.o

DEBUGER=kdbg
CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -Wextra -g


# vzorové pravidlo pro generování všech objektových souborů
%.o : %.c
	$(CC) $(CFLAGS) -c $<

# Startovací pravidlo
all: $(NAME)

## ## ## 
# pravidla bez těla - to se sem doplní z univerzálního pravidla
vektor.o: vektor.c vektor.h
main.o: main.c gvid.h
## ## ## 

# Slinkování všech objektových souborů do jednoho spustitelného programu.
$(NAME): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -lm -o $@

run:
	./$(NAME)

debug: $(NAME)
	$(DEBUGER) $(NAME)

clean:
	rm -f *~ $(NAME) *.bak *.o

edit:
	kate $(NAME).c

