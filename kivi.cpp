#include <iostream>
#include <Windows.h>
#include <random>
using namespace std;

mt19937 rng(random_device{}());

void menu() {
    cout << "Hit 'X' to Start and 'V' to Stop autoclicker. Hit 'R' to Switch between Left or Click click mode. Hit 'Q' to quit.\n";
}

    void clicker() {
        bool click = false;
        bool rightClick = false;
        bool xWasDown = false;
        bool vWasDown = false;
        bool rWasDown = false;

        while (true) {
            if (GetAsyncKeyState('Q') & 0x8000) break;
        
            bool xDown = GetAsyncKeyState('X') & 0x8000;
            bool vDown = GetAsyncKeyState('V') & 0x8000;
            bool rDown = GetAsyncKeyState('R') & 0x8000;

            if (xDown && !xWasDown) click = true;
            if (vDown && !vWasDown) click = false;
            if (rDown && !rWasDown) {
                rightClick = !rightClick;
                cout << (rightClick ? "Right Click\n" : "Left Click\n");
            }

            xWasDown = xDown;
            vWasDown = vDown;
            rWasDown = rDown;

            if (click) {
                if (rightClick) {
                    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
                    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
                } else {
                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                }
                Sleep(uniform_int_distribution<int>(73, 93)(rng)); // 12 CPS Randomized
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