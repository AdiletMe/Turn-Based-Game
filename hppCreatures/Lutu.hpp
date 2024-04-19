#ifndef UNTITLED2_LUTU_HPP
#define UNTITLED2_LUTU_HPP

#include "../Creature.hpp"

class Lutu : public Creature{
public:
    Lutu();
    virtual ~Lutu() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED2_LUTU_HPP