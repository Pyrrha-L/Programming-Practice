#ifndef FUZHOU_H
#define FUZHOU_H

#include <QImage>
#include <vector>
#include <QPainter>
#include <string>
#include <icon.h>
#include "rpgobj.h"
#include "stillobjs.h"
#include <map>

class FuZhou:public StillObjs
{
public:
    FuZhou(){}
    ~FuZhou(){}

    void onErase();

private:

};

#endif // FUZHOU_H
