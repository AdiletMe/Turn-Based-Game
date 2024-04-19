#ifndef UNTITLED3_DIVOS_HPP
#define UNTITLED3_DIVOS_HPP

#include "../Creature.hpp"

class Divos : public Creature{

public:
    Divos();
    virtual ~Divos() = default;
private:
    int specialPower() override;
};

#endif //UNTITLED3_DIVOS_HPP