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

    void on_supprimeragent_clicked();

    void on_pushButton_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();


    void on_ajouter_Ag_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_supprimeragent_3_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_rechercher_3_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_home_5_clicked();

    void on_home_6_clicked();

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














