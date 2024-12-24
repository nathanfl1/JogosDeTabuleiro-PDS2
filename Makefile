CC=g++
CFLAGS=-std=c++11 -Wall
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj
all: main

$(OBJ_DIR)/BoardGame.o: $(INCLUDE_DIR)/BoardGame.hpp $(SRC_DIR)/BoardGame.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/BoardGame.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/BoardGame.o

$(OBJ_DIR)/Checkers.o: $(INCLUDE_DIR)/Checkers.hpp $(INCLUDE_DIR)/BoardGame.hpp $(SRC_DIR)/Checkers.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Checkers.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Checkers.o

#$(OBJ_DIR)/LigFour.o: $(INCLUDE_DIR)/LigFour.hpp $(SRC_DIR)/LigFour.cpp
#	$(CC) $(CFLAGS) -c $(SRC_DIR)/LigFour.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/LigFour.o

#$(OBJ_DIR)/Reversi.o: $(INCLUDE_DIR)/Reversi.hpp $(SRC_DIR)/Reversi.cpp
#	$(CC) $(CFLAGS) -c $(SRC_DIR)/Reversi.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Reversi.o

#$(OBJ_DIR)/TikTacToe.o: $(INCLUDE_DIR)/TikTacToe.hpp $(SRC_DIR)/TikTacToe.cpp
#	$(CC) $(CFLAGS) -c $(SRC_DIR)/TikTacToe.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/TikTacToe.o
	
$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/BoardGame.hpp $(INCLUDE_DIR)/Checkers.hpp $(SRC_DIR)/main.cpp  
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o


main: $(OBJ_DIR)/main.o $(OBJ_DIR)/BoardGame.o $(OBJ_DIR)/Checkers.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/BoardGame.o $(OBJ_DIR)/Checkers.o -o main


clean:
	rm -f main $(OBJ_DIR)/*.o