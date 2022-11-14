#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

int main()
{
    int choice = 0;
    while (true) {
        cout << "Enter 1 to play sound.\nEnter 2 to quit: ";
        cin >> choice;
        if (choice == 1) {
            PlaySound(TEXT("put your .wav file name here"), NULL, SND_FILENAME);
        }
        else if (choice == 2) {
            break;
        }
        else {
            cout << "Try again!\n";
        }
    }
}
