#include <iostream>
#include <string>
#include <iomanip>
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
int Statistics::getBankerWinCount(){
    return bankerWins;
}

//getTieCount is a getter function for ties
int Statistics::getTieCount(){
    return ties;
}

void Statistics::playerWinIncrement(){
    playerWins++;
    cycleCount++;
}

void Statistics::bankerWinIncrement(){
    bankerWins++;
    cycleCount++;
}

void Statistics::tieIncrement(){
    ties++;
    cycleCount++;
}

void Statistics::outputStats(){
    int totalCount = playerWins + bankerWins + ties;
    
    float playerPercentage = (playerWins*100.0) / totalCount;
    float bankerPercentage = (bankerWins*100.0) / totalCount;
    float tiesPercentage = (ties*100.0) / totalCount;
    
    cout << "_____________________BACCARAT SIMULATION OUTCOMES_______________________________" << endl << endl;
    
    cout << setw(5) << "|  PLAYER WINS: " << playerWins  << "  PROBABILITY  " << setprecision(8) << playerPercentage << "%" << endl;;
    cout << setw(5) << "|  BANKER WINS: " << bankerWins << "  PROBABILITY  " << setprecision(8) << bankerPercentage << "%" << endl;
    cout << setw(5) << "|  TIES: " << ties <<"  PROBABILITY  " << setprecision(8) <<  tiesPercentage << "%" << endl;
    cout << "________________________________________________________________________________" << endl << endl;

    cout << "_____________________BACCARAT SIMULATION BANKER BET RETURNS_____________________"<< endl << endl;
    cout << "BANKER WIN PAYS 0.95  |   PROBABILITY:  " << setprecision(5) << bankerPercentage << "%         |  RETURN: " <<   (.95*bankerPercentage)/100 << endl;
    cout << "PLAYER WIN PAYS -1.0  |   PROBABILITY:  " << setprecision(5) << playerPercentage << "%         |  RETURN: " <<   (-1*playerPercentage)/100 << endl;
    cout << "TIE WIN PAYS 0        |   PROBABILITY:  " << setprecision(5) << tiesPercentage <<   "%           |  RETURN: " <<   0 << endl << endl;
    cout << "NET RETURN:  " << (.95*bankerPercentage)/100 + (-1*playerPercentage)/100 << endl << endl;

    cout << "_____________________BACCARAT SIMULATION PLAYER BET RETURNS_____________________"<< endl << endl;
    cout << "BANKER WIN PAYS -1.0  |   PROBABILITY:  " << setprecision(5) << bankerPercentage << "%   |  RETURN: " <<   (-1*bankerPercentage)/100 << endl;
    cout << "PLAYER WIN PAYS  1.0  |   PROBABILITY:  " << setprecision(5) << playerPercentage << "%   |  RETURN: " <<   (playerPercentage)/100 << endl;
    cout << "TIE WIN PAYS 0        |   PROBABILITY:  " << setprecision(5) << tiesPercentage << "%     |  RETURN: " <<   0 << endl << endl;
    cout << "NET RETURN:  " << (-1*bankerPercentage)/100 + (playerPercentage)/100 << endl << endl;

    cout << "_____________________BACCARAT SIMULATION TIE BET RETURNS________________________"<< endl << endl;
    cout << "BANKER WIN PAYS -1.0  |   PROBABILITY:  " << setprecision(5) << bankerPercentage << "%   |  RETURN: " <<   (-1*bankerPercentage)/100 << endl;
    cout << "PLAYER WIN PAYS -1.0  |   PROBABILITY:  " << setprecision(5) << playerPercentage << "%   |  RETURN: " <<   (-1*playerPercentage)/100 << endl;
    cout << "TIE WIN PAYS 8        |   PROBABILITY:  " << setprecision(5) << tiesPercentage << "%     |  RETURN: " <<   (8*tiesPercentage)/100 << endl << endl;
    cout << "NET RETURN:  " << (-1*bankerPercentage)/100 + (-1*playerPercentage)/100 + (8*tiesPercentage)/100 << endl << endl;

    cout << "MADE BY EDGAR ARAKELYAN :)" << endl;
}

