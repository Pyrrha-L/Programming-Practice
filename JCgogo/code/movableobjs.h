#ifndef MOVABLEOBJS
#define MOVABLEOBJS

#include <QImage>
#include <vector>
#include <QPainter>
#include <string>
#include <icon.h>
#include <rpgobj.h>
#include <map>

//第一层继承
class MovableObjs:public RPGObj
{
public:
    MovableObjs(){}
    ~MovableObjs(){}

    void setHP(int x){this->_HP=x;}
    int getHP(){return this->_HP;}

    virtual void attack(int x){
        return;
    }

    virtual void death(){
        return;
    }

    void move(int direction, int steps=1);

private:
    int _HP;
};

#endif // MOVABLEOBJS

