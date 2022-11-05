#pragma once
#include <string>
#include <sstream>
#include <random>

//The UUID is used for uniquely referencing an entity when, for example, it is stored as a Memento
//Basically it replaces pointer values as a safer way of referencing objects over time
typedef std::string UUID;

//Initialize generators for UUID
static std::random_device              rd;
static std::mt19937                    gen(rd());
static std::uniform_int_distribution<> uuidUniformDistribution(0, 15);

class uuid {
    public:
        static UUID generateUUID();
        static std::string generateName();
        static int randomInt(int min, int max);
};