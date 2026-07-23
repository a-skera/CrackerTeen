#include "WindowHandling.h"
#include<iostream>
#include<windows.h>
#include<thread>
#include <msclr/marshal_cppstd.h>
using namespace std;
using namespace msclr::interop;

char* Convert_to_char(const std::string& input) {
    char* charStr = new char[input.length() + 1];
    strcpy_s(charStr, input.length() + 1, input.c_str());
    return charStr;
}

WindowHandling::WindowHandling() {
    // X: 667 | Y: 338 -> Password text field
    // X: 751 | Y: 366 -> login button

    window_Title = "FakeBook";  //Default Application
    PASSWORD_X = 588;          //X axis of the password text field
    PASSWORD_Y = 299;          //Y axis of the    ~      ~     ~
    Login_X = 751;             //X axis of the login button
    Login_Y = 366;             //Y axis of the   ~     ~
}
WindowHandling::WindowHandling(string only_modified_winTarget) {
    window_Title = only_modified_winTarget;
}
WindowHandling::WindowHandling(string modified_winTarget, int modified_PX, int modified_PY, int modified_LX, int modified_LY) {
    window_Title = modified_winTarget;
    PASSWORD_X = modified_PX;
    PASSWORD_Y = modified_PY;
    Login_X = modified_LX;
    Login_Y = modified_LY;
}


void WindowHandling::Password_Click() {
    SetCursorPos(PASSWORD_X, PASSWORD_Y);
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));

    this_thread::sleep_for(chrono::milliseconds(200));
}
void WindowHandling::Confirm_Click() {
    SetCursorPos(Login_X, Login_Y);
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));

    this_thread::sleep_for(chrono::milliseconds(200));
}
bool WindowHandling::getZtarget() {
    bool isTargetFound;
    const char* win_name = Convert_to_char(window_Title);
    HWND targetWindow = FindWindowA(NULL, win_name);
    if(!targetWindow) {
        //MessageBoxA(NULL, "Window not found", "Error", MB_OK);
        isTargetFound = false;

    }
    if(targetWindow) {
        isTargetFound = true;
        Target_window = targetWindow;
        //SetForegroundWindow(Target_window);
    }
    delete[] win_name;
    return isTargetFound;
}
void WindowHandling::TypeString(const string& text) {
    for(char ch : text) {
        SHORT vk = VkKeyScanA(ch);
        if(vk == -1) continue;

        bool shift = (vk & 0x0100) != 0;

        if(shift) {
            INPUT shiftDown = { 0 };
            shiftDown.type = INPUT_KEYBOARD;
            shiftDown.ki.wVk = VK_SHIFT;
            SendInput(1, &shiftDown, sizeof(INPUT));
        }

        INPUT keyDown = { 0 };
        keyDown.type = INPUT_KEYBOARD;
        keyDown.ki.wVk = LOBYTE(vk);
        SendInput(1, &keyDown, sizeof(INPUT));

        INPUT keyUp = keyDown;
        keyUp.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &keyUp, sizeof(INPUT));

        if(shift) {
            INPUT shiftUp = { 0 };
            shiftUp.type = INPUT_KEYBOARD;
            shiftUp.ki.wVk = VK_SHIFT;
            shiftUp.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &shiftUp, sizeof(INPUT));
        }

        this_thread::sleep_for(chrono::milliseconds(50));
    }

}
void WindowHandling::enter_Click() {
    // Press Enter key down
    INPUT enterDown = { 0 };
    enterDown.type = INPUT_KEYBOARD;
    enterDown.ki.wVk = VK_RETURN;
    SendInput(1, &enterDown, sizeof(INPUT));

    // Small delay
    this_thread::sleep_for(std::chrono::milliseconds(50));

    // Release Enter key
    INPUT enterUp = enterDown;
    enterUp.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &enterUp, sizeof(INPUT));
}

string WindowHandling::getwinTitle() {
    return window_Title;
}
void WindowHandling::DisplayTarget() {
    SetForegroundWindow(Target_window);
    //SetFocus(Target_window);
}
void WindowHandling::DisplayVictim(string windowName) {
    const char* windowVictim = Convert_to_char(windowName);
    HWND targetWindow = FindWindowA(NULL, windowVictim);
    SetForegroundWindow(targetWindow);
}
string WindowHandling::getCurrentWindow() {

    HWND hwnd = GetForegroundWindow();  // Get handle to the active window
    const int length = 256;
    char title[length];

    // Get the window title
    if(GetWindowTextA(hwnd, title, length) > 0) {
        return string(title);
    }
    return "";

};




/*
int main() {
    WindowHandling obj;
    WindowHandling obj_mod_title("GoBook");
    cout << obj.getwinTitle();
    cout << endl;
    cout << obj_mod_title.getwinTitle();
    return 0;
}*/