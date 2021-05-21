#include "../tests/doctest/doctest.h"
#include "vector3D.hh"
#include "cuboid.hh"



TEST_CASE("test konstruktora prostopadloscianu z parametrami") {
    double a1[3] = {1, 1, 1}, a2[3] = {10, 1,1}, a3[3] = {10, 20, 1}, a4[3] = {1, 20, 1},a5[3] = {1, 1, 1}, a6[6] = {10, 1, 1}, a7[3] = {10, 20, 1}, a8[3] = {1, 20, 1};
    Vector3D v1(a1), v2(a2), v3(a3), v4(a4),v5(a5),v6(a6),v7{a7},v8(a8);
    Vector3D res1(a1), res2(a2), res3(a3), res4(a4), res5(a5), res6(a6), res7(a7), res8(a8);
    Cuboid cube(v1,v2,v3,v4,v5,v6,v7,v8);
    CHECK(((cube(0) == res1) && (cube(1) == res2) && (cube(2) == res3) && (cube(3) == res4) && (cube(4) == res5) && (cube(5) == res6) && (cube(6) == res7) && (cube(7) == res8)));
}

 TEST_CASE("test konstruktora bezparametrycznego prostopadloscianu") {
    Cuboid cube;
    Vector3D empty;
    CHECK(((cube(0) == empty) &&(cube(1) == empty) &&(cube(2) == empty) &&(cube(3) == empty) &&(cube(4) == empty) &&(cube(5) == empty) &&(cube(6) == empty) &&(cube(7) == empty)));
}

/* TEST_CASE("test metody Translation") {
    double a1[2] = {1, 1}, a2[2] = {10, 1}, a3[2] = {10, 20}, a4[2] = {1, 20}, a5[2] = {10, 20};
    Vector v1(a1), v2(a2), v3(a3), v4(a4), v5(a5);
    Rectangle Rec(v1, v2, v3, v4);
    Rec.Translation(v5);
    CHECK(((Rec[0][0] == 11) && (Rec[0][1] == 21) && (Rec[1][0] == 20) && (Rec[1][1] == 21) && (Rec[2][0] == 20) && (Rec[2][1] == 40) && (Rec[3][0] == 11) && (Rec[3][1] == 40)));
}

TEST_CASE("test metody Rotation") {
    double a1[2] = {1, 1}, a2[2] = {10, 1}, a3[2] = {10, 20}, a4[2] = {1, 20};
    Vector v1(a1), v2(a2), v3(a3), v4(a4);
    Rectangle Rec(v1, v2, v3, v4);
    Rec.Rotation(180, 1);
    CHECK(((Rec[0][0] >= -1-0.0000000001) && (Rec[0][1] >= -1-0.0000000001) && (Rec[1][0] >= -10-0.0000000001) && (Rec[1][1] >= -1-0.0000000001) && (Rec[2][0] >= -10-0.0000000001) && (Rec[2][1] >= -20-0.0000000001) && (Rec[3][0] >= -1-0.0000000001) && (Rec[3][1] >= -20-0.0000000001)));
}  */