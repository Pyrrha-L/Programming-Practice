#include "stillobjs.h"

void StillObjs::setInfo(string type){

    const char * type2=type.c_str();

    if(strcmp(type2,"mushroom")==0){
        _AddHP=100;
    }
    else if(strcmp(type2,"wine")==0){
        _AddHP=80;
    }
    else if(strcmp(type2,"fruit")==0){
        _AddHP=50;
    }
    else{
        _AddHP=0;
    }

    return;
}

void StillObjs::onErase(){
    string path= getDisk() + ":/JCgogo/Scene2/Fruit.mp3";
    const char * _path = path.c_str();

    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(_path));
    player->setVolume(30);
    player->play();
    return;

}
