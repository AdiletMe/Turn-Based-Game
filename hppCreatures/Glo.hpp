#ifndef UNTITLED2_GLO_HPP
#define UNTITLED2_GLO_HPP

#include "../Creature.hpp"

class Glo : public Creature {
public:
    Glo();
    virtual ~Glo() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED2_GLO_HPP