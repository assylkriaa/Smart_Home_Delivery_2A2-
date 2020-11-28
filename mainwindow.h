#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gestion_perso_conge.h"
#include <QMainWindow>
#include<QPropertyAnimation>
#include<QSequentialAnimationGroup>
#include <QSound>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    gestion_perso_conge *p;
    QPropertyAnimation *animation ;
    QPropertyAnimation *animation1;
        QPropertyAnimation *animation2;
        QPropertyAnimation *animation3;
        QSequentialAnimationGroup * animgrp;
        QSound *son;

};
#endif // MAINWINDOW_H
