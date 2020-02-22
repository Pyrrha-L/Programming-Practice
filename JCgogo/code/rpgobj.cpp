#include "rpgobj.h"
#include <iostream>

void RPGObj::initObj(string type)
{
    if (type.compare("A")==0){
        return;
    }

    if (type.compare("scene0")==0||type.compare("scene1")==0||type.compare("scene2")==0||
       type.compare("scene3")==0||type.compare("scene4")==0||type.compare("pkscene1")==0||
       type.compare("pkscene2")==0){
        this->_coverable = true;
        this->_eatable = false;
    }
    else if (type.compare("JC")==0||type.compare("JCwk1")==0||type.compare("JCpk1")==0||
             type.compare("JCpk2")==0||type.compare("JCpk3")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("monster1")==0||type.compare("monster2")==0||type.compare("monster3")==0||
             type.compare("monster4")==0||type.compare("monster5")==0||type.compare("monsterpk1")==0||
             type.compare("monsterpk2")==0||type.compare("monsterpk3")==0||type.compare("npc")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("wine")==0||type.compare("fruit")==0||type.compare("mushroom")==0||
             type.compare("box")==0){
        this->_coverable = false;
        this->_eatable = true;
    }
    else if (type.compare("dragon")==0||type.compare("sheep")==0||type.compare("snake")==0||
             type.compare("horse")==0||type.compare("dog")==0||type.compare("chicken")==0||
             type.compare("rabbit")==0||type.compare("pig")==0||type.compare("monkey")==0||
             type.compare("mouse")==0||type.compare("bull")==0||type.compare("tiger")==0){
        this->_coverable = false;
        this->_eatable = true;
    }
    else if (type.compare("spe1")==0||type.compare("spe2")==0||type.compare("spe3")==0||
             type.compare("spe4")==0||type.compare("spe5")==0||type.compare("spe6")==0||
             type.compare("spe7")==0||type.compare("not1")==0||type.compare("dialo1")==0||
             type.compare("spe8")==0||type.compare("spe9")==0||type.compare("spe10")==0||
             type.compare("spe11")==0||type.compare("not3")==0||type.compare("not2")==0||
             type.compare("spe12")==0||type.compare("spe13")==0||type.compare("spe14")==0||
             type.compare("spe15")==0||type.compare("spe16")==0||type.compare("spe17")==0||
             type.compare("spe18")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else{
        cout<<type<<endl;
        cout<<"invalid ICON type."<<endl;
        return;
    }

    this->_icon = ICON::findICON(type);
    QImage all;
    all.load("C:/JCgogo/Scene2/Scene2_3.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
}

void RPGObj::show(QPainter * pa){
    int gSize = ICON::GRID_SIZE;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}




