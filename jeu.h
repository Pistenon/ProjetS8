#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <QString>
#include <vector>
#include <fstream>

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

    Q_INVOKABLE void CaseAleatoire();
    Q_INVOKABLE void nouvellePartie();
    Q_INVOKABLE int get_case(int x, int y);

    void Init();

signals:
    void caseChanged();

private:
    int **tab;
    int taille ;
    int Score;
    int MeilleurScore;
    void Free();
    int NbreAlea(); // Permet de renvoyer un nombre aléatoire n'excédant pas une certaine borne
};

#endif // JEU_H
