// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void Board();
int CheckWin(int turn);
bool ValidMove(char square);

char square[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };

int main()
{
	std::cout << " ----- Noughts and crosses game -----" << std::endl;
	std::cout << " --- Player 1: x --- Player 2: o --- " << std::endl;
	std::cout << std::endl;

	int turn = 0;
	char player;
	do {

		if (turn % 2 == 0) {
			player = 'x';
		}
		else {
			player = 'o';
		}

		Board();

		std::cout << " --- Please enter a number for the square you want to play" << std::endl;
		std::cout << std::endl;

		int choice;
		std::cin >> choice;
		
		if (ValidMove(square[choice])) {
			square[choice] = player;
			turn++;
		}
		else {
			std::cout << " --- That was an invalid move ---" << std::endl;
			std::cout << " --- Please enter a valid move ---" << std::endl;
			
		}

		std::cin.clear(); // Clear any errors
		std::cin.ignore(); // Discards error buffer
		
	} while (CheckWin(turn) == -1);

	std::cout << " --- The winner is: " << player << "! ---" << std::endl;
	std::cout << " --- ENTER ANY KEY TO EXIT ---" << std::endl;
	char exit;
	std::cin >> exit;

}
// Check if the move chosen by the player is valid
bool ValidMove(char square) {
	if (square == 'x' || square == 'o') {
		return false;
	}
	else {
		return true;
	}
}
// Check if the game has been won
// 1 = game won by a player
// 0 = game tie
// -1 = game in progress
int CheckWin(int turn) {
	// top horizontal
	if (square[0] == square[1] && square[1] == square[2]) {
		return 1;
	}
	// middle horizontal
	else if (square[3] == square[4] && square[4] == square[5]) {
		return 1;
	}
	// bottom horizontal
	else if (square[6] == square[7] && square[7] == square[8]) {
		return 1;
	}
	// left vertical
	else if (square[0] == square[3] && square[3] == square[6]) {
		return 1;
	}
	// middle vertical
	else if (square[1] == square[4] && square[4] == square[7]) {
		return 1;
	}
	// right vertical
	else if (square[2] == square[5] && square[5] == square[8]) {
		return 1;
	}
	// top-left bottom-right diagonal
	else if (square[0] == square[4] && square[4] == square[8]) {
		return 1;
	}
	// nobody has won but all moves have been done
	else if (turn == 9) {
		return 0;
	}
	// game still in progress
	else {
		return -1;
	}
}
// Draw the board state
void Board() {

	std::cout << "   |   |   " << std::endl;
	std::cout << " " << square[0] << " | " << square[1] << " | " << square[2] << " " << std::endl;
	std::cout << "___|___|___" << std::endl;
	std::cout << "   |   |   " << std::endl;
	std::cout << " " << square[3] << " | " << square[4] << " | " << square[5] << " " << std::endl;
	std::cout << "___|___|___" << std::endl;
	std::cout << "   |   |   " << std::endl;
	std::cout << " " << square[6] << " | " << square[7] << " | " << square[8] << " " << std::endl;
	std::cout << "   |   |   " << std::endl;
}
