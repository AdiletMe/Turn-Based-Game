#ifndef UNTITLED2_MORTUS_HPP
#define UNTITLED2_MORTUS_HPP

#include "../Creature.hpp"

class Mortus : public Creature{
public:
    Mortus() ;
    virtual ~Mortus() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED2_MORTUS_HPP