//Made by EDGAR ARAKELYAN
//Implementation file for Shoe.h

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Shoe.h"

using namespace std;


//Shoe constructor will initialize the 8-deck shoe 
//by calling newCycle and initalizes cycleCount to 0
Shoe::Shoe(){
    CycleCount = 0;
    //newCycle will increment CycleCount and generate a random deck
    Shoe::newCycle();
}

//Destructor for Shoe
Shoe::~Shoe(){
    //Destructor isn't actually necessary currently
}

//Getter function for CycleCount
int Shoe::getCycleCount(){
    return CycleCount;
}

//newCycle will generate a new 8-deck shoe, shuffle the deck,
//and then increment CycleCount
void Shoe::newCycle(){
    
    //reset shoe if it is not empty
    if (!shoe.empty()){
        shoe.clear();
    }

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

    //shuffle the shoe and increment cycle count
    Shoe::shuffleShoe();
    CycleCount++;
}

//randomFunc is a custom random generator function used for 
//random_shuffle called in shuffleShoe()
int Shoe::randomFunc(int i){
    return rand() % i;
}

//shuffleShoe will shuffle the shoe using a random sort
void Shoe::shuffleShoe(){
    //seed value
    srand(unsigned( time(0)) );

    random_shuffle(shoe.begin(), shoe.end(), Shoe::randomFunc);
}

//dealCard returns a card from the top of shoe and removesthe card from the shoe
string Shoe::dealCard(){
    string card = shoe.back();
    shoe.pop_back();
    return card;
}

