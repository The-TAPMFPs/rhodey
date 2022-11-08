#include "NarrativeBuilder.h"

//Pick a random string from the provided vector
std::string NarrativeBuilder::pickRandom(std::vector<std::string> strings)
{
    return strings[uuid::randomInt(0, strings.size()-1)];
}

void NarrativeBuilder::reset()
{
    this->product = Narrative();
}

Narrative NarrativeBuilder::getResult()
{
    return this->product;
}