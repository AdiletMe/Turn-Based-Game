#include <iostream>
#include "../hppCreatures/Glo.hpp"

Glo::Glo() {
    name             = "Glo";
    hp               = 340;
    strength         = 60;
    dexterity        = 41;
    exp              = 60;
    specialPowerName = "+100 Damage ( 2 )";
    type             = TYPE_FIRE;
}

int Glo::specialPower() {
    static int specialCounter = 2;

    if(specialCounter > 0) {

        int specialDamage = genericAttack() + 100;
        std::cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n"
                  << "~ -> Glo use special power: deal" << specialDamage << " damage                              -\n"
                  << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n";
        specialCounter -= 1;
        return specialDamage;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Glo has run out of special powers, so it's better to attack with a normal attack        ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}