#include <stdio.h>
#include <vector>

using namespace std;

void main()
{
    unsigned int m_A, m_B;

    printf("Enter m_A: ");
    scanf_s("%i", &m_A, "\n");

    vector <unsigned int> A(m_A);

    for (int i = 0; i < m_A; i++)
    {
        printf("%s %i %s", "Enter A[", i + 1, "]: ");
        scanf_s("%ui", &A[i]);
    }

    printf("Enter m_B: ");
    scanf_s("%i", &m_B, "\n");

    vector <unsigned int> B(m_B);

    for (int j = 0; j < m_B; j++)
    {
        printf("%s %i %s", "Enter B[", j + 1, "]: ");
        scanf_s("%ui", &B[j]);
    }

    printf("\nSet A:");

    for (int i = 0; i < m_A; i++)
    {
        printf("%s %i"," ", A[i]);
    }

    printf("\nSet B:");
    
    for (int i = 0; i < m_B; i++)
    {
        printf("%s %i", " ", B[i]);
    }
    

    


}

