#include "Troop.h"

class Commander : public Troop{
    public:
    Commander();
    void attack();
    void defend();
    void transport();
    void command();
    Entity* clone();
};