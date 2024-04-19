#include "../hppCreatures/Theran.hpp"
#include <iostream>

Theran::Theran() {
    name             = "Theran";
    hp               = 300;
    strength         = 65;
    dexterity        = 42;
    exp              = 90;
    specialPowerName = "+120 HP ( 1 )";
    type             = TYPE_EARTH;
}

int Theran::specialPower() {
    static int specialCounter = 1;

    if(specialCounter > 0) {
        hp += 120;
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                  << "+ -> Theran use special power: HP is increased by 60                                          +\n"
                  << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        specialCounter -= 1;
        return 0;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Theran has run out of special powers, so it's better to attack with a normal attack      ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }

}