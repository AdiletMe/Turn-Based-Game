#include <iostream>
#include "../hppCreatures/Gliss.hpp"

Gliss::Gliss() {
    name             = "Gliss";
    hp               = 360;
    strength         = 54;
    dexterity        = 43;
    exp              = 60;
    specialPowerName = "+120 Damage ( 2 )";
    type             = TYPE_ICE;
}
int Gliss::specialPower() {
    static int specialCounter = 2;

    if(specialCounter > 0) {

        int specialDamage = genericAttack() + 120;
        std::cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n"
                  << "~ -> Gliss use special power: deal" << specialDamage << " damage                            -\n"
                  << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n";
        specialCounter -= 1;
        return specialDamage;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Gliss has run out of special powers, so it's better to attack with a normal attack      ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}