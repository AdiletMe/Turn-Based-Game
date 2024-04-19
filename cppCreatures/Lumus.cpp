#include <iostream>
#include "../hppCreatures/Lumus.hpp"

Lumus::Lumus() {
    name             = "Lumus";
    hp               = 360;
    strength         = 55;
    dexterity        = 43;
    exp              = 70;
    specialPowerName = "+240 Damage ( 1 )";
    type             = TYPE_FIRE;
}

int Lumus::specialPower() {
    static int specialCounter = 1;

    if(specialCounter > 0) {
        int specialDamage = genericAttack() + 240;
        std::cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n"
                  << "~ -> Lumus use special power: deal" << specialDamage << " damage                            -\n"
                  << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n";
        specialCounter -= 1;
        return specialDamage;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Lumus has run out of special powers, so it's better to attack with a normal attack      ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}