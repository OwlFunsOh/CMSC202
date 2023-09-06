/*
File: Entity.cpp
Project: CMSC 202 - Project 4
Author: Alfonso Sebastian Apelacio Martinez
Date: 11/03/2022
Description: This file contains the coded functions for Entity.h
*/

#include "Entity.h"


Entity::Entity(){
    m_name = "";
    m_health = 0;
}

Entity::Entity(string name, int health){
    m_name = name;
    m_health = health;
}

Entity::~Entity(){
    
}

string Entity::GetName(){
    return m_name;
}

int Entity::GetHealth(){
    return m_health;
}

void Entity::SetName(string name){
    m_name = name;
}

void Entity::SetHealth(int health){
    m_health = health;
}

ostream& operator<<(ostream& output, Entity& myEntity){
    output << "Name: " << myEntity.GetName() << '\n'
    << "HP: " << myEntity.GetHealth();
    return output;
}