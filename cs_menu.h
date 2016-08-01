#ifndef CS_MENU_H
#define CS_MENU_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
class cs_menu;
}

class cs_menu : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit cs_menu(QWidget *parent = 0);
    ~cs_menu();
    
private slots:

    void on_Accept_clicked();

    void on_Refus_clicked();

    void on_pb_clicked();

private:
    Ui::cs_menu *ui;
};

#endif // CS_MENU_H
