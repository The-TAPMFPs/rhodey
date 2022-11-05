#include "Offensive.h"

Offensive::Offensive(_off off){
    this->off = off;
}

void Offensive::warAlgorithm(){
    switch(off){
        case redOff:
            redistributeTroops();
            break;
        case attOff:
            attack();
            break;
    }
    return;
}

void Offensive::redistributeTroops(){

}

void Offensive::attack(){

}
