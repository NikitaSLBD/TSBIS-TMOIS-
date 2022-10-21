#include <stdio.h>
#include <vector>
#include <windows.h>


using namespace std;

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int m_A, m_B, par;

    printf("Введите мощность множества А: ");
    scanf_s("%i", &m_A, "\n");

    vector <int> A(m_A);

    for (int i = 0; i < m_A; i++)
    {
        printf("%s %i %s", "Введите ", i + 1, "элемент множества А: ");
        scanf_s("%i", &A[i]);
    }

    printf("Введите мощность множества В: ");
    scanf_s("%i", &m_B, "\n");

    vector <int> B(m_B);

    for (int j = 0; j < m_B; j++)
    {
        printf("%s %i %s", "Введите ", j + 1, "элемент множества В: ");
        scanf_s("%i", &B[j]);
    }

    printf("\nМножество A:{");

    for (int i = 0; i < m_A; i++)
    {
        printf("%s %i", " ", A[i]);
    }

    printf(" }\nМножество B:{");

    for (int i = 0; i < m_B; i++)
    {
        printf("%s %i", " ", B[i]);
    }

    vector <int> C(1);


    printf(" }\n1) Объединение\n");
    printf("2) Пересечение\n");
    printf("Выберите операцию: ");

    scanf_s("%i", &par);

    switch (par)
    {
    case 1:
    {

        for (int i = 0; i < m_A; i++)
        {
            C.push_back(A[i]);
        }

        for (int i = 0; i < m_B; i++)
        {
            for (int j = 0; j < m_A; j++)
            {
                if (B[i] != A[j] && j == m_A - 1)
                {
                    C.push_back(B[i]);
                    break;
                }
                else
                {
                    if (B[i] == A[j])
                        break;
                }
            }
        }

        break;
    }
    case 2:
    {

        for (int i = 0; i < m_A; i++)
        {


            for (int j = 0; j < m_B; j++)
            {
                if (B[j] == A[i])
                {
                    C.push_back(B[j]);
                    break;
                }
            }
        }
    }

    }
    printf("\nМножество C:{");

    for (int i = 1; i < C.size(); i++)
    {
        printf("%s %i", " ", C[i]);
    }

    printf(" }");

}

