
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "BruteForce_injector.cpp"
#include <random>

using namespace std;
class pin_4_character {
private:
    int size;
    string* ReadyCommon;
    BruteForce_injector obj1;
    int passwordPos1;
    int passwordPos2;
public:
    
    pin_4_character() {
        size = 10;
        ReadyCommon = new string[size];
        ReadyCommon[0] = "0000";
        ReadyCommon[1] = "1111";
        ReadyCommon[2] = "2222";
        ReadyCommon[3] = "3333";
        ReadyCommon[4] = "4444";
        ReadyCommon[5] = "5555";
        ReadyCommon[6] = "6666";
        ReadyCommon[7] = "7777";
        ReadyCommon[8] = "8888";
        ReadyCommon[9] = "9999";
    }
    // if attempts is equals to 0
    string Generator_ReadyCommonBranch() {
        string* Function_satisfyingArray = new string[0];
        
        obj1.GetPasswordThenInject(ReadyCommon, size, passwordPos1 , Function_satisfyingArray,0,passwordPos2);
        if (passwordPos1) {
            delete[] Function_satisfyingArray;
            return "The right pin is " + ReadyCommon[passwordPos1];
        }
        else {
            delete[] Function_satisfyingArray;
            return "No pin matches";
        }
    }
    // if attempts more than 0
    string Generator(int attempts) {
        BruteForce_injector obj2;
        string* GeneratedPINs = new string[attempts];

        for (int i = 0; i < attempts; i++) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> distrib(1000, 9999);
            string pin_Converted_to_string = to_string(distrib(gen));
            GeneratedPINs[i] = pin_Converted_to_string;

        }
        obj2.GetPasswordThenInject(ReadyCommon, size, passwordPos1, GeneratedPINs, attempts, passwordPos2);
        if (passwordPos1) {
            return "The right pin is " + ReadyCommon[passwordPos1];
        }
        else if (passwordPos2) {
            return GeneratedPINs[passwordPos2];
        }
        else {
            return "No pin matches";
        }
        delete[] ReadyCommon;
        delete[] GeneratedPINs;

    }

};