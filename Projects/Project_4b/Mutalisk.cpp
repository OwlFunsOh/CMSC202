/*
Title: Mutalisk.cpp
Author: Alfonso Sebastian Apelacio Martinez
Date: 11/16/2022
Description: Codes the functions defined in Mutalisk.h
*/
#include "Mutalisk.h"

const int SPECIAL_ATTACK = 4;

Mutalisk::Mutalisk() : Zerg(){

}

Mutalisk::Mutalisk(string name, int health) : Zerg(name, health){

}

int Mutalisk::SpecialAttack(){
    cout << GetName() << " blasts you with their attack." << endl;
    cout << GetName() << " does " << SPECIAL_ATTACK << " damage!" << endl;
    return SPECIAL_ATTACK;
}