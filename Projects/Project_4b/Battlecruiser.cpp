/*
Title: Battlecruiser.cpp
Author: Alfonso Sebastian Apelacio Martinez
Date: 11/16/2022
Description: Codes the functions defined in Battlecruiser.h
*/
#include "Battlecruiser.h"
const int SPECIAL_ATTACK = (rand() % 10) + 3;

Battlecruiser::Battlecruiser() : Terran(){

}

Battlecruiser::Battlecruiser(string name, int health) : Terran(name, health){

}

Battlecruiser::~Battlecruiser(){

}

int Battlecruiser::SpecialAttack(){
    srand(time(NULL));
    cout << GetName() << " uses the Yomato Cannon!" << endl;
    int spAtk = SPECIAL_ATTACK;
    cout << GetName() << " does " << spAtk << " damage!" << endl;   

    return spAtk;
    
}