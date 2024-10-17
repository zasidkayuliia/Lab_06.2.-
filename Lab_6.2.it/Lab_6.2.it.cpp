#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High) // Формування масиву
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(const int* a, const int size) // Виведення масиву
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

int Count(const int* a, const int size) // Кількість елементів з парними індексами
{
    int N = 0;
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            N++;
        }
    }
    return N;
}

int Sum(const int* a, const int size) // Сума елементів з парними індексами
{
    int S = 0;
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            S += a[i];
        }
    }
    return S;
}

double CalculateArithmeticMean(const int* a, const int size) // Обчислення середнього арифметичного
{
    int count = Count(a, size);
    int sum = Sum(a, size);
    return static_cast<double>(sum) / count;
}

int main()
{
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел
    const int n = 21;
    int a[n];

    int Low = 15;
    int High = 85;

    // Формування та виведення масиву
    Create(a, n, Low, High);
    Print(a, n);

    // Обчислення середнього арифметичного елементів з парними індексами
    double arithmeticMean = CalculateArithmeticMean(a, n);

    // Виведення результату
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    cout << "Середнє арифметичне елементів з парними індексами: " << arithmeticMean << endl;

    return 0;
}