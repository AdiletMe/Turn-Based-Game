#ifndef UNTITLED2_DEMIS_HPP
#define UNTITLED2_DEMIS_HPP

#include "../Creature.hpp"

class Demis : public Creature {

public:
    Demis();
    virtual ~Demis() = default;
private:
    int specialPower() override;
};

#endif //UNTITLED2_DEMIS_HPP