#include "../tests/doctest/doctest.h"
#include "vector3D.hh"

TEST_CASE("test konstruktora Vector bezparametrycznego")  {
    Vector3D vec;
    CHECK((vec[0] == 0 && vec[1] == 0 && vec[2] == 0));
}

TEST_CASE("Test konstruktora Vector z parametrem") {
    double array[3] = {4,5,6};
    Vector3D vec(array);
    CHECK(((vec[0] == 4) && (vec[1] == 5) && (vec[2] == 6)));
}

TEST_CASE("test przeciazenia operatora [] dla odczytu") {
    double array[3] = {4,5,6};
    Vector3D vec(array);
    std::ostringstream out;
    out << vec[0] << " " << vec[1] << " " << vec[2];
    std::cout << out.str();
    CHECK("4 5 6" == out.str());
}

TEST_CASE("test przeciazenia operatora [] dla zapisu") {
    Vector3D vec;
    vec[0] = 4;
    vec[1] = 5;
    vec[2] = 6;
    std::ostringstream out;
    out << vec[0] << " " << vec[1] << " " << vec[2];
    std::cout << out.str();
    CHECK("4 5 6" == out.str());
}

TEST_CASE("test przeciazenia operatora <<") {
    double array[3] = {4,5,6};
    Vector3D vec(array);
    std::ostringstream out;
    out << vec;
    std::cout << out.str();
    CHECK("4.0000000000 5.0000000000 6.0000000000 " == out.str());
}

TEST_CASE("test przeciazenia operatora >>") {
    Vector3D vec;
    std::istringstream in("4 5 6");
    in >> vec;
    CHECK((vec[0] == 4 && vec[1] == 5 && vec[2] == 6));
}

TEST_CASE("test przeciazenia operatora +") {
    double a1[3] = {4, 5, 6}, a2[3] = {2, 3, 4};
    Vector3D v1(a1), v2(a2), v3;
    v3 = v1 + v2;
    CHECK((v3[0] == 6 && v3[1] == 8 && v3[2] == 10));
}

TEST_CASE("test przeciazenia operatora -") {
    double a1[3] = {4, 5, 6}, a2[3] = {2, 3, 4};
    Vector3D v1(a1), v2(a2), v3;
    v3 = v1 - v2;
    CHECK((v3[0] == 2 && v3[1] == 2 && v3[2] == 2));
}

TEST_CASE("test przeciazenia operatora *") {
    double a1[3] = {4, 5, 6}, a2 = 2;
    Vector3D v1(a1), v2;
    v2 = v1 * a2;
    CHECK((v2[0] == 8 && v2[1] == 10 && v2[2] == 12));
}

TEST_CASE("test przeciazenia operatora /") {
    double a1[3] = {4, 5, 6}, a2 = 2;
    Vector3D v1(a1), v2;
    v2 = v1 / a2;
    CHECK((v2[0] == 2 && v2[1] == 2.5 && v2[2] == 3));
}

TEST_CASE("test przeciazenia operatora <<") {
    double array[3] = {4,5,6};
    Vector3D vec(array);
    std::ostringstream out;
    out << vec;
    std::cout << out.str();
    CHECK("4.0000000000 5.0000000000 6.0000000000 " == out.str());
}

TEST_CASE("test przeciazenia operatora >> dla bledu") {
    Vector3D vec;
    std::istringstream in("o # $");
    WARN_THROWS(in >> vec);
}

TEST_CASE("test przeciazenia operatora [] dla wczytywania z bledem") {
    Vector3D vec;
    WARN_THROWS(vec[-21] = 1);
}

TEST_CASE("test przeciazenia operatora [] dla odczytu z bledem") {
    double array[3] = {4 ,5, 6};
    Vector3D vec(array);
    std::ostringstream out;
    WARN_THROWS(out << vec[-10]);
}

TEST_CASE("test dzielenia wektora przez 0") {
    double array[3] = {4, 5, 6};
    Vector3D vec(array);
    double a = 0;
    WARN_THROWS(vec/a);
}

