#include "scene.hh"


 /*    Scene::Scene(Cuboid c) {
    Vector3D tmp1;
    Matrix3D tmp2, tmp3;
    cube.push_back(c);
    Translation.push_back(tmp1);
    Rotation.push_back(tmp2);
    OneRotation.push_back(tmp3);
}  */

void Scene::RotationMatrix(const Matrix3D matrix, int CubeNumber) {
    Matrix3D tmp = matrix;
    Rotation.at(CubeNumber) = tmp * Rotation.at(CubeNumber);
}

void Scene::TranslationVector(const Vector3D vector, int CubeNumber) {
    Vector3D tmp = vector;
    Translation.at(CubeNumber) = Translation.at(CubeNumber) + tmp;
}

void Scene::Move(int CubeNumber) {
    for(int i=0; i<CUBE; ++i) {
        cube.at(CubeNumber)[i] = Rotation.at(CubeNumber) * cube.at(CubeNumber)(i) + Translation.at(CubeNumber);
    }
}

Cuboid Scene::GetCuboid(int CubeNumber) {
    return cube.at(CubeNumber);
}

void Scene::PrintRotation(int CubeNumber) {
    std::cout << Rotation.at(CubeNumber) << std::endl;
}

Matrix3D Scene::GetOneRotationMatrix(int CubeNumber) {
    return OneRotation.at(CubeNumber);
}

void Scene::ClearOneRotationMatrix(int CubeNumber) {
    Matrix3D tmp;
    OneRotation.at(CubeNumber) = tmp;
}

void Scene::OneRotationMatrix(const Matrix3D matrix, int CubeNumber) {
    Matrix3D tmp = matrix;
    OneRotation.at(CubeNumber) = tmp * OneRotation.at(CubeNumber);
}

void Scene::NewCuboid() {
    Vector3D center;

    Matrix3D tmp2, tmp3;

    Rotation.push_back(tmp2);
    OneRotation.push_back(tmp3);

    double length_X, length_Y, length_Z;

    std::cout << "Podaj srodek prostopadloscianu" << std::endl;
    std::cin >> center;
    Translation.push_back(center);

    std::cout << "Podaj dlugosci bokow w osiach X Y Z" << std::endl;
    std::cin >> length_X >> length_Y >> length_Z;
    
    double half_X = length_X / 2, half_Y = length_Y / 2, half_Z = length_Z / 2;

    Vector3D corner1, corner2, corner3, corner4, corner5, corner6, corner7, corner8, tmp;

    corner1[0] = 0 - half_X; corner1[1] = 0 - half_Y; corner1[2] = 0 - half_Z;
    corner2[0] = 0 + half_X; corner2[1] = 0 - half_Y; corner2[2] = 0 - half_Z;
    corner3[0] = 0 - half_X; corner3[1] = 0 + half_Y; corner3[2] = 0 - half_Z;
    corner4[0] = 0 + half_X; corner4[1] = 0 + half_Y; corner4[2] = 0 - half_Z;
    corner5[0] = 0 - half_X; corner5[1] = 0 + half_Y; corner5[2] = 0 + half_Z;
    corner6[0] = 0 + half_X; corner6[1] = 0 + half_Y; corner6[2] = 0 + half_Z;
    corner7[0] = 0 - half_X; corner7[1] = 0 - half_Y; corner7[2] = 0 + half_Z;
    corner8[0] = 0 + half_X; corner8[1] = 0 - half_Y; corner8[2] = 0 + half_Z;

    Cuboid newcube(corner1, corner2, corner3, corner4, corner5, corner6, corner7, corner8);
    
    for(int i = 0; i < CUBE; ++i) {
        tmp = newcube(i);
        newcube[i] = tmp + center;
    }

    cube.push_back(newcube);

}