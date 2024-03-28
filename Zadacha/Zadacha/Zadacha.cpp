#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string brand;
    string model;
    int year;
    string color;
    int km;

public:
    Car(string brand, string model, int year, string color, int km) {
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->color = color;
        this->km = km;
    }

    void information() {
        cout << "Марка: " << brand << endl;
        cout << "Модель: " << model << endl;
        cout << "Год выпуска: " << year << endl;
        cout << "Цвет: " << color << endl;
        cout << "Старый пробег: " << km << " км" << endl;
    }

    void increasekm(int additionalkm) {
        km += additionalkm;
    }
};


int main()
{
	setlocale(LC_ALL, "Rus");
    Car car("Шестерка", "Элитная", 1997, "Синий", 47036);
    car.information();

    car.increasekm(6482);
    cout << "Новый пробег: " << car.km << " км" << endl;

    return 0;
}