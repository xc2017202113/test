#ifndef PLAYER_H
#define PLAYER_H
#include "rpgobj.h"
#include "bullets.h"

class Player: public RPGObj
{
public:
    Player():HP(4),exp(0),grade(0),step(0),power(4){
        all.load("F:\\qt\\rpg\\boss2a.png");
    }
    ~Player(){}
    void move(int direction, int steps=1);
        //direction =1,2,3,4 for 上下左右
    void decrease_HP() {HP--;};
    void decrease_Power(){power-=2;}
    int getpower(){return power;}

    void increase_HP(){HP++;};
    int getHP() {return HP;};
    bool death()
    {
        if(HP == 0 )
            return true;

        else return false;
    }
    int get_exp() const{return exp;};
    void add_exp(){exp++;};
    void upgrade();
    int get_grade() const{return grade;};
    void set_HP(int i){HP=i;};
    void set_exp(int i){exp=i;};
    void set_grade(int i){grade=i;};


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
    void fullpower(){power=4;}

private:
    int HP;
    int exp;
    int grade;
    int direction;
    int step;
    int power;
    QImage all;
    QImage now;
};

#endif // PLAYER_H
