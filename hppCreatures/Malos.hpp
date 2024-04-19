#ifndef UNTITLED2_MALOS_HPP
#define UNTITLED2_MALOS_HPP

#include "../Creature.hpp"

class Malos : public Creature{
public:
    Malos();
    virtual ~Malos() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED2_MALOS_HPP