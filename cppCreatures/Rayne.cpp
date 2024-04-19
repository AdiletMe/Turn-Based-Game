#include <iostream>
#include "../hppCreatures/Rayne.hpp"

Rayne::Rayne() {
    name             = "Rayne";
    hp               = 350;
    strength         = 54;
    dexterity        = 42;
    exp              = 90;
    specialPowerName = "+140 Damage ( 2 )";
    type             = TYPE_ICE;
}

int Rayne::specialPower() {
    static int specialCounter = 1;

    if(specialCounter == 1) {

        int specialDamage = genericAttack() + 140;
        std::cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n"
                  << "~ -> Rayne use special power: deal" << specialDamage << " damage                            -\n"
                  << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n";
        specialCounter -= 1;
        return specialDamage;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Rayne has run out of special powers, so it's better to attack with a normal attack      ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}