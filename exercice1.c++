#include <iostream>
using namespace std;

class Boite {
private:
    double longueur;
    double largeur;
    double hauteur;
    static int nbBoites;

public:
    Boite(double l, double L, double h) : longueur(l), largeur(L), hauteur(h) {
        nbBoites++;
    }

    ~Boite() {
        nbBoites--;
    }

    static int getNombreBoites() {
        return nbBoites;
    }
};

int Boite::nbBoites = 0;

int main() {
    Boite b1(2.0, 3.0, 4.0);
    Boite b2(1.5, 2.5, 3.5);

    cout << "Nombre de boîtes créées : " << Boite::getNombreBoites() << endl;

    {
        Boite b3(1.0, 1.0, 1.0);
        cout << "Nombre de boîtes créées : " << Boite::getNombreBoites() << endl;
    }

    cout << "Nombre de boîtes après destruction locale : " << Boite::getNombreBoites() << endl;

    return 0;
}
