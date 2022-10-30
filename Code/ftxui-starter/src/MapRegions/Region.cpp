#include "Region.h"

Region::Region() {
  this->uuid = generateUUID();
  this->name = "NaN";
  this->coords = { -1, -1 };
}

Region::Region(std::string name, int xCoord, int yCoord)
    : name(name), coords({ xCoord, yCoord }) {
  generateUUID();
}

Region::Region(int xCoord, int yCoord) : coords({ xCoord, yCoord }) {
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

MapCoords Region::getCoords() {
  return this->coords;
}

void Region::setRegionCoords(int xCoord, int yCoord) {
  this->coords = { xCoord, yCoord };
}

Country* Region::getPossessor()
{
  return this->possessor;
}

RegionUUID Region::generateUUID()
{
  //TODO
  return "a";
}