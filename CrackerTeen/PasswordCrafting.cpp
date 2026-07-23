#pragma once
#include<iostream>
#include "Open_File.cpp"
#include "BruteForce_injector.cpp"
#include <random>
#include <string>

using namespace std;
Open_File openedfile_obj("passwordSamples.txt");
int arraysize = openedfile_obj.lines_for_array_size();
int passwordPos;
BruteForce_injector CraftedPassword_injector;

string * DicPassword() {
    string * loadDicPassword = new string[arraysize];
    openedfile_obj.get_password_keys(loadDicPassword, arraysize);
    return loadDicPassword;
}
char SymbolGenerator() {
    char Symbols[5] = {'@', '#', '_', '$', '&'};
    int pin;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 4);
    pin = distrib(gen);
    return Symbols[pin];
}

string GenerateExrtaPassword() {
    string GeneratedPassword = "";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1000, 9999);
    GeneratedPassword = to_string(distrib(gen));
    return GeneratedPassword;


}


string* CraftPassword() {
    string * CraftedPasswords = new string [arraysize];
    CraftedPasswords = DicPassword(); // we have taken the address of the array that stores the loaded passwords from the file
    for(int i = 0; i < arraysize; i++) {
        CraftedPasswords[i] += SymbolGenerator() + GenerateExrtaPassword();
    }
    return CraftedPasswords;

}


void loadTheCraftedPasswordsToInjection() {
    CraftedPassword_injector.GetPasswordThenInject(CraftPassword(), arraysize, passwordPos);

}

string PrintThePassword() {
    string * passwordContainer = CraftPassword();
    if(passwordPos) {
        string rightpassword =  passwordContainer[passwordPos];
        delete [] passwordContainer;
        return "The password is " + rightpassword;
    } else {
        delete []passwordContainer;
        return "No password matched";
    }
}
// This function is very very important to call to free the memory
void DeAllocation() {
    string * Arr1 = DicPassword();
    string * Arr2 = CraftPassword();

    delete[] Arr1;
    delete[] Arr2;
}

