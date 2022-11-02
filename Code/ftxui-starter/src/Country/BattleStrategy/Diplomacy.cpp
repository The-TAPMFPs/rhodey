#include "Diplomacy.h"

Diplomacy::Diplomacy(_dip dip){
    this->dip = dip;
}

void Diplomacy::warAlgorithm(){
    switch(dip){
        case suDip:
            surrender();
            break;
        case ptDip:
            proposeTreaty();
            break;
    }
    return;
}

void Diplomacy::surrender(){

}

void Diplomacy::proposeTreaty(){
    
}