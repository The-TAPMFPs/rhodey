#include "Region.h"

//Map is 100x100, tiles are 2x4, therefore possible region locations (0,0) to (49, 24)
Region::Region(Country* possessor)
 : uuid(uuid::generateUUID()), name("R_" + uuid), coords({ uuid::randomInt(0, 49), uuid::randomInt(0, 24) }), possessor(possessor)
{}

Region::Region(std::string name, int xCoord, int yCoord, Country* possessor)
    : name(name), coords({ xCoord, yCoord }), uuid(uuid::generateUUID()), possessor(possessor)
{}

Region::Region(int xCoord, int yCoord, Country* possessor)
: coords({ xCoord, yCoord }), uuid(uuid::generateUUID()), name("R_" + uuid), possessor(possessor) //TODO: Generate a proper name
{}

UUID Region::getUUID() {
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