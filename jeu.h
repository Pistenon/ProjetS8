#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <QString>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Jeu : public QObject
{
    Q_OBJECT

public:
    explicit Jeu(int taille, QObject *parent = nullptr);
    ~Jeu();

    Q_PROPERTY(QString case00 READ readCase00 NOTIFY caseChanged)
    Q_PROPERTY(QString case01 READ readCase01 NOTIFY caseChanged)
    Q_PROPERTY(QString case02 READ readCase02 NOTIFY caseChanged)
    Q_PROPERTY(QString case03 READ readCase03 NOTIFY caseChanged)
    Q_PROPERTY(QString case10 READ readCase10 NOTIFY caseChanged)
    Q_PROPERTY(QString case11 READ readCase11 NOTIFY caseChanged)
    Q_PROPERTY(QString case12 READ readCase12 NOTIFY caseChanged)
    Q_PROPERTY(QString case13 READ readCase13 NOTIFY caseChanged)
    Q_PROPERTY(QString case20 READ readCase20 NOTIFY caseChanged)
    Q_PROPERTY(QString case21 READ readCase21 NOTIFY caseChanged)
    Q_PROPERTY(QString case22 READ readCase22 NOTIFY caseChanged)
    Q_PROPERTY(QString case23 READ readCase23 NOTIFY caseChanged)
    Q_PROPERTY(QString case30 READ readCase30 NOTIFY caseChanged)
    Q_PROPERTY(QString case31 READ readCase31 NOTIFY caseChanged)
    Q_PROPERTY(QString case32 READ readCase32 NOTIFY caseChanged)
    Q_PROPERTY(QString case33 READ readCase33 NOTIFY caseChanged)
    Q_PROPERTY(QString score READ readScore NOTIFY scoreChanged)
    Q_PROPERTY(QString bestScore READ readBestScore NOTIFY scoreChanged)
    Q_PROPERTY(QString end READ readEnd NOTIFY endChanged)

    QString readCase00();
    QString readCase01();
    QString readCase02();
    QString readCase03();
    QString readCase10();
    QString readCase11();
    QString readCase12();
    QString readCase13();
    QString readCase20();
    QString readCase21();
    QString readCase22();
    QString readCase23();
    QString readCase30();
    QString readCase31();
    QString readCase32();
    QString readCase33();
    QString readScore();
    QString readBestScore();
    QString readEnd();


    Q_INVOKABLE void caseAleatoire();
    Q_INVOKABLE void nouvellePartie();
    Q_INVOKABLE int get_case(int x, int y);
    Q_INVOKABLE void move_up();
    Q_INVOKABLE void move_down();
    Q_INVOKABLE void move_left();
    Q_INVOKABLE void move_right();
    Q_INVOKABLE void cancel();
    Q_INVOKABLE void add_historique();
    Q_INVOKABLE void stocker();
    Q_INVOKABLE void reconstruire();

    void Init();
    vector<vector<int>> up();
    vector<vector<int>> down();
    vector<vector<int>> left();
    vector<vector<int>> right();
    void StockerScore();
    void DestockerScore();
    void RemiseZeroSauvegardes();
    void Stockerhistorique();
    void StockerhistoriqueScore();
    void Destockerhistorique();

signals:
    void caseChanged();
    void scoreChanged();
    void endChanged();

private:
    int **tab;
    int taille ;
    int Score;
    int MeilleurScore;
    int FIN;
    vector<int**> historique; // Répertorie tous les coups joues
    vector<int> historiqueScore; //Répertorie le score total apres chaque coup
    void Free();
    void FreeHistorique();
    int NbreAlea(); // Permet de renvoyer un nombre aléatoire n'excédant pas une certaine borne
    bool Cherche0(); // Permet de cherche s'il reste une place de libre dans le tableau
    bool Victoire(); // Permet de savoir quand la partie est gagnee
    bool GameOver(); // Permet de savoir quand la partie est perdue
    bool TestFusion(int xi,int xj,vector<vector<int>> fusions); //permet de savoir si une case a déjà été fusionné au préalable (une case ne peut fusionner qu'une unique fois)
};

#endif // JEU_H
