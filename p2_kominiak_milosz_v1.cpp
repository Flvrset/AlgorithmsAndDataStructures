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

void addFilm(Film *adres, std::string title, std::string director, int prodYear)
{
    Film *nowy;
    nowy->title = title;
    nowy->director = director;
    nowy->prodYear = prodYear;
    nowy->nast = NULL;
    while (adres->nast != nowy)
    {
        if (adres->nast == NULL)
            adres->nast = nowy;
        else if (adres == NULL)
            adres = nowy;
        else
            adres = adres->nast;
    }
}

int main()
{
    Film *glowa;
    std::ifstream dane;
    std::string nazwa, title_temp, director_temp;
    int prodYear_temp;
    std::cout << "Podaj nazwe pliku do wczytania:\n";
    getline(std::cin, nazwa);
    dane.open(nazwa);
    if (!dane.is_open())
    {
        std::cout << "Problem z wczytaniem pliku.\n";
        return 1;
    }
    while (!dane.eof())
    {
        dane >> title_temp >> director_temp >> prodYear_temp;
    }

    dane.close();
    deleteFilm(glowa);
    return 0;
}