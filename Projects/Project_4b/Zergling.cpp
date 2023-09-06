/*
Title: Zergling.cpp
Author: Alfonso Sebastian Apelacio Martinez
Date: 11/16/2022
Description: Codes the functions defined in Zergling.h
*/
#include "Zergling.h"
const int SPECIAL_ATTACK = 1;

Zergling::Zergling() : Zerg(){

}

Zergling::Zergling(string name, int health) : Zerg(name, health){

}

int Zergling::SpecialAttack(){
    cout << GetName() << " scratches at you ferociously!" << endl;
    cout << GetName() << " does " << SPECIAL_ATTACK << " damage!" << endl;
    return SPECIAL_ATTACK;
}