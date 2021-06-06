#include "Players.h"

// initialise new grid in the constructor
Players::Players() {
	pGrid = new Grid;
	pGrid->printGrid();
}

// destory the grid in the destructor
Players::~Players() {
	delete pGrid; 
}

void Players::turn() {
	cout << *pTurn << "'s Turn" << endl;

	// allows the user to select a row and column, reselects if invalid
	cout << "Select row: ";
	cin >> row;
	while (row != 1 && row != 2 && row != 3) {
		cout << endl;
		cout << "Row out of grid. Go Again: ";
		cin >> row;
	}
	cout << "Select column: ";
	cin >> column;
	while (column != 1 && column != 2 && column != 3) {
		cout << endl;
		cout << "Column out of grid. Go Again: ";
		cin >> column;
	}

	// saves rows and columns into array
	position[0] = row;
	position[1] = column;
}


void Players::place(){
	// where should squares variable be used instaed here
	placeIndex = pGrid->gridWidth * ((position[0]*2)-1) + (position[1] * 3) - 2;

	// Redo a move if theres already a piece there
	while (pGrid->grid[placeIndex] != ' ') {
		cout << "Invalid move. Place already taken. Go Again" << endl;
		turn();
		placeIndex = pGrid->gridWidth * ((position[0] * 2) - 1) + (position[1] * 3) - 2;
	}
	// Place an X if it's player 1's move
	if (*pTurn == "Player 1") {
		pGrid->grid[placeIndex] = 'X';
	}
	// Place an O if it's player 2's move
	else {
		pGrid->grid[placeIndex] = 'O';
	}
	
	pGrid->printGrid();
	check();								 // check if someone has won
	pTurn += (int)pow(-1, whichPlayer);		// point to the other player turn
}


void Players::check() {
	
	// check for any horizontal wins
	for (int checkrows = 1; checkrows < 4; checkrows++) {
		int rowpos1 = pGrid->gridWidth * ((checkrows * 2) - 1) + 1;
		int rowpos2 = rowpos1 + 3;
		int rowpos3 = rowpos2 + 3;
		if (pGrid->grid[rowpos1] != ' ' && pGrid->grid[rowpos1] == pGrid->grid[rowpos2] && pGrid->grid[rowpos2] == pGrid->grid[rowpos3]) {
			game = 0; 
		}
	}

	// check for any vertical wins
	for (int checkcolumns = 1; checkcolumns < 4; checkcolumns++) {
		int colpos1 = (checkcolumns * 3) - 2 + pGrid->gridWidth * ((1 * 2) - 1);
		int colpos2 = colpos1 + 2* pGrid->gridWidth;
		int colpos3 = colpos2 + 2 * pGrid->gridWidth; 
		if (pGrid->grid[colpos1] != ' ' && pGrid->grid[colpos1] == pGrid->grid[colpos2] && pGrid->grid[colpos2] == pGrid->grid[colpos3]) {
			game = 0; 
		}
	}

	// check for any forward diagonal wins
	int fdiag1 = pGrid->gridWidth + 1;
	int fdiag2 = pGrid->gridWidth * 3 + 4;
	int fdiag3 = pGrid->gridWidth * 5 + 7;
	if (pGrid->grid[fdiag1] != ' ' && pGrid->grid[fdiag1] == pGrid->grid[fdiag2] && pGrid->grid[fdiag2] == pGrid->grid[fdiag3]) {
		game = 0; 
	}

	// check for any reverse diagonal wins
	int rdiag1 = pGrid->gridWidth + 7;
	int rdiag2 = pGrid->gridWidth * 3 + 4;
	int rdiag3 = pGrid->gridWidth * 5 + 1;
	if (pGrid->grid[rdiag1] != ' ' && pGrid->grid[rdiag1] == pGrid->grid[rdiag2] && pGrid->grid[rdiag2] == pGrid->grid[rdiag3]) {
		game = 0; 
	}

	// if someone has won end game
	if (game == 0) {
		cout << *pTurn << " Wins!!!" << endl;
	}
}