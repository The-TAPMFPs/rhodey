#include "Offensive.h"

Offensive::Offensive(_off off){
    this->off = off;
}

void Offensive::warAlgorithm(){
    switch(off){
        case red:
            redistributeTroops();
            break;
        case att:
            attack();
            break;
    }
    return;
}

void Offensive::redistributeTroops(){

}

void Offensive::attack(){

}
