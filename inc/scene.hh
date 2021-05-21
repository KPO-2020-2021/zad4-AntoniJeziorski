#pragma once

#include "size.hh"
#include "cuboid.hh"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string.h>

/*!
 *
 * \file scene.hh
 * 
 * \brief Plik zawierający definicję klasy Scene
 */

/*!
 *
 * \brief Definicja klasy Scene przechowująca elementy w scenie oraz ich odpowiednie wlasciwosci
 */

class Scene {

    /*!
     *
     * \brief Pole przetrzymujące poszczególne prostopadłościany
     */

    std::vector <Cuboid> cube;

    /*!
     *
     * \brief Pole przetrzymujące całkowite macierze rotacji dla poszczególnych prostopadłościanów
     */

    std::vector <Matrix3D> Rotation;

    /*!
     *
     * \brief Pole przetrzymujące macierze ostatniej rotacji dla poszczególnych prostopadłoscianów
     */

    std::vector <Matrix3D> OneRotation;

    /*!
     *
     * \brief Pole przetrzymujące przesunięcie środka lokalnego układu współrzędnych
     */

    std::vector <Vector3D> Translation;

    public:

        /*!
         *
         * \brief Metoda domnazajaca macierz jednej rotacji do macierzy calkowitej
         * 
         * \param matrix - macierz domnazana
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         */

        void RotationMatrix(const Matrix3D, const int);

        /*!
         *
         * \brief Metoda zmniajaca wartosc wektora przesuniecia srodka prostopadloscianu
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         * \param vector - wektor o jaki chcemy przemiescic prostopadloscian
         */

        void TranslationVector(const Vector3D, const int);

        /*!
         *
         * \brief Metoda obliczajaca wspolrzedne wierzcholkow po zadanych operacjach
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         */

        void Move(const int);

        /*!
         *
         * \brief Metoda zwracajaca prostopadloscian ze sceny
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         * \return Prostopadloscian o podanym numerze
         */

        Cuboid GetCuboid(const int);

        /*!
         *
         * \brief Metoda wyswietlajaca calkowita macierz rotacji
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         * \return Macierz rotacji prostopadloscianu o podanym numerze
         */

        Matrix3D GetRotation(const int);

        /*!
         *
         * \brief Metoda zwracajaca macierz ostatniej rotacji ze sceny
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         * \return Macierz ostantiej rotacji podanego prostopadloscianu
         */

        Matrix3D GetOneRotationMatrix(const int);

        /*!
         *
         * \brief Metoda ustalajaca wartosc macierzy aktualnej rotacji
         * 
         * \param matrix - macierz rotacji wzgledem pojedynczej osi
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         */

        void OneRotationMatrix(const Matrix3D,const int);

        /*!
         *
         * \brief Metoda sluzaca do dodania nowego prostopadloscianu do sceny
         * 
         * \param center - punkt bedacy srodkiem prostopadloscianu
         * 
         * \param length_X - dlugosc bokow w osi OY
         * 
         * \param length_Y - dlugosc bokow w osi OY
         * 
         * \param length_Z - dlugosc bokow w osi OZ
         * 
         */

        void NewCuboid(const Vector3D center,const double length_X,const double length_Y,const double length_Z);

        /*!
         *
         * \brief Metoda czyszczaca macierz ostatniej rotacji robiac z niej macierz jedynkowa
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         */

        void ClearOneRotationMatrix(const int);

        /*!
         *
         * \brief Metoda zwracajaca wektor przesuniecia lokalnego ukladu wspolrzednych wzgledem globalnego
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         * \return wektor przesuniecia ukladu lokalnego
         */

        Vector3D GetTranslation(const int);
};