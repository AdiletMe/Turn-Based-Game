#ifndef UNTITLED3_CRYOGEN_HPP
#define UNTITLED3_CRYOGEN_HPP

#include "../Creature.hpp"

class Cryogen : public Creature{

public:
    Cryogen();
    virtual ~Cryogen() = default;
private:
    int specialPower() override;
};

#endif //UNTITLED3_CRYOGEN_HPP