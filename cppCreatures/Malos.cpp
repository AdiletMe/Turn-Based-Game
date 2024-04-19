#include "../hppCreatures/Malos.hpp"
#include <iostream>

Malos::Malos()
{
    name             = "Malos";
    hp               = 400;
    strength         = 45;
    dexterity        = 44;
    exp              = 80;
    specialPowerName = "+160 HP ( 1 ) ";
    type             = TYPE_WATER;
}

int Malos::specialPower() {
    static int specialCounter = 1;

    if(specialCounter > 0) {
        hp += 160;
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                  << "+ -> Malos use special power: HP is increased by 160                                         +\n"
                  << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        specialCounter -= 1;
        return 0;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Malos has run out of special powers, so it's better to attack with a normal attack      ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}
