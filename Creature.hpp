#ifndef UNTITLED3_CREATURE_HPP
#define UNTITLED3_CREATURE_HPP

#include <string>
#include <memory>

enum Type{
    TYPE_WATER,
    TYPE_EARTH,
    TYPE_AIR,
    TYPE_FIRE,
    TYPE_ICE,
    TYPE_STEEL
};

auto operator<<(std::ostream& stream, Type t) -> std::ostream&;

class Creature{

public:
    Creature();

    Type type;
    auto getExp() const -> int;

    auto damageType(const std::shared_ptr<Creature>& creature) const -> int;
    auto genericAttack() const -> int;
    auto takeDamage(const std::shared_ptr<Creature>& creature) -> void;
    auto takeSuperDamage(const std::shared_ptr<Creature>& creature) -> void;
    auto isDead() -> bool;
    auto addExperience(int xp) -> void;

    auto show_HUD() -> void;
    auto playerAction() -> int;
    auto enemyAction() const -> int;

    auto evolveCreature() -> void;
    auto enemyEvolution() -> void;

    virtual int specialPower();

protected:
    int hp;
    int strength;
    int dexterity;
    int exp;
    std::string name;
    std::string specialPowerName;
    int level = 0;
    int ExpCapacity = 0;

};



#endif //UNTITLED3_CREATURE_HPP
