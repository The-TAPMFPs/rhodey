#include "Troop.h"

class Soldier : public Troop{
    public:
    Soldier();
    void attack();
    void defend();
    void transport();
    Entity* clone();
};