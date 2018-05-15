#ifndef ENEMY_H
#define ENEMY_H
#include "rpgobj.h"
#include "player.h"
#include<iostream>
#include<QDebug>
using namespace std;

#include<QString>
#include<ctime>
#include<cmath>

class enemy:public RPGObj
{
public:
    enemy():HP(4),direction(1),step(0){
        all.load("F:\\qt\\rpg\\assassin1b.png");
    };
    int get_HP(){return HP;};
    void hurt(int posx,int posy){
        if(abs(posx-this->getPosX())<=1 && abs(posy-this->getPosY())<=1)
        {
            HP--;
        }

    };
    //void srand_move();
    void change_direction(int i){this->direction = i;};
    int get_direction(){return this->direction;};
    int get_step(){return step;};
    void change_step(){
        step++;
        step %= 3;
                      };
    //void set_path(QString path);
    //void debug(){qDebug() << path;}
    void show(QPainter *pa);

private:
    int HP;
    int direction;
    int step;
    QString path;
    QImage all;
    QImage now;
};

#endif // ENEMY_H
