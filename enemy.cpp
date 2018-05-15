#include "enemy.h"

void enemy::show(QPainter *pa)
{
    this->now=this->all.copy(this->step*ICON::GRID_SIZE,(this->direction-1)*ICON::GRID_SIZE,this->getWidth()*ICON::GRID_SIZE,this->getHeight()*ICON::GRID_SIZE);
    pa->drawImage(this->getPosX()*ICON::GRID_SIZE,this->getPosY()*ICON::GRID_SIZE,this->now);
}

//void enemy::set_path(QString path)
//{
  //  this->path = path;
//}
