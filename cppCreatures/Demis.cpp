#include "../hppCreatures/Demis.hpp"
#include <iostream>

Demis::Demis() {
    name             = "Demis";
    hp               = 330;
    strength         = 57;
    dexterity        = 41;
    exp              = 60;
    specialPowerName = "+130 HP, +130 Damage ( 1 )";
    type             = TYPE_AIR;
}

int Demis::specialPower() {
    static int specialCounter = 1;

    if(specialCounter > 0) {
        int specialDamage = genericAttack() + 130;
        hp += 130;
        std::cout << "//////////////////////////////////////////////////////////////////////////\n"
                  << "/ -> Demis use special power: HP is increased by 150 and deal " << specialDamage << " damage /\n"
                  << "//////////////////////////////////////////////////////////////////////////\n";
        specialCounter -= 1;
        return specialDamage;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Demis has run out of special powers, so it's better to attack with a normal attack      ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}
