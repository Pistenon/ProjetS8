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
    bool Changement=false ; // Permet de savoir si un seul changement a été fait dans la grille
    for (int i=1;i<taille;i++)
    {
        for (int j=0;j<taille;j++)
        {
            if (tab[i][j]!=0) // On ne remonte pas un 0
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
                        if (tab[i-(UP+1)][j]==tab[i][j])
                        {
                            UP+=1;
                        }
                        test=false; //On a rencontré une case non vide, donc on sort de la boucle
                    }
                }
                if (UP !=0)
                {
                    Changement=true;
                    if (tab[i-UP][j]==tab[i][j])
                    {
                        tab[i-UP][j]=2*tab[i-UP][j];
                        tab[i][j]=0;
                        if (tab[i-UP][j]>Score) //Seul moment où le score peut augmenter
                        {
                            Score=tab[i-UP][j];
                        }
                    }
                    else
                    {
                        tab[i-UP][j]=tab[i][j];
                        tab[i][j]=0;
                    }

                }
            }
        }
    }
    if (Changement) // Si la grille n'a pas changé suite au mouvement, on ne rajoute pas de case aléatoire
    {
        if (Cherche0())
        {
            CaseAleatoire();
        }
        else
        {
            FinPartie();
        }
    }
    if (Score>MeilleurScore)
    {
        MeilleurScore=Score;
    }
}

void Tableau::down()
{
    bool Changement=false ; // Permet de savoir si un seul changement a été fait dans la grille
    for (int i=taille-2;i>-1;i--)
    {
        for (int j=0;j<taille;j++)
        {
            if (tab[i][j]!=0) // On ne descend pas un 0
            {
                bool test = true; // Booléen permettant de savoir si on a rencontré une case pleine au-dessous ou non, dès que c'est le cas, la boucle while s'arrête
                int DOWN = 0;
                while (test && i+(DOWN+1)<taille) //test si on a rencontré une case non vide, et si on peut encore descendre d'un cran dans le tableau
                {
                    if (tab[i+(DOWN+1)][j]==0)
                    {
                        DOWN+=1; //la case est non vide, on peut donc au moins descendre la cas jusque là
                    }
                    else
                    {
                        if (tab[i+(DOWN+1)][j]==tab[i][j])
                        {
                            DOWN+=1;
                        }
                        test=false; //On a rencontré une case non vide, donc on sort de la boucle
                    }
                }
                if (DOWN !=0)
                {
                    Changement=true;
                    if (tab[i+DOWN][j]==tab[i][j])
                    {
                        tab[i+DOWN][j]=2*tab[i+DOWN][j];
                        tab[i][j]=0;
                        if (tab[i+DOWN][j]>Score) //Seul moment où le score peut augmenter
                        {
                            Score=tab[i+DOWN][j];
                        }
                    }
                    else
                    {
                        tab[i+DOWN][j]=tab[i][j];
                        tab[i][j]=0;
                    }

                }
            }
        }
    }
    if (Changement) // Si la grille n'a pas changé suite au mouvement, on ne rajoute pas de case aléatoire
    {
        if (Cherche0())
        {
            CaseAleatoire();
        }
        else
        {
            FinPartie();
        }
    }
    if (Score>MeilleurScore)
    {
        MeilleurScore=Score;
    }
}

void Tableau::left()
{
    bool Changement=false ; // Permet de savoir si un seul changement a été fait dans la grille
    for (int j=taille-2;j<taille;j++)
    {
        for (int i=0;i<taille;i++)
        {
            if (tab[i][j]!=0) // On ne décalle pas un 0
            {
                bool test = true; // Booléen permettant de savoir si on a rencontré une case pleine à gauche ou non, dès que c'est le cas, la boucle while s'arrête
                int LEFT = 0;
                while (test && j-(LEFT+1)>-1)
                {
                    if (tab[i][j-(LEFT+1)]==0)
                    {
                        LEFT+=1;
                    }
                    else
                    {
                        if (tab[i][j-(LEFT+1)]==tab[i][j])
                        {
                            LEFT+=1;
                        }
                        test=false; //On a rencontré une case non vide, donc on sort de la boucle
                    }
                }
                if (LEFT !=0)
                {
                    Changement=true;
                    if (tab[i][j-LEFT]==tab[i][j])
                    {
                        tab[i][j-LEFT]=2*tab[i][j];
                        tab[i][j]=0;
                        if (tab[i][j-LEFT]>Score) //Seul moment où le score peut augmenter
                        {
                            Score=tab[i][j-LEFT];
                        }
                    }
                    else
                    {
                        tab[i][j-LEFT]=tab[i][j];
                        tab[i][j]=0;
                    }

                }
            }
        }
    }
    if (Changement) // Si la grille n'a pas changé suite au mouvement, on ne rajoute pas de case aléatoire
    {
        if (Cherche0())
        {
            CaseAleatoire();
        }
        else
        {
            FinPartie();
        }
    }
    if (Score>MeilleurScore)
    {
        MeilleurScore=Score;
    }
}

void Tableau::right()
{
    bool Changement=false ; // Permet de savoir si un seul changement a été fait dans la grille
    for (int j=1;j>-1;j--)
    {
        for (int i=0;i<taille;i++)
        {
            if (tab[i][j]!=0) // On ne décalle pas un 0
            {
                bool test = true;
                int RIGHT = 0;
                while (test && j+(RIGHT+1)>-1)
                {
                    if (tab[i][j+(RIGHT+1)]==0)
                    {
                        RIGHT+=1;
                    }
                    else
                    {
                        if (tab[i][j+(RIGHT+1)]==tab[i][j])
                        {
                            RIGHT+=1;
                        }
                        test=false; //On a rencontré une case non vide, donc on sort de la boucle
                    }
                }
                if (RIGHT !=0)
                {
                    Changement=true;
                    if (tab[i][j+RIGHT]==tab[i][j])
                    {
                        tab[i][j+RIGHT]=2*tab[i][j];
                        tab[i][j]=0;
                        if (tab[i][j+RIGHT]>Score) //Seul moment où le score peut augmenter
                        {
                            Score=tab[i][j+RIGHT];
                        }
                    }
                    else
                    {
                        tab[i][j+RIGHT]=tab[i][j];
                        tab[i][j]=0;
                    }

                }
            }
        }
    }
    if (Changement) // Si la grille n'a pas changé suite au mouvement, on ne rajoute pas de case aléatoire
    {
        if (Cherche0())
        {
            CaseAleatoire();
        }
        else
        {
            FinPartie();
        }
    }
    if (Score>MeilleurScore)
    {
        MeilleurScore=Score;
    }
}

bool Tableau::Cherche0()
{
    for (int i=0;i<taille;i++)
    {
        for (int j=0;j<taille;j++)
        {
            if (tab[i][j]==0)
            {
                return true;
            }
        }
    }
    return false;
}

void Tableau::FinPartie() // A changer
{
    cout <<"Fin de partie" << endl;
    Print();
}

int Tableau::PrintScore()
{
    return Score;
}

int Tableau::PrintMeilleur()
{
    return MeilleurScore;
}

void Tableau::NouvellePartie()
{
    Free();
    Init();

    CaseAleatoire();
    CaseAleatoire();
    Score=2;
}

