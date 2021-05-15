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
#include <unistd.h>

#include "exampleConfig.h"
#include "vector.hh"
#include "matrix.hh"
#include "cuboid.hh"
#include "scene.hh"
#include "../inc/lacze_do_gnuplota.hh"




int main() {
    double X[3]={2,3,3}, Y[3]={22,3,3}, Z[3]={2,18,3}, T[3]={22,18,3}, A[3]={2,18,28}, B[3]={22,18,28}, C[3]={2,3,28}, D[3]={22,3,28}, angle, amount; // tablice typu double z wartosciami wierzcholkow bazowego prostokata, kat do obrotu, ilosc obrotow
    Vector3D x(X), y(Y), z(Z), t(T),a(A),b(B), c(C), d(D), v; // Wektory reprezentujace wierzcholki prostokata i wektor do translacji
    Cuboid Cub(x, y, z, t,a,b,c,d);   // Prostokat
    Matrix3D tmp;
    PzG::LaczeDoGNUPlota  Lacze;    // Ta zmienna jest potrzebna do wizualizacji
                                    // rysunku Prostokata
    char option = '0', axis; // Zmienne do oslugi menu
    Scene scene(Cub); // Utworzenie sceny
//-------------------------------------------------------
    //  Wspolrzedne wierzcholkow beda zapisywane w pliku "Prostokat.dat"
    //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
    //  na dwa sposoby:
    //   1. Rysowane jako linia ciagl o grubosci 2 piksele
    //
    Lacze.DodajNazwePliku("../datasets/prostopadloscian.dat",PzG::RR_Ciagly,2);
    //
    //   2. Rysowane jako zbior punktow reRecezentowanych Reczez kwadraty,
    //      których połowa długości boku wynosi 2.
    //
    //Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Punktowy,2);
    //
    //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
    //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
    //  jako wspolrzedne punktow podajemy tylko x,y.
    //
    Lacze.ZmienTrybRys(PzG::TR_3D);

    Lacze.UstawZakresY(-300,300);
    Lacze.UstawZakresX(-300,300);
    Lacze.UstawZakresZ(-300,300);
    try {
        scene.GetCuboid().Edges(); // Wyswietlenie dlugosci bokow oraz sprawdzenie, czy jest to prostokat
        scene.GetCuboid().ZapisWspolrzednychDoPliku("../datasets/prostopadloscian.dat");
        Lacze.Rysuj(); // Wyswietlenie prostokata
        
        while(option != 'k') { // Dopoki nie zostanie podane k
            if(option == '0') //
            {
                std::cout << "o - obrot prostopadloscianu o zadana sekwencje katow" << std::endl;
                std::cout << "t - powtorzenie poprzedniego obrotu" << std::endl;
                std::cout << "r - wyswietlenie macierzy rotacji" << std::endl;
                std::cout << "p - przesuniecie prostopadloscianu o zadany wektor" << std::endl;
                std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
                std::cout << "s - sprawdzenie dlugosci przeciwleglych bokow";
                std::cout << "m - wyswietl menu" << std::endl;
                std::cout << "k - koniec dzialania programu" << std:: endl;
            }
            std::cout << "Twoj wybor: " << std::endl;
            std::cin >> option;
            switch(option) {
                case 'k':
                    option = 'k'; break;
                case 'p':
                    std::cout << "Podaj wspolrzedne wektora" << std::endl;
                    std::cin >> v;
                    scene.TranslationVector(v); // Ustaw wektor translacji
                    scene.Move(); // Wykonaj ruch
                    //scene.GetCuboid().Edges(); // Sprawdz czy to prostopadloscian
                    scene.GetCuboid().ZapisWspolrzednychDoPliku("../datasets/prostopadloscian.dat");
                    scene.GetCuboid().Edges();
                    Lacze.Rysuj(); // Wyswietl wynik translacji
                    break;
                case 'o':
                    std::cout << "Podaj osie oraz katy" << std::endl;
                    axis = '0';
                    tmp.Clear();
                    while(axis != '.') {
                        std::cin >> axis;
                        switch(axis) {
                            case 'x':
                                std::cin >> angle;
                                tmp = RotationMatrix_X(angle) * tmp;
                                scene.RotationMatrix(RotationMatrix_X(angle));
                                break;
                            case 'y':
                                std::cin >> angle;
                                tmp = RotationMatrix_Y(angle) * tmp;
                                scene.RotationMatrix(RotationMatrix_Y(angle));
                                break;
                            case 'z':
                                std::cin >> angle;
                                tmp = RotationMatrix_Z(angle) * tmp;
                                scene.RotationMatrix(RotationMatrix_Z(angle));
                                break;
                            default:
                                if(axis != '.')
                                    std::cerr << "NIE MA TAKIEJ OSI\n Mozliwe opcje to x y z" << std::endl;
                                break;
                        }
                    }
                    std::cout <<"Podaj ilosc obrotow" << std::endl;
                    std::cin >> amount;
                    for(int i=0; i<amount-1; ++i) {
                        tmp = tmp * tmp;
                        scene.RotationMatrix(scene.GetMatrix());
                    }
                    scene.Move();
                    scene.GetCuboid().ZapisWspolrzednychDoPliku("../datasets/prostopadloscian.dat");
                    scene.GetCuboid().Edges();
                    Lacze.Rysuj(); // Wyswietl wynik translacji
                    break;
                case 't':
                    scene.RotationMatrix(tmp);
                    scene.Move();
                    scene.GetCuboid().ZapisWspolrzednychDoPliku("../datasets/prostopadloscian.dat");
                    scene.GetCuboid().Edges();
                    Lacze.Rysuj();
                    break;
                case 'w':
                    std::cout << scene.GetCuboid(); break; // Wyswietl wspolrzedne wierzcholkow prostokata
                case 'm':
                    option = '0';
                    break;
                case 'r':
                    scene.PrintRotation();
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

