#ifndef UNTITLED3_AMOGUS_HPP
#define UNTITLED3_AMOGUS_HPP

#include "../Creature.hpp"
class Amogus : public Creature{

public:
    Amogus();
    virtual ~Amogus() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED3_AMOGUS_HPP
