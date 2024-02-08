#include <iostream>
using namespace std;

double SinRoutR(double inR, double outR) {
    const float PI = 3.14;
    double S = PI * (outR * outR - inR * inR);
    return S;
}
int main() {
    setlocale(LC_ALL, "Rus");
    double inR, outR;
    cout << "Введведите внешний радиус: ";
    cin >> outR;
    cout << "Введите внутренний: ";
    cin >> inR;

    double S = SinRoutR(inR, outR);
    cout << "Площадь кольца: " << S << endl;

    return 0;
}