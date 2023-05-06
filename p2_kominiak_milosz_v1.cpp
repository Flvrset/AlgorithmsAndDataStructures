#include <iostream>
#include <string>
#include <fstream>

struct Film
{
    std::string title;
    std::string director;
    int prodYear;
    Film *nast;
};

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

void addFilm(Film *&adres, std::string title, std::string director, int prodYear)
{
    Film *nowy = new Film;
    nowy->title = title;
    nowy->director = director;
    nowy->prodYear = prodYear;
    nowy->nast = nullptr;
    if (adres == nullptr)
    {
        adres = nowy;
        return;
    }
    Film *aktualny = adres;
    while (aktualny->nast != nullptr)
        aktualny = aktualny->nast;
    aktualny->nast = nowy;
    return;
}

void theFunction(Film *&glowa, char charToFind, std::string title, std::string director, int prodYear, int nthElement, std::string header)
{
    Film *aktualny2 = glowa;
    Film *poprzedni = NULL;
    Film *usuwany = new Film();

    std::cout << header << std::endl;
    printFilm(glowa);
    while (aktualny2 != NULL)
    {
        if (aktualny2->title.find(charToFind) && glowa->prodYear > aktualny2->prodYear)
        {
            if (aktualny2->nast == NULL)
                poprzedni->nast = NULL;
            else
                poprzedni->nast = aktualny2->nast;
            usuwany = aktualny2;
            aktualny2 = aktualny2->nast;
            delete usuwany;
            continue;
        }
        poprzedni = aktualny2;
        aktualny2 = aktualny2->nast;
    }
    std::cout << header << std::endl;
    printFilm(glowa);

    // aktualny = glowa;
    // Film *nowy = new Film();
    // nowy->director = director;
    // nowy->title = title;
    // nowy->prodYear = prodYear;
    // while (aktualny != NULL)
    // {}
}

int main()
{
    Film *glowa = nullptr;
    std::ifstream dane;
    std::string nazwa, title_temp, director_temp;
    int prodYear_temp;
    std::cout << "Podaj nazwe pliku do wczytania:\n";
    getline(std::cin, nazwa);
    dane.open("dane.txt");
    if (!dane.is_open())
    {
        std::cout << "Problem z wczytaniem pliku.\n";
        return 1;
    }
    while (!dane.eof())
    {
        title_temp = "";
        director_temp = "";
        prodYear_temp = 0;
        dane >> title_temp >> director_temp >> prodYear_temp;
        addFilm(glowa, title_temp, director_temp, prodYear_temp);
    }
    printFilm(glowa);
    dane.close();
    theFunction(glowa, 'b', "x", "rez_x", 1999, 2, "dzialaajj");
    deleteFilm(glowa);
    return 0;
}