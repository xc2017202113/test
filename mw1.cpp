#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"

#include <map>
#include <iostream>

using namespace std;

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);
    this->resize(600,600);
    //init game world
    _game.initWorld("");//TODO 应该是输入有效的地图文件
    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(move_bullets()));//timeoutslot()为自定义槽
    //timer2->start(10);
    timer1->start(10);

    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(move_enemy()));//timeoutslot()为自定义槽
    //timer2->start(10);
    timer2->start(400);

    timer3 = new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(enemy_show()));//timeoutslot()为自定义槽
    //timer2->start(10);
    timer3->start(5000-100*this->_game.get_grade());

    timer4 = new QTimer(this);
    connect(timer4,SIGNAL(timeout()),this,SLOT(fruit_show()));//timeoutslot()为自定义槽
    //timer2->start(10);
    timer4->start(50000);
}

MW1::~MW1()
{
    delete ui;
}

void MW1::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    this->_game.show(pa);
    pa->end();
    //this->repaint();
    delete pa;
}

void MW1::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove(2,1);

    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handlePlayerMove(4,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handlePlayerMove(1,1);
    }
    if(e->key() == Qt::Key_J)
    {
        this->_game.shoot();
    }
    if(e->key() == Qt::Key_M)
    {
        //ofstream outfile;
        //outfile.open("F:\\qt\\rpg\\initiate_player.txt");
        this->_game.record_player();
    }
    if(e->key() == Qt::Key_L)
    {
        //ofstream outfile;
        //outfile.open("F:\\qt\\rpg\\initiate_player.txt");
        this->_game.skill();
    }
    this->repaint();
}



void MW1::move_bullets()
{
    this->_game.move_bullet();
    this->repaint();
}

void MW1::move_enemy()
{
    this->_game.srand_enemymove();
    this->repaint();
}

void MW1::enemy_show()
{
    this->_game.srand_enemy();
    this->repaint();
}

void MW1::fruit_show()
{
    this->_game.srand_fruit();
    this->repaint();
}
