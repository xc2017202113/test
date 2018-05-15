#include "world.h"
#include "icon.h"



void World::initmap_move(RPGObj obj)
{
    //cout<<obj.getPosX()<<endl;
    //cout<<obj.getWidth()<<endl;
    for(int i=obj.getPosX();i<obj.getPosX()+obj.getWidth();i++)
    {
        for(int j=obj.getPosY();j<obj.getHeight()+obj.getPosY();j++)
        {
            //cout<<"test"<<i<<" "<<j<<endl;
            if(obj.getObjType() == "stone" || obj.getObjType() == "tree")
            {
                this->map_move[i][j] = 1;
            }
            else if(obj.getObjType() == "fruit")
            {
                this->map_move[i][j] = 2;
            }
            else if(obj.getObjType() == "cactus")
            {
                this->map_move[i][j] = 3;
            }
            else if(obj.getObjType() == "cactus")
            {
                this->map_move[i][j] = 4;
            }
            else if(obj.getObjType() == "enemy")
            {
                this->map_move[i][j] = 5;
            }
        }
    }
}

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_player.initObj("player");
    this->iniate_player();
    //this->_player.setPosX(5);
    //this->_player.setPosY(5);
    memset(this->map_move,0,sizeof(this->map_move));
    //stone 4 5
    //this->_player.setPosY(5);

    int num_tree = 32;

    for(int i=0;i<=16;i+=2)
    {
        RPGObj obj_tree;
        obj_tree.initObj("tree");
        obj_tree.setPosX(i);
        obj_tree.setPosY(1);
        this->initmap_move(obj_tree);
        this->_objs.push_back(obj_tree);

        obj_tree.setPosY(16);
        this->initmap_move(obj_tree);
        this->_objs.push_back(obj_tree);

        obj_tree.setPosX(0);
        obj_tree.setPosY(i+2);
        this->initmap_move(obj_tree);
        this->_objs.push_back(obj_tree);

        obj_tree.setPosX(16);
        obj_tree.setPosY(i+2);
        this->initmap_move(obj_tree);
        this->_objs.push_back(obj_tree);

        //obj_tree.~RPGObj();
    }
    RPGObj obj1, obj2, obj3, obj5 ;
    enemy obj6,obj4;
    obj1.initObj("stone");
    obj1.setPosX(4);
    obj1.setPosY(3);
    this->initmap_move(obj1);

    obj2.initObj("stone");
    obj2.setPosX(6);
    obj2.setPosY(5);
    this->initmap_move(obj2);

    obj3.initObj("fruit");
    obj3.setPosX(5);
    obj3.setPosY(7);
    this->initmap_move(obj3);


    obj5.initObj("cactus");
    obj5.setPosX(13);
    obj5.setPosY(15);
    this->initmap_move(obj5);

    obj4.initObj("enemy");
    //obj4.set_path("F:\\qt\\rpg\\assassin1b.png");

    obj4.setPosX(6);
    obj4.setPosY(6);
    this->initmap_move(obj4);

    obj6.initObj("enemy");
    //obj6.set_path("F:\\qt\\rpg\\assassin1b.png");
    obj6.setPosX(12);
    obj6.setPosY(10);
    this->initmap_move(obj6);

    cout<<"enemy:"<<obj6.getPosX()<<endl;
    /*for(int i=0;i<=40;i++)
    {

        for(int j=0;j<=40 ;j++)
        {
            cout<<this->map_move[i][j]<<" ";
        }
        cout<<endl;
    }*/

    this->_objs.push_back(obj1);
    this->_objs.push_back(obj2);
    this->_objs.push_back(obj3);
    this->enemy_obj.push_back(obj4);
    this->_objs.push_back(obj5);
    this->enemy_obj.push_back(obj6);
}


void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    this->background.load("F:\\qt\\rpg\\grass.png");
    painter->drawImage(0,0,this->background);
    painter->setBrush(Qt::red);
    //painter->setBackground(QT::red);
    //painter->fillRect();
    QRect word(this->_player.getPosX()*ICON::GRID_SIZE,this->_player.getPosY()*ICON::GRID_SIZE-42,52,20);
    painter->setPen(Qt::black);
    QString lv_show;
    lv_show.setNum(this->_player.get_grade());
    QFont font ( "Microsoft YaHei", 10, 75);

    lv_show.insert(0,"LV:");

    painter->drawText(word,lv_show);

    for(int i=1;i<=this->_player.getHP();i++)
    {
        painter->drawRect(this->_player.getPosX()*ICON::GRID_SIZE-10+i*10,this->_player.getPosY()*ICON::GRID_SIZE-22,10,10);
    }
    painter->setBrush(Qt::blue);
    for(int i=1;i<=this->_player.getpower();i++)
    {
        painter->drawRect(this->_player.getPosX()*ICON::GRID_SIZE-10+i*10,this->_player.getPosY()*ICON::GRID_SIZE-12,10,10);
    }
    painter->setBrush(Qt::yellow);
    for(int i=0;i<=this->_player.get_exp();i++)
    {
        painter->drawRect(this->_player.getPosX()*ICON::GRID_SIZE+i*10,this->_player.getPosY()*ICON::GRID_SIZE-2,10,10);
    }



    vector<bullets>::iterator it2;
    for(it2 = this->bullet_obj.begin() ; it2 != this->bullet_obj.end() ; it2++)
    {
        (*it2).show(painter);
    }

    vector<enemy>::iterator it3;
    painter->setBrush(Qt::red);
    for(it3 = this->enemy_obj.begin() ; it3 != this->enemy_obj.end() ; it3++)
    {
        for(int i=1;i<=(*it3).get_HP();i++)
        {
            painter->drawRect((*it3).getPosX()*ICON::GRID_SIZE+i*10,(*it3).getPosY()*ICON::GRID_SIZE-2,10,10);
        }
        (*it3).show(painter);

    }
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        //cout<<(*it).getPosX()<<" ";
        //cout<<this->_player.getPosX()<<endl;
        if(this->map_move[this->_player.getPosX()][this->_player.getPosY()] == 2 && (*it).getPosX() == this->_player.getPosX() && (*it).getPosY() == this->_player.getPosY())
        {
            this->_objs.erase(it);
            this->map_move[this->_player.getPosX()][this->_player.getPosY()] = 0;
            this->_player.increase_HP();
            break;
        }

            (*it).show(painter);

    }

        this->_player.show(painter);

}

void World::handlePlayerMove(int direction, int steps){

    this->_player.move(direction, steps);
    this->_player.change_direction(direction);
    if(this->map_move[this->_player.getPosX()][this->_player.getPosY()] == 1)
    {
        this->_player.move(direction, steps-2);
    }
    else if(this->map_move[this->_player.getPosX()][this->_player.getPosY()] == 3)
    {
        this->_player.decrease_HP();
        if(this->_player.death() == true)
        {
            this->_player.~Player();
        }
    }
    else if(this->map_move[this->_player.getPosX()][this->_player.getPosY()] == 5)
    {
        this->_player.decrease_HP();
        if(this->_player.death() == true)
        {
            this->_player.setPosX(5);
            this->_player.setPosY(5);
            for(int i=0;i<4;i++)
            {
                this->_player.increase_HP();
            }


        }
    }
}



void World::shoot()
{
    bullets obj1;
    cout<<bullets::direction<<endl;
    switch(bullets::direction)
    {
        case 1:
            obj1.setPosX(this->_player.getPosX());
            obj1.setPosY(this->_player.getPosY()-1);
            obj1.set_direction(1);
            break;
        case 2:
            obj1.setPosX(this->_player.getPosX());
            obj1.setPosY(this->_player.getPosY()+1);
            obj1.set_direction(2);
            break;
        case 3:
            obj1.setPosX(this->_player.getPosX()-1);
            obj1.setPosY(this->_player.getPosY());
            obj1.set_direction(3);
            break;

        case 4:
            obj1.setPosX(this->_player.getPosX()+1);
            obj1.setPosY(this->_player.getPosY());
            obj1.set_direction(4);
            break;
    }

    //obj1.setPosX(this->_player.getPosX());
    //obj1.setPosY(this->_player.getPosY()-1);
    cout<<obj1.getPosX()<<endl;
    //if(this->map_move[obj1.getPosX()][obj1.getPosY()] == 0)
    this->bullet_obj.push_back(obj1);
    //obj1.~bullets();
}

void World::move_bullet()
{
    vector<bullets>::iterator it2;
    vector<enemy>::iterator it3;
    //int corrdiate=0;
    //if(it != NULL)
    //{
        for(it2=this->bullet_obj.begin();it2!=this->bullet_obj.end();it2++)
        {
            if( (*it2).get_step() == (*it2).get_radius() )
            {
                this->bullet_obj.erase(it2);
                break;
            }

            else if(this->map_move[(*it2).getPosX()][(*it2).getPosY()] == 5)//被子弹打中
            {
                for(it3=this->enemy_obj.begin();it3!=this->enemy_obj.end();it3++)
                {
                    (*it3).hurt((*it2).getPosX(),(*it2).getPosY());
                    if((*it3).get_HP() == 0)
                    {
                        this->_player.add_exp();
                        if(this->_player.get_exp() == 4)
                        {//经验到4就升级
                            this->_player.upgrade();
                        }
                        this->map_move[(*it2).getPosX()][(*it2).getPosY() ] = 0;
                        this->enemy_obj.erase(it3);
                        break;
                    }
                }
                this->bullet_obj.erase(it2);
                break;
            }

            else if(this->map_move[(*it2).getPosX()][(*it2).getPosY()] != 0)
            {
                this->bullet_obj.erase(it2);
                break;
            }
            else if(this->map_move[(*it2).getPosX()][(*it2).getPosY()] == 4)
            {
                //for(it3 = this->bullet_obj.begin() ; it3 != this->bullet_obj.end() ; it3++)
                //{
                  //  if((*it3).)
                //}
                this->bullet_obj.erase(it2);
                break;
            }
            else
            {
                (*it2).move();
                switch((*it2).get_direciton())
                {
                    case 1:
                        //corrdiate = (*it2).getPosY;
                        //cout<<"corrdiate"<<endl;
                        (*it2).setPosY( (*it2).getPosY() - 1 );
                        break;
                    case 2:
                        (*it2).setPosY( (*it2).getPosY() + 1 );
                        break;
                    case 3:
                        (*it2).setPosX( (*it2).getPosX() - 1 );
                        break;
                    case 4:
                        (*it2).setPosX( (*it2).getPosX() + 1 );
                        break;
                }

            }
        //}
    }
}

void World::srand_enemymove()
{
    srand((unsigned)time(NULL));
    vector<enemy>::iterator it;
    for(it=this->enemy_obj.begin();it!=this->enemy_obj.end();it++)
    {
        switch((*it).get_direction())
        {
            case 4:
                if( this->map_move[(*it).getPosX()][(*it).getPosY()-1] != 0 )
                {
                    (*it).change_direction(rand()%4+1);
                }
                else
                {

                     this->map_move[(*it).getPosX()][(*it).getPosY()] = 0;


                    (*it).setPosY((*it).getPosY()-1);
                    (*it).change_step();
                    this->initmap_move((*it));
                }
                break;


            case 1:
            if( this->map_move[(*it).getPosX()][(*it).getPosY()+1] != 0)
            {
                (*it).change_direction(rand()%4+1);
            }
            else
            {
                this->map_move[(*it).getPosX()][(*it).getPosY()] = 0;


                (*it).setPosY((*it).getPosY()+1);
                (*it).change_step();
                this->initmap_move((*it));
            }
            break;

        case 2:
            if( this->map_move[(*it).getPosX()-1][(*it).getPosY()] != 0)
            {
                (*it).change_direction(rand()%4+1);
            }
            else
            {
                this->map_move[(*it).getPosX()][(*it).getPosY()] = 0;
                (*it).setPosX((*it).getPosX()-1);
                (*it).change_step();
                this->initmap_move((*it));
            }
            break;

        case 3:
            if( this->map_move[(*it).getPosX()+1][(*it).getPosY()] != 0)
            {
                (*it).change_direction(rand()%4+1);
            }
            else
            {
                this->map_move[(*it).getPosX()][(*it).getPosY()] = 0;

                (*it).setPosX((*it).getPosX()+1);
                (*it).change_step();
                this->initmap_move((*it));
            }
            break;
        }
    }
}

void World::srand_enemy()
{//随机出现敌人
    srand((unsigned)time(NULL));
    enemy obj;
    obj.initObj("enemy");
    //obj.set_path("F:\\qt\\rpg\\assassin1b.png");
    int x=rand()%16+2;
    int y=rand()%16+4;
    while(this->map_move[x][y] != 0 )
    {
        x=rand()%16+2;
        y=rand()%14+4;
    }
    cout<<"x"<<x<<" y"<<y<<endl;
    obj.setPosX(x);
    obj.setPosY(y);
    this->initmap_move(obj);
    this->enemy_obj.push_back(obj);
}

void World::srand_fruit()
{
    srand((unsigned)time(NULL));
    RPGObj obj;
    obj.initObj("fruit");
    int x=rand()%16;
    int y=rand()%16+2;
    while(this->map_move[x][y] != 0 )
    {
        x=rand()%16;
        y=rand()%16+2;
    }
    obj.setPosX(x);
    obj.setPosY(y);
    this->initmap_move(obj);
    this->_objs.push_back(obj);
}

void World::iniate_player()
{
    ifstream infile;
    infile.open("F:\\qt\\rpg\\initiate_player.txt");
    if(!infile.is_open()) exit(0);
    int buff;
    infile>>buff;
    this->_player.setPosX(buff);
    infile>>buff;
    this->_player.setPosY(buff);
    infile>>buff;
    this->_player.set_HP(buff);
    infile>>buff;
    this->_player.set_exp(buff);
    infile>>buff;
    this->_player.set_grade(buff);
    this->_player.fullpower();
}

void World::record_player()
{
    ofstream outfile;
    outfile.open("F:\\qt\\rpg\\initiate_player.txt");
    outfile<<5<<endl;
    outfile<<5<<endl;
    outfile<<this->_player.getHP()<<endl;
    outfile<<this->_player.get_exp()<<endl;
    outfile<<this->_player.get_grade()<<endl;
    //outfile<<this->_player.getpower()<<endl;
}

void World::skill()
{
    if(this->_player.get_grade()>=6 && this->_player.getpower()>0)
    {
        this->_player.decrease_Power();
        for(int i=2;i<=15;i++)
        {
            bullets obj;
            obj.setPosX(i);
            obj.setPosY(3);
            obj.set_direction(2);
            this->bullet_obj.push_back(obj);

            obj.setPosX(i);
            obj.setPosY(15);
            obj.set_direction(1);
            this->bullet_obj.push_back(obj);
        }

        for(int i=3;i<=14;i++)
        {
            bullets obj;
            obj.setPosX(2);
            obj.setPosY(i);
            obj.set_direction(4);
            this->bullet_obj.push_back(obj);

            obj.setPosX(15);
            obj.setPosY(i);
            obj.set_direction(3);
            this->bullet_obj.push_back(obj);
        }
    }
}
