#ifndef TABLEAU_H
#define TABLEAU_H

#include <iostream>
using namespace std;


class Tableau
{
public:
    Tableau();
    ~Tableau(); // destructeur
    void Init(); //Initialise le tableau
    void CaseAleatoire(); //Permet de placer une case 2 aléatoirement dans le tableau
    void Print(); //Pour faire des tests
    void up();
    void down();
    void left();
    void right();
    void FinPartie();
    int PrintScore();
    int PrintMeilleur();
    void NouvellePartie();


private:
    int **tab;
    int taille ;
    void Free();
    int NbreAlea(); // Permet de renvoyer un nombre aléatoire n'excédant pas une certaine borne
};

#endif // TABLEAU_H
