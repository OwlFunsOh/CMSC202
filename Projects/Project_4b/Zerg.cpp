/*
File: Zerg.cpp
Project: CMSC 202 - Project 4
Author: Alfonso Sebastian Apelacio Martinez
Date: 11/03/2022
Description: This file contains the coded functions for Zerg.h
This is the child class of Entity
*/

#include "Zerg.h"
const int ZERG_ATTACK = 1;

Zerg::Zerg() : Entity(){

}

Zerg::Zerg(string name, int health) : Entity(name, health){

}

int Zerg::Attack(){
    cout << GetName() << " deals " << ZERG_ATTACK << " point of damage!" << endl;
    return ZERG_ATTACK;
}