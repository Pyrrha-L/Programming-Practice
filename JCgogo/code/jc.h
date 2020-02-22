#ifndef JC_H
#define JC_H

#include <QImage>
#include <vector>
#include <QPainter>
#include <string>
#include <icon.h>
#include <rpgobj.h>
#include <map>
#include <movableobjs.h>

class JC:public MovableObjs
{
public:
    JC(){}
    ~JC(){}

    void changeBull(){
        Bull=1;
    }

    bool getBull(){
        return Bull;
    }

    void attack(int x){
        jcHP-=(50+rand()%20);

        string path= getDisk() + ":/JCgogo/Scene2/Attack.mp3";
        const char * _path = path.c_str();

        QMediaPlayer * player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile(_path));
        player->setVolume(30);
        player->play();
        return;
    }

    void addjcHP(int x){
        jcHP+=x;
        return;
    }

    void setjcHP(int x){
        jcHP=x;
    }

    void death(){
        string path= getDisk() + ":/JCgogo/Scene2/Dead.mp3";
        const char * _path = path.c_str();
        QMediaPlayer * player = new QMediaPlayer;

        player->setMedia(QUrl::fromLocalFile(_path));
        player->setVolume(30);
        player->play();

        return;
    }

    int GetjcHP(){
        return jcHP;
    }



private:
    static int jcHP;
    static bool Bull;
};

#endif // JC_H

