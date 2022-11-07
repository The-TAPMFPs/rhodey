
#include "Region.h"
/**
 * \file Region.cpp
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \date 7 November 2022
 */


//Map is 100x100, tiles are 2x4, therefore possible region locations (0,0) to (49, 24)
/**
 * \fn void Region::Region ()
 * \brief constructs a region with a with the name of its UUID on with a random locaiton on the map
 * \param name() the uuid of the region 
 * \param coords() the co-ordinates od the region
 */
Region::Region()
 : uuid(uuid::generateUUID()), name("R_" + uuid), coords({ uuid::randomInt(0, 49), uuid::randomInt(0, 24) })
{}

/**
 * \fn Region::Region (std::string name, std::pair<int, int> coords)
 * \brief construction a region with the name and coordinates provided
 * 
 * \param name the name of the region
 * \param xCoord the x coordinate of the region
 * \param yCoord the y coordinate of the region
*/
Region::Region(std::string name, int xCoord, int yCoord)
    : name(name), coords({ xCoord, yCoord }), uuid(uuid::generateUUID())
{}

/**
 * \fn Region::Region (int xCoord, int yCoord)
 * \brief constructs a region of a random name with the coordinates provided
 * 
 * \param xCoord the x coordinate of the region
 * \param yCoord the y coordinate of the region
*/
Region::Region(int xCoord, int yCoord)
: coords({ xCoord, yCoord }), uuid(uuid::generateUUID()), name("R_" + uuid) //TODO: Generate a proper name
{}

/**
 * \fn Region::getUUUI ()
 * 
 * \return the UUID of the region
*/
UUID Region::getUUID() {
  return uuid;
}

/**
 * \fn std::string Region::getName ()
 * 
 * \return the name of the region
*/
std::string Region::getRegionName() {
  return name;
}

/**
 * \fn void Region::setRegionName (std::string name)
 * \brief sets the name of the region
 * \param name the name of the region
*/
void Region::setRegionName(std::string name) {
  this->name = name;
}

/**
 * \fn MapCoords Region::getCoords ()
 * \brief get coords of a region 
 * \return the coordinates of the region
*/
MapCoords Region::getCoords() {
  return this->coords;
}

/**
 * \fn void Region::setRegionCoords (int xCoord, int yCoord)
 * \brief sets the region co-ordinates 
 * \param xCoord the x coordinate of the region
 * \param yCoord the y coordinate of the region
*/
void Region::setRegionCoords(int xCoord, int yCoord) {
  this->coords = { xCoord, yCoord };
}

/**
 * \fn Country* Region::getPossessor()
 * \brief gets the possessor of a country 
 * \return the owner Country of the region
*/
Country* Region::getPossessor()
{
  return this->possessor;
}