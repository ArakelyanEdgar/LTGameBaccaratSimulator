#include <iostream>
#include <string>
#include "Statistics.h"

using namespace std;


//intialize wins and ties to 0
Statistics::Statistics(){
    playerWins = 0;
    bankerWins = 0;
    ties = 0;
    cycleCount = 0;
}

Statistics::~Statistics(){
    //nothing to deallocate
}

//getCycleCount() is a getter function for cycleCount
int Statistics::getCycleCount(){
    return cycleCount;
}

//GetPlayerWinCount is a getter function for playerWins
int Statistics::getPlayerWinCount(){
    return playerWins;
}

//GetBankerWinCount is a getter function for bankerWins
int Statistics::getPlayerWinCount(){
    return playerWins;
}

//getTieCount is a getter function for ties
int Statistics::getTieCount(){
    return ties;
}

