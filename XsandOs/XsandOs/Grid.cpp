#include "Grid.h"

// constructor creates empty grid
Grid::Grid() {
    cout << "New Game Started!" << endl;
    cout << "Enter row and column numbers between 1 and 3" << endl;

    grid = new char[gridHeight*gridWidth]; // explain here
    
    // creates empty grid array
    int row = 0;
    for (int i = 0; i < gridHeight-1; i+=2) {
        for (int j = 0; j < gridWidth; j += 3) {
            grid[row + j] = ' '; 
            grid[row + j + 1] = '-';
            grid[row + j + 2] = ' '; 
        }
        row += gridWidth;
        for (int j = 0; j < gridWidth; j += 3) {
            grid[row + j] = '|';
            grid[row + j + 1] = ' ';
            grid[row + j + 2] = '|';
        }
        row += gridWidth;
    }
    for (int j = 0; j < gridWidth; j += 3) {
        grid[row + j] = ' ';
        grid[row + j + 1] = '-';
        grid[row + j + 2] = ' ';
    }

}

// destroys the grid and ends the game
Grid::~Grid() {
    delete[] grid;
    cout << "Game Ended" << endl;
    cout << endl;
}

// print the grid
void Grid::printGrid() {
    for (int i = 0; i < gridWidth * gridHeight; i++) {
        if (i % gridWidth == 0) {
            cout << endl;
        }
        cout << grid[i];
    }
    cout << endl;
    cout << endl;
}