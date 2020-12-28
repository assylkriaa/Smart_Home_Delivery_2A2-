#ifndef MODIFIER_H
#define MODIFIER_H
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QModelIndex>
#include"facture.h"



namespace Ui {
class modifier;
}

class modifier : public QDialog
{
    Q_OBJECT

public:
    explicit modifier(QWidget *parent = nullptr);
    ~modifier();
    QString date() const ;
    QString montant() const ;
    QString source() const;
    QString mode() const ;
    int id() const;

void fill_form(int);
void fill_form_recette(int);
    Ui::modifier *ui;
private slots:
    void on_pushButton_clicked();
};

#endif // modifier_H
