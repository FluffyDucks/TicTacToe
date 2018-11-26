#include <iostream>
#include "TTT.cpp"

int main(){
	int input;
	TTT game;
	game.createBoard();

	std::cout << "----Start----" << std::endl << std::endl;

	std::cout << "To select a spot, input the corresponding letter as follows:" << '\n';
	std::cout << "^^^^^^^^^^^" << '\n';
	std::cout << " 7 | 8 | 9 " << '\n';
	std::cout << "-----------" << '\n';
	std::cout << " 4 | 5 | 6 " << '\n';
	std::cout << "-----------" << '\n';
	std::cout << " 1 | 2 | 3 " << '\n';
	std::cout << "vvvvvvvvvvv" << '\n';

	bool flagFull = game.isFull();
	bool flagWin = game.checkWinCondition();

	while((flagWin == false) && (flagFull == false)){
		// std::cout << "full = " << flagFull << '\n';
		// std::cout << "win = " << flagWin << '\n';
		std::cout << "Player " << game.turnChange() << " chooses: ";
		std::cin >> input;
		bool check = game.validateInput(input);
		if(check == false){
			std::cout << "please choose a valid spot" << '\n';
			std::cout << "Player " << game.whosTurn() << " chooses: ";
			std::cin >> input;
			bool check = game.validateInput(input);
		}
		bool validInput = game.placeOnBoard(input);
		while(!validInput){
			std::cout << "Spot is already taken, choose again: ";
			std::cin >> input;
			bool check = game.validateInput(input);
			if(check == false){
				std::cout << "please choose a valid spot" << '\n';
				std::cout << "Player " << game.whosTurn() << " chooses: ";
				std::cin >> input;
				bool check = game.validateInput(input);
			}
			validInput = game.placeOnBoard(input);
		}

		game.displayBoard();
		flagFull = game.isFull();
		flagWin = game.checkWinCondition();
	}

	//check if its a win or a tie
	if(flagWin){
		std::cout << "Player " << game.whosTurn() << " wins!" << '\n';
	}
	else if(flagFull){
		std::cout << "It's a Tie!" << '\n';
	}

	std::cout << std::endl << "-----End-----" << std::endl;
	return 0;
}
