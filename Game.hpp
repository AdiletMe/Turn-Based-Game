#ifndef UNTITLED3_GAME_HPP
#define UNTITLED3_GAME_HPP

#include <vector>
#include <fstream>
#include <memory>

#include "Creature.hpp"


class Game {
public:
    Game();
    auto startGame() -> void;

private:
    auto includeCreatures() -> void;

    auto printAllCreatures() -> void;
    auto printPlayerCreatures() -> void;
    auto printEnemyCreatures() -> void;

    auto chooseCreatures() -> void;
    auto activeCreature() -> void;

    auto setEnemy() -> void;
    auto activeEnemyCreature() -> void;
    auto enemyEvolve() -> void;

    auto battle() -> void;

    auto saveGame() -> void;
    auto openGame() -> void;
    auto continueGame() -> void;

    bool isPlaying;

    std::string path = "(AllCreatures.bin)";
    std::fstream fileSave = std::fstream(path,std::ios::out | std::ios::in | std::ios::binary);

    std::vector<std::shared_ptr<Creature>> availableCreatures;
    std::vector<std::shared_ptr<Creature>> playerCreatures;
    std::vector<std::shared_ptr<Creature>> enemyCreatures;

    std::shared_ptr<Creature> player;
    std::shared_ptr<Creature> enemy;

};

#endif //UNTITLED3_GAME_HPP
