#pragma once
#include<iostream>
#include<windows.h>
#include<thread>
#include<string>
using namespace std;
class WindowHandling {
  private:
    int USERNAME_X;  // X axis of the username field
    int USERNAME_Y;  // Y axis of the username field
    int PASSWORD_X;  // X axis of the password text field
    int PASSWORD_Y;  // Y axis of the    ~      ~     ~
    int Login_X ;
    int Login_Y;
    string window_Title;
    HWND Target_window;
  protected:

  public:
    WindowHandling();
    // in case we will perform on another application
    WindowHandling(string only_modified_winTarget);
    WindowHandling(string modified_winTarget, int modified_PX, int modified_PY, int modified_LX, int modified_LY);
    void TypeString(const string& text);
    void Password_Click();
    void Confirm_Click();
    void enter_Click();
    bool getZtarget();
    string getwinTitle();
    void DisplayTarget();
    string getCurrentWindow();
    void DisplayVictim(string window);

};

