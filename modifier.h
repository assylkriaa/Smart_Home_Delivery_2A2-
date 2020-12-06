#ifndef MODIFIER_H
#define MODIFIER_H
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QModelIndex>
#include"facture.h"



namespace Ui {
class Modifier;
}

class Modifier : public QDialog
{
    Q_OBJECT

public:
    explicit Modifier(QWidget *parent = nullptr);
    ~Modifier();
    QString date() const ;
    QString montant() const ;
    QString source() const;
    QString mode() const ;
    int id() const;

void fill_form(int);
void fill_form_recette(int);
    Ui::Modifier *ui;
private slots:
    void on_pushButton_clicked();
};

#endif // MODIFIER_H
