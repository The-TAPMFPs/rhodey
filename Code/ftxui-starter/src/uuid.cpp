#include "uuid.h"

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

//Return uniformly distributed random int in range [min, max] inclusive
int uuid::randomInt(int min, int max)
{
    std::uniform_int_distribution<> uniformDistribution(min, max);
    return uniformDistribution(gen);
}