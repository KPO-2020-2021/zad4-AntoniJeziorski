#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
#include "vector3D.hh"
#include "matrix3D.hh"

/*!
 *
 * \file cuboid.hh
 * 
 * \brief Plik zawierający definicję klasy Cuboid
 */

/*!
 * 
 * \brief Klasa Cuboid reprezentująca prostoapdłościan w trójwymiarowym układzie współrzędnych
 */

class Cuboid {

    /*!
     *
     * \brief Jednowymiarowa tablica typu Vector3D przetrzymująca lokalne współrzędne wierzchołków
     */

    Vector3D DefaultCorners[CUBE]; 

    /*!
     *
     * \brief Jednowymiarowa tablica typu Vector3D przetrzymująca globalne współrzędne wierzchołków
     */

    Vector3D Corners[CUBE]; 

    public:

        /*!
         * \brief Metoda wyswietlająca długości boków prostopadłościanu oraz sprawdzająca, czy przeciwległe boki są tej samej długości
         * 
         * \param this - sprawdzany prostopadłościan
         */

        void Edges() const;

        /*!
         * \brief Konstruktor parametryczny klasy Cuboid
         * 
         * \param a - wektor zawierający współrzędne 1 wierzchołka
         * 
         * \param b - wektor zawierający współrzędne 2 wierzchołka
         * 
         * \param c - wektor zawierający współrzędne 3 wierzchołka
         * 
         * \param d - wektor zawierający współrzędne 4 wierzchołka
         * 
         * \param e - wektor zawierający współrzędne 5 wierzchołka
         * 
         * \param f - wektor zawierający współrzędne 6 wierzchołka
         * 
         * \param g - wektor zawierający współrzędne 7 wierzchołka
         * 
         * \param h - wektor zawierający współrzędne 8 wierzchołka
         * 
         * \return Prostopadłościan o zadanych wierzcholkach
         */

        Cuboid(Vector3D, Vector3D, Vector3D, Vector3D, Vector3D, Vector3D, Vector3D, Vector3D); // Konstruktor parametryczny

        /*!
         * \brief Konstruktor bezparametryczny klasy Cuboid
         * 
         * 
         * \return 8 wektorów, z których każdy jest wypełniony zerami
         */


        Cuboid(); // Konstruktor bezparametryczny

        /*!
         * \brief Metoda realizująca zapis współrzędnych wierzchołków prostopadłościanu do pliku
         * 
         * \param sNazwaPliku - wskaznik do pliku, w ktorym zostana zapisane wspolrzedne
         * \return true jesli zapis sie powiodl\n false jesli zapis sie nie powiodl
         */

        bool ZapisWspolrzednychDoPliku( const char *sNazwaPliku);

        /*!
         *
         * \brief Przeciązenie operatora indeksującego dla odczytu
         * 
         * \param index - indeks określający jeden z wierzchołków
         * 
         * \return Jeden z wierzchołków jako stały wektor zawierający wartości globalne.
         */

        const Vector3D &operator [] (int index) const; // Operator indeksujacy dla odczytu

        /*!
         *
         * \brief Przeciążenie operatora funkcyjnego dla odczytu
         * 
         * \param index - indeks określający jeden z wierzchołków
         * 
         * \return Jeden z wierzchołków jako stały wektor zawierający wartości lokalne.
         */

        const Vector3D &operator () (int index) const; // Operator indeksujacy dla odczytu

        /*!
         *
         * \brief Przeciążenie operatora indeksującego dla zapisu
         * 
         * \param index - indeks określający jeden z wierzchołków
         * 
         * \return Jeden z wierzchołków jako wektor zawierający wartości globalne.
         */ 

        Vector3D &operator [] (int index); // Operator indeksujacy dla zapisu
};

/*!
 * \brief Przeciazenie operatora bitowego dla wyswietladnia prostopadłościanu
 * 
 * \param Strm - referencja do strumienia wyjsciowego, na którym zostanie wyświetlony prostopadłoscian
 * \param Pr - prostokat, ktory zostanie wyswietlony
 * 
 * \return Podaje prostopadłoscian na zadane wyjście
 */

std::ostream& operator << (std::ostream &Strm, const Cuboid &Pr); // Operator bitowy <<

/*!
 * \brief Przeciazenie operatora bitowego >> dla wczytywania prostokata
 * 
 * \param Strm - referencja do strumienia wejsciowego na, do którego zostanie podany prostpadłościan
 * \param Pr -  referencja do wprowadzanego prostopadłościanu
 * 
 * \return Podaje prostopadłościan na zadane wejście
 */

std::istream& operator >> (std::istream &Strm, Cuboid &Pr);

