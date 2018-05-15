#include "player.h"
#include<iostream>

//direction =1,2,3,4 for 上下左右
void Player::move(int direction, int steps){
    switch (direction){
        case 4:
            this->_pos_y -= steps;
            this->change_step();
            bullets::direction = 1;
            break;
        case 1:
            this->_pos_y += steps;
            this->change_step();
            bullets::direction = 2;
            break;
        case 2:
            this->_pos_x -= steps;
            this->change_step();
            bullets::direction = 3;
            break;
        case 3:
            this->_pos_x += steps;
            this->change_step();
            bullets::direction = 4;
            break;
    }
}

void Player::upgrade()
{
    this->grade++;
    bullets::change_radius(1);
    this->exp = 0;
    this->HP++;
    this->fullpower();
}

void Player::show(QPainter *pa)
{
    //std::cout<<this->get_step()<<endl;
    //std::cout<<this->get_direction()<<endl;
    this->now=this->all.copy(this->step*ICON::GRID_SIZE,(this->direction-1)*ICON::GRID_SIZE,this->getWidth()*ICON::GRID_SIZE,this->getHeight()*ICON::GRID_SIZE);
    pa->drawImage(this->getPosX()*ICON::GRID_SIZE,this->getPosY()*ICON::GRID_SIZE,this->now);
}
