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

void deleteFilm(Film *adres)
{
    Film *aktualny;
    while (adres != NULL)
    {
        aktualny = adres;
        adres=adres->nast;
        delete aktualny;
    }
    
}

int main()
{
    const int N = 3;

    Film *glowa, *aktualny, *ogon, *usuwany;
    glowa = new Film;
    std::cout << "Podaj tytul filmu 1" << std::endl;
    std::cin >> glowa->title;
    std::cout << "Podaj rezysera filmu 1" << std::endl;
    std::cin >> glowa->director;
    std::cout << "Podaj rok produkcji filmu 1" << std::endl;
    std::cin >> glowa->prodYear;
    glowa->nast = NULL;
    ogon = glowa;

    for (int i = 1; i < N; i++)
    {
        aktualny = new Film;
        std::cout << "Podaj tytul filmu " << i << std::endl;
        std::cin >> aktualny->title;
        std::cout << "Podaj rezysera filmu " << i << std::endl;
        std::cin >> aktualny->director;
        std::cout << "Podaj rok produkcji filmu " << i << std::endl;
        std::cin >> aktualny->prodYear;
        aktualny->nast = NULL;
        ogon->nast = aktualny;
        ogon = aktualny;
    }
    printFilm(glowa);

}