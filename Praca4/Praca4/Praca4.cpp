#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    const int rows = 3, columns = 5;
    double num[rows][columns];

    for (int i = 0; i < rows; i++) {
        cout << "Введите 5 дробных элементов\n";
        for (int j = 0; j < columns; j++) {
            cin >> num[i][j];
        }
    }

    double avg;
    for (int i = 0; i < rows; i++) {
        double sum = 0.0;
        for (int j = 0; j < columns; j++) {
            sum += num[i][j];
        }
        avg = sum / columns;
        cout << "Среднее арифметическое элементов " << i + 1 << " строки: " << avg << endl;
    }
    return 0;
}
/*

12.3
1.5
13.2
15.7
2.3

=9

1.2
13.2
11.6
14.1
1.5

=8.32

11.1
5.6
34.2
53.7
4.9

=21.9

*/