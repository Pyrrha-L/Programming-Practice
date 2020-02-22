#include "icon.h"
#include<iostream>
int ICON::GRID_SIZE = 30;


pair<string,ICON> pairArray[] =
{
    make_pair("scene0",ICON("scene0",0,32, 20, 16)),
    make_pair("scene1",ICON("scene1",20,16, 20, 16)),
    make_pair("scene2",ICON("scene2",0,48, 20, 16)),
    make_pair("scene3",ICON("scene3",0,16, 20, 16)),
    make_pair("scene4",ICON("scene4",20,48, 20, 16)),
    make_pair("pkscene1",ICON("pkscene1",40,32, 20, 16)),
    make_pair("pkscene2",ICON("pkscene2",20,32, 20, 16)),

    make_pair("JC",ICON("JC",1,5, 1, 1)),
    make_pair("JCpk1",ICON("JCpk1",20,10, 2, 3)),
    make_pair("JCpk2",ICON("JCpk2",22,10, 2, 3)),
    make_pair("JCpk3",ICON("JCpk3",24,10, 2, 3)),
    make_pair("JCwk1",ICON("JCwk1",20,13, 2, 3)),
    make_pair("npc",ICON("npc",1,6, 1, 1)),    
    make_pair("monster1",ICON("monster1",0,1, 2, 1)),
    make_pair("monster2",ICON("monster2",0,0, 1, 1)),
    make_pair("monster3",ICON("monster3",1,0, 1, 1)),
    make_pair("monster4",ICON("monster4",2,0, 1, 1)),
    make_pair("monster5",ICON("monster5",4,0, 2, 1)),
    make_pair("monsterpk1",ICON("monsterpk1",26,13, 3, 3)),
    make_pair("monsterpk2",ICON("monsterpk2",26,10, 3, 3)),
    make_pair("monsterpk3",ICON("monsterpk3",22,13, 4, 3)),

    make_pair("wine",ICON("wine",18,0, 1, 1)),
    make_pair("mushroom",ICON("mushroom",17,3, 1, 1)),
    make_pair("fruit",ICON("fruit",18,4, 1, 1)),
    make_pair("box",ICON("box",18,3, 1, 1)),

    make_pair("dog",ICON("dog",15,0, 1, 1)),
    make_pair("chicken",ICON("chicken",15,1, 1, 1)),
    make_pair("rabbit",ICON("rabbit",16,0, 1, 1)),
    make_pair("pig",ICON("pig",16,1, 1, 1)),
    make_pair("monkey",ICON("monkey",16,2, 1, 1)),
    make_pair("mouse",ICON("mouse",17,0, 1, 1)),
    make_pair("bull",ICON("bull",17,1, 1, 1)),
    make_pair("tiger",ICON("tiger",17,2, 1, 1)),
    make_pair("dragon",ICON("dragon",18,2, 1, 1)),
    make_pair("horse",ICON("horse",19,0, 1, 1)),
    make_pair("sheep",ICON("sheep",19,1, 1, 1)),
    make_pair("snake",ICON("snake",19,2, 1, 1)),

    make_pair("dialo1",ICON("dialo1",20,0, 10, 5)),
    make_pair("dialo2",ICON("dialo2",20,5, 10, 5)),
    make_pair("spe1",ICON("spe1",30,0, 10, 5)),
    make_pair("spe2",ICON("spe2",30,5, 10, 5)),
    make_pair("spe3",ICON("spe3",40,0, 10, 5)),
    make_pair("spe4",ICON("spe4",40,5, 10, 5)),
    make_pair("spe5",ICON("spe5",50,0, 10, 5)),
    make_pair("spe6",ICON("spe6",50,5, 10, 5)),
    make_pair("spe7",ICON("spe7",50,10, 10, 5)),
    make_pair("spe8",ICON("spe8",40,10, 10, 5)),
    make_pair("spe9",ICON("spe9",40,15, 10, 5)),
    make_pair("spe10",ICON("spe10",40,20, 10, 5)),
    make_pair("spe11",ICON("spe11",50,20, 10, 5)),
    make_pair("spe12",ICON("spe12",50,25, 10, 5)),
    make_pair("spe13",ICON("spe13",60,0, 10, 5)),
    make_pair("spe14",ICON("spe14",60,5, 10, 5)),
    make_pair("spe15",ICON("spe15",60,10, 10, 5)),
    make_pair("spe16",ICON("spe16",60,15, 10, 5)),
    make_pair("spe17",ICON("spe17",60,20, 10, 5)),
    make_pair("spe18",ICON("spe18",60,25, 10, 5)),
    make_pair("not1",ICON("not1",30,10, 10, 5)),
    make_pair("not2",ICON("not2",40,25, 10, 5)),
    make_pair("not3",ICON("not3",50,15, 10, 5))

};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


ICON::ICON(string name, int x, int y, int w, int h){
    this->typeName = name;
    this->srcX = x;
    this->srcY = y;
    this->width = w;
    this->height = h;
}

ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;
    kv = ICON::GAME_ICON_SET.find(type);
    if (kv==ICON::GAME_ICON_SET.end()){

       cout<<"Error: cannot find ICON"<<endl;
       return ICON();
    }
    else{
        return kv->second;
    }
}


