/*
File: Terran.cpp
Project: CMSC 202 - Project 4
Author: Alfonso Sebastian Apelacio Martinez
Date: 11/03/2022
Description: This file contains the coded functions for Terran.h
This is the child class of Entity
*/

#include "Terran.h"

Terran::Terran() : Entity(){

}

Terran::Terran(string name, int health) : Entity(name, health){
    
}

Terran::~Terran(){

}

int Terran::Attack(){
    srand(time(NULL));
    int atk = (rand() % 6) + 1;
    cout << GetName() << " attacks dealing " << atk << " damage." << endl;
    return atk;
}

int Terran::SpecialAttack(){
    cout << "Terrans do not have Special attacks" << endl;
    return 0;
}