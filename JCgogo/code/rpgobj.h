

#ifndef RPGOBJ
#define RPGOBJ

#include <QImage>
#include <vector>
#include <QPainter>
#include <string>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <icon.h>
#include <map>

using namespace std;
class RPGObj
{
public:
    RPGObj(){}

    void initObj(string type);
    void show(QPainter * painter);

    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}

    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getHeight() const{return this->_icon.getHeight();}
    int getWidth() const{return this->_icon.getWidth();}

    bool canCover() const{return this->_coverable;}
    bool canEat() const{return this->_eatable;}

    virtual void setInfo(string type){
        return;
    }

    string getObjType() const{return this->_icon.getTypeName();}//返回类名
    string getDisk(){
        return DISK2;
    }

protected:
    string DISK2="C";
    int _SceneNo;//出现在第几个场景中
    QImage _pic;
    int _pos_x, _pos_y;//该物体在游戏中当前位置（左上角坐标）
    ICON _icon;//可以从ICON中获取对象的素材，尺寸等信息
    bool _coverable;
    bool _eatable;
};

#endif // RPGOBJ

