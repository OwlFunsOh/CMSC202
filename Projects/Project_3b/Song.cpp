/*
Filename: Song.cpp
Author: Alfonso Sebastian Apelacio Martinez
Date: 11/01/2022
Description: Contains the coded functions for Song.h
Contains basic linked list structure for song

*/#include "Song.h"
using namespace std;

Song::Song(){
    m_title = "New Title";
    m_artist = "New Artist";
    m_rank = 0;
    m_year = 0;
    m_next = nullptr;
}

Song::Song(string title, string artist, int year, int rank){
    m_title = title;
    m_artist = artist;
    m_rank = rank;
    m_year = year;
    m_next = nullptr;
}

string Song::GetTitle(){
    return m_title;
}

string Song::GetArtist(){
    return m_artist;
}

int Song::GetYear(){
    return m_year;
}

int Song::GetRank(){
    return m_rank;
}

void Song::SetTitle(string title){
    m_title = title;
}

void Song::SetArtist(string artist){
    m_artist = artist;
}

void Song::SetYear(int year){
    m_year = year;
}

void Song::SetRank(int rank){
    m_rank = rank;
}

Song* Song::GetNext(){
    return m_next;
}

void Song::SetNext(Song* song){
    m_next = song;
}