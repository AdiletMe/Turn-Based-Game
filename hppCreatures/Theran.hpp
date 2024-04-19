#ifndef UNTITLED3_THERAN_HPP
#define UNTITLED3_THERAN_HPP

#include "../Creature.hpp"

class Theran : public Creature{
public:
    Theran();
    virtual ~Theran() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED3_THERAN_HPP