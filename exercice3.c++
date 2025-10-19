#include <iostream>
#include <string>
using namespace std;

class Utilisateur {
private:
    string nom;
    string role;
    static int nbUtilisateursConnectes;

public:
    Utilisateur(const string& n, const string& r) : nom(n), role(r) {
        nbUtilisateursConnectes++;
    }

    ~Utilisateur() {
        nbUtilisateursConnectes--;
    }

    static int getNbUtilisateursConnectes() {
        return nbUtilisateursConnectes;
    }

    void afficher() const {
        cout << "Nom : " << nom << ", Rôle : " << role << endl;
    }
};

int Utilisateur::nbUtilisateursConnectes = 0;

int main() {
    cout << "Nombre d'utilisateurs connectés : " << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur u1("Alice", "admin");
    cout << "Nombre d'utilisateurs connectés : " << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur u2("Bob", "visiteur");
    cout << "Nombre d'utilisateurs connectés : " << Utilisateur::getNbUtilisateursConnectes() << endl;

    {
        Utilisateur u3("Charlie", "visiteur");
        cout << "Nombre d'utilisateurs connectés : " << Utilisateur::getNbUtilisateursConnectes() << endl;
    }

    cout << "Nombre d'utilisateurs après déconnexion locale : " << Utilisateur::getNbUtilisateursConnectes() << endl;

    return 0;
}
