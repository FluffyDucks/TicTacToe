#include <iostream>
#include <cctype>
#include "TTT.h"

bool TTT::placeOnBoard(int spot){
	int x;
	int y;
	switch(spot) {
		case 7:
			x = 0;
			y = 0;
			break;
		case 8:
			x = 0;
			y = 1;
			break;
		case 9:
			x = 0;
			y = 2;
			break;

		case 4:
			x = 1;
			y = 0;
			break;
		case 5:
			x = 1;
		 	y = 1;
			break;
		case 6:
			x = 1;
			y = 2;
			break;

		case 1:
			x = 2;
			y = 0;
			break;
		case 2:
			x = 2;
			y = 1;
			break;
		case 3:
			x = 2;
			y = 2;
			break;
		default:
			std::cout << "ERROR" << '\n';
			break;
	}

	if((playerTurn == 1) && (board[x][y] == ' ')){
		board[x][y] = 'X';
	}
	else if((playerTurn == 2) && (board[x][y] == ' ')){
		board[x][y] = 'O';
	}
	else{
		return false;
	}
	return true;
}

void TTT::displayBoard(){
	std::cout << std::endl;
	std::cout << "Tic Tac Toe" << '\n';
	std::cout << "-----------" << '\n';
	std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "  " << '\n';
	std::cout << "-----------" << '\n';
	std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << '\n';
	std::cout << "-----------" << '\n';
	std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << '\n';
	std::cout << "vvvvvvvvvvv" << '\n';
}

bool TTT::isFull(){
	int counter = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(board[i][j] == ' '){
				counter++;
			}
		}
	}
	if(counter == 0){
		return true;
	}
	else{
		return false;
	}
}

int TTT::turnChange(){
	if(playerTurn == 1){
		playerTurn = 2;
	}
	else{
		playerTurn = 1;
	}
	return playerTurn;
}

bool TTT::validateInput(int input){
	if((input < 1) || (input > 9)){
		return false;
	}
	else{
		return true;
	}
}

bool TTT::checkWinCondition(){
	for(int x = 0; x < 3; x++){
		if((board[x][0] != ' ') && ((board[x][0] == board[x][1]) && (board[x][1] == board[x][2]))) {
			return true;
		}
		if((board[0][x] != ' ') && ((board[0][x] == board[1][x]) && (board[1][x] == board[2][x]))) {
			return true;
		}
	}
	if((board[0][0] != ' ') && ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))) {
		return true;
	}
	if((board[0][2] != ' ') && ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))) {
		return true;
	}
	return false;
}
