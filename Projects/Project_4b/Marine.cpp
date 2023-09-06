/*
File: Marine.cpp
Project: CMSC 202 - Project 4
Author: Alfonso Sebastian Apelacio Martinez
Date: 11/03/2022
Description: This file contains the coded functions for Marine.h
This is the child class of Terran and Grandchild of Entity
*/

#include "Marine.h"

Marine::Marine() : Terran(){

}

Marine::Marine(string name, int health) : Terran(name, health){

}

Marine::~Marine(){
    
}

int Marine::SpecialAttack(){
    cout << GetName() << " spins up doing GATLING DAMAGE!" << endl;
    srand(time(NULL)); //seeds the random generator
    int specialAtk = (rand() % 8) + 1;
    cout << GetName() << " does " << specialAtk << " damage!" << endl;
    return specialAtk;
}