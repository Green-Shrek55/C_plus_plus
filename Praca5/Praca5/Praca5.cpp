#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

string reverseWord(string word) {
    reverse(word.begin(), word.end());
    return word;
}

string removeVowels(string word) {
    string vowels = "aeiouAEIOU";
    word.erase(remove_if(word.begin(), word.end(),
        [&](char c) { return vowels.find(c) != string::npos; }), word.end());
    return word;
}

string removeConsonants(string word) {
    string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    word.erase(remove_if(word.begin(), word.end(),
        [&](char c) { return consonants.find(c) != string::npos; }), word.end());
    return word;
}

string shuffleWord(string word) {
    random_shuffle(word.begin(), word.end());
    return word;
}

int main() {
    setlocale(LC_ALL, "Rus");
    string word;
    int a;

    cout << "Введите слово: ";
    cin >> word;

    cout << "1. Задом наперед" << endl;
    cout << "2. Слово без гласных" << endl;
    cout << "3. Слово без согласных" << endl;
    cout << "4. Слово в разброс" << endl;
    cin >> a;

    switch (a) {
    case 1:
        cout << "Задом наперед: " << reverseWord(word) << endl;
        break;
    case 2:
        cout << "Слово без гласных: " << removeVowels(word) << endl;
        break;
    case 3:
        cout << "Слово без согласных: " << removeConsonants(word) << endl;
        break;
    case 4:
        cout << "Слово в разброс: " << shuffleWord(word) << endl;
        break;
    default:
        cout << "Выберите другую команду!" << endl;
        break;
    }

    return 0;
}