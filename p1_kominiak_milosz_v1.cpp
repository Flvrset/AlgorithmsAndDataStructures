#include <iostream>
#include <string>

struct Film
{
    std::string title;
    std::string director;
    int prodYear;
    Film *nast;
};

void printFilm(Film *adres)
{
    std::cout << "Zawartosc listy\n";
    while (adres != NULL)
    {
        std::cout << adres->title << ", " << adres->director << ", " << adres->prodYear << std::endl;
        adres = adres->nast;
    }
}

int main()
{
    const int N = 3;

    Film lista[N];
    for (int i = 0; i < N; i++)
    {
        std::cout << "Podaj tytul filmu " << i << std::endl;
        std::cin >> lista[i].title;
        std::cout << "Podaj rezysera filmu " << i << std::endl;
        std::cin >> lista[i].director;
        std::cout << "Podaj rok produkcji filmu " << i << std::endl;
        std::cin >> lista[i].prodYear;
    }
}