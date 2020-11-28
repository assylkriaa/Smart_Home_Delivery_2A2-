#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_perso_conge.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
son=new QSound("C:/Users/oumayma/Desktop/oxp.wav");

        animation =new QPropertyAnimation(ui->label,"geometry");
                animation->setDuration(1000);
                animation->setStartValue(ui->label->geometry());
                animation->setEndValue(QRect(900,20,81,50));

                animation2 =new QPropertyAnimation(ui->label,"geometry");
                animation2->setDuration(1000);
              //  animation2->setStartValue(ui->label->geometry());
                 animation2->setStartValue(QRect(900,20,81,50));
                animation2->setEndValue(QRect(900,550,81,50));

                 animation1 =new QPropertyAnimation(ui->label,"geometry");
                animation1->setDuration(1000);
               // animation1->setStartValue(ui->label->geometry());
                 animation1->setStartValue(QRect(900,550,81,50));
                animation1->setEndValue(QRect(40,550,81,50));


                animation3 =new QPropertyAnimation(ui->label,"geometry");
                    animation3->setDuration(1000);
               // animation3->setStartValue(ui->label->geometry());
                  animation3->setStartValue(QRect(40,550,81,50));
                animation3->setEndValue(QRect(40,20,81,50));
               animgrp= new QSequentialAnimationGroup;
               animgrp->addAnimation(animation);
                animgrp->addAnimation(animation2);
                 animgrp->addAnimation(animation1);
                  animgrp->addAnimation(animation3);
                  animgrp->setLoopCount(2);
                  animgrp->start();







}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

son->play();
    p = new gestion_perso_conge(this);
    p->show();

}
