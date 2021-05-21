#include "../tests/doctest/doctest.h"
#include "matrix4x4.hh"

TEST_CASE("test metody Rotation") {
    double a[3] = {22,3,28};
    Vector3D vec(a);
    Matrix4x4 res = RotationMatrix(30,60,90,vec);

    std::ostringstream out;
    out << res;

    CHECK("| 0.4330127019 | | 0.7500000000 | | 0.5000000000 | | 22.0000000000 | | 0.2500000000 | | 0.4330127019 | | -0.0135127548 | | 3.0000000000 | | -0.8660254038 | | 0.5000000000 | | 0.0000000000 | | 28.0000000000 | | 0.0000000000 | | 0.0000000000 | | 0.0000000000 | | 1.0000000000 | " == out.str());
}
