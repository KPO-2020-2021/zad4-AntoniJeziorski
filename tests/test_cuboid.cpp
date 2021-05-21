#include "../tests/doctest/doctest.h"
#include "vector3D.hh"
#include "cuboid.hh"

 TEST_CASE("test konstruktora bezparametrycznego prostopadloscianu oraz test prezciazenia operatora () dla odczytu wartosci lokalnych") {
    Cuboid cube;
    Vector3D empty;
    CHECK(((cube(0)[0] == empty[0]) && (cube(0)[1] == empty[1]) && (cube(0)[2] == empty[2]) && 
    (cube(1)[0] == empty[0]) && (cube(1)[1] == empty[1]) && (cube(1)[2] == empty[2]) && 
    (cube(2)[0] == empty[0]) && (cube(2)[1] == empty[1]) && (cube(2)[2] == empty[2]) && 
    (cube(3)[0] == empty[0]) && (cube(3)[1] == empty[1]) && (cube(3)[2] == empty[2]) && 
    (cube(4)[0] == empty[0]) && (cube(4)[1] == empty[1]) && (cube(4)[2] == empty[2]) && 
    (cube(5)[0] == empty[0]) && (cube(5)[1] == empty[1]) && (cube(5)[2] == empty[2]) && 
    (cube(6)[0] == empty[0]) && (cube(6)[1] == empty[1]) && (cube(6)[2] == empty[2]) && 
    (cube(7)[0] == empty[0]) && (cube(7)[1] == empty[1]) && (cube(7)[2] == empty[2])));
}

TEST_CASE("test konstruktora prostopadloscianu z parametrami i") {
    double a1[3] = {1, 1, 1}, a2[3] = {10, 1,1}, a3[3] = {10, 20, 1}, a4[3] = {1, 20, 1},a5[3] = {1, 1, 1}, a6[6] = {10, 1, 1}, a7[3] = {10, 20, 1}, a8[3] = {1, 20, 1};
    Vector3D v1(a1), v2(a2), v3(a3), v4(a4),v5(a5),v6(a6),v7{a7},v8(a8);
    Vector3D res1(a1), res2(a2), res3(a3), res4(a4), res5(a5), res6(a6), res7(a7), res8(a8);
    Cuboid cube(v1,v2,v3,v4,v5,v6,v7,v8);
    CHECK(((cube(0) == res1) && (cube(1) == res2) && (cube(2) == res3) && (cube(3) == res4) && (cube(4) == res5) && (cube(5) == res6) && (cube(6) == res7) && (cube(7) == res8)));
}

TEST_CASE("test przeciazenia operatora [] dla odczytu wartosci globalnych") {
    Cuboid cube;
    Vector3D vec;
    CHECK(((cube[0] == vec) && (cube[1] == vec) && (cube[2] == vec) && (cube[3] == vec) && 
    (cube[4] == vec) && (cube[5] == vec) && (cube[6] == vec) && (cube[7] == vec)));
}

TEST_CASE("test przeciazenia operatora [] dla zapisu wartosci globalnych") {
    Cuboid cube;
    double a[3] = {1,2,3};
    Vector3D vec(a);
    for(int i = 0; i<CUBE; ++i) {
        cube[i] = vec;
    }

    CHECK(((cube[0] == vec) && (cube[1] == vec) && (cube[2] == vec) && (cube[3] == vec) && 
    (cube[4] == vec) && (cube[5] == vec) && (cube[6] == vec) && (cube[7] == vec)));
}

TEST_CASE("test przeciazenia operatora <<") {
    Cuboid cube;

    std::ostringstream out;
    out << cube;

    CHECK("0.0000000000 0.0000000000 0.0000000000 \n0.0000000000 0.0000000000 0.0000000000 \n\n0.0000000000 0.0000000000 0.0000000000 \n0.0000000000 0.0000000000 0.0000000000 \n\n0.0000000000 0.0000000000 0.0000000000 \n0.0000000000 0.0000000000 0.0000000000 \n\n0.0000000000 0.0000000000 0.0000000000 \n0.0000000000 0.0000000000 0.0000000000 \n\n" == out.str());
} 

TEST_CASE("test zapisu do pliku") {
    Cuboid cube;

    CHECK((cube.ZapisWspolrzednychDoPliku("../datasets/test")));
}