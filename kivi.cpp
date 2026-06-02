#include <iostream>
#include <Windows.h>
using namespace std;

void menu() {
    cout << "Hit 'X' to Start and 'V' to Stop autoclicker. Hit 'Q' to quit.\n";
}

    void clicker() {
        bool click = false;
        bool xWasDown = false;
        bool vWasDown = false;

        while (true) {
            if (GetAsyncKeyState('Q') & 0x8000) break;
        
            bool xDown = GetAsyncKeyState('X') & 0x8000;
            bool vDown = GetAsyncKeyState('V') & 0x8000;

            if (xDown && !xWasDown) click = true;
            if (vDown && !vWasDown) click = false;

            if (click) {
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                Sleep(83); // 12 CPS
            } else {
                Sleep(10); // idle
            }

        }
    }

int main() {
        menu();
        clicker();
        system("pause");
        return 0;
}