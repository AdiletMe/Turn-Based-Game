#ifndef UNTITLED3_TEMPUS_HPP
#define UNTITLED3_TEMPUS_HPP

#include "../Creature.hpp"

class Tempus :public Creature{
public:
    Tempus();
    virtual ~Tempus() = default;

private:
    int specialPower() override;
};


#endif //UNTITLED3_TEMPUS_HPP
