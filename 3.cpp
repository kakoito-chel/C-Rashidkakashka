#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // Исходный массив (пример)
    vector<int> arr = {123, -456, 789, 0, -321, 654, 0, -999, 111, 0};

    cout << "Исходный массив: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    int countPos = 0, countNeg = 0;
    vector<int> zeroIndices;

    // Подсчёт положительных, отрицательных и поиск нулей
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) countPos++;
        else if (arr[i] < 0) countNeg++;
        else zeroIndices.push_back(i);
    }

    cout << "Количество положительных элементов: " << countPos << "\n";
    cout << "Количество отрицательных элементов: " << countNeg << "\n";

    // Вывод массива индексов нулевых элементов
    cout << "Индексы нулевых элементов: ";
    if (zeroIndices.empty()) cout << "нет";
    else for (int i : zeroIndices) cout << i << " ";
    cout << "\n";

    // Замена нулей на сумму трёх предыдущих положительных
    for (int idx : zeroIndices) {
        int sum = 0, found = 0;
        // Идем назад от текущего индекса
        for (int j = idx - 1; j >= 0 && found < 3; j--) {
            if (arr[j] > 0) {
                sum += arr[j];
                found++;
            }
        }
        // Если найдено меньше трёх положительных — можно оставить как есть
        if (found == 3)
            arr[idx] = sum;
        else
            arr[idx] = 0; // или можно оставить без изменений
    }

    // Вывод результирующего массива
    cout << "Результирующий массив: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
