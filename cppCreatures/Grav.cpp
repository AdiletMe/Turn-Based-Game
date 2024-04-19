#include "../hppCreatures/Grav.hpp"
#include <iostream>

Grav::Grav() {
    name             = "Grav";
    hp               = 310;
    strength         = 60;
    dexterity        = 40;
    exp              = 70;
    specialPowerName = "Increase HP by 180 (1)";
    type             = TYPE_EARTH;
}

int Grav::specialPower() {
    auto static specialCounter = 1;

    if(specialCounter > 0) {
        hp += 180;
        std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                 <<"+ -> Grav use special power: HP is increased by 180                                          +\n"
                 <<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        specialCounter -= 1;
        return genericAttack();
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Grav has run out of special powers, so it's better to attack with a normal attack       ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}