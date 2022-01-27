#include <windows.h>

// https://stackoverflow.com/questions/18260508/c-how-do-i-hide-a-console-window-on-startup

void hideConsole() {
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void showConsole() {
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

bool isConsoleVisible() {
    return ::IsWindowVisible(::GetConsoleWindow()) != FALSE;
}

int main(){
    for(size_t i = 0; i < 6; ++i) {
        if(i % 2 == 0)
            hideConsole();
        else
            showConsole();
        Sleep(1000);
    }
}
