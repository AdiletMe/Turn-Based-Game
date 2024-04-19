#ifndef UNTITLED2_LUMUS_HPP
#define UNTITLED2_LUMUS_HPP

#include "../Creature.hpp"

class Lumus : public Creature {
public:
    Lumus();
    virtual ~Lumus() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED2_LUMUS_HPP