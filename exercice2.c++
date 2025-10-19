#include <iostream>
#include <string>
using namespace std;

class Produit {
private:
    string nom;
    float prixHT;
    static float tauxTVA;

public:
    Produit(const string& n, float p) : nom(n), prixHT(p) {}

    float getPrixTTC() const {
        return prixHT * (1 + tauxTVA / 100);
    }

    static void modifierTVA(float nouveauTaux) {
        tauxTVA = nouveauTaux;
    }

    void afficher() const {
        cout << nom << " : Prix TTC = " << getPrixTTC() << endl;
    }
};

float Produit::tauxTVA = 20.0f;

int main() {
    Produit p1("Stylo", 10.0f);
    Produit p2("Cahier", 20.0f);

    p1.afficher();
    p2.afficher();

    Produit::modifierTVA(10.0f);

    cout << "Après modification du taux de TVA :" << endl;
    p1.afficher();
    p2.afficher();

    return 0;
}
