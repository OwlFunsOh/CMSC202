/*
Title: Area.cpp
Date: 11/11/2022
Description: This codes the functions from Area.h
*/

#include "Area.h"

Area::Area(int id, string name, string description, int north, int east, 
    int south, int west){
        m_ID = id;
        m_name = name;
        m_desc = description;
        m_direction[0] = north;
        m_direction[1] = east;
        m_direction[2] = south;
        m_direction[3] = west;
}

string Area::GetName(){
    return m_name;
}

int Area::GetID(){
    return m_ID;
}

string Area::GetDesc(){
    return m_desc;
}

int Area::CheckDirection(char myDirection){
    if(myDirection == 'n' or myDirection == 'N'){
        return m_direction[n];
    }else if(myDirection == 'e' or myDirection == 'E'){
        return m_direction[e];
    }else if (myDirection == 's' or myDirection == 'S'){
        return m_direction[s];
    }else if(myDirection == 'w' or myDirection == 'W'){
        return m_direction[w];
    }else{
        return -1;
    }
}

void Area::PrintArea(){
    cout << GetName() << endl;
    cout << GetDesc() << endl;

    string exits = "";
    if(m_direction[0] != -1){
        exits = exits + "N";
    }
    if(m_direction[1] != -1){
        exits = exits + " E";
    }
    if(m_direction[2] != -1){
        exits = exits + " S";
    }
    if(m_direction[3] != -1){
        exits = exits + " W";
    }

    cout << "Possible Exits: " << exits << endl;
}