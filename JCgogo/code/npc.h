#ifndef NPC_H
#define NPC_H

#include <QImage>
#include <vector>
#include <QPainter>
#include <string>
#include <icon.h>
#include "rpgobj.h"
#include <QObject>
#include <map>

class NPC:public RPGObj
{
public:
    int SpeakingControl(int x,int y);
    int ChangeSP(int x);
    int GetSpeakPro(){
        return SpeakPro;
    }

private:
    static int SpeakPro;
};



#endif // NPC

