#pragma once
#ifndef PIN4Character_H
#define PIN4Character_H
#include<iostream>
#include<Windows.h>
#include<thread>
#include "WindowHandling.h"

using namespace std;
class BruteForce_injector {
private:
    bool is_AttackSucced;
    WindowHandling* win_object;
    string skip_window_name;

public:
    BruteForce_injector();
    bool isDone();
    void GetPasswordThenInject(string* password_list, int size, int& passwordPos);
    void GetPasswordThenInject(string* password_list, int size, int& passwordPos, int attempts);
};#endif