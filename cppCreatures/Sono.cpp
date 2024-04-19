#include "../hppCreatures/Sono.hpp"
#include <iostream>

Sono::Sono() {
    name             = "Sono";
    hp               = 340;
    strength         = 50;
    dexterity        = 42;
    exp              = 65;
    specialPowerName = "+60 HP, +110 Damage ( 2 )";
    type             = TYPE_AIR;
}

int Sono::specialPower() {
    static int specialCounter = 2;

    if(specialCounter > 0) {
        int specialDamage = genericAttack() + 110;
        hp += 60;
        std::cout << "//////////////////////////////////////////////////////////////////////////\n"
                  << "/ -> Sono use special power: HP is increased by 150 and deal " << specialDamage << " damage  /\n"
                  << "//////////////////////////////////////////////////////////////////////////\n";
        specialCounter -= 1;
        return specialDamage;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Sono has run out of special powers, so it's better to attack with a normal attack       ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}