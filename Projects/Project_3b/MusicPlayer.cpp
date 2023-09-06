/*
Filename: MusicPlayer.cpp
Author: Alfonso Sebastian Apelacio Martinez
Date: 11/01/2022
Description: Contains the coded functions for MusicPlayer.h
Main Menu actions

*/
#include "MusicPlayer.h"
using namespace std;

MusicPlayer::MusicPlayer(){
    m_playList = new Playlist;
}

MusicPlayer::~MusicPlayer(){
    for(unsigned int i = 0; i < m_songCatalog.size(); i++){
        delete m_songCatalog[i];
        m_songCatalog[i] = nullptr;
    }
    m_songCatalog.clear();
    delete m_playList;
}

void MusicPlayer::LoadCatalog(string filename){
    ifstream songCatalogFile(filename); //opens the file
    while(!(songCatalogFile.is_open())){
        cout << "The file was not opened" << endl;
        cout << "Please type the name of the file you would like to open" << endl;
        cin >> filename;
    }

    string title;
    string artist;
    string year;
    string rank;
    int intYear = 0;
    int intRank = 0;
    int counter = 0;
    Song* songPointer = nullptr;

    while(getline(songCatalogFile, title, DELIMITER)){
        getline(songCatalogFile, artist, DELIMITER);
        getline(songCatalogFile, year, DELIMITER);
        getline(songCatalogFile, rank);

        //change year and rank to ints
        intYear = stoi(year);
        intRank = stoi(rank);

        //make the song object
        songPointer = new Song(title, artist, intYear, intRank);
        m_songCatalog.push_back(songPointer);

        //reset song pointer
        songPointer = nullptr;

        counter += 1;
    }

    cout << "Songs Loaded: " << counter << endl;

}

void MusicPlayer::MainMenu(){

    int answer = 0;
    bool quit = false;
    while((answer < 1 or answer > 5) and (not (quit))){
        cout << "What would you like to do?" << endl;
        cout << "1. Display Songs by Year" << endl;
        cout << "2. Add Song" << endl;
        cout << "3. Display Playlist" << endl;
        cout << "4. Play Song" << endl;
        cout << "5. Quit" << endl;

        cin >> answer;

        if(answer == 1){
            DisplaySongs();
        }else if(answer == 2){
            AddSong();
        }else if(answer == 3){
            DisplayPlaylist();
        }else if(answer == 4){
            PlaySong();
        }else if(answer == 5){
            quit = true;
        }

        answer = 0;
    }
}

void MusicPlayer::DisplaySongs(){
    int answer = 0;

    while(answer < LOW_YEAR or answer > HIGH_YEAR){
        cout << "Which year would you like to display?" << endl;
        cin >> answer;
    }

    cout << "******" << answer << "*****" << endl;

    for(unsigned int i = 0; i < m_songCatalog.size(); i++){
        if(m_songCatalog[i] -> GetYear() == answer){
            cout << i + 1 << ". " << *m_songCatalog[i] << endl;
        }
    }
}

void MusicPlayer::AddSong(){
    DisplayPlaylist();
    cout << "Choose the songs you would like to add to the playlist" << endl;
    DisplaySongs();

    int answer = 0;
    while(answer < 1 or answer > 1200){
        cout << "Enter the number of the song you would like to add" << endl;
        cin >> answer;
    }

    Song* song = m_songCatalog[answer - 1];
    //m_playList = new Playlist();
    m_playList -> AddSong(song -> GetTitle(), song -> GetArtist(), song -> GetYear(), song -> GetRank());

}

void MusicPlayer::DisplayPlaylist(){
    Song* song = nullptr;
    if(m_playList -> Size() == 0){
        cout << "*** Current Playlist is Empty ***" << endl;
    }else{
        cout << "Your Playlist" << endl;
        for(int i = 0; i < m_playList -> Size(); i++){ //will display songs in current playlist
            song = m_playList -> GetPlaylistDetails(i);
            cout << i + 1 << ". " << *song << endl;
        }
    }

    song = nullptr;
}

void MusicPlayer::PlaySong(){
    DisplayPlaylist();

    if(m_playList -> Size() != 0){
        int answer = 0;
        while(answer < 1 or answer > m_playList -> Size()){
            cout << "Which song would you like to play?" << endl;
            cin >> answer;
        }

        m_playList -> PlayAt(answer - 1);
    }
}