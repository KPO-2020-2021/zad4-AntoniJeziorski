#include "cuboid.hh"

/*!
 *
 * \file cuboid.cpp
 * 
 * \brief Plik zawierający definicje metod dla klasy Cuboid
 */


const Vector3D &Cuboid::operator [] (int index) const {
    if (index < 0 || index >= CUBE) {
        throw std::runtime_error("Error:  Blad ilosci wierzcholkow!");
    }
    return Corners[index];
}

Vector3D &Cuboid::operator () (int index) {
    if (index < 0 || index >= CUBE) {
        throw std::runtime_error("Error:  Blad ilosci wierzcholkow!");
    }
    return DefaultCorners[index];
}

Vector3D &Cuboid::operator[](int index) {
    return const_cast<Vector3D &>(const_cast<const Cuboid *>(this)->operator[](index));
}

std::ostream& operator << (std::ostream &Strm, const Cuboid &Pr) {
    for(int i=0; i < CUBE; i++) {
        Strm << Pr[i] << std::endl;
        if(i%2 == 1)
            Strm << std::endl;
    }
    return Strm;
}

std::istream& operator >> (std::istream &Strm, Cuboid &Pr) {
    for(int i=0; i < CUBE; i++) {
        Strm >> Pr[i];
    }
    return Strm;
}

void Cuboid::Edges() const {
    double a, b, c, d, e, f, g, h, i, j, k, l; // dlugosci bokow

    int counterX = 0, counterY = 0, counterZ = 0; // liczniki poprawnych porownan

    a = sqrt(pow(Corners[1][0] - Corners[3][0],2)+pow(Corners[1][1]-Corners[3][1],2)+pow(Corners[1][2] - Corners[3][2],2));
    b = sqrt(pow(Corners[3][0] - Corners[2][0],2)+pow(Corners[3][1]-Corners[2][1],2)+pow(Corners[3][2] - Corners[2][2],2));
    c = sqrt(pow(Corners[2][0] - Corners[0][0],2)+pow(Corners[2][1]-Corners[0][1],2)+pow(Corners[2][2] - Corners[0][2],2));
    d = sqrt(pow(Corners[0][0] - Corners[1][0],2)+pow(Corners[0][1]-Corners[1][1],2)+pow(Corners[0][2] - Corners[1][2],2));
    e = sqrt(pow(Corners[1][0] - Corners[7][0],2)+pow(Corners[1][1]-Corners[7][1],2)+pow(Corners[1][2] - Corners[7][2],2));
    f = sqrt(pow(Corners[7][0] - Corners[6][0],2)+pow(Corners[7][1]-Corners[6][1],2)+pow(Corners[7][2] - Corners[6][2],2));
    g = sqrt(pow(Corners[6][0] - Corners[4][0],2)+pow(Corners[6][1]-Corners[4][1],2)+pow(Corners[6][2] - Corners[4][2],2));
    h = sqrt(pow(Corners[4][0] - Corners[5][0],2)+pow(Corners[4][1]-Corners[5][1],2)+pow(Corners[4][2] - Corners[5][2],2));
    i = sqrt(pow(Corners[5][0] - Corners[7][0],2)+pow(Corners[5][1]-Corners[7][1],2)+pow(Corners[5][2] - Corners[7][2],2));
    j = sqrt(pow(Corners[0][0] - Corners[6][0],2)+pow(Corners[0][1]-Corners[6][1],2)+pow(Corners[0][2] - Corners[6][2],2));
    k = sqrt(pow(Corners[3][0] - Corners[5][0],2)+pow(Corners[3][1]-Corners[5][1],2)+pow(Corners[3][2] - Corners[5][2],2));
    l = sqrt(pow(Corners[2][0] - Corners[4][0],2)+pow(Corners[2][1]-Corners[4][1],2)+pow(Corners[2][2] - Corners[4][2],2));

    double X[4] = {a,c,g,i}, Y[4] = {d,b,f,h}, Z[4] = {e,j,k,l};

    for(int i=0; i<4; ++i) {
        for(int j=i+1; j<4; ++j) {
            if(X[i] >= X[j]-MAX_DIFF && X[i]<=X[j]+MAX_DIFF)
                counterX += 1;
        }
    }

    for(int i=0; i<4; ++i) {
        for(int j=i+1; j<4; ++j) {
            if(Y[i] >= Y[j]-MAX_DIFF && Y[i]<=Y[j]+MAX_DIFF)
                counterY += 1;
        }
    }

    for(int i=0; i<4; ++i) {
        for(int j=i+1; j<4; ++j) {
            if(Z[i] >= Z[j]-MAX_DIFF && Z[i]<=Z[j]+MAX_DIFF)
                counterZ += 1;
        }
    }

    if(counterX == 6) {
        if(a > d)
            std::cout << ":)\tDluzsze boki sa rowne" << std::endl;
        else
            std::cout << ":)\tKrotsze boki sa rowne" << std::endl;
    }
    else {
        if(a > d)
            std::cout << ":O\tDluzsze boki nie sa rowne" << std::endl;
        else
            std::cout << ":O\tKrotsze przeciwlegle boki nie sa rowne" << std::endl;
    }
    std::cout << std::fixed << std::setprecision(10) << X[0] << " " << X[1] << " " << X[2] << " " << X[3] << std::endl;

    if(counterY == 6) {
        if(a > d)
            std::cout << ":)\tKrotsze boki sa rowne" << std::endl;
        else
            std::cout << ":)\tDluzsze boki sa rowne" << std::endl;
    }
    else {
        if(a > d)
            std::cout << ":O\tKrotsze przeciwlegle boki nie sa rowne" << std::endl;
        else
            std::cout << ":O\tDluzsze boki nie sa rowne" << std::endl;
    }
    std::cout << Y[0] << " " << Y[1] << " " << Y[2] << " " << Y[3] << std::endl;

    if(counterZ == 6) {
        std::cout << ":)\tPoprzeczne boki sa rowne" << std::endl;
    }
    else {
        std::cout << ":O\tPoprzeczne boki nie sa rowne" << std::endl;
    }
    std::cout << Z[0] << " " << Z[1] << " " << Z[2] << " " << Z[3] << std::endl;

}

Cuboid::Cuboid(Vector3D a, Vector3D b, Vector3D c, Vector3D d, Vector3D e, Vector3D f, Vector3D g, Vector3D h) {
    DefaultCorners[0] = a;
    DefaultCorners[1] = b;
    DefaultCorners[2] = c;
    DefaultCorners[3] = d;
    DefaultCorners[4] = e;
    DefaultCorners[5] = f;
    DefaultCorners[6] = g;
    DefaultCorners[7] = h;

}

Cuboid::Cuboid() {
    Vector3D x;
    for(int i = 0; i < CUBE; ++i)
        DefaultCorners[i] = x;
}

bool Cuboid::ZapisWspolrzednychDoPliku( const char *sNazwaPliku) {

    Vector3D X, Y, tmp1 = Corners[0], tmp2 = Corners[7], tmp3 = Corners[2], tmp4 = Corners[5];

    std::ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())  {
        throw std::runtime_error("Operacja otwarcia pliku do zapisu nie powiodla sie");
        return false;
    }

    X = (tmp1 + tmp2) / 2;
    Y = (tmp3 + tmp4) / 2;

    StrmPlikowy << X << std::endl << Corners[7] << std::endl << Corners[5] << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    StrmPlikowy << X << std::endl << Corners[1] << std::endl << Corners[3] << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    StrmPlikowy << X << std::endl << Corners[0] << std::endl << Corners[2] << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    StrmPlikowy << X << std::endl << Corners[6] << std::endl << Corners[4] << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    StrmPlikowy << X << std::endl << Corners[7] << std::endl << Corners[5] << std::endl << Y << std::endl << '#' << std::endl;

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}

