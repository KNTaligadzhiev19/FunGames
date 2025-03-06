#include <iostream>
#include <string>
#include "TicTacToe.h"
using namespace std;

// try your functions to follow the flow of the game: printTableTicTacToe, turns, checkWinnerTicTacToe
// in this context startTicTacToe should be first but it usses the other functions so it is last as per a function must be declared before it is used
// if you want you can define the startTicTacToe function here as inline function (like in the header file) and the body of the function to be at the end of the file but it is not nessesary and not a good practice I think
void printTableTicTacToe(char table[3][3]) {
    for (int i = 0; i < 3; i++) {
        cout << "-------------" << endl;
        for (int j = 0; j < 3; j++) {
            cout << "| " << table[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-------------" << endl;
}

// I like the recursion you are using here
int turns(bool& player, char table[3][3]) {
    int x = 0;
    int y = 0;

	// better split the commands in two strings to avoid wrongly plased figures
    string input, row, column;

    cout << "Player 1 is X and Player 2 is O" << endl;

    if (player) {
        cout << "Player 1, enter the cell you want to fill: ";
    }
    else {
        cout << "Player 2, enter the cell you want to fill: ";
    }

	// when you use cin >> it reads only the first word cuz cin leaves a new line character in the buffer so we now use cin.ignore() to ignore the new line character
	//otherwise getline will read the new line character and the program will skip the input
	// so it will fail to pass the if clauses below and will prompt the user to enter the input again when the user hasn't even entered an input
    //cin.ignore();
	getline(cin, input);

	// the "top bottom" input will be split into "top" and "bottom" and the program will prompt the user to enter the input again
	// before when it was only cin >> input it was reading only the first word and the program was skipping the if clauses below
	// so I added getline(cin, input) to read the whole line above and now I split the input into two strings that I can use to determine the coordinates
	// here I split the input into two strings
	row = input.substr(0, input.find(" "));
	column = input.substr(input.find(" ") + 1);

    if (row == "top") {

        if (column == "left") {
            cout << "You chose the top left cell" << endl;
			// I like this way of getting the coordinates I would have it done like table[0][0] = (player ? 'X' : 'O'); but your way is smarter
            x = 0;
            y = 0;
        }
        if (column == "middle") {
            cout << "You chose the top middle cell" << endl;
            x = 0;
            y = 1;
        }
        if (column == "right") {
            cout << "You chose the top right cell" << endl;
            x = 0;
            y = 2;
        }
    }
    else if (row == "middle") {

        if (column == "left") {
            cout << "You chose the top left cell" << endl;
            x = 1;
            y = 0;
        }
        if (column == "middle") {
            cout << "You chose the top middle cell" << endl;
            x = 1;
            y = 1;
        }
        if (column == "right") {
            cout << "You chose the top right cell" << endl;
            x = 1;
            y = 2;
        }

    }
    else if (row == "bottom") {

        if (column == "left") {
            cout << "You chose the top left cell" << endl;
            x = 2;
            y = 0;
        }
        if (column == "middle") {
            cout << "You chose the top middle cell" << endl;
            x = 2;
            y = 1;
        }
        if (column == "right") {
            cout << "You chose the top right cell" << endl;
            x = 2;
            y = 2;
        }
    }
    else if (input == "exit") {
        cout << "Goodbye!" << endl;
		return 0;
    }
    else {
        cout << "Invalid input. Please try again." << endl;
        turns(player, table);
    } 

    if (table[x][y] == 'X' || table[x][y] == 'O') {
        cout << "This cell is already filled. Please choose another one." << endl;
        turns(player, table);  // retry
    }
    else {
        table[x][y] = (player ? 'X' : 'O');
        player = !player;
        //return 1;
    }
}

int checkWinnerTicTacToe(char table[3][3]) {
    for (int i = 0; i < 3; i++) {
        
        if (table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][0] != ' ') {
            cout << "Player " << table[i][0] << " wins!" << endl;
            return 1;//row check
        }
        
        if (table[0][i] == table[1][i] && table[1][i] == table[2][i] && table[0][i] != ' ') {
            cout << "Player " << table[0][i] << " wins!" << endl;
			return 1;//column check
        }
    }
    
    if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0] != ' ') {
        cout << "Player " << table[0][0] << " wins!" << endl;
		return 1;//diagonal check
    }
    if (table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[0][2] != ' ') {
        cout << "Player " << table[0][2] << " wins!" << endl;
		return 1;//diagonal check
    }
    return 0;
}

int startTicTacToe() {
    char table[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

	// btw placing count on last plase saved you 18 kb of memory :)
	// it actually didn't save memory but avoided memory padding
	// this is the magic of memory alignment
	// not a grat deal in this case but in bigger projects it can save a lot of memory
	// and if you are working on a microcontroller with hilariously small memory as older or cheaper arduinos it can save you a lot of time figuring out wich variable to remove to make the program fit in the memory
	// so bear in mind to align the variables from smallest to biggest
	// this happens because the compiler aligns the variables in memory to the size of the biggest variable in the struct
	// which means that if you have a char and an int in a struct the char will be aligned to the size of the int
	// this is a safety feature to prevent memory leaks and overflows cuz this way the compiler will not accidentally write in the next variable
	// and following this if you have a double and a char the char will be aligned to the size of the double (8 bytes instead of 1)
    bool player = true;
    char playAgain;
    short count = 0;
    
    cout << "Welcome to Tic Tac Toe!" << endl;
	cout << "Type 'top' for the top row, 'middle' for the middle row, and 'bottom' for the bottom row." << endl;
	cout << "Type 'left' for the left column, 'middle' for the middle column, and 'right' for the right column." << endl;
	cout << "For example, type 'top left' to place your piece in the top left cell." << endl;
    cout << "To exit type 'exit'." << endl;

    printTableTicTacToe(table);

    do {
        while (count < 9) {
           
            if (!turns(player, table)) break;
            count++;
            printTableTicTacToe(table);
            if (checkWinnerTicTacToe(table)) {
                break;
            }
            else if (count == 9) {
                cout << "It's a draw!" << endl;
            }
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'y') {
            count = 0;
            player = true;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    table[i][j] = ' ';
                }
            }
            printTableTicTacToe(table);
        }
        else {
            cout << "Goodbye!" << endl;
        }
    } while (playAgain == 'y');

    return 0;
}
