#include <iostream>
#include "../hppCreatures/Mortus.hpp"

Mortus::Mortus() {
    name             = "Mortus";
    hp               = 350;
    strength         = 55;
    dexterity        = 43;
    exp              = 60;
    specialPowerName = "+80 HP ( 2 )";
    type             = TYPE_WATER;
}

int Mortus::specialPower() {
    static int specialCounter = 2;

    if(specialCounter > 0) {
        hp += 80;
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                  << "+ -> Mortus use special power: HP is increased by 80                                         +\n"
                  << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        specialCounter -= 1;
        return 0;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Mortus has run out of special powers, so it's better to attack with a normal attack      ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}