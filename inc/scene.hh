#pragma once

#include "size.hh"
#include "cuboid.hh"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>

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

        void Move(int);

        /*!
         *
         * \brief Metoda zwracajaca prostopadloscian ze sceny
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         * \return Prostopadloscian o podanym numerze
         */

        Cuboid GetCuboid(int);

        /*!
         *
         * \brief Metoda wyswietlajaca calkowita macierz rotacji
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         * \return Macierz rotacji prostopadloscianu o podanym numerze
         */

        void PrintRotation(int);

        /*!
         *
         * \brief Metoda zwracajaca macierz ostatniej rotacji ze scnny
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         * \return Macierz ostantiej rotacji podanego prostopadloscianu
         */

        Matrix3D GetOneRotationMatrix(int);

        /*!
         *
         * \brief Metoda ustalajaca wartosc macierzy aktualnej rotacji
         * 
         * \param matrix - macierz rotacji wzgledem pojedynczej osi
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         */

        void OneRotationMatrix(const Matrix3D, int);

        /*!
         *
         * \brief Metoda sluzaca do dodania nowego prostopadloscianu do sceny
         * 
         */

        void NewCuboid();

        /*!
         *
         * \brief Metoda czyszczaca macierz ostatniej rotacji robiac z niej macierz jedynkowa
         * 
         * \param CubeNumber - numer prostopadloscianu
         * 
         */

        void ClearOneRotationMatrix(int);
};