#include "../hppCreatures/Cryogen.hpp"
#include <iostream>
Cryogen::Cryogen() {
    name             = "Cryogen";
    hp               = 370;
    strength         = 52;
    dexterity        = 42;
    exp              = 70;
    specialPowerName = "+150 Damage ( 1 )";
    type            = TYPE_ICE;
}

int Cryogen::specialPower() {
    static int specialCounter = 1;

    if(specialCounter > 0) {
        int specialDamage = genericAttack() + 90;
        std::cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n"
                  << "~ -> Cryogen use special power: deal" << specialDamage << " damage                          -\n"
                  << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n";
        specialCounter -= 1;
        return specialDamage;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Cryogen has run out of special powers, so it's better to attack with a normal attack    ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }

}