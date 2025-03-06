#include <iostream>
#include "Connect4.h"
using namespace std;

// try your functions to follow the flow of the game: printTableConnect4, turns, checkWinerConnect4
void printTableConnect4(char connect4table[6][7]) {
	for (int i = 0; i < 6; i++) {
		cout << "-----------------------------" << endl;
		for (int j = 0; j < 7; j++) {
			cout << "| " << connect4table[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "-----------------------------" << endl;
	for (int j = 0; j < 7; j++) {
		cout << "| " << j + 1 << " ";
	}
	cout << "|" << endl;
}

void turns(bool& player, short& count, int& column, char conncect4table[6][7]) {

	cout << "Which column do you want to place your piece in?" << endl;

	if (column < 1 || column > 7 || (conncect4table[0][column - 1] == 'X' || conncect4table[0][column - 1] == 'O')) {
		cout << "Invalid or full column, please pick another." << endl;
		count--;
	}
	else {

		for (int i = 5; i >= 0; i--)
		{

			if (conncect4table[i][column - 1] == ' ')
			{
				player ? conncect4table[i][column - 1] = 'X' : conncect4table[i][column - 1] = 'O';
				break;
			}

		}
		player = !player;
	}
}

int checkWinerConnect4(char connect4table[6][7]) {
	int countX = 0;
	int countO = 0;				
	
	for (int i = 0; i < 6; i++) { //horizontal
		countX = 0;
		countO = 0;
		for (int j = 0; j < 7; j++) {
			if (connect4table[i][j] == 'X') {
				countO = 0;
				countX++;
				if (countX == 4) {
					cout << "Player X wins!" << endl;
					return 1;
				}
			}
			else if (connect4table[i][j] == 'O') {
				countX = 0;
				countO++;
				if (countO == 4) {
					cout << "Player O wins!" << endl;
					return 2;
				}
			}
		}
	}

	for (int i = 0; i < 7; i++) {    //vertical
		countX = 0;
		countO = 0;
		for (int j = 0; j < 6; j++) {
			if (connect4table[j][i] == 'X') {
				countO = 0;
				countX++;
				if (countX == 4) {
					cout << "Player X wins!" << endl;
					return 1;
				}
			}
			else if (connect4table[j][i] == 'O') {
				countX = 0;
				countO++;
				if (countO == 4) {
					cout << "Player O wins!" << endl;
					return 1;
				}
			}
		}
	}

	//diagonal right to left
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (connect4table[i][j] == 'X' && connect4table[i + 1][j + 1] == 'X' && connect4table[i + 2][j + 2] == 'X' && connect4table[i + 3][j + 3] == 'X') {
				cout << "Player X wins!" << endl;
				return 1;
			}
			else if (connect4table[i][j] == 'O' && connect4table[i + 1][j + 1] == 'O' && connect4table[i + 2][j + 2] == 'O' && connect4table[i + 3][j + 3] == 'O') {
				cout << "Player O wins!" << endl;
				return 2;
			}
		}
	}

	//diagonal left to right
	for (int i = 0; i < 3; i++) {
		for (int j = 3; j < 7; j++) {
			if (connect4table[i][j] == 'X' && connect4table[i + 1][j - 1] == 'X' && connect4table[i + 2][j - 2] == 'X' && connect4table[i + 3][j - 3] == 'X') {
				cout << "Player X wins!" << endl;
				return 1;
			}
			else if (connect4table[i][j] == 'O' && connect4table[i + 1][j - 1] == 'O' && connect4table[i + 2][j - 2] == 'O' && connect4table[i + 3][j - 3] == 'O') {
				cout << "Player O wins!" << endl;
				return 2;
			}
		}
	}
	return 0;
}

int startConnect4() {

	char connect4table[6][7];
	bool player = true;
	char playAgain;
	short count = 0;
	int column;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++) {
			connect4table[j][i] = ' ';
		}
	}
	cout << "Welcome to Connect 4!" << endl;
	cout << "Player 1 is X and Player 2 is O." << endl;
	cout << "Type '0' to quit." << endl;
	cout << "It is strongly advised to use the numbers 1-7 to place your piece and not letters/words." << endl;
	printTableConnect4(connect4table);
	
	do {
		while (count < 41) {
		
			cin >> column;
			count++;
			if (column == 0) break;  
			else turns(player, count, column, connect4table);
			
			printTableConnect4(connect4table);
			if (checkWinerConnect4(connect4table) || column == 0) {
				
				break;
			} 
			else if (count == 41) {
				cout << "It's a draw!" << endl;
			}
			
		}
		
		cout << "Play again? (y/n): ";
		cin >> playAgain;

		if (playAgain == 'y') {
			count = 0;
			player = true;

			for (int i = 0; i < 7; i++) {
				for (int j = 0; j < 6; j++) {
					connect4table[j][i] = ' ';
				}
			}
			printTableConnect4(connect4table);
		}
		else {
			cout << "Goodbye!" << endl;
		}	
	} while (playAgain == 'y');

	return 0;
}