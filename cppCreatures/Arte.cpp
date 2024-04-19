#include "../hppCreatures/Arte.hpp"
#include <iostream>

Arte::Arte() {
    name             = "Arte";
    hp               = 340;
    strength         = 57;
    dexterity        = 45;
    exp              = 75;
    specialPowerName = "+90 HP, +85 Damage (2)";
    type             = TYPE_STEEL;
}

int Arte::specialPower() {
    static int specialCounter = 2;

    if(specialCounter > 0) {
        int specialDamage = genericAttack() + 85;
        hp += 90;
        std::cout << "//////////////////////////////////////////////////////////////////////////\n"
                  << "/ -> Arte use special power: HP is increased by 150 and deal " << specialDamage << " damage  /\n"
                  << "//////////////////////////////////////////////////////////////////////////\n";
        specialCounter -= 1;
        return specialDamage;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Arte has run out of special powers, so it's better to attack with a normal attack       ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}