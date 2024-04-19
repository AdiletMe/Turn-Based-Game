#include <iostream>
#include <string>

#include "Creature.hpp"
#include "Common.hpp"

using namespace Common;

Creature::Creature() = default;



auto Creature::getExp() const -> int{
    return exp;
}



auto operator<<(std::ostream& stream, Type const t) ->std::ostream&{
    switch(t){
        case Type::TYPE_WATER: stream << "WATER"; break;
        case Type::TYPE_EARTH: stream << "EARTH"; break;
        case Type::TYPE_AIR:   stream << "AIR"; break;
        case Type::TYPE_FIRE:  stream << "FIRE"; break;
        case Type::TYPE_ICE:   stream << "ICE"; break;
        case Type::TYPE_STEEL: stream << "STEEL"; break;
    }
    return stream;
}



auto Creature::damageType(const std::shared_ptr<Creature>& creature) const -> int {
    if (type == TYPE_WATER) {
        if (creature->type == TYPE_WATER) return -10;
        if (creature->type == TYPE_EARTH) return 10;
        if (creature->type == TYPE_AIR) return 0;
        if (creature->type == TYPE_FIRE) return 10;
        if (creature->type == TYPE_ICE) return 0;
        if (creature->type == TYPE_STEEL) return 0;
    }
    if (type == TYPE_EARTH) {
        if (creature->type == TYPE_WATER) return 0;
        if (creature->type == TYPE_EARTH) return 0;
        if (creature->type == TYPE_AIR) return -10;
        if (creature->type == TYPE_FIRE) return 10;
        if (creature->type == TYPE_ICE) return 10;
        if (creature->type == TYPE_STEEL) return 10;
    }
    if (type == TYPE_AIR) {
        if (creature->type == TYPE_WATER) return 0;
        if (creature->type == TYPE_EARTH) return -10;
        if (creature->type == TYPE_AIR) return 0;
        if (creature->type == TYPE_FIRE) return 0;
        if (creature->type == TYPE_ICE) return 10;
        if (creature->type == TYPE_STEEL) return -10;
    }
    if (type == TYPE_FIRE) {
        if (creature->type == TYPE_WATER) return -10;
        if (creature->type == TYPE_EARTH) return -10;
        if (creature->type == TYPE_AIR) return 0;
        if (creature->type == TYPE_FIRE) return 0;
        if (creature->type == TYPE_ICE) return 10;
        if (creature->type == TYPE_STEEL) return 10;
    }
    if (type == TYPE_ICE) {
        if (creature->type == TYPE_WATER) return -10;
        if (creature->type == TYPE_EARTH) return 10;
        if (creature->type == TYPE_AIR) return 0;
        if (creature->type == TYPE_FIRE) return -10;
        if (creature->type == TYPE_ICE) return -10;
        if (creature->type == TYPE_STEEL) return 0;
    }
    if (type == TYPE_STEEL) {
        if (creature->type == TYPE_WATER) return 10;
        if (creature->type == TYPE_EARTH) return 0;
        if (creature->type == TYPE_AIR) return 10;
        if (creature->type == TYPE_FIRE) return -10;
        if (creature->type == TYPE_ICE) return 0;
        if (creature->type == TYPE_STEEL) return -10;
    }
    return 0;
}



auto Creature::genericAttack() const -> int {
    return strength + Common::randomInt(-11,16);
}



auto Creature::takeDamage(const std::shared_ptr<Creature>& creature) -> void{
    int damage = creature->genericAttack() + creature->damageType(creature);
    if(dexterity < damage) {
        std::cout <<"------ -> " << creature->name << " attacked " << name << " and deal " << damage << " damage\n";
        hp -= damage;
    }else{
        std::cout<<"$$$$$ -> " << name << " dodged the attack\n";
    }
}



auto Creature::takeSuperDamage(const std::shared_ptr<Creature>& creature) -> void {
    int damage = creature->specialPower() + creature->damageType(creature);
    if(dexterity < damage) {
        std::cout <<"------ -> " << creature->name << " attacked " << name << " and deal " << damage << " damage\n";
        hp -= damage;
    }else{
        std::cout<<"$$$$$ -> " << name << " dodged the attack\n";
    }
}



auto Creature::isDead() -> bool {
    // Returns a bool value, if the player's health is equal or below 0.
    if (hp <= 0) {
        std::cout <<"****** -> " << name << " is dead! \n\n";
        return true;
    }
    return false;
}



auto Creature::addExperience(int xp) -> void {
    ExpCapacity += xp;

    if (ExpCapacity>99) {
        ExpCapacity = 0;
        level+=1;
        std::cout << "!!+!! -> You get 1 lvl Point! " << std::endl;
    }
}



auto Creature::show_HUD() -> void {
    std::cout<<name
    <<"  \t[ HP:" << hp <<" ]  "
    <<"[ Str:" << strength <<" ]  "
    <<"[ Dex:" << dexterity <<" ]  "
    <<"[ Type:" << type <<" ]  "
    <<"[ EXP:" << exp<< " ]  "
    <<"[ LVL:" << level <<" ] \n"
    <<"  \t\t\t\t[ SP: " << specialPowerName <<" ]";
}



auto Creature::playerAction() -> int {

    std::cout << "[---------------------------------------------------------------------------------]\n"
              << "[                            Choose your move:                                    ]\n"
              << "[    0) Attack                                                                    ]\n"
              << "[    1) Use super Power                                                           ]\n"
              << "[    2) Change active creature                                                    ]\n"
              << "[    3) Evolve the creature                                                       ]\n"
              << "[    4) Help                                                                      ]\n"
              << "[---------------------------------------------------------------------------------]\n\n";
    auto choice = 0;
    std::cin>>choice;

    switch (choice) {
        case 0:
            return genericAttack();
            break;
        case 1:
            return -2;
            break;
        case 2:
            return -3;
            break;
        case 3:
            evolveCreature();
            break;
        case 4:
            Common::help();
            break;
        default:
            return 0;
    }

    return 0;
}



auto Creature::enemyAction() const -> int{
    int selector = Common::randomInt(0, 9);
    switch (selector) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            return genericAttack();
            break;
        case 8:
        case 9:
            return -2;
            break;
        default:
            return 0;
    }
}



auto Creature::evolveCreature() -> void{
    if(level > 0) {
    std::cout<<"...................................................................................\n"
             <<" .                      1 lvl point == 1 improve                                 . \n"
             <<" .                      Your lvl points: "<<level<<"                             . \n"
             <<" .                      What do you want to improve?                             . \n"
             <<" .                      0.HP           (+30)                                     . \n"
             <<" .                      1.Strength     (+20)                                     . \n"
             <<" .                      2.Dexterity    (+1)                                      . \n"
             <<" .                      3-9.Nothing                                              . \n"
             <<"...................................................................................\n";
        int select;
        std::cin >> select;
        switch (select) {
            case 0:
                hp += 30;
                level -= 1;
                std::cout << name << " increase HP by 30!\n";
                break;
            case 1:
                strength += 20;
                level -= 1;
                std::cout << name << " increase Strength by 30!\n";
                break;
            case 2:
                dexterity += 1;
                level -= 1;
                std::cout << name << " increase Dexterity by 30!\n";
                break;
            default:
                return;
        }
    }else{
        std::cout<<"You don't have enough level points to evolve creature!\n";
    }

}



auto Creature::enemyEvolution() -> void {
    hp += 50;
    strength += 15;
    dexterity += 1;
    exp += 30;
}



auto Creature::specialPower() -> int {
    return specialPower();
}


