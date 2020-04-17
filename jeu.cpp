#include "jeu.h"
#include <random>
#include <iostream>
#include <iomanip>

using namespace std;



Jeu::Jeu(int tailletableau,QObject *parent) : QObject(parent)
{
    tab = nullptr;
    taille = tailletableau;

    Init();

    CaseAleatoire();
    CaseAleatoire();

}

void Jeu::Init()
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


Jeu::~Jeu()
{
    Free();
}

void Jeu::Free()
{
    for (int i=0;i<taille;i++)
        delete [] tab[i];
    delete [] tab;
    tab = nullptr;
}


void Jeu::CaseAleatoire()
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

int Jeu::NbreAlea()
{
    srand(time(NULL)); // initialisation de rand
    return rand()%taille; //le nombre taille est exclus du tirage : [0,taille[
}


void Jeu::nouvellePartie()
{
    Free();
    Init();
    CaseAleatoire();
    CaseAleatoire();
    Score=2;
}


int Jeu::get_case(int x,int y)
{
    return tab[x][y];
}




QString Jeu::readCase00()
{
    if(get_case(0,0)!=0)
        return QString::number(get_case(0,0));
    else
        return QString("");
}
QString Jeu::readCase01()
{
    if(get_case(0,1)!=0)
        return QString::number(get_case(0,1));
    else
        return QString("");
}
QString Jeu::readCase02()
{
    if(get_case(0,2)!=0)
        return QString::number(get_case(0,2));
    else
        return QString("");
}
QString Jeu::readCase03()
{
    if(get_case(0,3)!=0)
        return QString::number(get_case(0,3));
    else
        return QString("");
}
QString Jeu::readCase10()
{
    if(get_case(1,0)!=0)
        return QString::number(get_case(1,0));
    else
        return QString("");
}
QString Jeu::readCase11()
{
    if(get_case(1,1)!=0)
        return QString::number(get_case(1,1));
    else
        return QString("");
}
QString Jeu::readCase12()
{
    if(get_case(1,2)!=0)
        return QString::number(get_case(1,2));
    else
        return QString("");
}
QString Jeu::readCase13()
{
    if(get_case(1,3)!=0)
        return QString::number(get_case(1,3));
    else
        return QString("");
}
QString Jeu::readCase20()
{
    if(get_case(2,0)!=0)
        return QString::number(get_case(2,0));
    else
        return QString("");
}
QString Jeu::readCase21()
{
    if(get_case(2,1)!=0)
        return QString::number(get_case(2,1));
    else
        return QString("");
}
QString Jeu::readCase22()
{
    if(get_case(2,2)!=0)
        return QString::number(get_case(2,2));
    else
        return QString("");
}
QString Jeu::readCase23()
{
    if(get_case(2,3)!=0)
        return QString::number(get_case(2,3));
    else
        return QString("");
}
QString Jeu::readCase30()
{
    if(get_case(3,0)!=0)
        return QString::number(get_case(3,0));
    else
        return QString("");
}
QString Jeu::readCase31()
{
    if(get_case(3,1)!=0)
        return QString::number(get_case(3,1));
    else
        return QString("");
}
QString Jeu::readCase32()
{
    if(get_case(3,2)!=0)
        return QString::number(get_case(3,2));
    else
        return QString("");
}
QString Jeu::readCase33()
{
    if(get_case(3,3)!=0)
        return QString::number(get_case(3,3));
    else
        return QString("");
}
