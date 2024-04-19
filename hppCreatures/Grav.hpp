#ifndef UNTITLED2_GRAV_HPP
#define UNTITLED2_GRAV_HPP

#include "../Creature.hpp"

class Grav : public Creature {
public:
    Grav();
    virtual ~Grav() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED2_GRAV_HPP