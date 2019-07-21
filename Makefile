CC = g++
CFLAGS = -Wall -std=c++17 
EXEC_NAME =out/app.exe
INCLUDES =-IC:\SFML-2.5.1\include
LIBS =-LC:\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system
OBJ_FILES = main.o board.o tetris.o piece.o

INSTALL_DIR = C:/bin/

all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

install :
	cp $(EXEC_NAME) $(INSTALL_DIR)$(EXEC_NAME)
