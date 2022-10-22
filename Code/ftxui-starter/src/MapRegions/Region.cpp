#include "Region.h"

Region::Region() {
    generateUUID();
    this->name = "NaN";
    this->xCoord = INT_MIN;
    this->yCoord = INT_MIN;
}

Region::Region(std::string name, int xCoord, int yCoord), name(name), xCoord(xCoord), yCoord(yCoord) {
    generateUUID();
}

Region::Region(int xCoord, int yCoord), xCoord(xCoord), yCoord(yCoord) {
    generateUUID();
    this->name = "NaN";
}

RegionUUID getUUID() {
    return uuid;
}

std::string getRegionName() {
    return name;
}

void setRegionName(std::string name) {
    this->name = name;
}

int* getCoords() {
    int[] coords = {xCoord, yCoord};
    return coords;
}

void setRegionCoords(int xCoord, int yCoord) {
    this->xCoord = xCoord;
    this->yCoord = yCoord;
}