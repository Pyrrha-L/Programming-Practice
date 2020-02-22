#ifndef MONSTERS_H
#define MONSTERS_H

#include <QImage>
#include <QTimer>
#include <QTime>
#include <vector>
#include <QPainter>
#include <string>
#include <icon.h>
#include <rpgobj.h>
#include <map>
#include <movableobjs.h>

class Monsters:public MovableObjs
{
public:
    Monsters(){}
    ~Monsters(){}

    void death(){
        return;
    }

    void attack(int x){
        if(x==1){
            this->setHP(getHP()-300-rand()%20);
        }
        else{
            this->setHP(getHP()-100-rand()%20);
        }

    }

    void setInfo(string type){

        const char * type2=type.c_str();

        if(strcmp(type2,"monsterpk1")==0){
            setHP(1500);
        }
        else if(strcmp(type2,"monsterpk2")==0){
            setHP(800);
        }
        else if(strcmp(type2,"monsterpk3")==0){
            setHP(500);
        }
        return;
    }

private:
    bool _att=0;
    int _att2=0;
};

#endif // MONSTERS

