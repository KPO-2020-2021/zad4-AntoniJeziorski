#include "../tests/doctest/doctest.h"
#include "vector2D.hh"
#include "matrix2D.hh"

TEST_CASE("test konstruktora Matrix bezparametrycznego oraz przeciazenia operatora () dla odczytu") {
    Matrix2D test;
    CHECK((test(0, 0) == 1 && test(0, 1) == 0 && test(1, 0) == 0 && test(1, 1) == 1));
}

TEST_CASE("test konstruktora Matrix z parametrem") {
    double array[2][2] = {1, 2, 3, 4};
    Matrix2D test(array);
    CHECK((test(0, 0) == 1 && test(0, 1) == 2 && test(1, 0) == 3 && test(1, 1) == 4));
}

TEST_CASE("test przeciazenia operatora () dla wczytywania") {
    Matrix2D test;
    test(0, 0) = 1;
    test(0, 1) = 2;
    test(1, 0) = 3;
    test(1, 1) = 4;
    CHECK((test(0, 0) == 1 && test(0, 1) == 2 && test(1, 0) == 3 && test(1, 1) == 4));
}

TEST_CASE("test przeciazenia operatora * macierz razy wektor") {
    double array[2] = {2, 4}, array2[2][2] = {1, 2, 3, 4};
    Vector2D v1(array), v2;
    Matrix2D test(array2);
    v2 = test * v1;
    CHECK((v2[0] == 10 && v2[1] == 22));
}

TEST_CASE("test przeciazenia operatora +") {
    double array1[2][2] = {1, 2, 3, 4}, array2[2][2] = {5, 6, 7, 8};
    Matrix2D test1(array1), test2(array2), result;
    result = test1 + test2;
    CHECK((result(0, 0) == 6 && result(0, 1) == 8 && result(1, 0) == 10 && result(1, 1) == 12));
}

TEST_CASE("test przeciazenia operatora >>") {
    Matrix2D test;
    std::istringstream in("1 2 3 4");
    in >> test;
    CHECK((test(0, 0) == 1 && test(0, 1) == 2 && test(1, 0) == 3 && test(1, 1) == 4));
}

TEST_CASE("test przeciazenia operatora >> dla bledu") {
    Matrix2D test;
    std::istringstream in("o r t m");
    WARN_THROWS(in >> test);
}

TEST_CASE("test przeciazenia operatora <<") {
    double array[2][2] = {1, 2, 3, 4};
    Matrix2D test(array);
    std::ostringstream out;
    out << test;
    CHECK("| 1.0000000000 | | 2.0000000000 | | 3.0000000000 | | 4.0000000000 | " == out.str());
}

TEST_CASE("test przeciazenia operatora () dla odczytu z bledem") {
    double array2[2][2] = {1, 2, 3, 4};
    Matrix2D test(array2);
    std::ostringstream out;
    WARN_THROWS(out << test(10, -15));
}

TEST_CASE("test przeciazenia operatora () dla wczytywania z bledem") {
    Matrix2D test;
    WARN_THROWS(test(10, -15) = 5);
}

TEST_CASE("Test przeciazenia operatora ==") {
    double X[2][2] = {1,2,3,4};
    Matrix2D tmp1(X), tmp2(X);
    bool test = tmp1 == tmp2;

    CHECK(test);
}

TEST_CASE("test przeciazenia operatora * macierz razy macierz") {
    double X[2][2] = {1,2,3,4}, Y[2][2] = {7,10,15,22};
    Matrix2D tmp1(X), tmp2(X), res(Y);
    CHECK((res(0,0) == 7 && res(0,1) == 10 && res(1,0) == 15 && res(1,1) == 22));
}

TEST_CASE("Test przeciazenia operatora mnozenia dwoch macierzy") {
    Matrix2D tmp1, tmp2, result, check;

    tmp1 = RotationMatrix(50);
    tmp2 = RotationMatrix(-50);

    result = tmp1 * tmp2;

    CHECK((result == check)); 
}


