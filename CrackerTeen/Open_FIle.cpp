#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Open_File {

  private:
    string passList;
    int size_;
  public:
    Open_File() {
        passList = "file.txt";
        size_ = 0;
    }
    Open_File(string anotherFile) {
        passList = anotherFile;
        size_ = 0;
    }
    string validate_file() {
        ifstream inputFile(passList);
        if(!inputFile.is_open()) {
            return "The file does not exit";
        } else {
            return "The file is successfully imported";
        }
    }
    int lines_for_array_size() {
        ifstream inputFile(passList);
        if(!inputFile.is_open()) {
            // cout << "Error: Could not open the taregt file: " << passList << endl;
            return 0;
        }
        int counter = 0;
        string line;
        while(getline(inputFile, line)) {
            //This to get dynamically the size of the array
            counter++;
        }
        size_ = counter;
        inputFile.close();
        return size_;
    }

    void get_password_keys(string* password_array, int size) {
        ifstream inputFile(passList);
        if(!inputFile.is_open()) {
            // cout << "Error: Could not open the taregt file: " << passList << endl;
            return;
        }
        int counter = 0;
        string line;
        while(getline(inputFile, line) && counter < size) {
            //This to load the passwords in the local array of passwords to launch the injection
            password_array[counter] = line;
            counter++;
        }



    }
    string getZFile() {
        return passList;
    }


};
/*
int main() {

    Open_File obj("passwordList.txt");
    int size =  obj.lines_for_array_size();
    string* passkeys = new string[size];
    obj.get_password_keys(passkeys, size);
    for(int i = 0; i < size; i++) {
        cout << passkeys[i] << endl;
    }


}
    */