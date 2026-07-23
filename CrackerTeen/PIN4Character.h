#pragma once
#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
class PIN4Character {


private:
    int size;
    string* ReadyCommon;
    int passwordPos;
public:
    PIN4Character();
    string Generator_ReadyCommonBranch();
    string Generator();

};