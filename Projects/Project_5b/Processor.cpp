/*
Author: Alfonso Sebastian Apelacio Martinez
Filename: Processor.cpp
Date: 12/07/2022
Description: Codes functions for Processor.h
*/

#include "Processor.h"

Processor::Processor(string filename){
    m_fileName = filename;
}

Processor::~Processor(){
    //clear m_processes
    int size = m_processes.size();
    for(int i = 0; i < size; i++){
        delete m_processes[i];
        m_processes[i] = nullptr;
    }
    m_processes.clear();

    //clear m_threads
    for(int i = 0; i < NUM_THREADS; i++){
        m_threads[i] -> Clear();
        delete m_threads[i];
        m_threads[i] = nullptr;
    }
    m_threads.clear();
}

void Processor::InitializeProcessor(){
    DisplayTitle();
    LoadProcesses(m_fileName);
    PopulateThreads();
    bool quit = false;
    int choice = 0;
    while(not quit){
        choice = 0;
        MainMenu();
        cin >> choice;
        if(choice < 1 or choice > 3){
            cout << "Please enter a valid option." << endl;
        }else if(choice == 1){
            DisplayThread();
        }else if(choice == 2){
            StartThreads();
        }else if(choice == 3){
            quit = true;
        }
    }
    cout << "Thank you for trying UMBC Processor!" << endl;
}

bool Processor::LoadProcesses(string filename){
    ifstream processes(m_fileName);
    string name;
    string stringId;
    string stringCall;
    string stringDuration;
    int id;
    int call;
    int duration;

    if(not processes.is_open()){
        return false;
    }

    while(getline(processes, name, DELIMITER)){
        getline(processes, stringId, DELIMITER);
        getline(processes, stringCall, DELIMITER);
        getline(processes, stringDuration);

        //convert id, call, and duration to ints
        id = stoi(stringId);
        call = stoi(stringCall);
        duration = stoi(stringDuration);

        Process* newProcess = new Process(name, id, call, duration);
        m_processes.push_back(newProcess);
        newProcess = nullptr;
    }

    //after all processes have been loaded, add threads from the first processes
    for(int i = 0; i < NUM_THREADS; i++){
        AddThread(m_processes.at(i));
    }
    return true;
}

void Processor::AddThread(Process* process){
    Lstack<Process*>* thread = new Lstack<Process*>();
    thread -> Push(process);
    m_threads.push_back(thread);
}


int Processor::GetProcessCalled(int id){
    int size = m_processes.size();
    int location = -1; //default to not found
    for(int i = 0; i < size; i++){
        if(m_processes.at(i) -> m_id == id){
            location = i;
        }
    }
    return location;
}

void Processor::PopulateThreads(){
    int numThreads = m_threads.size();
    for(int i = 0; i < numThreads; i++){
        while(m_threads[i] -> Top() -> m_call != -1){
            m_threads[i] -> Push(m_processes[GetProcessCalled(m_threads[i] -> Top() -> m_call)]);
        }
    }
}

void Processor::MainMenu(){
    cout << "Choose an option." << endl;
    cout << "1. Display Threads" << endl;
    cout << "2. Start Thread" << endl;
    cout << "3. Quit" << endl;
}

void Processor::DisplayProcesses(){
    int size = m_processes.size();
    for(int i = 0; i < size; i++){
        cout << *m_processes[i] << endl;
    }
}

void Processor::ListThreads(){
    int numThreads = m_threads.size();
    for(int i = 0; i < numThreads; i++){
        cout << i + 1 << ". Thread " << i + 1 << " (" << m_threads[i] -> GetSize() << " processes)" << endl;
    }
}

int Processor::ChooseThread(){
    int choice = 0;
    do{
        cout << "What thread would you like to view?" << endl;
        ListThreads();
        cin >> choice;
    }while(choice < 1 or choice > NUM_THREADS);

    return (choice - 1);
}

void Processor::DisplayThread(){
    int index = ChooseThread();
    Lstack<Process*>* thread = m_threads[index];
    int size = thread -> GetSize();
    for(int i = 0; i < size; i++){
        cout << *thread -> At(i) << endl;
    }

    thread = nullptr;
}

void Processor::StartThreads(){
    for(int i = 0; i < NUM_THREADS; i++){
        int duration = 0;
        Lstack<Process*>* thread = m_threads[i];
        int size = thread -> GetSize();
        for(int i = 0; i < size; i++){
            duration = duration + thread -> Top() -> m_duration;
            thread -> Pop();
        }
        cout << "Thread " << i + 1 << " took " << duration << " milliseconds to complete" << endl;
    }
}

void Processor::DisplayTitle(){
    cout << "Welcome to UMBC Processor!" << endl;
}