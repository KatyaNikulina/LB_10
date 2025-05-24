#include <iostream>
#include <iomanip>

using namespace std;

// Структура для завдання 1
struct TTime 
{
    int Hour;  // 0..23
    int Min;   // 0..59
    int Sec;   // 0..59
    bool IsCorrect;
};

void ShowTime(const TTime& T);
bool IsValidTime(int Hour, int Min, int Sec);
void SetTime(TTime& T, int Hour, int Min, int Sec);
void NextSec(TTime& T);

//======= Завданне 1: Процедура NextSec ========
void ShowTime(const TTime& T) 
{
    if (T.IsCorrect) 
    {
        cout << setfill('0') << setw(2) << T.Hour << ":"
            << setfill('0') << setw(2) << T.Min << ":"
            << setfill('0') << setw(2) << T.Sec;
    }
    else 
    {
        cout << "Wrong time";
    }
}

bool IsValidTime(int Hour, int Min, int Sec) 
{
    return (Hour >= 0) && (Hour <= 23) &&
        (Min >= 0) && (Min <= 59) &&
        (Sec >= 0) && (Sec <= 59);
}

void SetTime(TTime& T, int Hour, int Min, int Sec) 
{
    if (IsValidTime(Hour, Min, Sec)) 
    {
        T.Hour = Hour;
        T.Min = Min;
        T.Sec = Sec;
        T.IsCorrect = true;
    }
    else 
    {
        T.IsCorrect = false;
    }
}

void NextSec(TTime& T) 
{
    if (!T.IsCorrect)
    {
        return; // Якщо час неправильний, не змінюємо його
    }

    T.Sec = T.Sec + 1;

    if (T.Sec == 60) 
    {
        T.Sec = 0;
        T.Min = T.Min + 1;

        if (T.Min == 60) 
        {
            T.Min = 0;
            T.Hour = T.Hour + 1;

            if (T.Hour == 24) 
            {
                T.Hour = 0;
            }
        }
    }
}

void Task1() 
{
    cout << "\n=== Task 1: NextSec Procedure ===\n" << endl;

    TTime times[5]; // Масив для зберігання 5 моментів часу
    int hour, min, sec;

    // Ввод 5 моментів часу
    for (int i = 0; i < 5; i++) 
    {
        cout << "Enter time T" << (i + 1) << " (hours minutes seconds): ";
        cin >> hour >> min >> sec;
        SetTime(times[i], hour, min, sec);
    }

    // Виводимо ісходні значення часу
    cout << "\nOutput time values:" << endl;
    for (int i = 0; i < 5; i++) 
    {
        cout << "T" << (i + 1) << " = ";
        ShowTime(times[i]);
        cout << endl;
    }

    // Застосовуємо процедуру NextSec до кожного моменту часу
    cout << "\nAfter NextSec execution:" << endl;
    for (int i = 0; i < 5; i++) 
    {
        NextSec(times[i]);
        cout << "T" << (i + 1) << " = ";
        ShowTime(times[i]);
        cout << endl;
    }
}

//======= Завданне 2: Обмін значень змінних A и B ========

void Task2() 
{
    cout << "\n=== Task 2: Exchange the values ​​of variables A and B ===\n" << endl;

    int A, B;

    // Ввод значень A и B
    cout << "Enter the value of A: ";
    cin >> A;

    cout << "Enter the value of B: ";
    cin >> B;

    // Вивести початкові значення
    cout << "Initial values:" << endl;
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;

    int temp = A;
    A = B;
    B = temp;

    // Виводимо новіе значення після обміну
    cout << "\nNew values ​​after swap:" << endl;
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
}

//======= Завданне 3: Перевірка існування трикутника ========

void Task3() 
{
    cout << "\n=== Task 3: Checking the existence of a triangle ===\n" << endl;

    int a, b, c;

    // Ввод даних
    cout << "Enter the length of side a: ";
    cin >> a;

    cout << "Enter the length of side b: ";
    cin >> b;

    cout << "Enter the length of side c: ";
    cin >> c;

    // Перевірка існування трикутника за нерівністю трикутника
    bool exists = false;

    // Всі сторони мають бути додатними
    if (a > 0 && b > 0 && c > 0) 
    {
        // Кожна сторона має бути меншою за суму двох інших
        if (a < b + c && b < a + c && c < a + b) 
        {
            exists = true;
        }
    }

    // Виведення результату
    if (exists) 
    {
        cout << "The statement is true: a triangle with sides "
            << a << ", " << b << ", " << c << " exists." << endl;
    }
    else 
    {
        cout << "The statement is false: a triangle with sides "
            << a << ", " << b << ", " << c << " does not exist." << endl;
    }
}

int main()
{

    int choice;
    bool exitProgram = false;

    while (!exitProgram)
    {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Task 1: NextSec procedure (time change)" << endl;
        cout << "2. Task 2: Swapping the values ​​of variables A and B" << endl;
        cout << "3. Task 3: Checking the existence of a triangle" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter the task number: ";
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
            cout << "Incorrect selection. Try again.." << endl;
        }
    }

    return 0;
}
