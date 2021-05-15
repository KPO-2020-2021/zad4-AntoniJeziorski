#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
#include "vector3D.hh"
#include "matrix3D.hh"


class Cuboid {
  
  Vector3D DefaultCorners[CUBE]; // Tablica 8 wektorow reprezentujaca wierzcholki podstawowego prostopadloscianiu

  Vector3D Corners[CUBE]; // Tablica 8 wektorow reprezentujaca przetworzony prostopadloscian

  public:

    Cuboid Translation(const Vector3D); // Metoda translacji

    Cuboid Rotation(const double, const int); // Metoda obrotu

    void Edges() const; // Metoda sprawdzajaca boki

    Cuboid(Vector3D, Vector3D, Vector3D, Vector3D, Vector3D, Vector3D, Vector3D, Vector3D); // Konstruktor parametryczny

    Cuboid(); // Konstruktor bezparametryczny

    bool ZapisWspolrzednychDoPliku( const char *sNazwaPliku); // Metoda zapisu do pliku

    const Vector3D &operator [] (int index) const; // Operator indeksujacy dla odczytu

    const Vector3D &operator () (int index) const; // Operator indeksujacy dla odczytu

    Vector3D &operator [] (int index); // Operator indeksujacy dla zapisu
};

std::ostream& operator << (std::ostream &Strm, const Cuboid &Pr); // Operator bitowy <<

std::istream& operator >> (std::istream &Strm, Cuboid &Pr); // Operator bitowy >>

