#include <iostream>
#include "../hppCreatures/Genos.hpp"

Genos::Genos() {
    name             = "Genos";
    hp               = 370;
    strength         = 53;
    dexterity        = 42;
    exp              = 70;
    specialPowerName = "+150 Damage ( 1 )";
    type             = TYPE_FIRE;
}

int Genos::specialPower() {
    static int specialCounter = 1;

    if(specialCounter > 0) {

        int specialDamage = genericAttack() + 150;
        std::cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n"
                  << "~ -> Genos use special power: deal" << specialDamage << " damage                            -\n"
                  << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n";
        specialCounter -= 1;
        return specialDamage;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Genos has run out of special powers, so it's better to attack with a normal attack      ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}
