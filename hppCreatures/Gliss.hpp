#ifndef UNTITLED2_GLISS_HPP
#define UNTITLED2_GLISS_HPP

#include "../Creature.hpp"

class Gliss : public Creature {
public:
    Gliss();
    virtual ~Gliss() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED2_GLISS_HPP