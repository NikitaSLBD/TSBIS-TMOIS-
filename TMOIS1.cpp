#include <stdio.h>
#include <vector>

using namespace std;

void main()
{
    unsigned int m_A, m_B, par;

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
    
    vector <unsigned int> C(1);

    
    printf("\n1) Unification\n");
    printf("2) Decussation\n");

    scanf_s("%ui", &par);   

    switch (par)
    {
        case 1: 
        {
            if (m_A > m_B)
            {
                for (int i = 0; i < m_A; i++)
                {
                    C.push_back(A[i]);

                    for (int j = 0; j < m_B; j++)
                    {
                        if (B[j] != A[i])
                            C.push_back(B[j]);
                    }
                }
            }
            else
            {
                for (int i = 0; i < m_B; i++)
                {
                    C.push_back(B[i]);

                    for (int j = 0; j < m_A; j++)
                    {
                        if (A[j] != B[i])
                            C.push_back(A[j]);
                    }
                }
            }
        }

        case 2: 
        {
            if (m_A < m_B)
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
            else
            {
                for (int i = 0; i < m_B; i++)
                {


                    for (int j = 0; j < m_A; j++)
                    {
                        if (A[j] == B[i])
                        {
                            C.push_back(A[j]);
                            break;
                        }
                    }
                }
            }
        }
    }

    printf("\nSet C:");

    for (int i = 1; i < C.size(); i++)
    {
        printf("%s %i", " ", C[i]);
    }

}

