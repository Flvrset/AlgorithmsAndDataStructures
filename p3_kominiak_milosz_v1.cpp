#include <iostream>
#include <chrono>

void quickSort(int tablica[], int lewy, int prawy)
{
    int l = lewy;
    int p = prawy;
    int srodek = tablica[(lewy + prawy) / 2];

    do
    {
        while (tablica[l] < srodek)
            l++;
        while (tablica[p] > srodek)
            p--;
        if (l <= p)
            std::swap(tablica[l++], tablica[p--]);
    } while (l <= p);

    if (lewy < prawy)
        quickSort(tablica, lewy, p);

    if (prawy > l)
        quickSort(tablica, l, prawy);
}

void bubbleSort(int tablica[], int dlugosc)
{
    for (int i = 0; i < dlugosc; i++)
        for (int j = 1; j < dlugosc - i; j++)
            if (tablica[j - 1] > tablica[j])
                std::swap(tablica[j - 1], tablica[j]);
}

int main()
{
    int T7_quick[7] = {9, 3, 3, 6, 8, 5, 7};
    int T20_quick[20] = {9, 3, 3, 6, 8, 5, 7, 19, 18, 17, 18, 5, 6, 100, 3, 5, 6, 4, 99, 2};
    int T50_quick[50] = {9, 3, 3, 6, 8, 5, 7, 19, 18, 17, 18, 5, 6, 100, 3, 5, 6, 4, 99, 2, 3, 3, 6, 8, 5, 7, 19, 18, 17, 18, 5, 6, 100, 3, 5, 6, 4, 99, 2, 4, 15, 23, 54, 12, 23, 45, 65, 3, 42, 23};

    int T7_bubble[7] = {9, 3, 3, 6, 8, 5, 7};
    int T20_bubble[20] = {9, 3, 3, 6, 8, 5, 7, 19, 18, 17, 18, 5, 6, 100, 3, 5, 6, 4, 99, 2};
    int T50_bubble[50] = {9, 3, 3, 6, 8, 5, 7, 19, 18, 17, 18, 5, 6, 100, 3, 5, 6, 4, 99, 2, 3, 3, 6, 8, 5, 7, 19, 18, 17, 18, 5, 6, 100, 3, 5, 6, 4, 99, 2, 4, 15, 23, 54, 12, 23, 45, 65, 3, 42, 23};

    std::cout << "Licze czas wykonywania algorytmow...\n";
    auto start_quickSort7 = std::chrono::high_resolution_clock::now();
    quickSort(T7_quick, 0, 6);
    auto stop_quickSort7 = std::chrono::high_resolution_clock::now();
    auto duration_quickSort7 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_quickSort7 - start_quickSort7).count();
    auto start_bubbleSort7 = std::chrono::high_resolution_clock::now();
    bubbleSort(T7_bubble, 7);
    auto stop_bubbleSort7 = std::chrono::high_resolution_clock::now();
    auto duration_bubbleSort7 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_bubbleSort7 - start_bubbleSort7).count();

    auto start_quickSort20 = std::chrono::high_resolution_clock::now();
    quickSort(T20_quick, 0, 19);
    auto stop_quickSort20 = std::chrono::high_resolution_clock::now();
    auto duration_quickSort20 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_quickSort20 - start_quickSort20).count();
    auto start_bubbleSort20 = std::chrono::high_resolution_clock::now();
    bubbleSort(T20_bubble, 20);
    auto stop_bubbleSort20 = std::chrono::high_resolution_clock::now();
    auto duration_bubbleSort20 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_bubbleSort20 - start_bubbleSort20).count();

    auto start_quickSort50 = std::chrono::high_resolution_clock::now();
    quickSort(T50_quick, 0, 49);
    auto stop_quickSort50 = std::chrono::high_resolution_clock::now();
    auto duration_quickSort50 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_quickSort50 - start_quickSort50).count();
    auto start_bubbleSort50 = std::chrono::high_resolution_clock::now();
    bubbleSort(T50_bubble, 50);
    auto stop_bubbleSort50 = std::chrono::high_resolution_clock::now();
    auto duration_bubbleSort50 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_bubbleSort50 - start_bubbleSort50).count();

    std::cout << "Dla list o dlugosci 7:\n" << "quickSort: " << duration_quickSort7 << " ns" << std::endl << "bubbleSort: " << duration_bubbleSort7 << " ns" << std::endl;
    std::cout << "Dla list o dlugosci 20:\n" << "quickSort: " << duration_quickSort20 << " ns" << std::endl << "bubbleSort: " << duration_bubbleSort20 << " ns" << std::endl;
    std::cout << "Dla list o dlugosci 50:\n" << "quickSort: " << duration_quickSort50 << " ns" << std::endl << "bubbleSort: " << duration_bubbleSort50 << " ns" << std::endl;
    return 0;
}