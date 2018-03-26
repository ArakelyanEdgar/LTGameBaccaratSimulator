//Made by Edgar Arakelyan
//User is a class to hold Player and Banker instances

#include <iostream>
#include <string>
#include <vector>
#include "User.h"

using namespace std;

//User() doesn't have anything to do
User::User(){
    //nothing to initialize
}

//~User() has nothing to do
User::~User(){
    //nothing
}

//drawCard() will add the card into the User's hand
void User::drawCard(string card){
    hand.push_back(card);
}   

//resetHand() will simply reset User's hand to empty set
void User::resetHand(){
    hand.clear();
}

//getHandValue() will calculate the value of the hand per baccarat rules
int User::GetHandValue(){
    int cardSum = 0;
    
    //get net points for individual cards in hand
    for (int i = 0; i < hand.size(); i++){
        string card = hand[i];
        if (card == "J" || card == "Q" || card == "K")
            continue;
        else if (card == "A")
            cardSum += 1;
        else
            cardSum += stoi(card);
    }

    //Baccarat only uses rightmost digit
    return cardSum % 10;
}

//printHand() will print the cards in user's hand
void User::printHand(){
    for (int i = 0; i < hand.size(); i++){
        cout << hand[i] << " ";
    }
    cout << endl;
}

