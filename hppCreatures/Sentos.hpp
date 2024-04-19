#ifndef UNTITLED2_SENTOS_HPP
#define UNTITLED2_SENTOS_HPP

#include "../Creature.hpp"

class Sentos : public Creature {
public:
    Sentos();
    virtual ~Sentos() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED2_SENTOS_HPP