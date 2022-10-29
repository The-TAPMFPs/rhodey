#include "Region.h"

Region::Region() {
  generateUUID();
  this->name = "NaN";
  this->xCoord = -1;
  this->yCoord = -1;
}

Region::Region(std::string name, int xCoord, int yCoord)
    : name(name), xCoord(xCoord), yCoord(yCoord) {
  generateUUID();
}

Region::Region(int xCoord, int yCoord) : xCoord(xCoord), yCoord(yCoord) {
  generateUUID();
  this->name = "NaN";
}

RegionUUID Region::getUUID() {
  return uuid;
}

std::string Region::getRegionName() {
  return name;
}

void Region::setRegionName(std::string name) {
  this->name = name;
}

int* Region::getCoords() {
  return new int[2] {xCoord, yCoord};
}

void Region::setRegionCoords(int xCoord, int yCoord) {
  this->xCoord = xCoord;
  this->yCoord = yCoord;
}

RegionUUID Region::generateUUID()
{
  return nullptr;
}