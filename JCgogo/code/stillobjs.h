#ifndef STILLOBJS_H
#define STILLOBJS_H

#include <QImage>
#include <vector>
#include <QPainter>
#include <string>
#include <icon.h>
#include <rpgobj.h>
#include <map>

class StillObjs:public RPGObj
{
public:
    StillObjs(){}
    ~StillObjs(){}

    int GetAddHP(){
        return _AddHP;
    }

    void SetAddHP(int x){
        _AddHP=x;
    }

    void setInfo(string type);

    virtual void onErase();

private:
    int _AddHP=0;
};

#endif // STILLOBJS_H
