#include "cuboid.hh"

/*!
 * Przeciazenie operator indeksujacego dla odczytu
 * Argumenty:
 *      index - numer miejsca w tablicy
 * Zwraca:
 *      Wektor reprezentujacy jeden z wierzcholkow jako stala
 */



const Vector3D &Cuboid::operator [] (int index) const {
    if (index < 0 || index >= CUBE) {
        throw std::runtime_error("Error:  Blad ilosci wierzcholkow!");
    }
    return Corners[index];
}

const Vector3D &Cuboid::operator () (int index) const {
    if (index < 0 || index >= CUBE) {
        throw std::runtime_error("Error:  Blad ilosci wierzcholkow!");
    }
    return DefaultCorners[index];
}
/*!
 * Przeciazenie operator indeksujacego dla zapisu
 * Argumenty:
 *      index - numer miejsca w tablicy
 * Zwraca:
 *      Wektor reprezentujacy jeden z wierzcholkow
 */


Vector3D &Cuboid::operator[](int index) {
    return const_cast<Vector3D &>(const_cast<const Cuboid *>(this)->operator[](index));
}





/*!
 * Przeciazenie operatora bitowego dla wyswietladnia prostokata
 * Argumenty:
 *  &Strm - referencja do strumienia wyjsciowego
 *  &Pr - prostokat, ktory zostanie wyswietlony
 * Zwraca:
 *  Strumien wyjsciowy z prostokatem
 */

std::ostream& operator << (std::ostream &Strm, const Cuboid &Pr) {
    for(int i=0; i < CUBE; i++) {
        Strm << Pr[i] << std::endl;
        if(i%2 == 1)
            Strm << std::endl;
    }
    return Strm;
}



/*!
 * Przeciazenie operatora bitowego dla wczytywania prostokata
 * Argumenty:
 *  &Strm - referencja do strumienia wejsciowego
 *  &Pr -  referencja do wprowadzanego prostokata
 * Zwraca:
 *  Strumien wejsciowy z prostokatem
 */

std::istream& operator >> (std::istream &Strm, Cuboid &Pr) {
    for(int i=0; i < CUBE; i++) {
        Strm >> Pr[i];
    }
    return Strm;
}



/*!
 * Realizuje translacje prostokata o zadany wektor
 * Argumenty:
 *  vector - wektor, o jaki ma zostac wykonana translacja
 * Zwraca:
 *  Prostokat po przesunieciu o zadany wektor
 */

Cuboid Cuboid::Translation(const Vector3D vector) {
    for(int i=0; i<CUBE; i++) {
        this->Corners[i] = this->Corners[i] + vector;
    }
    return *this;
}




/*!
 * Realizuje obrot CUBEtanglea wokol poczatku ukladu wspolrzednych
 * o zadany kat podana ilosc razy
 * Argumenty:
 *  angle - kat o jaki zostanie wykonany obrot
 *  amount - ilosc obrotow
 * Zwraca:
 *  Prostokat po wykonaniu obrotu
 */

Cuboid Cuboid::Rotation(const double angle, const int amount) {
    Matrix3D Rotation;
    Rotation = RotationMatrix_Z(angle);
    for(int j=0; j < amount; j++){
        for(int i=0; i<CUBE; i++) {
            Corners[i] = Rotation * DefaultCorners[i];
        }
    }
    return *this;
}


/*!
 * Wyswietla dlugosci bokow prostokata oraz sprawdza, czy przeciwne boki sa tej samej dlugosci
 * Argumenty:
 *  this - sprawdzany prostokat
 * Zwraca:
 */

void Cuboid::Edges() const {
    double a, b, c, d, e, f, g, h, i, j, k, l; // dlugosci bokow
    int counterX = 0, counterY = 0, counterZ = 0;
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


/*!
 * Konstruktor parametryczny prostokata
 * Argumenty:
 *  4 wektory, gdzie kazdy reprezentuje wspolrzedne jednego wierzcholka
 * Zwraca:
 *  Prostokat o zadanych wierzcholkach
 */

Cuboid::Cuboid(Vector3D a, Vector3D b, Vector3D c, Vector3D d, Vector3D e, Vector3D f, Vector3D g, Vector3D h) {
    DefaultCorners[0] = a;
    DefaultCorners[1] = b;
    DefaultCorners[2] = c;
    DefaultCorners[3] = d;
    DefaultCorners[4] = e;
    DefaultCorners[5] = f;
    DefaultCorners[6] = g;
    DefaultCorners[7] = h;
    for(int i = 0; i < CUBE; ++i)
        Corners[i] = DefaultCorners[i];
}



/*!
 * Konstruktor bezparametryczny prostokata
 * Argumenty:
 * Zwraca:
 *  Tablice 4 wektorow z ktorych kazdy jest wypelniony zerami
 */

Cuboid::Cuboid() {
    Vector3D x;
    for(int i = 0; i < CUBE; ++i)
        DefaultCorners[i] = x;
}



/*!
 * Realizuje zapis wspolrzednych wierzcholkow prostokata do pliku
 * Argumenty:
 *  *sNazwaPliku - wskaznik do pliku, w ktorym zostana zapisane wspolrzedne
 * Zwraca:
 *  Prada jesli zapis sie powiodl
 *  Falsz jesli zapis sie nie powiodl
 */

bool Cuboid::ZapisWspolrzednychDoPliku( const char *sNazwaPliku) {

    std::ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())  {
        throw std::runtime_error("Operacja otwarcia pliku do zapisu nie powiodla sie");
        return false;
    }

    StrmPlikowy << *this;
    StrmPlikowy << Corners[0];
    StrmPlikowy << std::endl;
    StrmPlikowy << Corners[1];

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}
