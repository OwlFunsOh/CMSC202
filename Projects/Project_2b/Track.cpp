#include "Track.h"
using namespace std;

Track::Track(){
    m_length = DEFAULT_LENGTH;
    m_track[NUM_RACERS] = {0};
}

void Track::SetLength(int length){
    m_length = length;
}

void Track::PopulateObstacles(){
    int obstacleType;
    srand(time(NULL)); // sets the seed for RNG

    for(int i = 0; i < m_length; i++){
        obstacleType = rand() % 3;
        m_obstacle[i] = obstacleType;
    }
}

void Track::GetStatus(){
    //for you
    cout << "You are on a " << ConvertObstacle(0) << " obstacle in (obstacle "  
    << m_track[0] + 1 << " of " << m_length << ")" << endl;

    //for computers
    for(int i = 0; i < NUM_RACERS - 1; i++){
        cout << "Player " << i + 1 << " is on a " << ConvertObstacle(i + 1)
        << " obstacle in (obstacle " << m_track[i + 1] + 1 << " of " <<
        m_length << ")" << endl;
    }
}

int Track::CheckWin(){
    for(int i = 0; i < NUM_RACERS; i++){
        if(m_track[i] == m_length){
            return i;
        }
    }
    return -1;
}

int Track::GetObstacle(int location){
    return m_obstacle[location];
}

void Track::IncrementLocation(int player){
    m_track[player] += 1;
}

void Track::ResetLocation(){
    for(int i = 0; i < NUM_RACERS; i++){
        m_track[i] = 0;
    }
}

string Track::ConvertObstacle(int player){
    if(m_obstacle[m_track[player]] == 0){
        return "speed";
    }else if(m_obstacle[m_track[player]] == 1){
        return "agility";
    }else{
        return "jump";
    }
}