/*
Author: Alfonso Sebastian Apelacio Martinez
Filename: Process.cpp
Date: 12/07/2022
Description: Codes the functions under Process.h
*/

#include "Process.h"

Process::Process(){
    m_name = "test";
    m_id = -1;
    m_call = -1;
    m_duration = -1;
}

Process::Process(string name, int id, int call, int duration){
    m_name = name;
    m_id = id;
    m_call = call;
    m_duration = duration;
}

ostream& operator<< (ostream& output, Process& process){
    output << process.m_name << " " << process.m_id << " " << process.m_call << " " << process.m_duration << endl;
    return output;
}