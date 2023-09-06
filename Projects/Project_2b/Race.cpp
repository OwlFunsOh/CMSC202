#include "Race.h"
using namespace std;

Race::Race(){

}

void Race::StartRace(){
    //resets location
    m_track.ResetLocation();

    //increment num races for player
    m_myPlayer.SetRaces(m_myPlayer.GetRaces() + 1);

    //set up track length
    int answer = -1;
    while(answer < 0 or answer > MAX_LENGTH){
        cout << "How long would you like the race?" << endl;
        cin >> answer;
    }
    m_track.SetLength(answer);

    //now populate track with random obstacles
    m_track.PopulateObstacles();

    while(m_track.CheckWin() < 0){
        //calls the options
        answer = RaceOptions();

        //branches out depending on the options
        if(answer == 1){
            m_track.GetStatus();
        }else if(answer == 2){
            ProgressRace(0);
        }else if(answer == 3){
            ProgressRace(1);
        }else if(answer == 4){
            ProgressRace(2);
        }

        //checks to see if someone won. -1 if no one.
        if(m_track.CheckWin() >= 0){
            if(m_track.CheckWin() == 0){
                cout << "You have won the race!" << endl;
                m_myPlayer.IncreaseStat();
                m_myPlayer.IncreaseWins();
            }else{
                cout << "Player " << m_track.CheckWin() + 1 << " has won the race!" << endl;
            }
        }
    }
}

void Race::GetRacerInfo(){
    //asks for the racer's name and populates m_myPlayer
    string name;
    cout << "What is the Racer's name?" << endl;
    getline(cin, name);
    m_myPlayer.SetName(name);
}

void Race::ProgressRace(int skill){
    //assign 1-100 to all obstacles
    int difficulty = 0;
    srand(time(NULL)); //sets seed
    difficulty = (rand() % BASE_DIFFICULTY) + 1; //picks a number 1-100

    //figure out what obstacle the player is on
    string playerObstacle = m_track.ConvertObstacle(0);

    //get's player skill for a certain obstacle
    int playerSkill = 0;
    if(playerObstacle == "speed" and skill == 0){
        playerSkill = BASE_SKILL + (5 * m_myPlayer.GetSpeed());
    }else if(playerObstacle == "agility" and skill == 1){
        playerSkill = BASE_SKILL + (5 * m_myPlayer.GetAgility());
    }else if(playerObstacle == "jump" and skill == 2){
        playerSkill = BASE_SKILL + (5 * m_myPlayer.GetJump());
    }else{
        playerSkill = BASE_SKILL;
    }

    cout << "You are trying to progress the race!" << endl;

    if(playerSkill < difficulty){
        cout << "You fell" << endl;
        int falls = m_myPlayer.GetFalls();
        m_myPlayer.SetFalls(falls + 1);
    }else{
        cout << "You made it through the " << m_track.ConvertObstacle(0) << " obstacle!" << endl;
        m_track.IncrementLocation(0);
    }

    ProgressComputer(difficulty);

}

bool Race::MainMenu(){
    int answer = 0;
    while(answer < 1 or answer > 3){
    cout << "What would you like to do?" << endl;
    cout << "1. Start New Race" << endl;
    cout << "2. View Racer History" << endl;
    cout << "3. Quit" << endl;

    cin >> answer;
    }

    if(answer == 3){
        return false;
    }else if(answer == 1){
        StartRace();
    }else if(answer == 2){
        m_myPlayer.DisplayStatus();
    }

    return true;

}

int Race::RaceOptions(){
    int answer = 0;

    while(answer < 1 or answer > 4){
        cout << "What would you like to do?" << endl;
        cout << "1. Get Race Status" << endl;
        cout << "2. Try to Sprint (Speed)" << endl;
        cout << "3. Try to Dodge (Agility)" << endl;
        cout << "4. Try to Jump (Jump)" << endl;

        cin >> answer;
    }
    return answer;

}

void Race::ManageGame(){
    RaceTitle();
    GetRacerInfo();
    while(MainMenu()){}
    cout << "Thank you for playing UMBC Race!" << endl;
}

void Race::ProgressComputer(int obstacleDifficulty){
    int playerSkill = 0;
    srand(time(NULL)); //seed the RNG
    for(int i = 0; i < NUM_RACERS - 1; i++){
        string playerObstacle = m_track.ConvertObstacle(i + 1);
        playerSkill = COMP_MIN + rand() % ((COMP_MAX + 1) - COMP_MIN);
        if(playerSkill < obstacleDifficulty){
            cout << "Player " << i + 1 << " fell!" << endl;
        }else{
            cout << "Player " << i + 1 << " made it through the " << m_track.ConvertObstacle(i + 1) << " obstacle!" << endl;
            m_track.IncrementLocation(i + 1);
        }

        playerSkill = 0;

    }
}