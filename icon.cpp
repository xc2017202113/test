#include "icon.h"
#include<iostream>
int ICON::GRID_SIZE = 32;//32像素


pair<string,ICON> pairArray[] =
{
    make_pair("player",ICON("player",1,13, 1, 1)),
    make_pair("stone",ICON("stone",4,9, 1, 1)),
    make_pair("fruit",ICON("fruit",3,6, 1, 1)),
    make_pair("tree",ICON("tree",0,9,2,2)),
    make_pair("cactus",ICON("cactus",6,13,1,1)),
    make_pair("enemy",ICON("enemy",4,4,1,1))
};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


ICON::ICON(string name, int x, int y, int w, int h){
    this->typeName = name;
    this->srcX = x;
    this->srcY = y;
    this->width = w;
    this->height = h;
}

ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;//迭代器
    kv = ICON::GAME_ICON_SET.find(type);
    if (kv==ICON::GAME_ICON_SET.end()){

       cout<<"Error: cannot find ICON"<<endl;
       return ICON();
    }
    else{
        return kv->second;
    }
}
