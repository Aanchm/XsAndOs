#pragma once
#include <iostream>
#include "Grid.h"

using namespace std;

class Players
{
public: 
	//work out which of these should be const static public/private
	int whichPlayer = 0; 
	int game = 1; 

	int row = 0;
	int column = 0; 
	int position[2] = {};
	int placeIndex = 0;

	string playernames[2] = { "Player 1", "Player 2"};
	string* pTurn = playernames; // points to a player
	// look at how this works
	Grid* pGrid; 

public: 
	Players();
	~Players();
	void turn();
	void place();
	void check();

};

