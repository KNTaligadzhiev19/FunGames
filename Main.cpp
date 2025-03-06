#include <iostream>
#include "Connect4.h"
#include "TicTacToe.h"
using namespace std;

int main() {

	int choice = 0;

	/* your way worked too and is purfectly fine 
	but this is another way to do it that garuntees 
	the program will execute at least once and again 
	no problem to use yours as much as it works this 
	is just different coding style */
	
	do {
		cout << "MENU" << endl;
		cout << "1. Tic Tac Toe" << endl;
		cout << "2. Connect 4" << endl;
		cout << "3. Exit" << endl;

		cin >> choice;

		if (choice == 1) startTicTacToe();
		else if (choice == 2) startConnect4();
		// altrenalte way is to set exit to 0 and use the while loop to exit
		else if (choice == 3) { cout << "Goodbye!" << endl; choice = 0; }
		else cout << "Invalid choice. Please try again." << endl;
	} while (choice);
	
	return 0;
}
