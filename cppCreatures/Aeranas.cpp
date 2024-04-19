#include "../hppCreatures/Aeranas.hpp"
#include <iostream>

Aeranas::Aeranas() {
    name             = "Aeranas";
    hp               = 300;
    strength         = 6500;
    dexterity        = 40;
    exp              = 75;
    specialPowerName = "+80 HP, +90 Damage ( 2 )";
    type             = TYPE_AIR;
}

int Aeranas::specialPower() {
    static int specialCounter = 2;

    if(specialCounter > 0) {
        int specialDamage = genericAttack() + 90;
        hp += 80;
        std::cout << "///////////////////////////////////////////////////////////////////////////\n"
                  << "/ -> Aeranas use special power: HP is increased by 150 and deal " << specialDamage << " damage/\n"
                  << "///////////////////////////////////////////////////////////////////////////\n";
        specialCounter -= 1;
        return specialDamage;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Aeranas has run out of special powers, so it's better to attack with a normal attack    ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}