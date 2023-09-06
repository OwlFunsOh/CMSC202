/*
Title: Ghost.cpp
Author: Alfonso Sebastian Apelacio Martinez
Date: 11/16/2022
Description: Codes the functions defined in Ghost.h
*/
#include "Ghost.h"

const int SPECIAL_ATTACK = (rand() % 11) + 2;
Ghost::Ghost() : Terran(){

}

Ghost::Ghost(string name, int health) : Terran(name, health){

}

Ghost::~Ghost(){

}

int Ghost::SpecialAttack(){
    srand(time(NULL));
    int spAtk = SPECIAL_ATTACK;
    cout << GetName() << " performs a sneak attack!" << endl;
    cout << GetName() << " does " << spAtk << " damage!" << endl;
    return spAtk;
}