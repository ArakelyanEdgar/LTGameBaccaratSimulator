//Made by EDGAR ARAKELYAN
//Implementation file for Shoe.h

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include "Shoe.h"

using namespace std;


//Shoe constructor will initialize the 8-deck shoe 
//by calling newCycle
Shoe::Shoe(){
    //newCycle will increment CycleCount and generate a random deck
    Shoe::newCycle();
}

//Destructor for Shoe
Shoe::~Shoe(){
    //Destructor isn't actually necessary currently
}

//newCycle will generate a new 8-deck shoe, shuffle the deck,
//and then increment CycleCount
void Shoe::newCycle(){
    
    //reset shoe if it is not empty
    if (!shoe.empty())
        shoe.erase(shoe.begin(), shoe.end());

    //placing 32 ace cards
    shoe.insert(shoe.begin(), 32, "A");

    //adding the pip cards (2-10) to the shoe
    for (int i = 2; i <= 10; i++){
        shoe.insert(shoe.begin(), 32, to_string(i));
    }

    //placing 32 J, Q, K cards
    shoe.insert(shoe.begin(), 32, "J");
    shoe.insert(shoe.begin(), 32, "Q");
    shoe.insert(shoe.begin(), 32, "K");
}

//shuffleShoe will shuffle the shoe using a random sort
void Shoe::shuffleShoe(){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(shoe.begin(), shoe.end(), default_random_engine(seed));
}

//dealCard returns a card from the top of shoe and removesthe card from the shoe
string Shoe::dealCard(){
    string card = shoe.back();
    shoe.pop_back();
    return card;
}

