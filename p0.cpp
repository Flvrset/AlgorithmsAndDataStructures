#include <iostream>
#include <cctype>

struct Rekord
{
    char znak1;
    char znak2;
};

void printArray(Rekord Arr[], int arr_len) {
    for (int i = 0; i < arr_len; i++)
    {
        std::cout << Arr[i].znak1 << Arr[i].znak2 << " ";
    }
}

int main()
{
    const int N = 5;
    const double L = 4.0;
    Rekord P[N], *A, *B;
    int size_a = 0, size_b = N;

    for (int i = 0; i < N; i++)
    {
        std::cout << "Podaj znak pierwszy w rekordzie " << i << std::endl;
        std::cin >> P[i].znak1;
        std::cout << "Podaj znak drugi w rekordzie" << i << std::endl;
        std::cin >> P[i].znak2;
    }

    std::cout << "Wypisuje tablice: \n";
    printArray(P, N);

    for (int i = 0; i < N; i++)
    {
        if ((isalpha(P[i].znak1)) && (isalpha(P[i].znak2)) && ((abs(P[i].znak1 - 'a') / abs(P[i].znak2 - 'a') <= L) || P[i].znak2 - 'a' == 0))
        {
            size_a++;
            size_b--;
        }
    }

    A = new Rekord[size_a];
    int count_a = 0;
    B = new Rekord[size_b];
    int count_b = 0;

    for (int i = 0; i < N; i++)
    {
        if ((isalpha(P[i].znak1)) && (isalpha(P[i].znak2)) && ((abs(P[i].znak1 - 'a') / abs(P[i].znak2 - 'a') <= L) || P[i].znak2 - 'a' == 0))
            A[count_a++] = P[i];
        else
            B[count_b++] = P[i];
    }

    std::cout << "\nPierwsza tablica dynamiczna: \n";
    printArray(A, count_a);

    std::cout << "\nDruga tablica dynamiczna: \n";
    for (int i = 0; i < count_b; i++)
    printArray(B, count_b);

    delete[] A;
    delete[] B;

    return 0;
}
