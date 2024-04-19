#ifndef UNTITLED2_FROSE_HPP
#define UNTITLED2_FROSE_HPP

#include "../Creature.hpp"

class Frose : public Creature {
public:
    Frose();
    virtual ~Frose() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED2_FROSE_HPP