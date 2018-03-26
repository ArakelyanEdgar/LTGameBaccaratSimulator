//Made by Edgar Arakelyan
//Baccarat simulator
//run with: "./baccaratSimulator.exe -c <shoeCycles> -s <numberOfShufflesPerCycle>"

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
    //BANKER DRAWING RULES TABLE-----------------
    vector<vector<int>> bankerDrawingRulesTable;

    for (int i = 0; i < 7; i++){
        if (i <= 4){
            vector<int> row(10, 1);
            bankerDrawingRulesTable.push_back(row);
        }
        else{
            vector<int> row(10, 0);
            bankerDrawingRulesTable.push_back(row);
        }
    }

    //referring to wizardofodd's banker drawing rules table
    bankerDrawingRulesTable[3][8] = 0;
    bankerDrawingRulesTable[4][0] = 0;
    bankerDrawingRulesTable[4][1] = 0;
    bankerDrawingRulesTable[4][8] = 0;
    bankerDrawingRulesTable[4][9] = 0;
    bankerDrawingRulesTable[5][4] = 1;
    bankerDrawingRulesTable[5][5] = 1;
    bankerDrawingRulesTable[5][6] = 1;
    bankerDrawingRulesTable[5][7] = 1;
    bankerDrawingRulesTable[6][6] = 1;
    bankerDrawingRulesTable[6][7] = 1;




    //initialize game
    Statistics gameStats;
    Shoe gameShoe;
    User player;
    User banker;

    string card;

    //run CYCLELIMIT iterations
    while(gameStats.getCycleCount() < CYCLELIMIT){
        cout << gameStats.getCycleCount() << endl;

        //initiate a new shoe cycle
        int playerValue = 0;
        int bankerValue = 0;
        int playerThirdCardValue = 0;
        bool natural = false;
        bool playerDrewThirdCard = false;
        gameShoe.newCycle();
        
        //shuffle the shoe SHUFFLESPERSHOE times
        for (int i = 0; i < SHUFFLESPERSHOE; i++){
            gameShoe.shuffleShoe();
        }

        //deal two cards to player and banker, alternating
        //between both users like how it is done in real life
        card = gameShoe.dealCard();
        player.drawCard(card);
        card = gameShoe.dealCard();
        banker.drawCard(card);
        card = gameShoe.dealCard();
        player.drawCard(card);
        card = gameShoe.dealCard();
        banker.drawCard(card);
        
        //retrieve player and banker's two card hand value
        playerValue = player.GetHandValue();
        bankerValue = banker.GetHandValue();

        //determine if either player or banker has a natural hand (hand valued at 8 or 9)
        if (playerValue == 9 || playerValue == 8 || bankerValue == 8 || bankerValue == 9){
            natural = true;
        }

        //if not natural then determine if player can draw a third card
        if (!natural && playerValue <= 5){
            card = gameShoe.dealCard();
            player.drawCard(card);
            playerDrewThirdCard = true;
        }

        //if player didn't draw a card then banker can draw a card if a hand total of 5 or less
        if (!playerDrewThirdCard && bankerValue <= 5){
            card = gameShoe.dealCard();
            banker.drawCard(card);
        }

        //if player did draw a third card then we must determine if banker draws third card
        //depending on The BANKER DRAWING RULES table
        if (playerDrewThirdCard && bankerValue <= 6){
            playerThirdCardValue = player.GetHandValue() - playerValue;
            
            if (bankerDrawingRulesTable[bankerValue][playerThirdCardValue] == 1){
                card = gameShoe.dealCard();
                banker.drawCard(card);
            }
        }

        //recalculate player and banker values
        playerValue = player.GetHandValue();
        bankerValue = banker.GetHandValue();

        cout << "Player's hand: ";
        player.printHand();
        cout << "Banker's hand: ";
        banker.printHand();

        //record win type, note that increment functions increment cyclecount
        if (playerValue > bankerValue)
            gameStats.playerWinIncrement();
        if (playerValue == bankerValue)
            gameStats.bankerWinIncrement();
        if (playerValue == bankerValue)
            gameStats.tieIncrement();

        //reset user hands
        player.resetHand();
        banker.resetHand();
    }



    return 0;
}
