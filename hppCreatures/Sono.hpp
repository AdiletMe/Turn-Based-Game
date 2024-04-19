#ifndef UNTITLED2_SONO_HPP
#define UNTITLED2_SONO_HPP

#include "../Creature.hpp"

class Sono : public Creature{
public:
    Sono();
    virtual ~Sono() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED2_SONO_HPP