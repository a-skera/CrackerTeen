#pragma once
#include<iostream>
#include<thread>
#include "WindowHandling.h"
using namespace std;
class BruteForce_injector {

  private:
    bool is_AttackSucced;
    WindowHandling* win_object; // for fakebook only
    WindowHandling* win_object_pin;//for the 4-pin application

    bool isDone() {
        if(win_object->getCurrentWindow() == "Success") {
            is_AttackSucced = true;
            return is_AttackSucced;
        }
        if(win_object->getCurrentWindow() == "Login Failed") {
            is_AttackSucced = false;
            return is_AttackSucced;
        }
    }
    bool isDone4Pin() {
        if(win_object_pin->getCurrentWindow() == "Unlocked") {
            is_AttackSucced = true;
            return is_AttackSucced;
        }
        if(win_object_pin->getCurrentWindow() == "Wrong-Pin") {
            is_AttackSucced = false;
            return is_AttackSucced;
        }
    }

  public:
    BruteForce_injector() {
        is_AttackSucced = false;
        win_object = new WindowHandling();

    }


    void GetPasswordThenInject(string* password_list, int size, int &passwordPos) {

        // while (!isDone()) {

        for(int i = 0; i < size; i++) {
            win_object->Password_Click();
            win_object->TypeString(password_list[i]);
            win_object->Confirm_Click();
            if(isDone()) {
                passwordPos = i;
                break;
            } else {
                win_object->enter_Click();
                continue;
            }
        }

        //}

    }

    void GetPasswordThenInject(string* password_list, int size, int& passwordPos, string* password_generated_list, int attempts, int &passwordPos2) {

        win_object_pin = new WindowHandling("Password4Pin", 590, 253, 754, 417);

        for(int i = 0; i < size; i++) {
            win_object_pin->Password_Click();
            win_object_pin->TypeString(password_list[i]);
            win_object_pin->Confirm_Click();
            if(isDone4Pin()) {
                passwordPos = i;
                break;
            } else {
                win_object_pin->enter_Click();
                continue;
            }
        }
        for(int i = 0; i < attempts; i++) {
            win_object_pin->Password_Click();
            win_object_pin->TypeString(password_generated_list[i]);
            win_object_pin->Confirm_Click();
            if(isDone4Pin()) {
                passwordPos2 = i;
                break;
            } else {
                win_object_pin->enter_Click();
                continue;
            }

        }

    }

};

