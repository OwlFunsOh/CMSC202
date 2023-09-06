/*
Filename: Playlist.cpp
Author: Alfonso Sebastian Apelacio Martinez
Date: 11/01/2022
Description: Contains the coded functions for Playlist.h
Contains playlist actions/modifications

*/
#include "Playlist.h"

Playlist::Playlist(){
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

Playlist::~Playlist(){
    Song* temp = m_head;
    m_tail = nullptr;
    while(m_head != nullptr){
        m_head = m_head -> GetNext();
        delete temp;
        temp = m_head;
    }
}

void Playlist::AddSong(string title, string artist, int year, int rank){
    Song* newSong = new Song(title, artist, year, rank);
    if(m_head == nullptr){
        m_head = newSong;
        m_tail = newSong;
    }else{
        m_tail -> SetNext(newSong);
        m_tail = newSong;
    }

    m_size += 1;
}

Song* Playlist::GetPlaylistDetails(int location){
    Song* song = m_head;
    for(int i = 0; i < location; i++){
        song = song -> GetNext();
    }

    return song;
}

int Playlist::Size(){
    return m_size;
}

void Playlist::PlayAt(int location){
    Song* currSong = m_head;
    Song* prevSong = nullptr;

    for(int i = 0; i < location; i++){
        prevSong = currSong;
        currSong = currSong -> GetNext();
    }

    if(m_head == m_tail){ //case 1: m_head = m_tail
        m_head = nullptr;
        m_tail = nullptr;
        delete currSong;
    }else if(currSong == m_head){ // case 2: delete the beginning
        m_head = m_head -> GetNext();
        delete currSong;
    }else if(currSong != m_head and currSong != m_tail){ //case 3: Delete the middle
        prevSong -> SetNext(currSong -> GetNext());
        delete currSong;
    }else{ // case 4: delete the end
        m_tail = prevSong;
        m_tail -> SetNext(nullptr);
        delete currSong;

    }
        currSong = nullptr;
        prevSong = nullptr;
        m_size -= 1;
}