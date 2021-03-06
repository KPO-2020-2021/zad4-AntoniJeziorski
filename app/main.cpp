// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <filesystem>
#include <unistd.h>

#include "exampleConfig.h"
#include "vector.hh"
#include "matrix.hh"
#include "cuboid.hh"
#include "matrix4x4.hh"
#include "scene.hh"
#include "../inc/lacze_do_gnuplota.hh"

/*!
 *
 * \file main.cpp
 * 
 * \brief Plik zawierający główną funkcję main.
 */


/*!
 *
 * \brief Funkcja usuwająca zawartość folderu
 * 
 * \param data - scieżka folderu, którego zawartość chcemy usunąć
 * 
 * \return Usuwa wszystkie pliki w podanym folderze
 */

void deleteCuboids(const std::string& data) {
    for (const auto& entry : std::filesystem::directory_iterator(data)) 
        std::filesystem::remove_all(entry.path());
}

int main() {
    double  angle; //  kat do obrotu

    double lx, ly, lz; // dlugosci bokow prostopadloscianu

    Vector3D v, center; // wektor do translacji i  wektor reprezentujacy wspolrzedne srodka prostopadloscianu

    PzG::LaczeDoGNUPlota  Lacze;    // Ta zmienna jest potrzebna do wizualizacji rysunku Prostokata

    char option = '0', axis; // Zmienne do oslugi menu

    Scene scene; // Utworzenie sceny

    int cubeNumber, cubeAmount = 0, amount; // zmienna do obslugi wielu prostopadloscianow oraz licznik prostopadloscianow

    std::string filename = "../datasets/prostopadloscian";

//-------------------------------------------------------
    //  Wspolrzedne wierzcholkow pierwszego prostopadloscianu beda zapisywane w pliku "prostopadloscian1.dat"
    //  Ponizsze metoda powoduje, ze dane z pliku beda wizualizowane jako linia ciagla o grubosci 2 piksele
    //

    Lacze.DodajNazwePliku("../datasets/prostopadloscian1.dat",PzG::RR_Ciagly,2);

    //
    //  Ustawienie trybu rysowania 3D
    //

    Lacze.ZmienTrybRys(PzG::TR_3D);

    Lacze.UstawZakresY(-200,200);
    Lacze.UstawZakresX(-200,200);
    Lacze.UstawZakresZ(-200,200);

    try {
        
        while(option != 'k') { // Dopoki nie zostanie podane k
            if(option == '0') //
            {
                std::cout << "o - obrot prostopadloscianu o zadana sekwencje katow" << std::endl;
                std::cout << "t - powtorzenie poprzedniego obrotu" << std::endl;
                std::cout << "r - wyswietlenie macierzy rotacji" << std::endl;
                std::cout << "p - przesuniecie prostopadloscianu o zadany wektor" << std::endl;
                std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
                std::cout << "s - sprawdzenie dlugosci przeciwleglych bokow" << std::endl;
                std::cout << "n - dodanie nowego prostopadloscianu" << std::endl;
                std::cout << "m - wyswietl menu" << std::endl;
                std::cout << "k - koniec dzialania programu" << std:: endl;
            }

            std::cout << "Twoj wybor: " << std::endl;
            std::cin >> option;

            switch(option) {
                case 'k':
                    deleteCuboids("../datasets");
                    option = 'k'; break;

                case 'p':
                    while(true) {
                        std::cout << "Podaj numer prostopadloscianu " << std::endl;
                        std::cin >> cubeNumber;

                        if(cubeNumber < 0 || cubeNumber > cubeAmount) {
                            std::cin.setstate(std::ios_base::failbit);
                            std::cerr << "NIE MA TAKIEGO PROSTOPADLOSCIANIU" << std::endl;
                            std::cin.clear();
                            std::cin.ignore(100000, '\n');

                        }
                        else if(std::cin.fail()) {
                            std::cin.clear();
                            std::cerr << "NIE MA TAKIEGO PROSTOPADLOSCIANU" << std::endl;
                            std::cin.ignore(100000,'\n');
                        }
                        else 
                            break;
                    }

                    std::cout << "Podaj wspolrzedne wektora" << std::endl;
                    std::cin >> v;

                    scene.TranslationVector(v, cubeNumber - 1); // Ustaw wektor translacji
                    scene.Move(cubeNumber - 1); // Wykonaj ruch

                    filename = filename + std::to_string(cubeNumber) + ".dat";
                    scene.GetCuboid(cubeNumber - 1).ZapisWspolrzednychDoPliku(filename.c_str());
                    filename = filename = "../datasets/prostopadloscian";
                    scene.GetCuboid(cubeNumber - 1).Edges();
                    Lacze.Rysuj(); // Wyswietl wynik translacji

                    break;

                case 'o':
                        while(true) {
                        std::cout << "Podaj numer prostopadloscianu " << std::endl;
                        std::cin >> cubeNumber;
                        if(cubeNumber < 0 || cubeNumber > cubeAmount) {
                            std::cin.setstate(std::ios_base::failbit);
                            std::cerr << "NIE MA TAKIEGO PROSTOPADLOSCIANIU" << std::endl;
                            std::cin.clear();
                            std::cin.ignore(100000, '\n');
                        }
                        else if(std::cin.fail()) {
                            std::cin.clear();
                            std::cerr << "NIE MA TAKIEGO PROSTOPADLOSCIANU" << std::endl;
                            std::cin.ignore(100000,'\n');
                        }
                        else 
                            break;
                        }

                    scene.ClearOneRotationMatrix(cubeNumber-1);

                    std::cout << "Podaj osie oraz katy i zakoncz znakiem \".\"" << std::endl;
                    axis = '0';

                    while(axis != '.') {
                        std::cin >> axis;

                        switch(axis) {
                            case 'x':
                                std::cin >> angle;
                                if(std::cin.fail()) {
                                    std::cin.clear();
                                    std::cerr << "BLEDNA WARTOSC KATA\nPodaj jeszcze raz" << std::endl;
                                    std::cin.ignore(100000,'\n');
                                }
                                else
                                    scene.OneRotationMatrix(RotationMatrix_X(angle),cubeNumber - 1);
                                break;
                            case 'y':
                                std::cin >> angle;
                                if(std::cin.fail()) {
                                    std::cin.clear();
                                    std::cerr << "BLEDNA WARTOSC KATA\nPodaj jeszcze raz" << std::endl;
                                    std::cin.ignore(100000,'\n');
                                }
                                else
                                    scene.OneRotationMatrix(RotationMatrix_Y(angle),cubeNumber - 1);
                                break;
                            case 'z':
                                std::cin >> angle;
                                if(std::cin.fail()) {
                                    std::cin.clear();
                                    std::cerr << "BLEDNA WARTOSC KATA\nPodaj jeszcze raz" << std::endl;
                                    std::cin.ignore(100000,'\n');
                                }
                                else
                                    scene.OneRotationMatrix(RotationMatrix_Z(angle),cubeNumber - 1);
                                break;
                            default:
                                if(axis != '.') {
                                    std::cerr << "NIE MA TAKIEJ OSI\nMozliwe opcje to x y z" << std::endl;
                                    std::cin.ignore(100000,'\n');
                                }
                                break;
                        }
                    }

                    while(true) {
                        std::cout <<"Podaj ilosc obrotow" << std::endl;
                        std::cin >> amount;
                        if(amount <= 0) {
                            std::cin.setstate(std::ios_base::failbit);
                            std::cerr << "ILOSC OBROTOW NIE MOZE BYC UJEMNA" << std::endl;
                            std::cin.clear();
                            std::cin.ignore(100000, '\n');
                        }
                        else if(std::cin.fail()) {
                            std::cin.clear();
                            std::cerr << "BLAD ILOSCI OBROTOW" << std::endl;
                            std::cin.ignore(100000,'\n');
                        }
                        else 
                            break;
                        }

                    for(int i=0; i<amount; ++i) 
                        scene.RotationMatrix(scene.GetOneRotationMatrix(cubeNumber - 1),cubeNumber - 1);
                    scene.Move(cubeNumber-1);

                    filename = filename + std::to_string(cubeNumber) + ".dat";
                    scene.GetCuboid(cubeNumber - 1).ZapisWspolrzednychDoPliku(filename.c_str());
                    filename = filename = "../datasets/prostopadloscian";
                    scene.GetCuboid(cubeNumber-1).Edges();
                    Lacze.Rysuj(); // Wyswietl wynik translacji

                    break;
                case 't':
                    for(int i=0; i<amount; ++i)
                        scene.RotationMatrix(scene.GetOneRotationMatrix(cubeNumber - 1),cubeNumber - 1);
                    scene.Move(cubeNumber - 1);
                    std::cout << scene.GetOneRotationMatrix(cubeNumber - 1) << std::endl;
                    filename = filename + std::to_string(cubeNumber) + ".dat";
                    scene.GetCuboid(cubeNumber - 1).ZapisWspolrzednychDoPliku(filename.c_str());
                    filename = filename = "../datasets/prostopadloscian";
                    scene.GetCuboid(cubeNumber - 1).Edges();
                    Lacze.Rysuj();

                    break;
                case 'w':
                    while(true) {
                        std::cout << "Podaj numer prostopadloscianu " << std::endl;
                        std::cin >> cubeNumber;
                        if(cubeNumber < 0 || cubeNumber > cubeAmount) {
                            std::cin.setstate(std::ios_base::failbit);
                            std::cerr << "NIE MA TAKIEGO PROSTOPADLOSCIANIU" << std::endl;
                            std::cin.clear();
                            std::cin.ignore(100000, '\n');

                        }
                        else if(std::cin.fail()) {
                            std::cin.clear();
                            std::cerr << "NIE MA TAKIEGO PROSTOPADLOSCIANU" << std::endl;
                            std::cin.ignore(100000,'\n');
                        }
                        else 
                            break;
                        }

                    std::cout << scene.GetCuboid(cubeNumber - 1); // Wyswietl wspolrzedne wierzcholkow prostokata
                    
                    break; 
                case 'n':
                    std::cout << "Podaj wspolrzedne srodka prostopadloscianiu" << std::endl;
                    std::cin >> center;
                    std::cout << "Podaj dlugosci bokow w osiach X Y Z" << std::endl;
                    std::cin >> lx >> ly >>lz;
                    cubeAmount += 1;
                    scene.NewCuboid(center, lx, ly, lz);

                    filename = filename + std::to_string(cubeAmount) + ".dat";
                    Lacze.DodajNazwePliku(filename.c_str(),PzG::RR_Ciagly,2);
                    scene.GetCuboid(cubeAmount - 1).Edges(); // Wyswietlenie dlugosci bokow oraz sprawdzenie, czy jest to prostokat
                    scene.GetCuboid(cubeAmount - 1).ZapisWspolrzednychDoPliku(filename.c_str());
                    Lacze.Rysuj(); // Wyswietlenie prostokata
                    filename = filename = "../datasets/prostopadloscian";

                    break;
                case 'm':
                    option = '0';

                    break;
                case 'r':
                    while(true) {
                        std::cout << "Podaj numer prostopadloscianu " << std::endl;
                        std::cin >> cubeNumber;
                        if(cubeNumber < 0 || cubeNumber > cubeAmount) {
                            std::cin.setstate(std::ios_base::failbit);
                            std::cerr << "NIE MA TAKIEGO PROSTOPADLOSCIANIU" << std::endl;
                            std::cin.clear();
                            std::cin.ignore(100000, '\n');

                        }
                        else if(std::cin.fail()) {
                            std::cin.clear();
                            std::cerr << "NIE MA TAKIEGO PROSTOPADLOSCIANU" << std::endl;
                            std::cin.ignore(100000,'\n');
                        }
                        else 
                            break;
                        }

                    std::cout << scene.GetRotation(cubeNumber-1);
                    break;
                default:
                    option = '0';
                    std::cerr << "!!! NIEPOPRAWNA OPCJA !!!" << std::endl; break;
            }
        }
    }
    catch(std::runtime_error& e) {
        std::cerr << "Blad" << e.what() << "\n";
        exit(1);
    }
    return 0;
}

