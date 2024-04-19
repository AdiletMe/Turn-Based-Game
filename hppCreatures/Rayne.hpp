#ifndef UNTITLED3_RAYNE_HPP
#define UNTITLED3_RAYNE_HPP

#include "../Creature.hpp"

class Rayne :public Creature{
public:
    Rayne();
    virtual ~Rayne() = default;

private:
    int specialPower() override;
};


#endif //UNTITLED3_RAYNE_HPP
