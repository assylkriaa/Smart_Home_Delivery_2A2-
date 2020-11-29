#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include <qpropertyanimation.h>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    MainWindow *w;
    QPropertyAnimation *animation;
};

#endif // DIALOG_H
