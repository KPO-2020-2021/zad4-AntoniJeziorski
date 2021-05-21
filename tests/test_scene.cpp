#include "../tests/doctest/doctest.h"
#include "scene.hh"

TEST_CASE("test dodawania prostopadloscianu do sceny metod GetCuboid, GetTranslation, GetOneRotationMatrix, GetMatrix") {
    Scene test;
    double x, y, z,a[3] = {-20, -25, -30}, b[3] = {0, -25, -30},c[3] = {-20, 5, -30},d[3] = {0, 5, -30},e[3] = {-20, 5,10 },f[3] = {0, 5, 10},g[3] = {-20, -25, 10},h[3] = {0,-25, 10};
    Vector3D center, c1(a),c2(b),c3(c),c4(d),c5(e),c6(f),c7(g),c8(h);
    Matrix3D empty;

    std::istringstream in1("-10 -10 -10");
    std::istringstream in2("20 30 40");

    in1 >> center;
    in2 >> x >> y >> z;

    test.NewCuboid(center,x,y,z);

    CHECK((test.GetTranslation(0) == center));
    CHECK((test.GetRotation(0) == empty));
    CHECK((test.GetOneRotationMatrix(0) == empty));
    CHECK((test.GetCuboid(0)[0] == c1));
    CHECK((test.GetCuboid(0)[1] == c2));
    CHECK((test.GetCuboid(0)[2] == c3));
    CHECK((test.GetCuboid(0)[3] == c4));
    CHECK((test.GetCuboid(0)[4] == c5));
    CHECK((test.GetCuboid(0)[5] == c6));
    CHECK((test.GetCuboid(0)[6] == c7));
    CHECK((test.GetCuboid(0)[7] == c8));
}

TEST_CASE("test metody TranslationVector") {
    Scene test;
    double x, y, z,a[3] = {-20, -25, -30}, b[3] = {0, -25, -30},c[3] = {-20, 5, -30},d[3] = {0, 5, -30},e[3] = {-20, 5,10 },f[3] = {0, 5, 10},g[3] = {-20, -25, 10},h[3] = {0,-25, 10}, t[3] = {10,10,10};
    Vector3D center, c1(a),c2(b),c3(c),c4(d),c5(e),c6(f),c7(g),c8(h), translation(t);
    Matrix3D empty;
    Vector3D result;

    std::istringstream in1("-10 -10 -10");
    std::istringstream in2("20 30 40");

    in1 >> center;
    in2 >> x >> y >> z;

    test.NewCuboid(center,x,y,z);

    test.TranslationVector(translation, 0);

    CHECK((test.GetTranslation(0) == result));
}

TEST_CASE("test metody OneRotationMatrix") {
    Scene test;
    double x, y, z,a[3] = {-20, -25, -30}, b[3] = {0, -25, -30},c[3] = {-20, 5, -30},d[3] = {0, 5, -30},e[3] = {-20, 5,10 },f[3] = {0, 5, 10},g[3] = {-20, -25, 10},h[3] = {0,-25, 10};
    Vector3D center, c1(a),c2(b),c3(c),c4(d),c5(e),c6(f),c7(g),c8(h);

    double r[3][3] = {1,2,3,4,5,6,7,8,9};
    Matrix3D empty, rot(r), result(r);

    std::istringstream in1("-10 -10 -10");
    std::istringstream in2("20 30 40");

    in1 >> center;
    in2 >> x >> y >> z;

    test.NewCuboid(center,x,y,z);

    test.OneRotationMatrix(rot, 0);

    CHECK((test.GetOneRotationMatrix(0) == result));
}

TEST_CASE("test metody ClearOneRotationMatrix") {
    Scene test;
    double x, y, z,a[3] = {-20, -25, -30}, b[3] = {0, -25, -30},c[3] = {-20, 5, -30},d[3] = {0, 5, -30},e[3] = {-20, 5,10 },f[3] = {0, 5, 10},g[3] = {-20, -25, 10},h[3] = {0,-25, 10};
    Vector3D center, c1(a),c2(b),c3(c),c4(d),c5(e),c6(f),c7(g),c8(h);

    double r[3][3] = {1,2,3,4,5,6,7,8,9};
    Matrix3D empty, rot(r), result;

    std::istringstream in1("-10 -10 -10");
    std::istringstream in2("20 30 40");

    in1 >> center;
    in2 >> x >> y >> z;

    test.NewCuboid(center,x,y,z);

    test.OneRotationMatrix(rot, 0);

    test.ClearOneRotationMatrix(0);

    CHECK((test.GetOneRotationMatrix(0) == result));


}

TEST_CASE("test metody RotationMatrix") {
    Scene test;
    double x, y, z,a[3] = {-20, -25, -30}, b[3] = {0, -25, -30},c[3] = {-20, 5, -30},d[3] = {0, 5, -30},e[3] = {-20, 5,10 },f[3] = {0, 5, 10},g[3] = {-20, -25, 10},h[3] = {0,-25, 10};
    Vector3D center, c1(a),c2(b),c3(c),c4(d),c5(e),c6(f),c7(g),c8(h);

    double r[3][3] = {1,2,3,4,5,6,7,8,9}, res[3][3] = {30,36,42,66,81,96,102,126,150};
    Matrix3D empty, rot(r), result(res);

    std::istringstream in1("-10 -10 -10");
    std::istringstream in2("20 30 40");

    in1 >> center;
    in2 >> x >> y >> z;

    test.NewCuboid(center,x,y,z);

    test.OneRotationMatrix(rot, 0);
    test.OneRotationMatrix(rot, 0);

    test.RotationMatrix(test.GetOneRotationMatrix(0), 0);

    CHECK((test.GetRotation(0) == result));
}

TEST_CASE("test metody Move") {
    Scene test;
    double x, y, z,a[3] = {-10, 20, -15}, b[3] = {10, 20, -15},c[3] = {-10, 20, 15},d[3] = {10, 20, 15},e[3] = {-10, -20, 15},f[3] = {10, -20, 15},g[3] = {-10, -20, -15},h[3] = {10,-20, -15}, t[3] = {10, 10, 10};
    Vector3D center, c1(a),c2(b),c3(c),c4(d),c5(e),c6(f),c7(g),c8(h), translation(t);

    double r[3][3] = {1,2,3,4,5,6,7,8,9};
    Matrix3D empty, rot(r), result(r);

    std::istringstream in1("-10 -10 -10");
    std::istringstream in2("20 30 40");

    in1 >> center;
    in2 >> x >> y >> z;

    test.NewCuboid(center,x,y,z);

    test.OneRotationMatrix(RotationMatrix_X(90), 0);

    test.RotationMatrix(test.GetOneRotationMatrix(0),0);

    test.TranslationVector(translation,0);

    test.Move(0);

    CHECK((test.GetCuboid(0)[0] == c1));
    CHECK((test.GetCuboid(0)[1] == c2));
    CHECK((test.GetCuboid(0)[2] == c3));
    CHECK((test.GetCuboid(0)[3] == c4));
    CHECK((test.GetCuboid(0)[4] == c5));
    CHECK((test.GetCuboid(0)[5] == c6));
    CHECK((test.GetCuboid(0)[6] == c7));
    CHECK((test.GetCuboid(0)[7] == c8));
}












