#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

typedef bool (*ContainsAllSymbols)(const char*, const char*);

int main() {
    setlocale(LC_ALL, "RUS");

    string line, sybmbol;
    cout << "Введите строку: ";
    getline(cin, line);
    cout << "Введите символы для поиска: ";
    getline(cin, sybmbol);
    HINSTANCE load = LoadLibrary(TEXT("DynamicLibrary.dll"));

    ContainsAllSymbols containsAllSymbols = (ContainsAllSymbols)GetProcAddress(load, "containsAllSymbols");

    bool result = containsAllSymbols(line.c_str(), sybmbol.c_str());

    if (result) {
        cout << "Введенные символы были найдены" << endl;
    }
    else {
        cout << "Таких символов нет" << endl;
    }

    FreeLibrary(load);

    return 0;
}