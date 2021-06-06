#pragma once

#include <iostream>

using namespace std; 

class Grid {
private: //do all these variables need to be static and const. use squares constantly
	static const int squares = 3;
public:	
	static const int gridWidth = squares * 3;
	static const int gridHeight = (squares * 2) + 1;
	char* grid;

public:
	Grid();
	~Grid();
	void printGrid();
};