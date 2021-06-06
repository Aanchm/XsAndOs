#include <iostream>
#include "Grid.h"
#include "Players.h"
using namespace std; 

/*
1. tidy and finish up code (commenting, member variables)
*/

int main(){

    string restart = "Y";

    while (restart == "Y") {
        Players players;

        while (players.whichPlayer < 9 && players.game == 1) {
            players.turn();
            players.place();
            players.whichPlayer++;
        }

        if (players.whichPlayer == 8 && players.game == 1) {
            cout << "It's a draw";
        }


        cout << "Restart (Y/N)?" << endl;
        cin >> restart;

    }

}
