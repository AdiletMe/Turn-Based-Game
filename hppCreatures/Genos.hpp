#ifndef UNTITLED2_GENOS_HPP
#define UNTITLED2_GENOS_HPP

#include "../Creature.hpp"

class Genos : public Creature {
public:
    Genos();
    virtual ~Genos() = default;

private:
    int specialPower() override;
};

#endif //UNTITLED2_GENOS_HPP