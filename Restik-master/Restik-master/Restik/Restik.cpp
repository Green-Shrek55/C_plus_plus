#include <string>
#include <thread>
#include <iostream>
#include <functional>
#include <Windows.h>
#include <vector>
#include <fstream>
using namespace std;

class oficiant {
public:
    oficiant() {
        of();
    }
    void of() {
        vector<string> status;
        string line;
        ifstream file_check("C:\\Users\\96298\\Desktop\\Java\\status2.txt");

        while (file_check >> line) {
            status.push_back(line);
        }
        file_check.close();

        int slovo = 0;
        for (int i = 0; i < status.size(); i++) {
            cout << status[i] << " ";
            slovo++;
        }

        int id = slovo - 1;
        ofstream fileclear("C:\\Users\\96298\\Desktop\\Java\\status2.txt");
        if (status[id] == "выдачу") {
            fileclear << "выполнен" << endl;
            cout << "Заказ готов! " << endl;
        }
        else {
            cout << "Заказы не готовы" << endl;
        }
        fileclear.close();
    }
};

class Povar {
public:
    Povar() {
        po();
    }
    void po() {
        ifstream zakaz("C:\\Users\\96298\\Desktop\\Java\\zakazi2.txt");
        if (zakaz.peek() == ifstream::traits_type::eof()) {
            cout << "заказы сделаны, можете отдохнуть " << std::endl;
        }
        else {
            ofstream filestat("C:\\Users\\96298\\Desktop\\Java\\status2.txt");
            filestat << "В процессе приготовления" << endl;

            cout << "Заказы: " << endl;
            vector<string> history;
            string number;

            while (zakaz >> number) {
                history.push_back(number);
            }
            zakaz.close();

            int newid = 1;
            for (int i = 0; i < history.size(); i++) {
                cout << newid++ << "/" << history[i] << endl;
            }

            int num;
            cout << "Введите номер элемента для приготовления" << endl;
            cin >> num;
            if (num <= history.size() && num >= 1) {
                history.erase(history.begin() + num - 1);
            }
            else {
                cout << "Введите корретктный индекс: " << endl;
                po();
                return;
            }

            string lines;
            vector<string> newproduct;
            ifstream file2("C:\\Users\\96298\\Desktop\\Java\\menu2.txt");
            while (file2 >> lines) {
                newproduct.push_back(lines);
            }
            file2.close();

            for (int i = 0; i < newproduct.size(); i++) {
                cout << newproduct[i] << endl;
            }
            cout << "Для приготовления строки повторите его строку из списка: " << endl;
            string information;
            cin >> information;
            auto it = find(newproduct.begin(), newproduct.end(), information);
            if (it != newproduct.end()) {
                cout << "Блюдо приготовлено" << endl;
                ofstream out("C:\\Users\\96298\\Desktop\\Java\\zakazi2.txt");
                if (out.is_open()) {
                    for (int i = 0; i < history.size(); i++) {
                        out << history[i] << endl;
                    }
                }
                out.close();

                ofstream filestat2("C:\\Users\\96298\\Desktop\\Java\\status2.txt");
                filestat2 << "Передан официанту на выдачу" << endl;
                filestat2.close();
            }
            else {
                cout << "Блюдо не приготовлено, вы что-то сделали не так" << endl;
                po();
                return;
            }
            filestat.close();
        }
    }
};

class Money {
public:
    Money() {
        info_about_rest();
    }
    void info_about_rest() {
        vector<string> info;
        string number;
        ifstream files("C:\\Users\\96298\\Desktop\\Java\\info.txt");
        while (files >> number) {
            info.push_back(number);
        }
        files.close();

        cout << "История заявок: " << endl;
        vector<string> history;
        string line;
        ifstream file("C:\\Users\\96298\\Desktop\\Java\\history2.txt");

        while (file >> line) {
            history.push_back(line);
        }
        file.close();

        for (int i = 0; i < history.size(); i++) {
            cout << history[i] << endl;
        }

        cout << "счет ресторана:" << info[0] << endl;
        cout << "количество проданных блюд: " << info[1] << endl;
        cout << "заработок на блюдах: " << info[2] << endl;
    }
};

class Skladov {
public:
    Skladov() {
        nado();
    }
    void nado() {
        int chose;
        cout << "1. Создание заявок" << endl << "2. Просмотр склада" << endl;
        cin >> chose;
        vector<string> spisok;
        string line;
        ifstream file("C:\\Users\\96298\\Desktop\\Java\\product2.txt");
        if (chose == 1) {
            cout << "Список товаров для закупки:" << endl;
            while (file >> line) {
                string number2 = line.substr(line.find("-") + 1, (((line.find_first_of("-")), (line.find_last_of("-") - 2))));
                spisok.push_back(number2);
            }
            file.close();

            for (int i = 0; i < spisok.size(); i++) {
                string ln = spisok[i];
                cout << ln.substr(ln.find("-") + 1, (((ln.find_first_of("-")), (ln.find_last_of("-") - 2)))) << endl;
            }

            cout << "Введите тип товара: " << endl;
            string type;
            cin >> type;

            vector<string> note;
            int quantity;
            cout << "Введите количество желаемого товара: " << endl;
            cin >> quantity;
            string quantity2 = to_string(quantity);
            string infile = type + "-" + quantity2;

            auto il = find(spisok.begin(), spisok.end(), type);
            if (il == spisok.end()) {
                cout << "Данного товара не существует в системе, обратитесь к админу" << endl;
                nado();
            }
            else {
                cout << "Заявка на товар создана" << endl;
                note.push_back(infile);

                ofstream histor("C:\\Users\\96298\\Desktop\\Java\\history2.txt", ios::app);
                ofstream note2("C:\\Users\\96298\\Desktop\\Java\\zaivki2.txt", ios::app);
                for (int i = 0; i < note.size(); i++) {
                    histor << note[i] << endl;
                    note2 << note[i] << endl;
                }
                histor.close();
                note2.close();
                nado();
            }
        }
        else if (chose == 2) {
            vector<string> sklad;
            string number;
            cout << "На складе сейчас: " << endl;
            ifstream file("C:\\Users\\96298\\Desktop\\Java\\quality2.txt");

            while (file >> number) {
                sklad.push_back(number);
            }
            file.close();

            for (int i = 0; i < sklad.size(); i++) {
                cout << sklad[i] << endl;
            }
            nado();
        }
        else {
            cout << "Введите число от 1 до 2" << endl;
            nado();
        }
    }
};

class Provider {
public:
    Provider() {
        SendMen();
    }
    void SendMen() {
        int cislo;
        cout << "1. Посмотреть заявки" << endl << "2. Выслать продукты" << endl;
        cin >> cislo;
        ifstream file("C:\\Users\\96298\\Desktop\\Java\\zaivki2.txt");
        string line;
        ofstream out1("C:\\Users\\96298\\Desktop\\Java\\zaivki2.txt");

        switch (cislo) {
        case 1:
            cout << " Все заявки: " << endl;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
            SendMen();
            break;
        case 2:
            cout << "Товар отправлен" << endl;
            out1 << "";
            out1.close();
            SendMen();
            break;
        default:
            cout << "Введите число от 1 до 2" << endl;
            SendMen();
        }
    }
};

class Admin {
public:
    Admin() {
        menu();
    }
    void menu() {
        int choice;
        cout << "Выберите действие: " << endl;
        cout << "1. Просмотреть доход ресторана" << endl;
        cout << "2. Просмотреть и изменить меню" << endl;
        cout << "3. Просмотреть и изменить список товаров" << endl;
        cout << "4. Просмотреть склад" << endl;
        cout << "5. Выйти" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            viewIncome();
            break;
        case 2:
            modifyMenu();
            break;
        case 3:
            modifyProducts();
            break;
        case 4:
            viewWarehouse();
            break;
        case 5:
            cout << "Выход из системы" << endl;
            return;
        default:
            cout << "Неверный выбор, попробуйте снова" << endl;
            menu();
            break;
        }
    }

    void viewIncome() {
        vector<string> info;
        string line;
        ifstream file("C:\\Users\\96298\\Desktop\\Java\\info.txt");

        while (getline(file, line)) {
            info.push_back(line);
        }
        file.close();

        cout << "Информация о доходе ресторана:" << endl;
        for (const auto& entry : info) {
            cout << entry << endl;
        }

        menu();
    }

    void modifyMenu() {
        vector<string> menuItems;
        string line;
        ifstream file("C:\\Users\\96298\\Desktop\\Java\\menu2.txt");

        cout << "Текущее меню:" << endl;
        while (getline(file, line)) {
            menuItems.push_back(line);
            cout << line << endl;
        }
        file.close();

        int choice;
        cout << "Выберите действие: " << endl;
        cout << "1. Добавить блюдо" << endl;
        cout << "2. Удалить блюдо" << endl;
        cout << "3. Вернуться в меню" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            addDish(menuItems);
            break;
        case 2:
            removeDish(menuItems);
            break;
        case 3:
            menu();
            return;
        default:
            cout << "Неверный выбор, попробуйте снова" << endl;
            modifyMenu();
            return;
        }

        ofstream outFile("C:\\Users\\96298\\Desktop\\Java\\menu2.txt");
        for (const auto& item : menuItems) {
            outFile << item << endl;
        }
        outFile.close();

        modifyMenu();
    }

    void addDish(vector<string>& menuItems) {
        string newDish;
        cout << "Введите название нового блюда: ";
        cin.ignore();
        getline(cin, newDish);
        menuItems.push_back(newDish);
        cout << "Блюдо добавлено." << endl;
    }

    void removeDish(vector<string>& menuItems) {
        int index;
        cout << "Введите номер блюда для удаления: ";
        cin >> index;
        if (index > 0 && index <= menuItems.size()) {
            menuItems.erase(menuItems.begin() + index - 1);
            cout << "Блюдо удалено." << endl;
        }
        else {
            cout << "Неверный номер, попробуйте снова." << endl;
        }
    }

    void modifyProducts() {
        vector<string> products;
        string line;
        ifstream file("C:\\Users\\96298\\Desktop\\Java\\product2.txt");

        cout << "Текущий список товаров:" << endl;
        while (getline(file, line)) {
            products.push_back(line);
            cout << line << endl;
        }
        file.close();

        int choice;
        cout << "Выберите действие: " << endl;
        cout << "1. Добавить товар" << endl;
        cout << "2. Удалить товар" << endl;
        cout << "3. Вернуться в меню" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            addProduct(products);
            break;
        case 2:
            removeProduct(products);
            break;
        case 3:
            menu();
            return;
        default:
            cout << "Неверный выбор, попробуйте снова" << endl;
            modifyProducts();
            return;
        }

        ofstream outFile("C:\\Users\\96298\\Desktop\\Java\\product2.txt");
        for (const auto& item : products) {
            outFile << item << endl;
        }
        outFile.close();

        modifyProducts();
    }

    void addProduct(vector<string>& products) {
        string newProduct;
        cout << "Введите название нового товара: ";
        cin.ignore();
        getline(cin, newProduct);
        products.push_back(newProduct);
        cout << "Товар добавлен." << endl;
    }

    void removeProduct(vector<string>& products) {
        int index;
        cout << "Введите номер товара для удаления: ";
        cin >> index;
        if (index > 0 && index <= products.size()) {
            products.erase(products.begin() + index - 1);
            cout << "Товар удален." << endl;
        }
        else {
            cout << "Неверный номер, попробуйте снова." << endl;
        }
    }

    void viewWarehouse() {
        vector<string> warehouseItems;
        string line;
        ifstream file("C:\\Users\\96298\\Desktop\\Java\\quality2.txt");

        cout << "Складские запасы:" << endl;
        while (getline(file, line)) {
            warehouseItems.push_back(line);
            cout << line << endl;
        }
        file.close();

        menu();
    }
};

class Posetitel {
public:
    Posetitel() {
        menu();
    }

    void menu() {
        int choice;
        cout << "Выберите действие: " << endl;
        cout << "1. Просмотреть меню" << endl;
        cout << "2. Заказать блюдо" << endl;
        cout << "3. Просмотреть заказ" << endl;
        cout << "4. Выйти" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            viewMenu();
            break;
        case 2:
            orderDish();
            break;
        case 3:
            viewOrder();
            break;
        case 4:
            cout << "Выход из системы" << endl;
            return;
        default:
            cout << "Неверный выбор, попробуйте снова" << endl;
            menu();
            break;
        }
    }

    void viewMenu() {
        vector<string> menuItems;
        string line;
        ifstream file("C:\\Users\\96298\\Desktop\\Java\\menu2.txt");

        cout << "Меню ресторана:" << endl;
        while (getline(file, line)) {
            menuItems.push_back(line);
            cout << line << endl;
        }
        file.close();

        menu();
    }

    void orderDish() {
        vector<string> menuItems;
        string line;
        ifstream file("C:\\Users\\96298\\Desktop\\Java\\menu2.txt");

        cout << "Меню ресторана:" << endl;
        while (getline(file, line)) {
            menuItems.push_back(line);
            cout << menuItems.size() << ". " << line << endl;
        }
        file.close();

        int choice;
        cout << "Введите номер блюда для заказа: ";
        cin >> choice;

        if (choice > 0 && choice <= menuItems.size()) {
            string selectedDish = menuItems[choice - 1];
            ofstream orderFile("C:\\Users\\96298\\Desktop\\Java\\zakaz2.txt", ios::app);
            orderFile << selectedDish << endl;
            orderFile.close();
            cout << "Блюдо добавлено в заказ." << endl;
        }
        else {
            cout << "Неверный номер, попробуйте снова." << endl;
        }

        menu();
    }

    void viewOrder() {
        vector<string> orderItems;
        string line;
        ifstream file("C:\\Users\\96298\\Desktop\\Java\\zakaz2.txt");

        cout << "Ваш заказ:" << endl;
        while (getline(file, line)) {
            orderItems.push_back(line);
            cout << line << endl;
        }
        file.close();

        menu();
    }
};

class Role {
public:
    virtual void performRole() = 0;
};

class PosetitelRole : public Role {
public:
    void performRole() override {
        Posetitel posetitel;
    }
};

class OficiantRole : public Role {
public:
    void performRole() override {
        oficiant oficiant;
    }
};

class PovarRole : public Role {
public:
    void performRole() override {
        Povar povar;
    }
};

class MoneyRole : public Role {
public:
    void performRole() override {
        Money money;
    }
};

class SkladovRole : public Role {
public:
    void performRole() override {
        Skladov skladov;
    }
};

class ProviderRole : public Role {
public:
    void performRole() override {
        Provider provider;
    }
};

class AdminRole : public Role {
public:
    void performRole() override {
        Admin admin;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    string login, password;
    cout << "Введите логин:" << endl;
    cin >> login;
    cout << "Введите пароль:" << endl;
    cin >> password;

    string filename = "C:\\Users\\96298\\Desktop\\Java\\password2.txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Не удалось открыть файл с логинами и паролями: " << filename << endl;
        return 1;
    }

    string line;
    bool authenticated = false;

    while (getline(file, line)) {
        size_t pos = line.find(':');
        if (pos != string::npos) {
            string username = line.substr(0, pos);
            string passwd = line.substr(pos + 1);

            if (login == username && password == passwd) {
                authenticated = true;
                break;
            }
        }
    }

    file.close();

    if (authenticated) {
        Role* role = nullptr;

        if (login == "posetitel" && password == "posetitel123") {
            role = new PosetitelRole();
        }
        else if (login == "oficiant" && password == "oficiant123") {
            role = new OficiantRole();
        }
        else if (login == "povar" && password == "povar123") {
            role = new PovarRole();
        }
        else if (login == "money" && password == "money123") {
            role = new MoneyRole();
        }
        else if (login == "skladov" && password == "skladov123") {
            role = new SkladovRole();
        }
        else if (login == "provider" && password == "provider123") {
            role = new ProviderRole();
        }
        else if (login == "admin" && password == "admin123") {
            role = new AdminRole();
        }
        else {
            cout << "Неправильный логин или пароль" << endl;
            return 1;
        }

        if (role) {
            role->performRole();
            delete role;
        }
    }
    else {
        cout << "Неправильный логин или пароль" << endl;
    }

    return 0;
}

