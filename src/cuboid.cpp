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
            this->Corners[i] = Rotation * DefaultCorners[i];
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
    double a, b, c, d; // dlugosci bokow
    a = sqrt(pow(this->Corners[0][0] - this->Corners[1][0],2)+pow(this->Corners[0][1]-this->Corners[1][1],2));
    b = sqrt(pow(this->Corners[2][0] - this->Corners[3][0],2)+pow(this->Corners[2][1]-this->Corners[3][1],2));
    c = sqrt(pow(this->Corners[0][0] - this->Corners[3][0],2)+pow(this->Corners[0][1]-this->Corners[3][1],2));
    d = sqrt(pow(this->Corners[1][0] - this->Corners[2][0],2)+pow(this->Corners[1][1]-this->Corners[2][1],2));
    
    if(a >= b-MAX_DIFF && a<=b+MAX_DIFF) {
        if(a > c) {
            std::cout << ":)\tDluzsze przeciwlegle boki sa sobie rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << a << std::endl;
            std::cout << std::fixed << std::setprecision(10) << b << std::endl;
        }
        else {
            std::cout << ":)\tKrotsze przeciwlegle boki sa sobie rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << a << std::endl;
            std::cout << std::fixed << std::setprecision(10) << b << std::endl;
        }
    }
    else {
        if(a > c) {
            std::cout << ":O\tDluzsze przeciwlegle boki nie sa rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << a << std::endl;
            std::cout << std::fixed << std::setprecision(10) << b << std::endl;
        }
        else {
            std::cout << ":O\tKrotsze przeciwlegle boki nie sa rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << a << std::endl;
            std::cout << std::fixed << std::setprecision(10) << b << std::endl;
        }
    }
    if(c >= d-MAX_DIFF && c<=d+MAX_DIFF) {
        if(a < c) {
            std::cout << ":)\tDluzsze przeciwlegle boki sa sobie rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << c << std::endl;
            std::cout << std::fixed << std::setprecision(10) << d << std::endl;
        }
        else {
            std::cout << ":)\tKrotsze przeciwlegle boki sa sobie rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << c << std::endl;
            std::cout << std::fixed << std::setprecision(10) <<d << std::endl;
        }
    }
    else {
        if(a < c) {
            std::cout << ":O\tDluzsze przeciwlegle boki nie sa rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << c << std::endl;
            std::cout << std::fixed << std::setprecision(10) << d << std::endl;
        }
        else {
            std::cout << ":O\tKrotsze przeciwlegle boki nie sa rowne" << std::endl;
            std::cout << std::fixed << std::setprecision(10) << c << std::endl;
            std::cout << std::fixed << std::setprecision(10) << d << std::endl;
        }
    }
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
    DefaultCorners[0] = 0;
    DefaultCorners[1] = 0;
    DefaultCorners[2] = 0;
    DefaultCorners[3] = 0;
    DefaultCorners[4] = 0;
    DefaultCorners[5] = 0;
    DefaultCorners[6] = 0;
    DefaultCorners[7] = 0;
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
    StrmPlikowy << this->Corners[0];
    StrmPlikowy << std::endl;
    StrmPlikowy << Corners[1];

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}
