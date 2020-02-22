#include "fuzhou.h"

void FuZhou::onErase(){
    string path= getDisk() + ":/JCgogo/Scene2/FuZhou.mp3";
    const char * _path = path.c_str();

    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(_path));
    player->setVolume(30);
    player->play();
    return;
}
