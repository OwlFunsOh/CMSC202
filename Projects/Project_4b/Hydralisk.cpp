/*
Title: Hydralisk.cpp
Author: Alfonso Sebastian Apelacio Martinez
Date: 11/16/2022
Description: Codes the functions defined in Hydralisk.h
*/
#include "Hydralisk.h"

const int SPECIAL_ATTACK = 2;

Hydralisk::Hydralisk() : Zerg(){

}

Hydralisk::Hydralisk(string name, int health) : Zerg(name, health){

}

int Hydralisk::SpecialAttack(){
    cout << GetName() << " sprays you with deadly acid." << endl;
    cout << GetName() << " does " << SPECIAL_ATTACK << " damage!" << endl;
    return SPECIAL_ATTACK;
}