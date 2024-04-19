#include "../hppCreatures/Divos.hpp"
#include <iostream>

Divos::Divos()  {
    name             = "Divos";
    hp               = 250;
    strength         = 52;
    dexterity        = 42;
    exp              = 65;
    specialPowerName = "+75 Damage ( 3 )";
    type             = TYPE_FIRE;
}

int Divos::specialPower() {
    static int specialCounter = 3;

    if(specialCounter > 0) {
        int specialDamage = genericAttack() + 75;
        std::cout << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n"
                  << "~ -> Divos use special power: deal" << specialDamage << " damage                            -\n"
                  << "~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n";
        specialCounter -= 1;
        return specialDamage;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Divos has run out of special powers, so it's better to attack with a normal attack      ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }

}