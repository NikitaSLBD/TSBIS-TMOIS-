﻿// Подключение библиотек
#include <stdio.h>
#include <vector>
#include <windows.h>

using namespace std; // Задаём пространство имён


void main() // Главная функция
{
    // Задаём кодировку ввода и вывода для консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int m_A, m_B, par; // Декларация переменных

    printf("Введите мощность множества А: "); // Вывод инструкции для пользователя
    scanf_s("%i", &m_A, "\n"); // Заносим ввод пользователя в переменную 

    vector <int> A(m_A); // Декларация множества А размером 

    // Цикл для записи множества А
    for (int i = 0; i < m_A; i++)
    {
        printf("%s %i %s", "Введите ", i + 1, "элемент множества А: "); // Вывод инструкции для пользователя
        scanf_s("%i", &A[i]); // Заносим ввод пользователя в переменную
    }

    printf("Введите мощность множества В: "); // Вывод инструкции для пользователя
    scanf_s("%i", &m_B, "\n"); // Заносим ввод пользователя в переменную

    vector <int> B(m_B); // Декларация множества В размером

    // Цикл для записи множества В
    for (int j = 0; j < m_B; j++)
    {
        printf("%s %i %s", "Введите ", j + 1, "элемент множества В: "); // Вывод инструкции для пользователя
        scanf_s("%i", &B[j]); // Заносим ввод пользователя в переменную
    }

    printf("\nМножество A:{"); // Вывод пояснительного сообщения для пользователя

    // Цикл для вывода множества А
    for (int i = 0; i < m_A; i++)
    {
        printf("%s %i", " ", A[i]); // Вывод элементов множества А
    }

    printf(" }\nМножество B:{"); // Вывод пояснительного сообщения для пользователя

    // Цикл для вывода множества В
    for (int i = 0; i < m_B; i++)
    {
        printf("%s %i", " ", B[i]); // Вывод элементов множества В
    }

    vector <int> C(1); // Декларация множества С с изначальным размером 1


    // Вывод меню операций с инструкцией для пользователя
    printf(" }\n1) Объединение\n");
    printf("2) Пересечение\n");
    printf("Выберите операцию: ");

    scanf_s("%i", &par); // Заносим ввод пользователя в переменную

    // Проверка значения переменной 
    switch (par)
    {
    case 1: // Операция объединения
    {

        // Цикл для записи множества А в множество С
        for (int i = 0; i < m_A; i++)
        {
            C.push_back(A[i]);
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
        for (int i = 0; i < m_A; i++)
        {
            for (int j = 0; j < m_B; j++)
            {
                if (B[j] == A[i]) // Проверка на равенство элементов множеств В и А
                {
                    C.push_back(B[j]); // Записываем элемент множества В в множество С
                    break; // Выходим из цикла и начинаем следующую итерацию i++
                }
            }
        }

        break; // Выходим из блока switch
    }

    }

    printf("\nМножество C:{"); // Вывод пояснительного сообщения для пользователя

    // Цикл для вывода множества С
    for (int i = 1; i < C.size(); i++)
    {
        printf("%s %i", " ", C[i]); // Вывод элементов множества С
    }

    printf(" }\n"); // Вывод пояснительного сообщения для пользователя
    system("pause"); // Остановка работы программы до тех пор пока пользователь не нажмёт любую клавишу
}

