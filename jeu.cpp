#include "jeu.h"
#include <random>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;



Jeu::Jeu(int tailletableau,QObject *parent) : QObject(parent)
{
    tab = nullptr;
    taille = tailletableau;
    MeilleurScore=0;

    Init();
    caseAleatoire();
    caseAleatoire();

    add_historique();

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
    FIN=0;
    Score=0;


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


void Jeu::caseAleatoire()
{
    vector<vector<int>> casesVides;

    //Creation liste des cases vides
    for (int i=0;i<taille;i++)
    {
        for (int j=0;j<taille;j++)
        {
            if (tab[i][j]==0)
            {
                casesVides.push_back(vector<int>(2));
                int s = casesVides.size();
                casesVides[s-1][0]=i;
                casesVides[s-1][1]=j;
            }


        }
    }

    // Choix d'une case vide aleatoirement
    int t=casesVides.size();
    int a = rand()%t;
    int n = rand()%4;
    if (n>=1)
    {
        tab[casesVides[a][0]][casesVides[a][1]]=2;
    }
    else
    {
        tab[casesVides[a][0]][casesVides[a][1]]=4;
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
    FreeHistorique();
    Init();
    caseAleatoire();
    caseAleatoire();

    add_historique();
    caseChanged();
    scoreChanged();
    endChanged();
}

void Jeu::add_historique()
{
    int** tab2 = new int *[taille];
    for (int i=0;i<taille;i++)
    {
        tab2[i]=new int[taille];
    }
    for (int i=0;i<taille;i++)
    {
        for (int j=0;j<taille;j++)
        {
            tab2[i][j]=tab[i][j];
        }
    }

    historique.push_back(tab2);
    int s =Score;
    historiqueScore.push_back(s);
}

void Jeu::FreeHistorique()
{
    int T=historique.size();
    while (T>0)
    {
       historique.pop_back();
       historiqueScore.pop_back();
       T=historique.size();
    }
}


void Jeu::cancel()
{
    if (FIN==1)
    {
        FIN=0;
    }
    int T = historique.size();
    if (T>1)
    {
        for (int i = 0 ; i < taille ; i++)
        {
            for (int j = 0 ; j < taille ; j++)
            {
                tab[i][j] = historique[T-2][i][j];
            }
         }

    historique.pop_back();
    Score=historiqueScore[T-2];
    historiqueScore.pop_back();

    }
    caseChanged();
    scoreChanged();    
    endChanged();

}



bool Jeu::Cherche0()
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




vector<vector<int>> Jeu::up()
{
    vector<vector<int>> CHANGEMENT; // Permet de collecter tout les changements sur la grille pour l'affichage graphique
    vector<vector<int>> fusions; //Permet de collecter toutes les fusions
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
                            if (TestFusion(i-(UP+1),j,fusions)) // la fusion est possible
                            {
                                UP+=1;
                                fusions.push_back(vector<int>(2));
                                int t=fusions.size();
                                fusions[t-1][0]=i-(UP);
                                fusions[t-1][1]=j;
                            }

                        }
                        test=false; //On a rencontré une case non vide, donc on sort de la boucle
                    }
                }
                if (UP !=0)
                {
                    if (tab[i-UP][j]==tab[i][j])
                    {
                        tab[i-UP][j]=2*tab[i-UP][j];
                        tab[i][j]=0;
                        CHANGEMENT.push_back(vector<int>(5));
                        int s=CHANGEMENT.size();
                        CHANGEMENT[s-1][2]=i-UP;
                        CHANGEMENT[s-1][3]=j;
                        CHANGEMENT[s-1][0]=i;
                        CHANGEMENT[s-1][1]=j;
                        CHANGEMENT[s-1][4]=tab[i-UP][j];
                        Score+=tab[i-UP][j];
                    }
                    else
                    {
                        tab[i-UP][j]=tab[i][j];
                        tab[i][j]=0;
                        CHANGEMENT.push_back(vector<int>(5));
                        int s=CHANGEMENT.size();
                        CHANGEMENT[s-1][2]=i-UP;
                        CHANGEMENT[s-1][3]=j;
                        CHANGEMENT[s-1][0]=i;
                        CHANGEMENT[s-1][1]=j;
                        CHANGEMENT[s-1][4]=tab[i-UP][j];
                    }

                }
            }
        }
    }
    if (Cherche0())
    {
        CHANGEMENT.push_back(vector<int>(1,1));
    }
    else
    {
        CHANGEMENT.push_back(vector<int>(1,0)); // la partie est finie, donc je l'indique par un 0 à la fin pour la gestion graphique
    }
    return CHANGEMENT;
}



vector<vector<int>> Jeu::down()
{
    vector<vector<int>> CHANGEMENT; // Permet de collecter tout les changements sur la grille pour l'affichage graphique
    vector<vector<int>> fusions; //Permet de collecter toutes les fusions
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
                            if (TestFusion(i+(DOWN+1),j,fusions)) // la fusion est possible
                            {
                                DOWN+=1;
                                fusions.push_back(vector<int>(2));
                                int t=fusions.size();
                                fusions[t-1][0]=i+(DOWN);
                                fusions[t-1][1]=j;
                            }
                        }
                        test=false; //On a rencontré une case non vide, donc on sort de la boucle
                    }
                }
                if (DOWN !=0)
                {
                    if (tab[i+DOWN][j]==tab[i][j])
                    {
                        tab[i+DOWN][j]=2*tab[i+DOWN][j];
                        tab[i][j]=0;
                        CHANGEMENT.push_back(vector<int>(5));
                        int s=CHANGEMENT.size();
                        CHANGEMENT[s-1][2]=i+DOWN;
                        CHANGEMENT[s-1][3]=j;
                        CHANGEMENT[s-1][0]=i;
                        CHANGEMENT[s-1][1]=j;
                        CHANGEMENT[s-1][4]=tab[i+DOWN][j];
                        Score+=tab[i+DOWN][j];
                    }
                    else
                    {
                        tab[i+DOWN][j]=tab[i][j];
                        tab[i][j]=0;
                        CHANGEMENT.push_back(vector<int>(5));
                        int s=CHANGEMENT.size();
                        CHANGEMENT[s-1][2]=i+DOWN;
                        CHANGEMENT[s-1][3]=j;
                        CHANGEMENT[s-1][0]=i;
                        CHANGEMENT[s-1][1]=j;
                        CHANGEMENT[s-1][4]=tab[i+DOWN][j];
                    }

                }
            }
        }
    }
    if (Cherche0())
    {
        CHANGEMENT.push_back(vector<int>(1,1));
    }
    else
    {
        CHANGEMENT.push_back(vector<int>(1,0)); // la partie est finie, donc je l'indique par un 0 à la fin pour la gestion graphique
    }
    return CHANGEMENT;
}

vector<vector<int>> Jeu::left()
{
    vector<vector<int>> CHANGEMENT; // Permet de collecter tout les changements sur la grille pour l'affichage graphique
    vector<vector<int>> fusions; //Permet de collecter toutes les fusions
    for (int j=1;j<taille;j++)
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
                            if (TestFusion(i,j-(LEFT+1),fusions)) // la fusion est possible
                            {
                                LEFT+=1;
                                fusions.push_back(vector<int>(2));
                                int t=fusions.size();
                                fusions[t-1][0]=i;
                                fusions[t-1][1]=j-(LEFT);
                            }
                        }
                        test=false; //On a rencontré une case non vide, donc on sort de la boucle
                    }
                }
                if (LEFT !=0)
                {
                    if (tab[i][j-LEFT]==tab[i][j])
                    {
                        tab[i][j-LEFT]=2*tab[i][j];
                        tab[i][j]=0;
                        CHANGEMENT.push_back(vector<int>(5));
                        int s=CHANGEMENT.size();
                        CHANGEMENT[s-1][2]=i;
                        CHANGEMENT[s-1][3]=j-LEFT;
                        CHANGEMENT[s-1][0]=i;
                        CHANGEMENT[s-1][1]=j;
                        CHANGEMENT[s-1][4]=tab[i][j-LEFT];
                        Score+=tab[i][j-LEFT];
                    }
                    else
                    {
                        tab[i][j-LEFT]=tab[i][j];
                        tab[i][j]=0;
                        CHANGEMENT.push_back(vector<int>(5));
                        int s=CHANGEMENT.size();
                        CHANGEMENT[s-1][2]=i;
                        CHANGEMENT[s-1][3]=j-LEFT;
                        CHANGEMENT[s-1][0]=i;
                        CHANGEMENT[s-1][1]=j;
                        CHANGEMENT[s-1][4]=tab[i][j-LEFT];
                    }

                }
            }
        }
    }
    if (Cherche0())
    {
        CHANGEMENT.push_back(vector<int>(1,1));
    }
    else
    {
        CHANGEMENT.push_back(vector<int>(1,0)); // la partie est finie, donc je l'indique par un 0 à la fin pour la gestion graphique
    }
    return CHANGEMENT;
}

vector<vector<int>> Jeu::right()
{
    vector<vector<int>> CHANGEMENT; // Permet de collecter tout les changements sur la grille pour l'affichage graphique
    vector<vector<int>> fusions; //Permet de collecter toutes les fusions
    for (int j=taille-2;j>-1;j--)
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
                            if (TestFusion(i,j+(RIGHT+1),fusions)) // la fusion est possible
                            {
                                RIGHT+=1;
                                fusions.push_back(vector<int>(2));
                                int t=fusions.size();
                                fusions[t-1][0]=i;
                                fusions[t-1][1]=j+(RIGHT);
                            }
                        }
                        test=false; //On a rencontré une case non vide, donc on sort de la boucle
                    }
                }
                if (RIGHT !=0)
                {
                    if (tab[i][j+RIGHT]==tab[i][j])
                    {
                        tab[i][j+RIGHT]=2*tab[i][j];
                        tab[i][j]=0;
                        CHANGEMENT.push_back(vector<int>(5));
                        int s=CHANGEMENT.size();
                        CHANGEMENT[s-1][2]=i;
                        CHANGEMENT[s-1][3]=j+RIGHT;
                        CHANGEMENT[s-1][0]=i;
                        CHANGEMENT[s-1][1]=j+RIGHT;
                        CHANGEMENT[s-1][4]=tab[i][j+RIGHT];
                        Score+=tab[i][j+RIGHT];
                    }
                    else
                    {
                        tab[i][j+RIGHT]=tab[i][j];
                        tab[i][j]=0;
                        CHANGEMENT.push_back(vector<int>(5));
                        int s=CHANGEMENT.size();
                        CHANGEMENT[s-1][2]=i;
                        CHANGEMENT[s-1][3]=j+RIGHT;
                        CHANGEMENT[s-1][0]=i;
                        CHANGEMENT[s-1][1]=j+RIGHT;
                        CHANGEMENT[s-1][4]=tab[i][j+RIGHT];
                    }

                }
            }
        }
    }
    if (Cherche0())
    {
        CHANGEMENT.push_back(vector<int>(1,1));
    }
    else
    {
        CHANGEMENT.push_back(vector<int>(1,0)); // la partie est finie, donc je l'indique par un 0 à la fin pour la gestion graphique
    }
    return CHANGEMENT;
}




void Jeu::move_up()
{
    if (FIN==0)  // Les cases ne peuvent bouger que si la partie n'est ni gagnee ni perdue
    {
    vector<vector<int>> CHANGEMENT = up();
    if (CHANGEMENT[0].size()>1)
    {
        int N = CHANGEMENT.size();
        for (int i=0;i<N-1;i++)
        {
            int a = CHANGEMENT[i][0];
            int b = CHANGEMENT[i][1];
            int an = CHANGEMENT[i][2];
            int bn = CHANGEMENT[i][3];
            int val = CHANGEMENT[i][4];
            tab[a][b] = 0;
            tab[an][bn] = val;
        }
        if (CHANGEMENT[N-1][0] == 1)
        {
            caseAleatoire();
        }
    }
    if (Score>MeilleurScore)
    {
        MeilleurScore=Score;
    }
    add_historique();
    caseChanged();
    scoreChanged();
    endChanged();
    }
}

void Jeu::move_down()
{
    if (FIN==0)
    {
    vector<vector<int>> CHANGEMENT = down();
    if (CHANGEMENT[0].size()>1)
    {
        int N = CHANGEMENT.size();
        for (int i=0;i<N-1;i++)
        {
            int a = CHANGEMENT[i][0];
            int b = CHANGEMENT[i][1];
            int an = CHANGEMENT[i][2];
            int bn = CHANGEMENT[i][3];
            int val = CHANGEMENT[i][4];
            tab[a][b] = 0;
            tab[an][bn] = val;
        }
        if (CHANGEMENT[N-1][0] == 1)
        {
            caseAleatoire();
        }
    }
    if (Score>MeilleurScore)
    {
        MeilleurScore=Score;
    }
    add_historique();
    caseChanged();
    scoreChanged();
    endChanged();
    }
}

void Jeu::move_left()
{
    if (FIN==0)
    {
    vector<vector<int>> CHANGEMENT = left();
    if (CHANGEMENT[0].size()>1)
    {
        int N = CHANGEMENT.size();
        for (int i=0;i<N-1;i++)
        {
            int a = CHANGEMENT[i][0];
            int b = CHANGEMENT[i][1];
            int an = CHANGEMENT[i][2];
            int bn = CHANGEMENT[i][3];
            int val = CHANGEMENT[i][4];
            tab[a][b] = 0;
            tab[an][bn] = val;
        }
        if (CHANGEMENT[N-1][0] == 1)
        {
            caseAleatoire();
        }
    }
    if (Score>MeilleurScore)
    {
        MeilleurScore=Score;
    }
    add_historique();
    caseChanged();
    scoreChanged();
    endChanged();
    }
}

void Jeu::move_right()
{
    if (FIN==0)
    {
    vector<vector<int>> CHANGEMENT = right();
    if (CHANGEMENT[0].size()>1)
    {
        int N = CHANGEMENT.size();
        for (int i=0;i<N-1;i++)
        {
            int a = CHANGEMENT[i][0];
            int b = CHANGEMENT[i][1];
            int an = CHANGEMENT[i][2];
            int bn = CHANGEMENT[i][3];
            int val = CHANGEMENT[i][4];
            tab[a][b] = 0;
            tab[an][bn] = val;
        }
        if (CHANGEMENT[N-1][0] == 1)
        {
            caseAleatoire();
        }
    }
    if (Score>MeilleurScore)
    {
        MeilleurScore=Score;
    }
    add_historique();
    caseChanged();
    scoreChanged();
    endChanged();
    }
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

QString Jeu::readScore()
{
    return QString::number(Score);
}


QString Jeu::readBestScore()
{
    return QString::number(MeilleurScore);
}


QString Jeu::readEnd()
{
    if (Victoire())
    {
        FIN=1;
        return QString("You win !");
    }
    else
        if(GameOver())
        {
            FIN=1;
            return QString("Game Over");
        }
        else
            return QString("");

}


bool Jeu::Victoire()
{
    bool ans = false;
    for (int i=0;i<taille;i++)
    {
        for (int j=0;j<taille;j++)
        {
            if (tab[i][j]==2048)
            {
                ans = true;
                break;
            }
        }
    }
    return ans;
}

bool Jeu::GameOver()
{
    bool ans = false;
    if (Cherche0()==false) // Dans le cas ou aucune case n'est vide, on regarde si deux cases peuvent fusionner entre elles ou non. Si non, la partie est perdue
    {
        ans = true;
        for (int i=1;i<taille;i++)
        {
            for (int j=0;j<taille;j++)
            {
                if (j<taille-1)
                    if(tab[i][j]==tab[i][j+1])
                        ans=false;
                if (j>0)
                    if(tab[i][j]==tab[i][j-1])
                        ans=false;
                if (i<taille-1)
                    if(tab[i][j]==tab[i+1][j])
                        ans=false;
                if(i>0)
                    if(tab[i][j]==tab[i-1][j])
                        ans=false;
           }
        }
    }
    return ans;
}




void Jeu::stocker()
{
    string const nomFichier("damier.txt");
    ofstream monFlux(nomFichier.c_str());
    if (monFlux)
    {
        for (int i=0;i<taille;i++)
        {
            for (int j=0;j<taille;j++)
            {
                monFlux << tab[i][j] << endl;
            }
        }
        StockerScore();
        Stockerhistorique();
        StockerhistoriqueScore();
    }
    else
    {
        cout << "Erreur  : Impossible d'ouvrir le fichier en ecriture.";
    }
}

void Jeu::reconstruire()
{
    ifstream fichier("damier.txt");

    if(fichier)
    {

        string ligne;
        int i=0;
        int j=0;
        while(getline(fichier, ligne))
        {
            if (j<taille)
            {
                int myint1 = std::stoi(ligne);
                tab[i][j]=myint1;
                j+=1;
            }
            else
            {
                j=0;
                i+=1;
                int myint1 = std::stoi(ligne);
                tab[i][j]=myint1;
                j+=1;
            }

         }
        if (i!=0)
        {
            DestockerScore();
            Destockerhistorique();
            RemiseZeroSauvegardes(); //Une fois la partie chargee, on efface la sauvegarde
            caseChanged();
            scoreChanged();
            endChanged();
        }

     }

}

void Jeu::StockerScore()
{
    string const nomFichier("score.txt");
    ofstream monFlux(nomFichier.c_str());
    if (monFlux)
    {
        monFlux << Score << endl;
    }
    else
    {
        cout << "Erreur  : Impossible d'ouvrir le fichier en ecriture.";
    }
}

void Jeu::DestockerScore()
{
    ifstream fichier("score.txt");

    if(fichier)
    {
        string ligne;
        while(getline(fichier, ligne))
        {
            int myint1 = std::stoi(ligne);
            Score=myint1;
        }
     }
     else
     {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
     }

}

void Jeu::RemiseZeroSauvegardes()
{
    string const nomFichier("damier.txt");
    ofstream monFlux(nomFichier.c_str());
    monFlux.close();
    string const nomFichier2("score.txt");
    ofstream monFlux2(nomFichier2.c_str());
    monFlux2.close();
    string const nomFichier3("historique.txt");
    ofstream monFlux3(nomFichier3.c_str());
    monFlux2.close();
    string const nomFichier4("historiquescore.txt");
    ofstream monFlux4(nomFichier4.c_str());
    monFlux2.close();
}

bool Jeu::TestFusion(int xi, int xj, vector<vector<int> > fusions)
{
    bool test=true;
    int N = fusions.size();
    for (int i=0;i<N;i++)
    {
        if (fusions[i][0]==xi)
        {
            if (fusions[i][1]==xj)
            {
               test=false;
                return test;
            }
        }
    }
    return test;
}

void Jeu::Stockerhistorique()
{
    string const nomFichier("historique.txt");
    ofstream monFlux(nomFichier.c_str());
    if (monFlux)
    {
        int T = historique.size();
        for (int t=0;t<T;t++)
        {
            for (int i=0;i<taille;i++)
            {
                for (int j=0;j<taille;j++)
                {
                    monFlux << historique[t][i][j] << endl;
                }
            }
        }
    }
    else
    {
        cout << "Erreur  : Impossible d'ouvrir le fichier historique en ecriture.";
    }
}

void Jeu::StockerhistoriqueScore()
{
    string const nomFichier("historiquescore.txt");
    ofstream monFlux(nomFichier.c_str());
    if (monFlux)
    {
        int T = historiqueScore.size();
        for (int t=0;t<T;t++)
        {
            monFlux << historiqueScore[t] << endl;
        }
    }
    else
    {
        cout << "Erreur  : Impossible d'ouvrir le fichier historiquescore en ecriture.";
    }
}

void Jeu::Destockerhistorique()
{
    FreeHistorique(); //On efface l'historique de la partie en cours

    //Destockage de l'historique
    ifstream fichier("historique.txt");
    if(fichier)
    {
        int** tab2 = new int *[taille];
        for (int i=0;i<taille;i++)
        {
            tab2[i]=new int[taille];
        }
        string ligne;
        int i=0;
        int j=0;
        while(getline(fichier, ligne))
        {

            int myint1 = std::stoi(ligne);
            if (j<taille)
            {
                tab2[i][j]=myint1;
            }
            else
            {
                j=0;
                i+=1;
                if (i<taille)
                {
                    tab2[i][j]=myint1;
                }
                else
                {
                    int** tab3 = new int *[taille];
                    for (int i=0;i<taille;i++)
                    {
                        tab3[i]=new int[taille];
                    }
                    for (int i=0;i<taille;i++)
                    {
                        for (int j=0;j<taille;j++)
                        {
                            tab3[i][j]=tab2[i][j];
                        }
                    }
                    historique.push_back(tab3);
                    i=0;
                    j=0;
                    tab2[i][j]=myint1;
                }
            }

            j+=1;
        }
        historique.push_back(tab2);
     }
     else
     {
        cout << "ERREUR: Impossible d'ouvrir le fichier historique en lecture." << endl;
     }


    //Destockage historique score
    ifstream fichier2("historiquescore.txt");
    if(fichier2)
    {
        string ligne;
        while(getline(fichier, ligne))
        {
            int myint1 = std::stoi(ligne);
            int s = myint1;
            historiqueScore.push_back(s);
        }
    }
    else
    {
       cout << "ERREUR: Impossible d'ouvrir le fichier historiquescore en lecture." << endl;
    }

}










