#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmovie.h"
#include "QMovie"
#include "e_menu.h"
#include "cs_menu.h"
#include <QMessageBox>
#include "a_menu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BT_Login_clicked()
{
    QString cin,pwd;

    cin=ui->LN_CIN->text();
    pwd=ui->LN_PWD->text();



QSqlQuery qry;
QSqlQuery qry2;
qry2.prepare("DELETE FROM `connected`");
qry2.exec();
    QSqlQuery qry1;
    qry.prepare("SELECT * FROM `employe` WHERE `cin` = '"+cin+"' AND `password` = '"+pwd+"'");
    if (qry.exec())
    {

        if (qry.next())
        {

            qry1.prepare("INSERT INTO `connected` values('"+qry.value(0).toString()+"','"+qry.value(1).toString()+"','"+qry.value(2).toString()+"','"+qry.value(3).toString()+"','"+qry.value(4).toString()+"','"+qry.value(5).toString()+"','"+qry.value(6).toString()+"','"+qry.value(7).toString()+"','"+qry.value(8).toString()+"')");
            QString CIN1=qry.value(3).toString();
            qry1.exec();
            qry.prepare("SELECT grade FROM employe WHERE CIN = '"+CIN1+"'");
            qry.exec();
            qry.next();

            QString grade=qry.value(0).toString();
            if (grade=="1")
            {
                e_menu *menu = new e_menu;
                setCentralWidget(menu);
            }
            else if (grade=="2")
            {

                cs_menu *menu1 = new cs_menu;
                setCentralWidget(menu1);
            }
            else if (grade=="3")
            {
                a_menu *menu2= new a_menu;
                setCentralWidget(menu2);
            }
        }
        else
            QMessageBox::information(0,qApp->tr("ERREUR"),qApp->tr("Compte non Trouver !"),QMessageBox::Close);
    }
}

void MainWindow::on_pb_clicked()
{
 qApp->closeAllWindows();
}
