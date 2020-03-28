#include "tableau.h"
#include <cstdlib>
#include <ctime>

Tableau::Tableau()
{
    tab = nullptr;
    taille = 4;
    Init();

    CaseAleatoire();
    CaseAleatoire();
}

Tableau::~Tableau()
{
    Free();
}

void Tableau::Free()
{
    for (int i=0;i<taille;i++)
        delete [] tab[i];
    delete [] tab;
    tab = nullptr;
}

void Tableau::Init()
{
    if (tab!=nullptr)
        Free();
    tab = new int *[taille];
    for (int i=0;i<taille;i++)
    {
        tab[i]=new int[taille];
    }
    for (int i=0;i<taille;i++)
    {
        for (int j=0;j<taille;j++)
        {
            tab[i][j]=0;
        }
    }
}

void Tableau::CaseAleatoire()
{
    // On suppose dans cette fonction qu'il y a au moins une case de libre dans le tableau (le test a été effectué avant l'appel de cette fonction)
    int Nombre1 = NbreAlea();
    int Nombre2 = NbreAlea();
    bool test = true;
    while (test)
    {
        if (tab[Nombre1][Nombre2]==0)
        {
            test=false;
            tab[Nombre1][Nombre2]=2;
        }
        else
        {
            Nombre1=NbreAlea();
            Nombre2=NbreAlea();
        }
    }
}

int Tableau::NbreAlea()
{
    srand(time(NULL)); // initialisation de rand
    return rand()%taille; //le nombre taille est exclus du tirage : [0,taille[
}

void Tableau::Print()
{
    for (int i=0;i<taille;i++)
    {
        for (int j=0;j<taille;j++)
        {
            cout <<tab[i][j] << " ";
        }
        cout << endl;
    }
}

void Tableau::up()
{
    for (int i=1;i<taille;i++)
    {
        for (int j=0;j<taille;j++)
        {
            bool test = true; // Booléen permettant de savoir si on a rencontré une case pleine au-dessus ou non, dès que c'est le cas, la boucle while s'arrête
            int UP = 0;
            while (test && i-(UP+1)>=0) //test si on a rencontré une case non vide, et si on peut encore remonter d'un cran dans le tableau
            {
                if (tab[i-(UP+1)][j]==0)
                {
                    UP+=1; //la case est non vide, on peut donc au moins remonter la cas jusque là
                }
                else
                {
                    test=false; //On a rencontré une case non vide, donc on sort de la boucle
                }
            }
            if (UP !=0)
            {
                tab[i-UP][j]=tab[i][j];
                tab[i][j]=0;
            }
        }
    }
    CaseAleatoire();
}
