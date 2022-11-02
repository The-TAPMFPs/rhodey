#include "Region.h"

Region::Region()
 : uuid(uuid::generateUUID()), name("R_" + uuid), coords({ uuid::randomInt(0, 99), uuid::randomInt(0, 99) })
{}

Region::Region(std::string name, int xCoord, int yCoord)
    : name(name), coords({ xCoord, yCoord }), uuid(uuid::generateUUID())
{}

Region::Region(int xCoord, int yCoord)
: coords({ xCoord, yCoord }), uuid(uuid::generateUUID()), name("R_" + uuid) //TODO: Generate a proper name
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