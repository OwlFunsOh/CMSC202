/*
Title: Game.cpp
Author: Alfonso Sebastian Apelacio Martinez
Date: 11/16/2022
Description: Codes the functions defined in Game.h
*/

#include "Game.h"

Game::Game(){
    m_numRests = NUM_RESTS;
    m_numSpecial = NUM_SPECIAL;
    m_curArea = START_AREA;
    m_filename = FILE_NAME;
    m_curZerg = nullptr;
    m_wins = START_WINS;
}

Game::Game(string fileName){
    m_numRests = NUM_RESTS;
    m_numSpecial = NUM_SPECIAL;
    m_curArea = START_AREA;
    m_filename = fileName;
    m_curZerg = nullptr;
    m_wins = START_WINS;
}

Game::~Game(){
    //Deals with Terran first
    delete m_myTerran;
    m_myTerran = nullptr;

    //Next, deal with Zerg
    delete m_curZerg;
    m_curZerg = nullptr;

    //Finally, deal with the map
    int size = m_myMap.size();
    for(int i = 0; i < size; i++){
        delete m_myMap[i];
        m_myMap[i] = nullptr;
    }
    m_myMap.clear();
}

void Game::LoadMap(){
    ifstream map(m_filename);

    string stringId;
    string name;
    string desc;
    string stringNorth;
    string stringEast;
    string stringSouth;
    string stringWest;
    string temp;
    int id;
    int north;
    int east;
    int south;
    int west;

    while(getline(map, stringId, DELIMITER)){ // while I can get the ID
        getline(map, name, DELIMITER);
        getline(map, desc, DELIMITER);
        getline(map, stringNorth, DELIMITER);
        getline(map, stringEast, DELIMITER);
        getline(map, stringSouth, DELIMITER);
        getline(map, stringWest, DELIMITER);
        getline(map, temp); //Extra getline to move to the next line

        //convert direction strings to ints
        id = stoi(stringId);
        north = stoi(stringNorth);
        east = stoi(stringEast);
        south = stoi(stringSouth);
        west = stoi(stringWest);

        Area* areaPointer = new Area(id, name, desc, north, east, south, west);
        m_myMap.push_back(areaPointer);

        areaPointer = nullptr;

    }
}

void Game::TerranCreation(){
    string name;
    int choice = 0;


    //first, ask for the name
    cout << "Terran Name: ";
    cin >> name;

    while(choice < 1 or choice > 4){
        cout << "Select a class" << endl;
        cout << "1. Marine" << endl;
        cout << "2. Ghost" << endl;
        cout << "3. Battlecruiser" << endl;
        cout << "4. No Class" << endl;
        cin >> choice;
    }

    if(choice == 1){
        m_myTerran = new Marine(name, MARINE_HEALTH);
    }else if(choice == 2){
        m_myTerran = new Ghost(name, GHOST_HEALTH);
    }else if(choice == 3){
        m_myTerran = new Battlecruiser(name, BATTLECRUISER_HEALTH);
    }else if(choice == 4){
        m_myTerran = new Terran(name, TERRAN_HEALTH);
    }

}

void Game::StartGame(){
    cout << "Welcome to UMBC Starcraft!" << endl;
    LoadMap();
    TerranCreation();
    m_myMap[m_curArea] -> PrintArea();
    Action();
}

void Game::Action(){
    bool quit = false;
    int choice;
    m_curZerg = RandomZerg(); //creates a zerg

    //loops while you don't want to quit game
    while(not quit and m_myTerran != nullptr){

        //display menu below
        choice = 0;
        while(choice < 1 or choice > 6){
            cout << "What would you like to do?" << endl;
            cout << "1. Look" << endl;
            cout << "2. Move" << endl;
            cout << "3. Attack Zerg" << endl;
            cout << "4. Rest" << endl;
            cout << "5. Check Stats" << endl;
            cout << "6. Quit" << endl;
            cin >> choice;
        }

        //Pass to other functions based on choice
        if(choice == 1){
            m_myMap[m_curArea] -> PrintArea();
        }else if(choice == 2){
            Move();
            m_myMap[m_curArea] -> PrintArea();
            m_curZerg = RandomZerg();
        }else if(choice == 3){
            Attack();
        }else if(choice == 4){
            Rest();
        }else if(choice == 5){
            Stats();
        }else if(choice == 6){
            quit = true;
        }

    }

}

Entity* Game::RandomZerg(){
    srand(time(NULL)); //seed the RNG
    int zerg = rand() % 4;
    Entity* zergPointer = nullptr;

    if(zerg == 0){
        cout << "It is peaceful here" << endl;
    }else if(zerg == 1){
        zergPointer = new Zergling("Zergling", ZERGLING_HEALTH);
        cout << "A small terrifying Zergling waits here." << endl;
    }else if(zerg == 2){
        zergPointer = new Mutalisk("Mutalisk", MUTALISK_HEALTH);
        cout << "A large flying Mutalisk hovers here." << endl;
    }else{
        zergPointer = new Hydralisk("Hydralisk", HYDRALISK_HEALTH);
        cout << "A medium sized Hydralisk slithers here waiting to cover you with acid" << endl;
    }

    return zergPointer;
}

void Game::Rest(){
    if(m_curZerg == nullptr and m_numRests > 0){
        m_numRests -= 1;
        int currHealth = m_myTerran -> GetHealth();
        m_myTerran -> SetHealth(currHealth + REST_HEAL);
        m_numSpecial = NUM_SPECIAL;
    }else if(m_curZerg != nullptr){
        cout << "You cannot rest with a Zerg in the area." << endl;
    }else if(m_numRests == 0){
        cout << "You do not have any more rests." << endl;
    }
}

void Game::Move(){
    char direction;
    bool validChoice = false;
    int choice = -1;
    int id = 0;

    while(not validChoice){
        cout << "Which direction? (N E S W)" << endl; 
        cin >> direction;
        id = m_myMap[m_curArea] -> CheckDirection(direction);
        if(id == -1){
            cout << "Invalid Direction" << endl;
        }else{
            validChoice = true;
        }
    }

    if(m_curZerg != nullptr){
        delete m_curZerg;
        m_curZerg = nullptr;
    }
    m_curArea = id;

}

void Game::Attack(){
    if(m_curZerg == nullptr){
        cout << "There is nothing to attack" << endl;
    }else{
        //Player attacks first
        //choose what type of attack
        int choice = 0;
        while(choice < 1 or choice > 2){
            cout << "1. Normal Attack" << endl;
            cout << "2. Special Attack" << endl;
            cin >> choice;
        }

        int atkDamage = 0;
        //if Normal attack is done, below will run
        if(choice == 1){
            atkDamage = m_myTerran -> Attack();
        }else{ //this is for special attack
            if(m_numSpecial < 1){
                cout << "You have no special attacks remaining" << endl;
            }else{
                atkDamage = m_myTerran -> SpecialAttack();
                m_numSpecial -= 1;
            }
        }

        //Calculates how much damage Terran did to Zerg
        m_curZerg -> SetHealth(m_curZerg -> GetHealth() - atkDamage);

        //Now it is the Zerg's turn to attack
        //Zergs have a 25% chance to use a special attack
        //if atkType = 0, the attack will be a special attack
        //else, it will be a normal attack
        srand(time(NULL));
        int atkType = rand() % 4;
        atkDamage = 0;

        if(atkType == 0){
            atkDamage = m_curZerg -> SpecialAttack();
        }else{
            atkDamage = m_curZerg -> Attack();
        }

        //Now that we have the damage done, calculate Terran health
        m_myTerran -> SetHealth(m_myTerran -> GetHealth() - atkDamage);

        //Now we do ProcessBattle(). Since we need two bools,
        //check if Terran and Zerg are alive
        bool alive = true;
        bool zergAlive = true;

        if(m_curZerg -> GetHealth() <= 0){
            zergAlive = false;
        }
        if(m_myTerran -> GetHealth() <= 0){
            alive = false;
        }

        //Only run if zerg or terran is unalive
        if(not alive or not zergAlive){
            ProcessBattle(zergAlive, alive);
        }else{
            cout << m_myTerran -> GetName() << " health: " << m_myTerran -> GetHealth() << endl;
            cout << m_curZerg -> GetName() << " health: " << m_curZerg -> GetHealth() << endl;
        }

    }
}

void Game::Stats(){
    cout << *m_myTerran << endl;
    cout << "Rests: " << m_numRests << endl;
    cout << "Specials: " << m_numSpecial << endl;
    cout << "Wins: " << m_wins << endl;
}

void Game::ProcessBattle(bool zergAlive, bool alive){
    if(zergAlive == false and alive == false){
        cout << "Mutual destruction. Both you and the Zerg have died" << endl;
        delete m_curZerg;
        delete m_myTerran;
        m_curZerg = nullptr;
        m_myTerran = nullptr;
    }else if(zergAlive == true and alive == false){
        cout << "The " << m_curZerg -> GetName() << " has won the battle" << endl;
        delete m_curZerg;
        delete m_myTerran;
        m_myTerran = nullptr;
        m_curZerg = nullptr;
    }else if(zergAlive == false and alive == true){
        cout << "You have defeated the " << m_curZerg -> GetName() << endl;
        delete m_curZerg;
        m_curZerg = nullptr;
        m_wins += 1;

        //Since you won, you have a 10% chance to get another rest action
        srand(time(NULL));
        int chance = rand() % 10;
        if(chance == 0){
            m_numRests += 1;
            cout << "You have earned another rest action!" << endl;
        }
    }
}