#include "tableau.h"

Tableau::Tableau()
{
    tab = nullptr;
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
    for (int i=0;i<taille;i++)
    {
        for (int j=0;j<taille;j++)
        {
            if (tab[i][j]==0)
                1+1; //NON FINI !!!!!!!!!!!!!!!!!!!!!!!!!!!
        }
    }
}
