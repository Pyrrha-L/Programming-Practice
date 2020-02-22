#include <windows.h>
#include "world.h"
#include "icon.h"

int World::FZPosX=0;
int World::FZPosY=18;
int FZnum=0;
int SceneNo=0;
bool ChangeSce=0;
string DISK="C";//在rpgobj类中也应当修改路径。

string World::coverblepath(){
    if(_PK==1){
        return DISK + "://JCgogo//Scene2//PKcoverable.txt";
    }
    else if(_PK==0&&(SceneNo==1||SceneNo==8)){
        return  DISK + "://JCgogo//Scene2//Scene1cov.txt";
    }
    else if(_PK==0&&SceneNo==2){
        return  DISK + "://JCgogo//Scene2//Scene2cov.txt";
    }
    else if(_PK==0&&SceneNo==4){
        return  DISK + "://JCgogo//Scene2//Scene3cov.txt";
    }
    else if(_PK==0&&SceneNo==6){
        return  DISK + "://JCgogo//Scene2//Scene4cov.txt";
    }
}

void World::addFZ(string type){

    string path,path2,path3;

    if(SceneNo==2||SceneNo==3){
        path=DISK + "://JCgogo//Scene2//Scene3set.txt";
        path2=DISK + "://JCgogo//Scene2//Scene4set.txt";
        path3=DISK + "://JCgogo//Scene2//Scene5set.txt";

        const char * out=path.c_str();
        ofstream fout(out, ios::app);
        fout<<type<<' '<<FZPosX-1<<' '<<FZPosY<<'\n';
        fout.close();

        const char * out2=path2.c_str();
        ofstream fout2(out2, ios::app);
        fout2<<type<<' '<<FZPosX-1<<' '<<FZPosY<<'\n';
        fout2.close();

        const char * out3=path3.c_str();
        ofstream fout3(out3, ios::app);
        fout3<<type<<' '<<FZPosX-1<<' '<<FZPosY<<'\n';
        fout3.close();
    }
    else if(SceneNo==4||SceneNo==5){
        path2=DISK + "://JCgogo//Scene2//Scene4set.txt";
        path3=DISK + "://JCgogo//Scene2//Scene5set.txt";

        const char * out2=path2.c_str();
        ofstream fout2(out2, ios::app);
        fout2<<type<<' '<<FZPosX-1<<' '<<FZPosY<<'\n';
        fout2.close();

        const char * out3=path3.c_str();
        ofstream fout3(out3, ios::app);
        fout3<<type<<' '<<FZPosX-1<<' '<<FZPosY<<'\n';
        fout3.close();

    }
    else if(SceneNo==6||SceneNo==7){
        path3=DISK + "://JCgogo//Scene2//Scene5set.txt";

        const char * out3=path3.c_str();
        ofstream fout3(out3, ios::app);
        fout3<<type<<' '<<FZPosX-1<<' '<<FZPosY<<'\n';
        fout3.close();
    }

    return;
}

void World::initWorld(string mapFile){

    string path=mapFile;
    const char * in=path.c_str();

    ifstream fin(in);

    if(!fin.is_open()){
        cout<<"Can't find file!!"<<endl;
        return;
    }

    bool savesig=0;
    char type[10];
    int PosX,PosY;
    string s;

    while ( getline(fin,s) )
    {
        const char * line=s.c_str();

        sscanf(line,"%s %d %d",&type,&PosX,&PosY);

        if(strcmp(type,"A")==0){
            this->_PK=1;
        }
        else if(strcmp(type,"SceneNo")==0){
            SceneNo=PosX;
            _JC.setjcHP(PosY);
            savesig=1;
        }
        else if(strcmp(type,"AB")==0){
            this->_PK=1;
            FZPosX=PosY;
            _pkmonster.setHP(PosX);
        }
        else if(strcmp(type,"JC")==0||strcmp(type,"JCpk1")==0||strcmp(type,"JCwk1")==0){
            this->_JC.initObj(type);
            this->_JC.setPosX(PosX);
            this->_JC.setPosY(PosY);
        }
        else if(strcmp(type,"monster1")==0||strcmp(type,"monster2")==0||strcmp(type,"monster3")==0||
                strcmp(type,"monster4")==0||strcmp(type,"monster5")==0){
            this->_monster.initObj(type);
            this->_monster.setPosX(PosX);
            this->_monster.setPosY(PosY);
        }
        else if(this->_PK==1&&(strcmp(type,"monsterpk1")==0||strcmp(type,"monsterpk2")==0||strcmp(type,"monsterpk3")==0)){
            this->_pkmonster.initObj(type);
            this->_pkmonster.setPosX(PosX);
            this->_pkmonster.setPosY(PosY);
            if(savesig==0) SetInformation(&_pkmonster, type);
        }
        else if(strcmp(type,"npc")==0){
            this->_npc.initObj(type);
            this->_npc.setPosX(PosX);
            this->_npc.setPosY(PosY);
        }
        else if((strcmp(type,"spe1")==0||strcmp(type,"spe2")==0||strcmp(type,"spe3")==0||
                strcmp(type,"spe4")==0||strcmp(type,"spe5")==0||strcmp(type,"spe6")==0)||
                strcmp(type,"spe7")==0||strcmp(type,"spe8")==0||strcmp(type,"spe9")==0||
                strcmp(type,"spe10")==0||strcmp(type,"spe11")==0||strcmp(type,"not1")==0||
                strcmp(type,"not2")==0||strcmp(type,"spe12")==0||strcmp(type,"spe13")==0||
                strcmp(type,"spe14")==0||strcmp(type,"spe15")==0||strcmp(type,"spe16")==0||
                strcmp(type,"spe17")==0||strcmp(type,"spe18")==0){
            RPGObj obj;
            obj.initObj(type);
            obj.setPosX(PosX);
            obj.setPosY(PosY);
            this->_dialos.push_back(obj);
        }
        else if(strcmp(type,"mouse")==0||strcmp(type,"bull")==0||strcmp(type,"tiger")==0||
                strcmp(type,"rabbit")==0||strcmp(type,"dragon")==0||strcmp(type,"snake")==0||
                strcmp(type,"horse")==0||strcmp(type,"sheep")==0||strcmp(type,"monkey")==0||
                strcmp(type,"chicken")==0||strcmp(type,"dog")==0||strcmp(type,"pig")==0){
            StillObjs * obj = new FuZhou;

            obj->initObj(type);
            obj->setPosX(PosX);
            obj->setPosY(PosY);

            this->_objs.push_back(obj);

        }
        else{
            StillObjs * obj = new StillObjs;

            obj->initObj(type);
            obj->setPosX(PosX);
            obj->setPosY(PosY);
            obj->setInfo(type);

            this->_objs.push_back(obj);
        }
    }

    FZnum=FZPosX;
    return;
}

void World::MonsterMove(){
    string path;
    switch(SceneNo){
        case 2:path=DISK + "://JCgogo//Scene2//Scene2mov.txt";break;
        case 4:path=DISK + "://JCgogo//Scene2//Scene3mov.txt";break;
        case 6:path=DISK + "://JCgogo//Scene2//Scene4mov.txt";break;
        default:return;
    }

    int dir,step,count=0;

    const char * in=path.c_str();

    ifstream fin(in);

    if(!fin.is_open()){
          cout<<"Can't find file~"<<endl;
          return;
    }

    int PosX,PosY;
    string s;

    while ( getline(fin,s) )
    {
         const char * line=s.c_str();

         sscanf(line,"%d %d",&dir,&step);

         if(count==MonMove){
             _monster.move(dir,step);
             MonMove++;
             return;
         }
         else count++;
    }

}

void World::show(QPainter * painter){

    vector<StillObjs *>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it)->show(painter);
    }

    this->_npc.show(painter);
    this->_JC.show(painter);
    this->_monster.show(painter);
    this->_pkmonster.show(painter);

    if(_npc.SpeakingControl(SceneNo,FZnum)==1){
        this->_dialos[_npc.GetSpeakPro()-1].show(painter);

        if(SceneNo==8&&_npc.GetSpeakPro()==2){
            QMediaPlayer * player = new QMediaPlayer;

            string path = DISK + "://JCgogo//Scene2//Success.mp3";
            const char * _path = path.c_str();

            player->setMedia(QUrl::fromLocalFile(_path));
            player->setVolume(30);
            player->play();
        }
    }
    else if(_npc.SpeakingControl(SceneNo,FZnum)==2){
        this->_dialos[_npc.GetSpeakPro()+1].show(painter);

        if(_npc.GetSpeakPro()==2){
            QMediaPlayer * player = new QMediaPlayer;

            string path = DISK + "://JCgogo//Scene2//Fail.mp3";
            const char * _path = path.c_str();

            player->setMedia(QUrl::fromLocalFile(_path));
            player->setVolume(30);
            player->play();
        }
    }

    return;
}

void World::saveRecord(){
    string path;
    path=DISK + "://JCgogo//Scene2//Record.txt";

    const char * out=path.c_str();
    ofstream fout(out, ios::app);
    fout<<"SceneNo"<<' '<<SceneNo<<' '<<_JC.GetjcHP()<<'\n';

    if(_PK==1){
        fout<<"AB"<<' '<<_pkmonster.getHP()<<' '<<FZPosX<<'\n';
    }

    vector<StillObjs *>::iterator it;

    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        fout<<(*it)->getObjType()<<' '<<(*it)->getPosX()<<' '<<(*it)->getPosY()<<'\n';
    }

    vector<RPGObj>::iterator it2;
    for(it2=this->_dialos.begin();it2!=this->_dialos.end();it2++){
        fout<<it2->getObjType()<<' '<<it2->getPosX()<<' '<<it2->getPosY()<<'\n';
    }

    fout<<_JC.getObjType()<<' '<<_JC.getPosX()<<' '<<_JC.getPosY()<<'\n';
    if(_PK==0) fout<<_npc.getObjType()<<' '<<_npc.getPosX()<<' '<<_npc.getPosY()<<'\n';

    if(_PK==1){
        fout<<_pkmonster.getObjType()<<' '<<getMonposX()<<' '<<getMonposY()<<'\n';
    }
    else {
        fout<<_monster.getObjType()<<' '<<getMonposX()<<' '<<getMonposY()<<'\n';
    }


}

void World::PKresult(){
    if(_pkmonster.getHP()<=0){
        this->deathevent(&_pkmonster);
        FZPosX++;
        if(_pkmonster.getObjType()=="monsterpk1"){
            addFZ("mouse");
        }
        else if(_pkmonster.getObjType()=="monsterpk2"){
            addFZ("snake");
        }
        else if(_pkmonster.getObjType()=="monsterpk3"){
            addFZ("chicken");
        }

        string path= DISK + ":/JCgogo/Scene2/Win.mp3";
        const char * _path = path.c_str();

        QMediaPlayer * player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile(_path));
        player->setVolume(30);
        player->play();

        FZnum++;
        SceneNo++;
        ChangeSce=1;
    }
    else if(_JC.GetjcHP()<=0){
        this->deathevent(&_JC);
        _death=1;
    }

    return;
}

void World::SpeakEvent(){
    _npc.ChangeSP(1);

    if(_npc.GetSpeakPro()==8&&SceneNo==1){
        SceneNo=2;
        ChangeSce=1;
        _npc.ChangeSP(2);
    }

    if((_npc.GetSpeakPro()==5&&SceneNo==2)||(_npc.GetSpeakPro()==4&&SceneNo==4)||(_npc.GetSpeakPro()==5&&SceneNo==6)){
        _npc.ChangeSP(2);
    }

    if((_npc.GetSpeakPro()==3&&SceneNo==8)){
        _end=1;

    }
}

bool World::DecideCover(int x,int y){
    string path=this->coverblepath();

    const char * in = path.c_str();

    ifstream fin(in);

    if(!fin.is_open()){
        cout<<"Can't find file~"<<endl;
        return 0;
    }

    int PosX,PosY;
    string s;

    while ( getline(fin,s) )
    {
        const char * line=s.c_str();

        sscanf(line,"%d %d",&PosY,&PosX);

        if(PosX==x&&PosY==y){
            return 1;
        }
    }

    return 0;
}

void World::handlePlayerMove(int direction, int steps){
    int nowX=_JC.getPosX();
    int nowY=_JC.getPosY();
    int nextX=nowX;
    int nextY=nowY;
    int sig=0;

    if((SceneNo==2||SceneNo==4||SceneNo==6)&&((nowX-_monster.getPosX())*(nowX-_monster.getPosX())+(nowY-_monster.getPosY())*(nowY-_monster.getPosY())<=1)){
        SceneNo++;
        ChangeSce=1;
        return;
    }

    if(_PK==1) PKresult();

    switch (direction){
    case 1:
            nextY -= steps;
            break;
    case 2:
            nextY += steps;
            break;
    case 3:
            nextX -= steps;
            break;
    case 4:
            nextX += steps;
            break;
    }

    if((nextX==_npc.getPosX()&&nextY==_npc.getPosY())||(SceneNo==1&&nextX==14)||(SceneNo==8&&nextX==14)){
        SpeakEvent();
        return;
    }

    if(DecideCover(nextX,nextY)){
        this->_JC.move(direction, steps);
    }
    else {
        return;
    }

    if(_JC.getPosX()==_pkmonster.getPosX()+1&&_PK==1){
        if(_JC.getBull()==1&&SceneNo==3){
            attackevent(&_pkmonster,1);
            attackevent(&_JC,1);
        }
        else{
            attackevent(&_pkmonster,2);
            attackevent(&_JC,1);
        }
        return;
    }

    vector<StillObjs *>::iterator it;

    for(it=this->_objs.begin();it!=this->_objs.end();it++){

        if((*it)->getPosX()==nextX&&(*it)->getPosY()==nextY&&(*it)->canEat()==true)
        {
             const char *tmp=(*it)->getObjType().c_str();

             if(strcmp(tmp,"wine")==0||strcmp(tmp,"fruit")==0||strcmp(tmp,"mushroom")==0){
                 _JC.addjcHP((*it)->GetAddHP()+rand()%50);
                 this->_objs.erase(it);

                 (*it)->onErase();

                 delete (*it);
                 break;
             }
             else if(strcmp(tmp,"box")==0){
                 StillObjs * obj = new FuZhou;
                 obj->initObj("bull");
                 obj->setPosX(FZPosX++);
                 obj->setPosY(FZPosY);

                 addFZ("bull");

                 FZnum++;

                 this->_objs.push_back(obj);
                 this->_JC.changeBull();
                 this->_objs.erase(it);
                 break;
             }
             else{
                FZnum++;
                StillObjs * obj = new FuZhou;
                obj->initObj((*it)->getObjType());
                obj->setPosX(FZPosX++);
                obj->setPosY(FZPosY);
                this->_objs.push_back(obj);

                addFZ((*it)->getObjType());

                (*it)->onErase();
                this->_objs.erase(it);
                break;
             }

        }
    }

    return;
}

void World::roundone(){
    int d = 3 + rand()%2;
    if(_pkmonster.getPosX()<16&&_pkmonster.getPosX()>2){
        _pkmonster.move(d,1);
    }
    else if(_pkmonster.getPosX()==16){
        _pkmonster.move(3,1);
    }
    else if(_pkmonster.getPosX()==2){
        _pkmonster.move(4,1);
    }

    return;
}
