NAME = mainwindow
PS = ps

SRC = $(NAME).c
OBJ = $(NAME).o
PS_SRC = $(PS).c
PS_OBJ = $(PS).o

ifeq ($(OS),Windows_NT)
	EXEC := $(NAME).exe
	LDLIBS := -mwindows
else
	EXEC := $(NAME)
endif

CC = gcc
LDLIBS += -lsqlite3 -no-pie `pkg-config --libs gtk+-3.0 gmodule-2.0`
CFLAGS = -Wall -g -no-pie `pkg-config --cflags gtk+-3.0 gmodule-2.0`

$(EXEC): $(OBJ) $(PS_OBJ)
	$(CC) $(OBJ) $(PS_OBJ) -o $(EXEC) $(LDLIBS) -ldl -lm

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -lm -ldl

$(PS_OBJ): $(PS_SRC)
	$(CC) -Wall -c $(PS_SRC) -lm -ldl


clean:
	rm -f $(EXEC)
	rm -f *.o