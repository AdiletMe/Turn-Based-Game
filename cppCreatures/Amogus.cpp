#include "../hppCreatures/Amogus.hpp"
#include <iostream>

Amogus::Amogus() {
    name             = "Amogus";
    hp               = 350;
    strength         = 55;
    dexterity        = 41;
    exp              = 70;
    specialPowerName = "+ 150 HP, + 90 Damage ( 1 )";
    type             = TYPE_STEEL;
}

int Amogus::specialPower() {
    static int specialCounter = 1;

    if(specialCounter > 0) {
        int specialDamage = genericAttack() + 90;
        hp += 150;
        std::cout << "//////////////////////////////////////////////////////////////////////////\n"
                  << "/ -> Amogus use special power: HP is increased by 150 and deal " << specialDamage << " damage/\n"
                  << "//////////////////////////////////////////////////////////////////////////\n";
        specialCounter -= 1;
        return specialDamage;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Amogus has run out of special powers, so it's better to attack with a normal attack    ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}