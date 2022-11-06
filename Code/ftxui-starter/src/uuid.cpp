/**
 * \file uuid.cpp
 * \brief Defines the UUID class
 * \author The TransactionAwarePersistenceManagerFactoryProxies
 * \version 1.0
 * \date 6 November 2022
 */

#include "uuid.h"


/**
 * \fn UUID uuid::generateUUID ()
 * \brief multiplies two numbers.
 *
 * \return a unique identifier
 */
UUID uuid::generateUUID()
{
  std::stringstream ss;

  ss << std::hex;

  for (int i = 0; i < 32; i++) {
      ss << uuidUniformDistribution(gen);
  }

  return ss.str();
}

std::string uuid::generateName()
{
    return "";
}

//
/**
 * \fn UUID uuid::randomInt (int min, int max)
 * \brief generates and returns uniformly distributed random int in range [min, max] inclusive.
 *
 * \param min maximunm value that can be returned
 * \param max minimum value that can be returned
 * \return number between min and max
 */
int uuid::randomInt(int min, int max)
{
    std::uniform_int_distribution<> uniformDistribution(min, max);
    return uniformDistribution(gen);
}