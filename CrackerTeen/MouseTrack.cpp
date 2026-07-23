#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;
static void Tracking() {
    POINT p;
    cout << " Move your mouse. Press any key to exit...\n\n";

    while (!_kbhit()) {  // Exit when any key is pressed
        if (GetCursorPos(&p)) {
            cout << "\rX: " << p.x << " | Y: " << p.y << "   " << flush;
        }
        Sleep(50); // update rate
    }
    cout << "Done. Use these coordinates in your automation.\n";

}

