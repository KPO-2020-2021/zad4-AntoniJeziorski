#include "scene.hh"


Scene::Scene(Cuboid c) {
    Vector3D tmp1;
    Matrix3D tmp2, tmp3;
    cube.push_back(c);
    Translation.push_back(tmp1);
    Rotation.push_back(tmp2);
    OneRotation.push_back(tmp3);
}

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

void Scene::OneRotationMatrix(const Matrix3D matrix, int CubeNumber) {
    Matrix3D tmp = matrix;
    OneRotation.at(CubeNumber) = tmp * OneRotation.at(CubeNumber);
}

void Scene::NewCuboid() {
    Vector3D corner1,corner2,corner3,corner4,corner5,corner6,corner7,corner8, tmp1;
    Matrix3D tmp2, tmp3;
    double length_X, length_Y, length_Z;
    std::cout << "Podaj wierzcholek poczatkowy" << std::endl;
    std::cin >> corner1;
    std::cout << "Podaj dlugosci bokow w osiach X Y Z" << std::endl;
    std::cin >> length_X >> length_Y >> length_Z;

    corner2[0] = corner1[0] + length_X; corner2[1] = corner1[1]; corner2[2] = corner2[2];
    corner3[0] = corner1[0]; corner3[1] = corner1[1] + length_Y; corner3[2] = corner1[2];
    corner4[0] = corner1[0]; corner4[1] = corner1[1]; corner4[2] = corner1[2] + length_Z;
    corner5[0] = corner4[0] + length_X; corner5[1] = corner4[1]; corner5[2] = corner4[2];
    corner6[0] = corner4[0]; corner6[1] = corner4[1] + length_Y; corner6[2] = corner4[2];
    corner7[0] = corner5[0]; corner7[1] = corner6[1]; corner7[2] = corner4[2];
    corner8[0] = corner2[0]; corner8[1] = corner3[1]; corner7[2] = corner1[2];

    Cuboid newcube(corner3, corner1, corner8, corner2, corner7, corner5, corner6, corner4);
    cube.push_back(newcube);
    Translation.push_back(tmp1);
    Rotation.push_back(tmp2);
    OneRotation.push_back(tmp3);
    
}