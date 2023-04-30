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
    std::cout << "Zawartosc listy:\n";
    if (adres == NULL)
        std::cout << "Lista pusta\n";
    else
        while (adres != NULL)
        {
            std::cout << adres->title << ", " << adres->director << ", " << adres->prodYear << std::endl;
            adres = adres->nast;
        }
}

void deleteFilm(Film *&adres)
{
    std::cout << "Usuwam liste od adresu: " << adres << std::endl;
    Film *aktualny;
    while (adres != NULL)
    {
        aktualny = adres;
        adres = adres->nast;
        delete aktualny;
    }
    std::cout << "Usuwanie zakonczone!" << std::endl;
}

int main()
{
    const int N = 4;

    Film *glowa, *aktualny, *ogon, *usuwany, *poprzedni, *nowy, *tmp1, *tmp2;
    glowa = new Film;
    std::cout << "Podaj tytul filmu 1" << std::endl;
    std::cin >> glowa->title;
    std::cout << "Podaj rezysera filmu 1" << std::endl;
    std::cin >> glowa->director;
    std::cout << "Podaj rok produkcji filmu 1" << std::endl;
    std::cin >> glowa->prodYear;
    glowa->nast = NULL;
    ogon = glowa;

    for (int i = 2; i < N + 1; i++)
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

    aktualny = glowa;
    poprzedni = NULL;
    int count = 0;
    while (aktualny != NULL)
    {
        if (poprzedni != NULL && poprzedni->prodYear < aktualny->prodYear)
            count++;

        if (poprzedni != NULL && poprzedni->prodYear < aktualny->prodYear && count == 2)
        {
            poprzedni->nast = aktualny->nast;
            usuwany = aktualny;
            aktualny = aktualny->nast;
            delete usuwany;
            nowy = new Film;
            std::cout << "Podaj tytul nowego filmu" << std::endl;
            std::cin >> nowy->title;
            std::cout << "Podaj rezysera nowego filmu" << std::endl;
            std::cin >> nowy->director;
            std::cout << "Podaj rok produkcji nowego filmu" << std::endl;
            std::cin >> nowy->prodYear;
            tmp1 = glowa->nast;
            tmp2 = tmp1->nast;
            tmp1->nast = nowy;
            nowy->nast = tmp2;
            break;
        }
        else
        {
            poprzedni = aktualny;
            aktualny = aktualny->nast;
        }
    }

    printFilm(glowa);
    deleteFilm(glowa);
    printFilm(glowa);
}