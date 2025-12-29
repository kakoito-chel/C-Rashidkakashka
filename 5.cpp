#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

const int N = 10;

void fillArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 41 - 20; 
}


void printArray(const int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << arr[i];
    cout << endl;
}


void sortByAbs(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (abs(arr[j]) > abs(arr[j + 1]))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int sumNegative(const int* arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] < 0)
            sum += arr[i];
    return sum;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr));

    int M[N];

    fillArray(M, N);

    cout << "Исходный массив M:\n";
    printArray(M, N);

    sortByAbs(M, N);

    cout << "\nМассив, упорядоченный по возрастанию модулей:\n";
    printArray(M, N);

    int sum = sumNegative(M, N);

    cout << "\nСумма отрицательных элементов массива = " << sum << endl;

    return 0;
}
