#include "../hppCreatures/Lutu.hpp"
#include <iostream>

Lutu::Lutu() {
    name             = "Lutu";
    hp               = 360;
    strength         = 60;
    dexterity        = 40;
    exp              = 55;
    specialPowerName = "Increase HP by 60 (3)";
    type             = TYPE_EARTH;
}

int Lutu::specialPower() {
    static int specialCounter = 3;

    if(specialCounter > 0) {
        hp += 60;
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                  << "+ -> Lutu use special power: HP is increased by 60                                           +\n"
                  << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        specialCounter -= 1;
        return 0;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Lutu has run out of special powers, so it's better to attack with a normal attack       ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}