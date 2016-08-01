#include "a_menu.h"
#include "ui_a_menu.h"
#include "mainwindow.h"
#include <QMessageBox>

a_menu::a_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::a_menu)
{
    ui->setupUi(this);

    QSqlQuery qry;
    qry.prepare("SELECT * FROM `connected`");
    if (qry.exec())
    {

        if (qry.next())
        {
            ui->nom_e->setText(qry.value(1).toString());
            ui->img->setPixmap(qry.value(8).toString());
        }
    }

    QSqlQuery qry1;
    qry1.prepare("SELECT * FROM `demande` WHERE etat_for='accepter' AND etat !='complet'");
    if (qry1.exec())
    {

        while(qry1.next())
        {
            ui->cb->addItem(qry1.value(1).toString()+" "+qry1.value(2).toString());
        }
    }
    QSqlQuery qry2;
    QString nom11,nom1,prn1;
    int test=0;
    nom11=ui->cb->currentText();

    for(int i=0;i<nom11.length();i++)
    {
        if(test==1)
            prn1+=nom11[i];
        if(nom11[i]==' ')
        {
            test=1;
        }
        if(test==0)
            nom1+=nom11[i];
    }    
}

a_menu::~a_menu()
{
    delete ui;
}

void a_menu::on_calendar_clicked(const QDate &date)
{
     QSqlQuery qry1;
     qry1.prepare("SELECT * FROM `catalogue`");
     if (qry1.exec())
     {
    int dmonth=date.month();
    int dyear=date.year();
         while(qry1.next())
         {

             QString cday,cmonth,cyear;
             QString st=qry1.value(4).toString();
             for(int i=0;i<st.length();i++)
                { if(i<2)
                     cday+=st[i];
             if(i>2 && i<5)
                 cmonth+=st[i];
             if(i>5)
                 cyear+=st[i];
         }
             int day,year,month;
             day=cday.toInt();
             month=cmonth.toInt();
             year=cyear.toInt();
             QString fch="Nom Formation : "+qry1.value(1).toString()+"\nA Propos :"+qry1.value(3).toString()+"\nDate Debut Session : "+qry1.value(4).toString()+"\nDate Fin Session : "+qry1.value(5).toString();
                 QDate d(year, month, day);
                 if((dyear==year)&&(dmonth==month)){
                 ui->cata->setText(fch);
                 break;
             }
             else
                 ui->cata->setText("Aucune Formation Disponible \nContacter Les Centres de Formation  Pour");
         }
     }
}

void a_menu::on_cb_currentIndexChanged(int index)
{
    QSqlQuery qry2;
    QString nom11,nom1,prn1;
    int test=0;
    nom11=ui->cb->currentText();
    for(int i=0;i<nom11.length();i++)
    {
        if(test==1)
            prn1+=nom11[i];
        if(nom11[i]==' ')
        {
            test=1;
        }
        if(test==0)
            nom1+=nom11[i];
    }
    qry2.prepare("SELECT * FROM `demande` WHERE nom='"+nom1+"' AND prenom='"+prn1+"'");
    if (qry2.exec())
    {

        if(qry2.next())
        {   QString tp=qry2.value(3).toString();
            ui->date_for_2->setText(tp);
            ui->date_for->setText(qry2.value(4).toString());
        }
    }
}

void a_menu::on_inscri_clicked()
{
    QSqlQuery qry2,qry;
    QString nom11,nom1,prn1;
    int test=0;
    QString st;
    nom11=ui->cb->currentText();
    for(int i=0;i<nom11.length();i++)
    {
        if(test==1)
            prn1+=nom11[i];
        if(nom11[i]==' ')
        {
            test=1;
        }
        if(test==0)
            nom1+=nom11[i];
    }
    qry2.prepare("SELECT * FROM `demande` WHERE nom='"+nom1+"' AND prenom='"+prn1+"'");
    if (qry2.exec())
    {

        if(qry2.next())
        {
            st=qry2.value(6).toString();

            qry.prepare("update demande set etat = 'complet' where nom = '"+nom1+"' AND prenom='"+prn1+"'");
            qry.exec();
        }
        QMessageBox::information(0,qApp->tr("Information"),qApp->tr("Employe Inscrit"),QMessageBox::Close);
    }
}

void a_menu::on_nn_clicked()
{
    QSqlQuery qry2,qry;
    QString nom11,nom1,prn1;
    int test=0;
    QString st;
    nom11=ui->cb->currentText();
    for(int i=0;i<nom11.length();i++)
    {
        if(test==1)
            prn1+=nom11[i];
        if(nom11[i]==' ')
        {
            test=1;
        }
        if(test==0)
            nom1+=nom11[i];
    }
    qry2.prepare("SELECT * FROM `demande` WHERE nom='"+nom1+"' AND prenom='"+prn1+"'");
    if (qry2.exec())
    {

        if(qry2.next())
        {
            qry.prepare("update demande set etat = 'refuser' where nom = '"+nom1+"' AND prenom='"+prn1+"'");
            qry.exec();
        }
        QMessageBox::information(0,qApp->tr("Information"),qApp->tr("Employe Non Inscrit"),QMessageBox::Close);
    }
}

void a_menu::on_pb_clicked()
{
    MainWindow *menu = new MainWindow;
    setCentralWidget(menu);
}
