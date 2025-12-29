#include <iostream>
#include <cstring>

using namespace std;

// Структура даты
struct Date {
    int day;
    int month;
    int year;
};

// Структура товара
struct Product {
    char name[50];
    double price;
    Date arrivalDate;
};

int main() {
    int n;
    cout << "Введите количество товаров: ";
    cin >> n;
    cin.ignore();

    // Динамический массив товаров
    Product* products = new Product[n];

    // Ввод данных
    for (int i = 0; i < n; i++) {
        cout << "\nТовар " << i + 1 << endl;

        cout << "Название: ";
        cin.getline(products[i].name, 50);

        cout << "Цена: ";
        cin >> products[i].price;

        cout << "Дата поступления (день месяц год): ";
        cin >> products[i].arrivalDate.day
            >> products[i].arrivalDate.month
            >> products[i].arrivalDate.year;

        cin.ignore();
    }

    // === Поиск по месяцу ===
    int searchMonth;
    cout << "\nВведите номер месяца для поиска: ";
    cin >> searchMonth;

    int countMonth = 0;
    for (int i = 0; i < n; i++) {
        if (products[i].arrivalDate.month == searchMonth)
            countMonth++;
    }

    Product* byMonth = new Product[countMonth];
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (products[i].arrivalDate.month == searchMonth)
            byMonth[k++] = products[i];
    }

    cout << "\n=== Товары, поступившие в месяце " << searchMonth << " ===\n";

    if (countMonth == 0) {
        cout << "Таких товаров нет.\n";
    } else {
        for (int i = 0; i < countMonth; i++) {
            cout << "\nНазвание: " << byMonth[i].name;
            cout << "\nЦена: " << byMonth[i].price;
            cout << "\nДата: "
                 << byMonth[i].arrivalDate.day << "."
                 << byMonth[i].arrivalDate.month << "."
                 << byMonth[i].arrivalDate.year << endl;
        }
    }

    delete[] byMonth;
    cin.ignore();

    // === Поиск по названию ===
    char searchName[50];
    cout << "\nВведите название товара для поиска: ";
    cin.getline(searchName, 50);

    int countName = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(products[i].name, searchName) == 0)
            countName++;
    }

    Product* byName = new Product[countName];
    k = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(products[i].name, searchName) == 0)
            byName[k++] = products[i];
    }

    cout << "\n=== Товары с названием \"" << searchName << "\" ===\n";

    if (countName == 0) {
        cout << "Таких товаров нет.\n";
    } else {
        for (int i = 0; i < countName; i++) {
            cout << "\nНазвание: " << byName[i].name;
            cout << "\nЦена: " << byName[i].price;
            cout << "\nДата: "
                 << byName[i].arrivalDate.day << "."
                 << byName[i].arrivalDate.month << "."
                 << byName[i].arrivalDate.year << endl;
        }
    }

    delete[] products;
    delete[] byName;

    return 0;
}
