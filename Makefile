CC=g++
CFLAGS=-std=c++11 -Wall
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj
BINARY_DIR=bin
all: main

$(OBJ_DIR)/BoardGame.o: $(INCLUDE_DIR)/BoardGame.hpp $(SRC_DIR)/BoardGame.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/BoardGame.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/BoardGame.o

$(OBJ_DIR)/Checkers.o: $(INCLUDE_DIR)/Checkers.hpp $(INCLUDE_DIR)/BoardGame.hpp $(SRC_DIR)/Checkers.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Checkers.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Checkers.o

$(OBJ_DIR)/LigFour.o: $(INCLUDE_DIR)/LigFour.hpp $(INCLUDE_DIR)/BoardGame.hpp $(SRC_DIR)/LigFour.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/LigFour.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/LigFour.o

$(OBJ_DIR)/Reversi.o: $(INCLUDE_DIR)/Reversi.hpp $(SRC_DIR)/Reversi.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Reversi.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Reversi.o

$(OBJ_DIR)/TicTacToe.o: $(INCLUDE_DIR)/TicTacToe.hpp $(SRC_DIR)/TicTacToe.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/TicTacToe.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/TicTacToe.o
	
$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/BoardGame.hpp $(INCLUDE_DIR)/Checkers.hpp $(INCLUDE_DIR)/LigFour.hpp $(INCLUDE_DIR)/TicTacToe.hpp $(SRC_DIR)/main.cpp  
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/Player.o: $(INCLUDE_DIR)/Player.hpp $(SRC_DIR)/Player.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Player.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Player.o

$(OBJ_DIR)/PlayerList.o: $(INCLUDE_DIR)/PlayerList.hpp $(SRC_DIR)/PlayerList.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/PlayerList.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/PlayerList.o

$(OBJ_DIR)/Manager.o: $(INCLUDE_DIR)/Manager.hpp $(SRC_DIR)/Manager.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Manager.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Manager.o

main: $(OBJ_DIR)/main.o $(OBJ_DIR)/BoardGame.o $(OBJ_DIR)/Checkers.o $(OBJ_DIR)/LigFour.o $(OBJ_DIR)/Reversi.o $(OBJ_DIR)/TicTacToe.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/PlayerList.o $(OBJ_DIR)/Manager.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/BoardGame.o $(OBJ_DIR)/TicTacToe.o $(OBJ_DIR)/LigFour.o $(OBJ_DIR)/Checkers.o $(OBJ_DIR)/Reversi.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/PlayerList.o $(OBJ_DIR)/Manager.o -o $(BINARY_DIR)/main


# $(OBJ_DIR)/ReversiTest.o: tests/ReversiTest.cpp $(SRC_DIR)/Reversi.cpp $(SRC_DIR)/BoardGame.cpp $(SRC_DIR)/Player.cpp $(SRC_DIR)/PlayerList.cpp 
# 	$(CC) $(CFLAGS) tests/ReversiTest.cpp $(OBJ_DIR)/Reversi.o $(OBJ_DIR)/BoardGame.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/PlayerList.o -c tests/ReversiTest.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/ReversiTest.o

# test_reversi: tests/ReversiTest.cpp (OBJ_DIR)/ReversiTest.o $(INCLUDE_DIR)/Reversi.hpp $(SRC_DIR)/Reversi.cpp $(SRC_DIR)/BoardGame.cpp $(SRC_DIR)/Player.cpp $(SRC_DIR)/PlayerList.cpp
# 	$(CC) $(CFLAGS) tests/ReversiTest.cpp $(OBJ_DIR)/ReversiTest.o $(OBJ_DIR)/Reversi.o $(OBJ_DIR)/BoardGame.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/PlayerList.o -o test_reversi
# 	./test_reversi


test_reversi: tests/ReversiTest.cpp $(OBJ_DIR)/Reversi.o $(OBJ_DIR)/BoardGame.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/PlayerList.o
	$(CC) $(CFLAGS) tests/ReversiTest.cpp $(SRC_DIR)/Reversi.cpp $(SRC_DIR)/BoardGame.cpp $(SRC_DIR)/Player.cpp $(SRC_DIR)/PlayerList.cpp -I$(INCLUDE_DIR) -o $(BINARY_DIR)/testeReversi

test_checkers: tests/CheckersTest.cpp $(OBJ_DIR)/Checkers.o $(OBJ_DIR)/BoardGame.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/PlayerList.o
	$(CC) $(CFLAGS) tests/CheckersTest.cpp $(SRC_DIR)/Checkers.cpp $(SRC_DIR)/BoardGame.cpp $(SRC_DIR)/Player.cpp $(SRC_DIR)/PlayerList.cpp -I$(INCLUDE_DIR) -o $(BINARY_DIR)/testeCheckers

test_ligfour: tests/LigFourTest.cpp $(OBJ_DIR)/LigFour.o $(OBJ_DIR)/BoardGame.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/PlayerList.o
	$(CC) $(CFLAGS) tests/LigFourTest.cpp $(SRC_DIR)/LigFour.cpp $(SRC_DIR)/BoardGame.cpp $(SRC_DIR)/Player.cpp $(SRC_DIR)/PlayerList.cpp -I$(INCLUDE_DIR) -o $(BINARY_DIR)/testeLigFour

test_tictactoe: tests/TicTacToeTest.cpp $(OBJ_DIR)/TicTacToe.o $(OBJ_DIR)/BoardGame.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/PlayerList.o
	$(CC) $(CFLAGS) tests/TicTacToeTest.cpp $(SRC_DIR)/TicTacToe.cpp $(SRC_DIR)/BoardGame.cpp $(SRC_DIR)/Player.cpp $(SRC_DIR)/PlayerList.cpp -I$(INCLUDE_DIR) -o $(BINARY_DIR)/testeTicTacToe

clean:
	rm -f $(BINARY_DIR)/main $(OBJ_DIR)/*.o $(BINARY_DIR)/testeReversi $(BINARY_DIR)/testeCheckers $(BINARY_DIR)/testeLigFour $(BINARY_DIR)/testeTicTacToe

