// Подключаем библиотеки
#include <vector>
#include <windows.h>
#include <utility>

using namespace std; // Задаём пространство имён

void main() // Главная функция
{
    // Задаём кодировку ввода и вывода для консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int m_A, m_B, par1, ord, n = 1, k = 1; // Декларация переменных

    printf("Введите мощность графика А: "); // Вывод инструкции для пользователя
    scanf_s("%i", &m_A); // Заносим ввод пользователя в переменную m_A 

    vector <pair <int, int> > A(m_A); // Декларация графика А размером m_A

    // Цикл для записи графика А
    for (int j = 0; j < m_A; j++)
    {
        printf("%s %i %s", "Введите ", j + 1, "кортеж графика A: "); // Вывод инструкции для пользователя
        scanf_s("%i %i", &A[j].first, &A[j].second); // Заносим ввод пользователя в переменную A[j]
    }

    printf("Введите мощность графика В: "); // Вывод инструкции для пользователя
    scanf_s("%i", &m_B); // Заносим ввод пользователя в переменную m_B

    vector <pair <int, int> > B(m_B); // Декларация множества В размером m_B

    // Цикл для записи множества В
    for (int i = 0; i < m_B; i++)
    {
        printf("%s %i %s", "Введите ", i + 1, "кортеж графика В: "); // Вывод инструкции для пользователя
        scanf_s("%i %i", &B[i].first, &B[i].second); // Заносим ввод пользователя в переменную B[i]
    }

    vector <pair <int, int>> C; // Декларация графика С

    // Вывод меню операций и инструкции для пользователя
    printf("\nВыберите операцию (1, 2, 3, 4, 5 или 6): ");
    printf("\n1) Объединение\n");
    printf("2) Пересечение\n");
    printf("3) Разность\n");
    printf("4) Симметрическая разность\n");
    printf("5) Дополнение\n");
    printf("6) Инверсия\n");
    printf("7) Композиция\n");
    scanf_s("%i", &par1); // Заносим ввод пользователя в переменную

    // Проверка значения переменной 
    switch (par1)
    {
        case 1: // Операция объединения
        {

            // Цикл для записи графика А в график С
            for (int i = 0; i < m_A; i++)
            {
                C.push_back(A[i]); // Запись всех элементов графика А в график С
            }

            // Вложенный цикл для обработки элементоd графиков В и А
            for (int i = 0; i < m_B; i++)
            {
                for (int j = 0; j < m_A; j++)
                {
                    if (B[i] != A[j] && j == m_A - 1) // Проверка на неравенство элементов графиков В и А, и на то, что элемент гафика А является последним 
                    {
                        C.push_back(B[i]); // Записываем элемент графика В в график С
                        break; // Выходим из цикла и начинаем следующую итерацию i++
                    }
                    else
                    {
                        if (B[i] == A[j]) // Проверка на равенство элементов графиков В и А
                            break; // Выходим из цикла и начинаем следующую итерацию i++
                    }
                }
            }

            break; // Выходим из блока switch
        }

        case 2: // Операция пересечения
        {
            // Вложенный цикл для обработки элементов графиков В и А
            for (int j = 0; j < m_A; j++)
            {
                for (int i = 0; i < m_B; i++)
                {
                    if (B[i] == A[j]) // Проверка на равенство элементов графиков В и А
                    {
                        C.push_back(B[i]); // Записываем элемент графика В в график С
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
                // Цикл для обработки элементов графика А
                for (int j = 0; j < m_A; j++)
                {
                    if (count(B.begin(), B.end(), A[j]) == 0) // Проверка наличия элементов графика А в В
                        C.push_back(A[j]); // Записываем элемент графика А в С
                }
            }
            else
            {
                // Цикл для обработки элементов графика В
                for (int i = 0; i < m_B; i++)
                {
                    if (count(A.begin(), A.end(), B[i]) == 0) // Проверка наличия элементов графика В в А
                        C.push_back(B[i]); // Записываем элемент графика В в С
                }
            }

            break; // Выходим из блока switch
        }

        case 4: // Операция симметрической разности
        {
            // Цикл для обработки элементов множества А
            for (int j = 0; j < m_A; j++)
            {
                if (count(B.begin(), B.end(), A[j]) == 0) // Проверка наличия элементов графика А в В
                    C.push_back(A[j]); // Записываем элемент графика А в С
            }

            // Цикл для обработки элементов множества В
            for (int i = 0; i < m_B; i++)
            {
                if (count(A.begin(), A.end(), B[i]) == 0) // Проверка наличия элементов графика В в А
                    C.push_back(B[i]); // Записываем элемент графика В в С
            }

            break; // Выходим из блока switch
        }

        case 5: // Операция дополнения 
        {
            // Вывод меню выбора и нструкции для пользователя
            printf("\n1) А'");
            printf("\n2) В'\n");
            printf("Выберите график над которым будет происходить операция (1 или 2): ");
            scanf_s("%i", &ord); // Заносим ввод пользователя в переменную

            vector <pair <int, int> > U(10000);
            int u = 0;

            // Цикл для создания универсального графика
            for (int p = 1; p <= 100; p++)
            {
                for (int q = 1; q <= 100; q++, u++)
                {
                    U[u].first = p;
                    U[u].second = q;
                }

            }

            // Цикл для обработки элементов универсального графика
            for (int p = 0; p < U.size(); p++)
            {
                if (ord == 1) // Проверка переменной 
                {
                    if (count(A.begin(), A.end(), U[p]) == 0) // Проверка наличия элементов универсального графика в А
                        C.push_back(U[p]); // Записываем элемент универсального графика в С
                }
                else
                {
                    if (count(B.begin(), B.end(), U[p]) == 0) // Проверка наличия элементов универсального графика в В
                        C.push_back(U[p]); // Записываем элемент универсального графика в С
                }
            }
            break; // Выходим из блока switch
        }

        case 6: // Операция инверсии
        {
            // Вывод меню выбора и нструкции для пользователя
            printf("\n1) А^-1");
            printf("\n2) В^-1\n");
            printf("Выберите график над которым будет происходить операция (1 или 2): ");
            scanf_s("%i", &ord); // Заносим ввод пользователя в переменную

            if (ord == 1) // Проверка переменной 
                for (int j = 0; j < m_A; j++) // Цикл для обработки элементов графика А
                    C.push_back(make_pair(A[j].second, A[j].first)); // Добавляем инверсированную пару А в С
            else
                for (int i = 0; i < m_B; i++) // Цикл для обработки элементов графика В
                    C.push_back(make_pair(B[i].second, B[i].first)); // Добавляем инверсированную пару В в С

            break; // Выходим из блока switch
        }

        case 7: // Операция композиции
        {
            // Вывод меню выбора и нструкции для пользователя
            printf("\n1) А*B");
            printf("\n2) B*A\n");
            printf("Выберите график над которым будет происходить операция (1 или 2): ");
            scanf_s("%i", &ord); // Заносим ввод пользователя в переменную

            if (ord == 1) // Проверка переменной
                for (int j = 0; j < m_A; j++) // Цикл для обработки элементов графика А
                    for (int i = 0; i < m_B; i++) // Цикл для обработки элементов графика В
                        if (A[j].second == B[i].first && count(C.begin(), C.end(), make_pair(A[j].first, B[i].second)) == 0) // Проверка условий для композиции А и В
                            C.push_back(make_pair(A[j].first, B[i].second)); // Добавляем пару, которая является результатом композиции А и В в С
            else
                for (int i = 0; i < m_B; i++) // Цикл для обработки элементов графика В
                    for (int j = 0; j < m_A; j++) // Цикл для обработки элементов графика А
                        if (B[i].second == A[j].first && count(C.begin(), C.end(), make_pair(B[i].first, A[j].second)) == 0) // Проверка условий для композиции В и А
                            C.push_back(make_pair(B[i].first, A[j].second)); // Добавляем пару, которая является результатом композиции В и А в С

            break; // Выходим из блока switch


        }

    }

    printf("\nГрафик C:{"); // Вывод пояснительного сообщения для пользователя

    // Цикл для вывода графика С
    for (int i = 0; i < C.size(); i++)
        if (C[i].first != 0 && C[i].second != 0)
            printf("%s %i %s %i %s", "<", C[i].first, ",", C[i].second, ">"); // Вывод элементов графика С

    printf("}\n"); // Вывод пояснительного сообщения для пользователя
    system("pause"); // Остановка работы программы до тех пор пока пользователь не нажмёт любую клавишу
}