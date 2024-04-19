#include "../hppCreatures/Quarris.hpp"
#include <iostream>

Quarris::Quarris() {
    name             = "Quarris";
    hp               = 330;
    strength         = 50;
    dexterity        = 42;
    exp              = 85;
    specialPowerName = "+200 HP ( 1 )";
    type             = TYPE_WATER;
}

int Quarris::specialPower() {
    static int specialCounter = 1;

    if(specialCounter > 0) {
        hp += 200;
        std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                 <<"+ -> Quarris use special power: HP is increased by 180                                       +\n"
                 <<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        specialCounter -= 1;
        return 0;
    }else{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                  << "~ -> Quarris has run out of special powers, so it's better to attack with a normal attack     ~\n"
                  << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        return genericAttack();
    }

}