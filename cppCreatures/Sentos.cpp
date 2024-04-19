#include "../hppCreatures/Sentos.hpp"
#include <iostream>

Sentos::Sentos() {
    name             = "Sentos";
    hp               = 345;
    strength         = 55;
    dexterity        = 43;
    exp              = 60;
    specialPowerName = "+120HP, +150 Damage(1)";
    type             = TYPE_STEEL;
}

int Sentos::specialPower() {
    static int specialCounter = 1;

    if(specialCounter == 1) {
        int specialDamage = genericAttack() + 150;
        hp += 120;
        std::cout << "//////////////////////////////////////////////////////////////////////////\n"
                  << "/ -> Sentos use special power: HP is increased by 150 and deal " << specialDamage << " damage/\n"
                  << "//////////////////////////////////////////////////////////////////////////\n";
        specialCounter -= 1;
        return specialDamage;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Sentos has run out of special powers, so it's better to attack with a normal attack     ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}