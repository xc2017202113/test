#ifndef WORLD_H
#define WORLD_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include<cstdlib>
#include<iostream>
#include <QPainter>
#include<QLabel>
#include<QString>
#include<QFont>
#include "bullets.h"
#include "player.h"
#include "enemy.h"
#include<fstream>
using namespace std;

class World
{
public:
    World(){}
    ~World(){}
    void initWorld(string mapFile);

    void initmap_move(RPGObj obj);
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
         */
    void show(QPainter * painter);
        //显示游戏世界所有对象
    void handlePlayerMove(int direction, int steps);
    //void push_bullets(bullets test);
    void shoot();
    void move_bullet();
    void srand_enemymove();
    void srand_enemy();
    void srand_fruit();
    void iniate_player();
    void record_player();
    void skill();
    int get_grade(){return this->_player.get_grade();}

        //假定只有一个玩家
protected:
    QImage background;

private:
    vector<RPGObj> _objs;//以栈的形式来储存
    Player _player;
    vector<enemy> enemy_obj;
    int map_move[40][40];
    vector<bullets> bullet_obj;
    QLabel lv;
};

#endif // WORLD_H
