#ifndef MW1_H
#define MW1_H

#include <QMainWindow>
#include <QImage>
#include <QTime>
#include <QTimer>
#include <QPainter>
#include<QKeyEvent>
#include "rpgobj.h"
#include "world.h"
#include "bullets.h"

namespace Ui {
class MW1;
}

class MW1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MW1(QWidget *parent = 0);
    ~MW1();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);


protected slots:
    void move_bullets();
    void move_enemy();
    void enemy_show();
    void fruit_show();

private:
    Ui::MW1 *ui;
    World _game;
    QTimer  *timer1;
    QTimer *timer2;
    QTimer *timer3;//随机出现敌人的时间
    QTimer *timer4;//随机出现水果
};

#endif // MW1_H
