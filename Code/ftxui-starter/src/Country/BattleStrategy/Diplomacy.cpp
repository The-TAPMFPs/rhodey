#include "Diplomacy.h"

Diplomacy::Diplomacy(_dip dip){
    this->dip = dip;
}

void Diplomacy::warAlgorithm(){
    switch(dip){
        case su:
            surrender();
            break;
        case pt:
            proposeTreaty();
            break;
    }
    return;
}

void Diplomacy::surrender(){

}

void Diplomacy::proposeTreaty(){
    
}