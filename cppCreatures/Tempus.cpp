#include "../hppCreatures/Tempus.hpp"
#include <iostream>

Tempus::Tempus() {
    name             = "Tempus";
    hp               = 370;
    strength         = 52;
    dexterity        = 41;
    exp              = 90;
    specialPowerName = "Increase HP by 140 (2)";
    type             = TYPE_EARTH;
}

int Tempus::specialPower() {
    static int specialCounter = 2;

    if(specialCounter > 0) {
        hp += 140;
        std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                 <<"+ -> Tempus use special power: HP is increased by 140                                        +\n"
                 <<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        specialCounter -= 1;
        return 0;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Tempus has run out of special powers, so it's better to attack with a normal attack     ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}