﻿// Подключаем библиотеки
#include <vector>
#include <windows.h>

using namespace std; // Задаём пространство имён

void main() // Главная функция
{
    // Задаём кодировку ввода и вывода для консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int m_A, m_B, par1, par2, ord, n = 1, k = 1; // Декларация переменных

    printf("Выберите способ задания множеств (1:Перечисление; 2:Высказывание): "); // Вывод инструкции для пользователя
    scanf_s("%i", &par2); // Заносим ввод пользователя в переменную par2

    printf("\nВведите мощность множества А: "); // Вывод инструкции для пользователя
    scanf_s("%i", &m_A); // Заносим ввод пользователя в переменную m_A 

    vector <int> A(m_A); // Декларация множества А размером m_A

    // Цикл для записи множества А
    for (int j = 0; j < m_A; j++)
    {
        if (par2 == 1) // Проверка на то, какой способ задания множества выбрал пользователь
        {
            printf("%s %i %s", "Введите ", j + 1, "элемент множества А: "); // Вывод инструкции для пользователя
            scanf_s("%i", &A[j]); // Заносим ввод пользователя в переменную A[i]
        }
        else
            A[j] = 3 * (n++) + 1; // Заносим значение выражения в переменную A[i]
    }

    printf("Введите мощность множества В: "); // Вывод инструкции для пользователя
    scanf_s("%i", &m_B); // Заносим ввод пользователя в переменную m_B

    vector <int> B(m_B); // Декларация множества В размером m_B

    // Цикл для записи множества В
    for (int i = 0; i < m_B; i++)
    {
        if (par2 == 1) // Проверка на то, какой способ задания множества выбрал пользователь
        {
            printf("%s %i %s", "Введите ", i + 1, "элемент множества В: "); // Вывод инструкции для пользователя
            scanf_s("%i", &B[i]); // Заносим ввод пользователя в переменную B[j]
        }
        else
            B[i] = 2 * (k++) + 3; // Заносим значение выражения в переменную B[j]
    }

    vector <int> C(1); // Декларация множества С с изначальным размером 1

    // Вывод меню операций и инструкции для пользователя
    printf("\nВыберите операцию (1, 2, 3, 4, 5 или 6): ");
    printf("\n1) Объединение\n");
    printf("2) Пересечение\n");
    printf("3) Разность\n");
    printf("4) Симметрическая разность\n");
    printf("5) Декартово произведение\n");
    printf("6) Дополнение\n");
    scanf_s("%i", &par1); // Заносим ввод пользователя в переменную

    // Проверка значения переменной 
    switch (par1)
    {
    case 1: // Операция объединения
    {

        // Цикл для записи множества А в множество С
        for (int j = 0; j < m_A; j++)
        {
            C.push_back(A[j]); // Запись всех элементов множества А в множество С
        }

        // Вложенный цикл для обработки элементов множеств В и А
        for (int i = 0; i < m_B; i++)
        {
            for (int j = 0; j < m_A; j++)
            {
                if (B[i] != A[j] && j == m_A - 1) // Проверка на неравенство элементов множеств В и А, и на то, что элемент множества А является последним 
                {
                    C.push_back(B[i]); // Записываем элемент множества В в множество С
                    break; // Выходим из цикла и начинаем следующую итерацию i++
                }
                else
                {
                    if (B[i] == A[j]) // Проверка на равенство элементов множеств В и А
                        break; // Выходим из цикла и начинаем следующую итерацию i++
                }
            }
        }

        break; // Выходим из блока switch
    }

    case 2: // Операция пересечения
    {
        // Вложенный цикл для обработки элементов множеств В и А
        for (int j = 0; j < m_A; j++)
        {
            for (int i = 0; i < m_B; i++)
            {
                if (B[i] == A[j]) // Проверка на равенство элементов множеств В и А
                {
                    C.push_back(B[i]); // Записываем элемент множества В в множество С
                    break; // Выходим из цикла и начинаем следующую итерацию i++
                }
            }
        }

        break; // Выходим из блока switch
    }

    case 3: // Операция разности
    {
        // Вывод меню выбора и нструкции для пользователя
        printf("\n1) А\\В");
        printf("\n2) В\\А\n");
        printf("Выберите порядок разности (1 или 2): ");
        scanf_s("%i", &ord); // Заносим ввод пользователя в переменную

        if (ord == 1) // Проверка переменной 
        {
            // Цикл для обработки элементов множества А
            for (int j = 0; j < m_A; j++)
            {
                if (count(B.begin(), B.end(), A[j]) == 0) // Проверка наличия элементов множества А в В
                    C.push_back(A[j]); // Записываем элемент множества А в С
            }
        }
        else
        {
            // Цикл для обработки элементов множества В
            for (int i = 0; i < m_B; i++)
            {
                if (count(A.begin(), A.end(), B[i]) == 0) // Проверка наличия элементов множества В в А
                    C.push_back(B[i]); // Записываем элемент множества В в С
            }
        }

        break; // Выходим из блока switch
    }

    case 4: // Операция симметрической разности
    {
        // Цикл для обработки элементов множества А
        for (int j = 0; j < m_A; j++)
        {
            if (count(B.begin(), B.end(), A[j]) == 0) // Проверка наличия элементов множества А в В
                C.push_back(A[j]); // Записываем элемент множества А в С
        }

        // Цикл для обработки элементов множества В
        for (int i = 0; i < m_B; i++)
        {
            if (count(A.begin(), A.end(), B[i]) == 0) // Проверка наличия элементов множества В в А
                C.push_back(B[i]); // Записываем элемент множества В в С
        }

        break; // Выходим из блока switch
    }

    case 5: // Операция декартова произведения
    {
        // Вывод меню выбора и нструкции для пользователя
        printf("\n1) А x В");
        printf("\n2) В x А\n");
        printf("Выберите порядок произведения (1 или 2): ");
        scanf_s("%i", &ord); // Заносим ввод пользователя в переменную

        if (ord == 1) // Проверка переменной
        {
            // Вложенный цикл для обработки элементов множеств В и А
            for (int j = 0; j < m_A; j++)
            {
                for (int i = 0; i < m_B; i++)
                {
                    // Записывание кортежа, где первый компонент - элемент множества А, а второй - элемент В
                    C.push_back(A[j]);
                    C.push_back(B[i]);
                }
            }
        }
        else
        {
            // Вложенный цикл для обработки элементов множеств В и А
            for (int i = 0; i < m_B; i++)
            {
                for (int j = 0; j < m_A; j++)
                {
                    // Записывание кортежа, где первый компонент - элемент множества В, а второй - элемент А
                    C.push_back(B[i]);
                    C.push_back(A[j]);
                }
            }
        }

        break; // Выходим из блока switch
    }

    case 6: // Операция дополнения 
    {
        // Вывод меню выбора и нструкции для пользователя
        printf("\n1) А'");
        printf("\n2) В'\n");
        printf("Выберите множество над которым будет происходить операция (1 или 2): ");
        scanf_s("%i", &ord); // Заносим ввод пользователя в переменную

        // Цикл для обработки элементов универсального множества
        for (int p = 1; p < 100; p++)
        {
            if (ord == 1) // Проверка переменной 
            {
                if (count(A.begin(), A.end(), p) == 0) // Проверка наличия элементов универсального множества в А
                    C.push_back(p); // Записываем элемент универсального множества в С
            }
            else
            {
                if (count(B.begin(), B.end(), p) == 0) // Проверка наличия элементов универсального множества в В
                    C.push_back(p); // Записываем элемент универсального множества в С
            }
        }
        break; // Выходим из блока switch
    }

    }

    if (par1 != 5) // Проверка на то, что пользователь не выбрал декартово произведение
    {

        printf("\nМножество C:{"); // Вывод пояснительного сообщения для пользователя

        // Цикл для вывода множества С
        for (int i = 1; i < C.size(); i++)
            printf("%s %i", " ", C[i]); // Вывод элементов множества С

        printf(" }\n"); // Вывод пояснительного сообщения для пользователя
        system("pause"); // Остановка работы программы до тех пор пока пользователь не нажмёт любую клавишу
    }
    else
    {
        printf("\nМножество C:{"); // Вывод пояснительного сообщения для пользователя

        // Цикл для вывода множества С
        for (int i = 1; i < C.size() - 1; i += 2)
            printf("%s %i %i %s", " <", C[i], C[i + 1], ">"); // Вывод элементов множества С

        printf(" }\n"); // Вывод пояснительного сообщения для пользователя
        system("pause"); // Остановка работы программы до тех пор пока пользователь не нажмёт любую клавиш
    }
}
