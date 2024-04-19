
#include <iostream>
#include <random>
#include "Common.hpp"

using namespace std;

int Common::randomInt(int min, int max) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

void Common::help() {
    std::cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
             <<"|                        Welcome to the Turn-Based-Game!                                    |\n"
             <<"|   Gameplay is divided into 2 parts.                                                       |\n"
             <<"|   Your turn and Enemy turn.                                                               |\n"
             <<"|   In your turn, you need to choose one of the following options:                          |\n"
             <<"|   \t0.Attack                                                                            |\n"
             <<"|   \t1.Use special ability                                                               |\n"
             <<"|   \t2.Change active creature                                                            |\n"
             <<"|   \t3.Evolve the creature                                                               |\n"
             <<"|   \t4.Use help.                                                                         |\n"
             <<"|   During an enemy's turn, he randomly attacks 80% that he attacks normally                |\n"
             <<"|   20% that he uses super power                                                            |\n"
             <<"|   After defeating an enemy, you will receive EXP.                                         |\n"
             <<"|   After getting 100 EXP you receive lvl point.                                            |\n"
             <<"|   For each lvl point you can improve your attributes.                                     |\n"
             <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
}

void Common::winMessage() {
    std::cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
             <<"|             FINALlY!!! You completed this game and now you can do your own thing.         |\n"
             <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
}

void Common::loseMessage() {
    std::cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
             <<"|             I think you should still try again, or not                                    |\n"
             <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
}

