#ifndef A_MENU_H
#define A_MENU_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
class a_menu;
}

class a_menu : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit a_menu(QWidget *parent = 0);
    ~a_menu();
    
private slots:

    void on_calendar_clicked(const QDate &date);

    void on_cb_currentIndexChanged(int index);

    void on_inscri_clicked();

    void on_nn_clicked();

    void on_pb_clicked();

private:
    Ui::a_menu *ui;
};

#endif // A_MENU_H
