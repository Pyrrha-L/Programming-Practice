#include "npc.h"

int NPC::SpeakPro=0;

int NPC::ChangeSP(int x){
    switch(x){
    case 1:SpeakPro++;break;
    case 2:SpeakPro=0;break;
    default:return 0;
    }

    return 0;
}

int NPC::SpeakingControl(int x,int y){
    switch(x){
    case 1:
        if(SpeakPro<8&&SpeakPro!=0){
            return 1;
        }
    case 2:
        if(SpeakPro<5&&SpeakPro!=0){
            return 1;
        }
    case 4:
        if(SpeakPro<4&&SpeakPro!=0){
            return 1;
        }
    case 6:
        if(SpeakPro<5&&SpeakPro!=0){
            return 1;
        }
    case 8:
        if(SpeakPro<3&&SpeakPro!=0&&y==12){
            return 1;
        }
        else if(SpeakPro<3&&SpeakPro!=0&&y!=12){
            return 2;
        }
    default:return 0;
    }
}
