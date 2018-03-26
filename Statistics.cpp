#include <iostream>
#include <string>
#include "Statistics.h"

using namespace std;


//intialize wins and ties to 0
Statistics::Statistics(){
    playerWins = 0;
    bankerWins = 0;
    ties = 0;
}

//intGetPlayerWinCount is a getter function for playerWins