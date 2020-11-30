#ifndef AGENT_H
#define AGENT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class Agent;
}

class Agent : public QDialog
{
    Q_OBJECT

public:
    explicit Agent(QWidget *parent = nullptr);
    ~Agent();
    void setnom(QString );
    void setprenom(QString );
    void setcin(QString);
    void setmdp(QString);
    void setno(QString );
    void setadresse(QString );
    void setci(QString);
    void setdon(QString);

    QString getnom(){
        return this->nom;
    }
    QString getcin(){
        return this->cin;
    }
    QString getmdp(){
        return this->mdp;
    }
    QString getprenom(){
        return this->prenom;
    }
    QString getno(){
        return this->no;
    }
    QString getci(){
        return this->ci;
    }
    QString getdon(){
        return this->don;
    }
    QString getadresse(){
        return this->adresse;
    }



private slots:

    void on_ajouter_Ag_clicked();


    void on_lineEdit_mdp_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::Agent *ui;

    QString nom,prenom,ci,no,adresse,don;
    QString cin;
    QString mdp;
    QSqlTableModel *modal;
};

void addValues(QString cin,QString nom,QString prenom,QString mdp);
void updateValues(QString cin,QString nom,QString prenom,QString mdp);
void supprimeragent(QString cin);
#endif // AGENT_H

