#include <iostream>
#include <iomanip>  
#include <cstdlib>  
#include <ctime>    

using namespace std;
double average(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return static_cast<double>(sum) / size;
}

int count_less_than_avg(const int arr[], int size, double avg) {
    int count = 0;
    cout << "Элементы меньше среднего (" << fixed << setprecision(2) << avg << "): ";
    for (int i = 0; i < size; i++) {
        if (arr[i] < avg) {
            cout << arr[i] << " ";
            count++;
        }
    }
    cout << endl;
    return count;
}

void fill_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = 10 + rand() % 90;
}

int main() {
    srand(time(0));
    const int sizeA = 27;
    const int sizeB = 34;
    const int sizeC = 11;
    const int sizeD = 40;

    int A[sizeA], B[sizeB], C[sizeC], D[sizeD];
    fill_array(A, sizeA);
    fill_array(B, sizeB);
    fill_array(C, sizeC);
    fill_array(D, sizeD);

    cout << "=== Массив A ===" << endl;
    double avgA = average(A, sizeA);
    cout << "Среднее арифметическое: " << avgA << endl;
    cout << "Количество элементов меньше среднего: " << count_less_than_avg(A, sizeA, avgA) << endl << endl;

    cout << "=== Массив B ===" << endl;
    double avgB = average(B, sizeB);
    cout << "Среднее арифметическое: " << avgB << endl;
    cout << "Количество элементов меньше среднего: " << count_less_than_avg(B, sizeB, avgB) << endl << endl;

    cout << "=== Массив C ===" << endl;
    double avgC = average(C, sizeC);
    cout << "Среднее арифметическое: " << avgC << endl;
    cout << "Количество элементов меньше среднего: " << count_less_than_avg(C, sizeC, avgC) << endl << endl;

    cout << "=== Массив D ===" << endl;
    double avgD = average(D, sizeD);
    cout << "Среднее арифметическое: " << avgD << endl;
    cout << "Количество элементов меньше среднего: " << count_less_than_avg(D, sizeD, avgD) << endl << endl;

    return 0;
}
