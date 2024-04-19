#include "../hppCreatures/Crayg.hpp"
#include <iostream>

Crayg::Crayg() {
    name             = "Crayg";
    hp               = 330;
    strength         = 53;
    dexterity        = 43;
    exp              = 60;
    specialPowerName = "Increase HP by 120 (2)";
    type             = TYPE_EARTH;
}

int Crayg::specialPower() {
    static int specialCounter = 2;

    if(specialCounter > 0) {
        hp += 120;
        std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                 <<"+ -> Crayg use special power: HP is increased by 120                                         +\n"
                 <<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        specialCounter -= 1;
        return 0;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Crayg has run out of special powers, so it's better to attack with a normal attack      ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }
}