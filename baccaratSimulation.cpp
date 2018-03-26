//Made by Edgar Arakelyan
//Baccarat simulator
//run with: "./baccaratSim.exe -c <shoeCycles> -s <numberOfShufflesPerCycle>"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "Shoe.h"
#include "User.h"
#include "Statistics.h"

int main(int argc, char *argv[]){

    int CYCLELIMIT;
    int SHUFFLESPERSHOE;
    stringstream ss,tt;

//VERIFY COMMAND LINE ARGUMENTS------------------------------------
    if (argc == 1){
        cout << "Usage: baccaratSim -c <shoeCycles> -s <numberOfShufflesPerShoeCycle>" << endl;
        exit(1);
    }

    if (argc != 5){
        cout << "Error, invalid command line options" << endl;
        exit(1);
    }

    if (string(argv[1]) != "-c"){
        cout << "Error, invalid shoeCyle option" << endl;
        exit(1);
    }

    if (string(argv[3]) != "-s"){
        cout << "Error, invalid shuffles per cycle option" << endl;
        exit(1);
    }

    if (string(argv[2]) != ""){
        ss << argv[2];
        ss >> CYCLELIMIT;
    }

    if (string(argv[4]) != ""){
        tt << argv[4];
        tt >> SHUFFLESPERSHOE;
    }

    if (CYCLELIMIT < 1 || SHUFFLESPERSHOE < 1){
        cout << "Error, shoe cycles and shuffles per shoe must be a greater than 1" << endl;
        exit(1);
    }
//---------------------------------------------------------------
    
    //initialize game
    Statistics gameStats;

    //run CYCLELIMIT iterations
    while(gameStats.getCycleCount() < CYCLELIMIT){

    }


    return 0;
}
