#include <iostream>
#include <cstdlib>

class TTT{
	private:
		char board[3][3];
		int playerTurn = 2;
	public:
		void createBoard(){
			for(int x = 0; x < 3; x++){
				for(int y = 0; y < 3; y++){
					board[x][y] = ' ';
				}
			}
		}
		void printArr(){
			for(int x = 0; x < 3; x++){
				for(int y = 0; y < 3; y++){
					std::cout << board[x][y] << ", ";
				}
				std::cout << '\n';
			}
		}
		int whosTurn(){
			return playerTurn;
		}
		void displayBoard();
		bool isFull();
		bool placeOnBoard(int spot);
		int turnChange();
		bool validateInput(int input);
		bool checkWinCondition();
};
