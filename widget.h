#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void keyPressEvent(QKeyEvent* event);
    void appear();
    void eachfromleft();
    void left();
    void eachfromright();
    void right();
    void eachfromup();
    void up();
    void eachfromdown();
    void down();
    void check();
    void changecolor();
    void pause();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QLabel* box[16];
    QString bc[16];
    QString obstacle[5];
    int score;
    int count;
    int countdown;
    QString judge[16];
    int fromleft[4][4];
    int fromright[4][4];
    int fromup[4][4];       //從上面數下來
    int fromdown[4][4];     //從下面數上來
};

#endif // WIDGET_H
