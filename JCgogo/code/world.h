#ifndef WORLD
#define WORLD

#include "rpgobj.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <sstream>
#include <QPainter>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "jc.h"
#include "npc.h"
#include "monsters.h"
#include "stillobjs.h"
#include "fuzhou.h"
#include <QWidgetData>
#include <QTime>
#include <QTimer>

using namespace std;

extern int FZnum;
extern int SceneNo;
extern bool ChangeSce;
extern string DISK;

class World
{
public:
    World(){}
    ~World(){}

//    static int SpeakPro;
    static int FZPosX,FZPosY;//控制吃掉符咒后符咒显示在窗口下方的位置

    bool getPK(){
        return _PK;
    }
    bool getEnd(){
        return _end;
    }

    void SpeakingControl();
    void SpeakEvent();
    bool DecideCover(int x,int y);
    string coverblepath();

    int getMonposX(){
        return (_PK==1)?_pkmonster.getPosX():_monster.getPosX();
    }

    int getMonposY(){
        return (_PK==1)?_pkmonster.getPosY():_monster.getPosY();
    }

    void addFZ(string type);
    void initWorld(string mapFile);
    void show(QPainter * painter);
    void handlePlayerMove(int direction, int steps);
    void MonsterMove();
    int getjcHP(){
        return _JC.GetjcHP();
    }
    int getMonsterHP(){
        return _pkmonster.getHP();
    }

    void SetInformation(RPGObj * ptr,string str){
        ptr->setInfo(str);
    }

    void attackevent(MovableObjs * ptr,int x){
        ptr->attack(x);
    }

    void deathevent(MovableObjs * ptr){
        ptr->death();
    }

//    int operator - (int x);

/*    void subjcHP(int x){
        jcHP-=x;
        return;
    }*/
/*    bool getEnd(){
        return _end;
    }*/
    bool getDeath(){
        return _death;
    }

    void roundone();
    void saveRecord();
    void PKresult();
private:
    int MonMove=0;
    int addHP=0;
//    static int jcHP;
    bool _note=0;
    bool _PK=0;
    bool _end=0;
    bool _death=0;
    vector<StillObjs *> _objs;
    vector<RPGObj> _dialos;
    Monsters _pkmonster;
    Monsters _monster;
    NPC _npc;
    JC _JC;
};

#endif // WORLD

