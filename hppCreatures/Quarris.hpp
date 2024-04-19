#ifndef UNTITLED3_QUARRIS_HPP
#define UNTITLED3_QUARRIS_HPP

#include "../Creature.hpp"
class Quarris : public Creature{

public:
    Quarris();
    virtual ~Quarris() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED3_QUARRIS_HPP