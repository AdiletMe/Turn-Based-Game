#ifndef UNTITLED2_CRAYG_HPP
#define UNTITLED2_CRAYG_HPP

#include "../Creature.hpp"

class Crayg : public Creature{

public:
    Crayg();
    virtual ~Crayg() = default;
private:
    int specialPower() override;
};

#endif //UNTITLED2_CRAYG_HPP