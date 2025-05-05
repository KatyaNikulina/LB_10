#include <iostream>
#include <iomanip>

using namespace std;

// Структура для задания 1
struct TTime {
    int Hour;  // 0..23
    int Min;   // 0..59
    int Sec;   // 0..59
    bool IsCorrect;
};

// Прототипы функций для задания 1
void ShowTime(const TTime& T);
bool IsValidTime(int Hour, int Min, int Sec);
void SetTime(TTime& T, int Hour, int Min, int Sec);
void NextSec(TTime& T);
void Task1();

// Прототип функции для задания 2
void Task2();

// Прототип функции для задания 3
void Task3();

int main() 
{

    setlocale(LC_ALL, "Russian");

    int choice;
    bool exitProgram = false;

    while (!exitProgram) 
    {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Задание 1: Процедура NextSec (изменение времени)" << endl;
        cout << "2. Задание 2: Обмен значений переменных A и B" << endl;
        cout << "3. Задание 3: Проверка существования треугольника" << endl;
        cout << "0. Выход" << endl;
        cout << "Введите номер задания: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        case 3:
            Task3();
            break;
        case 0:
            exitProgram = true;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    }

    return 0;
}

//======= Задание 1: Процедура NextSec ========

void ShowTime(const TTime& T) {
    if (T.IsCorrect) {
        cout << setfill('0') << setw(2) << T.Hour << ":"
            << setfill('0') << setw(2) << T.Min << ":"
            << setfill('0') << setw(2) << T.Sec;
    }
    else {
        cout << "Неправильное время";
    }
}

bool IsValidTime(int Hour, int Min, int Sec) {
    return (Hour >= 0) && (Hour <= 23) &&
        (Min >= 0) && (Min <= 59) &&
        (Sec >= 0) && (Sec <= 59);
}

void SetTime(TTime& T, int Hour, int Min, int Sec) {
    if (IsValidTime(Hour, Min, Sec)) {
        T.Hour = Hour;
        T.Min = Min;
        T.Sec = Sec;
        T.IsCorrect = true;
    }
    else {
        T.IsCorrect = false;
    }
}

void NextSec(TTime& T) {
    if (!T.IsCorrect) {
        return; // Якщо час неправильний, не змінюємо його
    }

    T.Sec = T.Sec + 1;

    if (T.Sec == 60) {
        T.Sec = 0;
        T.Min = T.Min + 1;

        if (T.Min == 60) {
            T.Min = 0;
            T.Hour = T.Hour + 1;

            if (T.Hour == 24) {
                T.Hour = 0;
            }
        }
    }
}

void Task1() {
    cout << "\n=== Задание 1: Процедура NextSec ===\n" << endl;

    TTime times[5]; // Массив для хранения 5 моментов времени
    int hour, min, sec;

    // Ввод 5 моментов времени
    for (int i = 0; i < 5; i++) {
        cout << "Введите время T" << (i + 1) << " (часы минуты секунды): ";
        cin >> hour >> min >> sec;
        SetTime(times[i], hour, min, sec);
    }

    // Выводим исходные значения времени
    cout << "\nВыходные значения времени:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "T" << (i + 1) << " = ";
        ShowTime(times[i]);
        cout << endl;
    }

    // Применяем процедуру NextSec к каждому моменту времени
    cout << "\nПосле виполнения NextSec:" << endl;
    for (int i = 0; i < 5; i++) {
        NextSec(times[i]);
        cout << "T" << (i + 1) << " = ";
        ShowTime(times[i]);
        cout << endl;
    }
}

//======= Задание 2: Обмен значений переменных A и B ========

void Task2() {
    cout << "\n=== Задание 2: Обмен значений переменных A и B ===\n" << endl;

    int A, B;

    // Ввод значений A и B
    cout << "Введите значение A: ";
    cin >> A;

    cout << "Введите значение B: ";
    cin >> B;

    // Выводим начальные значения
    cout << "Начальные значения:" << endl;
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;

    // Метод 1: Использование временной переменной
    int temp = A;
    A = B;
    B = temp;

    // Выводим новые значения после обмена
    cout << "\nНовые значения посля обмена:" << endl;
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
}

//======= Задание 3: Проверка существования треугольника ========

void Task3() {
    cout << "\n=== Задание 3: Проверка существования треугольника ===\n" << endl;

    int a, b, c;

    // Введення даних
    cout << "Введите длину стороны a: ";
    cin >> a;

    cout << "Введите длину стороны b: ";
    cin >> b;

    cout << "Введите длину стороны c: ";
    cin >> c;

    // Перевірка існування трикутника за нерівністю трикутника
    bool exists = false;

    // Всі сторони мають бути додатними
    if (a > 0 && b > 0 && c > 0) {
        // Кожна сторона має бути меншою за суму двох інших
        if (a < b + c && b < a + c && c < a + b) {
            exists = true;
        }
    }

    // Виведення результату
    if (exists) {
        cout << "Высказывание истинно: треугольник со сторонами"
            << a << ", " << b << ", " << c << " существует." << endl;
    }
    else {
        cout << "Высказывание ошибочно: треугольник со сторонами"
            << a << ", " << b << ", " << c << " не существует." << endl;
    }
}
