#include "../tests/doctest/doctest.h"
#include "vector3D.hh"
#include "matrix3D.hh"

TEST_CASE("test konstruktora Matrix bezparametrycznego oraz przeciazenia operatora () dla odczytu") {
    Matrix3D test;
    CHECK((test(0, 0) == 1 && test(0, 1) == 0 && test(0, 2) == 0 && test(1, 0) == 0 && test(1, 1) == 1 && test(1, 2) == 0 && test(2, 0) == 0 && test(2,1) == 0 && test(2,2) == 1));
}

TEST_CASE("test konstruktora Matrix z parametrem") {
    double array[3][3] = {1, 2, 3, 4, 5, 6,7,8,9};
    Matrix3D test(array);
    CHECK((test(0, 0) == 1 && test(0, 1) == 2 && test(0, 2) == 3 && test(1, 0) == 4 && test(1, 1) == 5 && test(1, 2) == 6 && test(2, 0) == 7 && test(2,1) == 8 && test(2,2) == 9));
}

TEST_CASE("test przeciazenia operatora () dla wczytywania") {
    Matrix3D test;

    test(0, 0) = 1;
    test(0, 1) = 2;
    test(0, 2) = 3;
    test(1, 0) = 4;
    test(1, 1) = 5;
    test(1, 2) = 6;
    test(2, 0) = 7;
    test(2, 1) = 8;
    test(2, 2) = 9;

    CHECK((test(0, 0) == 1 && test(0, 1) == 2 && test(0, 2) == 3 && test(1, 0) == 4 && test(1, 1) == 5 && test(1, 2) == 6 && test(2, 0) == 7 && test(2,1) == 8 && test(2,2) == 9));
}

TEST_CASE("test przeciazenia operatora * dla mnozenia macierzy razy wektor") {
    double array[3] = {2, 4, 6}, array2[3][3] = {1, 2, 3, 4,5,6,7,8,9};
    Vector3D v1(array), v2;
    Matrix3D test(array2);
    v2 = test * v1;
    CHECK((v2[0] == 28 && v2[1] == 64 && v2[2] == 100));
}

TEST_CASE("test przeciazenia operatora +") {
    double array1[3][3] = {1, 2, 3, 4,5,6,7,8,9}, array2[3][3] = {1,2,3,4,5, 6, 7, 8,9};
    Matrix3D test1(array1), test2(array2), test;
    test = test1 + test2;
    CHECK((test(0, 0) == 2 && test(0, 1) == 4 && test(0, 2) == 6 && test(1, 0) == 8 && test(1, 1) == 10 && test(1, 2) == 12 && test(2, 0) == 14 && test(2,1) == 16 && test(2,2) == 18));
}

TEST_CASE("test przeciazenia operatora >>") {
    Matrix3D test;
    std::istringstream in("1 2 3 4 5 6 7 8 9");
    in >> test;
    CHECK((test(0, 0) == 1 && test(0, 1) == 2 && test(0, 2) == 3 && test(1, 0) == 4 && test(1, 1) == 5 && test(1, 2) == 6 && test(2, 0) == 7 && test(2,1) == 8 && test(2,2) == 9));
}

TEST_CASE("test przeciazenia operatora >> dla bledu") {
    Matrix3D test;
    std::istringstream in("o r t m h u h g i o");
    WARN_THROWS(in >> test);
}

TEST_CASE("test przeciazenia operatora <<") {
    double array[3][3] = {1, 2, 3, 4,5,6,7,8,9};
    Matrix3D test(array);
    std::ostringstream out;
    out << test;
    CHECK("| 1.0000000000 | | 2.0000000000 | | 3.0000000000 | | 4.0000000000 | | 5.0000000000 | | 6.0000000000 | | 7.0000000000 | | 8.0000000000 | | 9.0000000000 | " == out.str());
}

TEST_CASE("test przeciazenia operatora () dla odczytu z bledem") {
    double array2[3][3] = {1, 2, 3, 4,5,6,7,8,9};
    Matrix3D test(array2);
    std::ostringstream out;
    WARN_THROWS(out << test(10, -15));
}

TEST_CASE("test przeciazenia operatora () dla wczytywania z bledem") {
    Matrix3D test;
    WARN_THROWS(test(10, -15) = 5);
}

TEST_CASE("Test przeciazenia operatora ==") {
    double X[3][3] = {1,2,3,4,5,6,7,8,9};
    Matrix3D tmp1(X), tmp2(X);
    bool test = tmp1 == tmp2;

    CHECK(test);
}

TEST_CASE("test przeciazenia operatora * dla mnozenia macierzy razy macierz") {
    double array[3][3] = {1, 2, 3, 4,5,6,7,8,9}, res[3][3] = {30,36,42,66,81,96,102,126,150};

    Matrix3D test1(array), test2(array), test, result(res);
    test = test1*test2;
    CHECK((test == result));
}

