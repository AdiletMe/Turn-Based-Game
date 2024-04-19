#ifndef UNTITLED2_ARTE_HPP
#define UNTITLED2_ARTE_HPP

#include "../Creature.hpp"

class Arte : public Creature{

public:
    Arte();
    virtual ~Arte() = default;
private:
    int specialPower() override;
};

#endif //UNTITLED2_ARTE_HPP
