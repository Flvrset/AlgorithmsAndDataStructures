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
    const int small = 10000, medium = 50000, large = 100000;
    int TSmall[small], TMedium[medium], TLarge[large];
    std::srand(time(NULL));

    std::cout << "Uzupelniam tablice losowymi liczbami...\n";
    for (int i = 0; i < small; i++)
        TSmall[i] = std::rand();
    for (int i = 0; i < medium; i++)
        TMedium[i] = std::rand();
    for (int i = 0; i < large; i++)
        TLarge[i] = std::rand();

    std::cout << "Licze czas wykonywania algorytmow...\n";
    auto start_quickSortSmall = std::chrono::high_resolution_clock::now();
    quickSort(TSmall, 0, small - 1);
    auto stop_quickSortSmall = std::chrono::high_resolution_clock::now();
    auto duration_quickSortSmall = std::chrono::duration_cast<std::chrono::milliseconds>(stop_quickSortSmall - start_quickSortSmall).count();
    auto start_bubbleSortSmall = std::chrono::high_resolution_clock::now();
    bubbleSort(TSmall, small);
    auto stop_bubbleSortSmall = std::chrono::high_resolution_clock::now();
    auto duration_bubbleSortSmall = std::chrono::duration_cast<std::chrono::milliseconds>(stop_bubbleSortSmall - start_bubbleSortSmall).count();

    auto start_quickSortMedium = std::chrono::high_resolution_clock::now();
    quickSort(TMedium, 0, medium - 1);
    auto stop_quickSortMedium = std::chrono::high_resolution_clock::now();
    auto duration_quickSortMedium = std::chrono::duration_cast<std::chrono::milliseconds>(stop_quickSortMedium - start_quickSortMedium).count();
    auto start_bubbleSortMedium = std::chrono::high_resolution_clock::now();
    bubbleSort(TMedium, medium);
    auto stop_bubbleSortMedium = std::chrono::high_resolution_clock::now();
    auto duration_bubbleSortMedium = std::chrono::duration_cast<std::chrono::milliseconds>(stop_bubbleSortMedium - start_bubbleSortMedium).count();

    auto start_quickSortLarge = std::chrono::high_resolution_clock::now();
    quickSort(TLarge, 0, large - 1);
    auto stop_quickSortLarge = std::chrono::high_resolution_clock::now();
    auto duration_quickSortLarge = std::chrono::duration_cast<std::chrono::milliseconds>(stop_quickSortLarge - start_quickSortLarge).count();
    auto start_bubbleSortLarge = std::chrono::high_resolution_clock::now();
    bubbleSort(TLarge, large);
    auto stop_bubbleSortLarge = std::chrono::high_resolution_clock::now();
    auto duration_bubbleSortLarge = std::chrono::duration_cast<std::chrono::milliseconds>(stop_bubbleSortLarge - start_bubbleSortLarge).count();

    std::cout << "Dla list o dlugosci " << small << ":\n"
              << "quickSort: " << duration_quickSortSmall << " ms" << std::endl
              << "bubbleSort: " << duration_bubbleSortSmall << " ms" << std::endl;
    std::cout << "Dla list o dlugosci " << medium << ":\n"
              << "quickSort: " << duration_quickSortMedium << " ms" << std::endl
              << "bubbleSort: " << duration_bubbleSortMedium << " ms" << std::endl;
    std::cout << "Dla list o dlugosci " << large << ":\n"
              << "quickSort: " << duration_quickSortLarge << " ms" << std::endl
              << "bubbleSort: " << duration_bubbleSortLarge << " ms" << std::endl;
    return 0;
}