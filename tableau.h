#ifndef TABLEAU_H
#define TABLEAU_H

#include <iostream>
using namespace std;
#include <vector>

class Tableau
{
public:
    Tableau();
    ~Tableau(); // destructeur
    void Init(); //Initialise le tableau
    vector<int> CaseAleatoire(); //Permet de placer une case 2 aléatoirement dans le tableau
    void Print(); //Pour faire des tests
    vector<vector<int>> up(); //Permet de faire le mouvement vers le haut; renvoie les modifications du tableau
    vector<vector<int>> down();
    vector<vector<int>> left();
    vector<vector<int>> right();
    void FinPartie();
    int PrintScore();
    int PrintMeilleur();
    void NouvellePartie(); //L'appel à cette méthode crée une nouvelle partie


private:
    int **tab;
    int taille ;
    int Score;
    int MeilleurScore;
    void Free();
    int NbreAlea(); // Permet de renvoyer un nombre aléatoire n'excédant pas une certaine borne
    bool Cherche0(); // Permet de cherche s'il reste une place de libre dans le tableau
};

#endif // TABLEAU_H
