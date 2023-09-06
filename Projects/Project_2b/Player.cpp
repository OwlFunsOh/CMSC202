#include "Player.h"
using namespace std;

Player::Player(){
    m_name = "Beannie";
    m_stat[0] = START_STAT;
    m_stat[1] = START_STAT;
    m_stat[2] = START_STAT;
    m_races = 0;
    m_falls = 0;
    m_wins = 0;
}

Player::Player(string name){
    m_name = name;
    m_stat[0] = START_STAT;
    m_stat[1] = START_STAT;
    m_stat[2] = START_STAT;
    m_races = 0;
    m_falls = 0;
    m_wins = 0;
}

string Player::GetName(){
    return m_name;
}

void Player::SetName(string name){
    m_name = name;
}

int Player::GetSpeed(){
    return m_stat[0];
}

int Player::GetAgility(){
    return m_stat[1];
}

int Player::GetJump(){
    return m_stat[2];
}

int Player::GetRaces(){
    return m_races;
}

int Player::GetFalls(){
    return m_falls;
}

void Player::SetRaces(int races){
    m_races = races;
}

void Player::SetFalls(int falls){
    m_falls = falls;
}

void Player::DisplayStatus(){
    cout << "*****The Mighty Racer " << GetName() << "**********" << endl;
    cout << "Races: " << GetRaces() << endl;
    cout << "Wins: " << m_wins << endl;
    cout << "Falls: " << GetFalls() << endl;

    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Stats: " << endl;
    cout << "Speed: " << GetSpeed() << endl;
    cout << "Agility: " << GetAgility() << endl;
    cout << "Jump: " << GetJump() << endl;
}

void Player::IncreaseStat(){
    int answer = 0;
    while(answer < 1 or answer > 3){
    cout << "What stat would you like to increase?" << endl;
    cout << "1. Speed" << endl;
    cout << "2. Agility" << endl;
    cout << "3. Jump" << endl;
    cin >> answer;
    }

    //bool will see if you're able to add one or if it's maxed
    bool validChoice = false;
    while(not validChoice){
        if(answer == 1 and GetSpeed() < 10){
            m_stat[0] += 1;
            validChoice = true;
        }else if(answer == 2 and GetAgility() < 10){
            m_stat[1] += 1;
            validChoice = true;
        }else if(answer == 3 and GetJump() < 10){
            m_stat[2] += 1;
            validChoice = true;
        }else{
            cout << "What stat would you like to increase? " << endl;
        }
    }
}

int Player::GetStat(int stat){
    return m_stat[stat];
}

void Player::IncreaseWins(){
    m_wins += 1;
}