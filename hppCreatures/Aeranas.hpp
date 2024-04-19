#ifndef UNTITLED2_AERANAS_HPP
#define UNTITLED2_AERANAS_HPP

#include "../Creature.hpp"

class Aeranas :public Creature{
public:
    Aeranas();
    virtual ~Aeranas() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED2_AERANAS_HPP
