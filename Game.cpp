#include "Game.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include "hppCreatures/hppCreatures.hpp"
#include "Common.hpp"


Game::Game() = default;

auto Game::includeCreatures() -> void {

    availableCreatures.push_back(std::make_shared<Aeranas>());
    availableCreatures.push_back(std::make_shared<Amogus>());
    availableCreatures.push_back(std::make_shared<Arte>());
    availableCreatures.push_back(std::make_shared<Crayg>());
    availableCreatures.push_back(std::make_shared<Cryogen>());
    availableCreatures.push_back(std::make_shared<Demis>());
    availableCreatures.push_back(std::make_shared<Divos>());
    availableCreatures.push_back(std::make_shared<Frose>());
    availableCreatures.push_back(std::make_shared<Genos>());
    availableCreatures.push_back(std::make_shared<Gliss>());
    availableCreatures.push_back(std::make_shared<Glo>());
    availableCreatures.push_back(std::make_shared<Grav>());
    availableCreatures.push_back(std::make_shared<Lumus>());
    availableCreatures.push_back(std::make_shared<Lutu>());
    availableCreatures.push_back(std::make_shared<Malos>());
    availableCreatures.push_back(std::make_shared<Mortus>());
    availableCreatures.push_back(std::make_shared<Quarris>());
    availableCreatures.push_back(std::make_shared<Rayne>());
    availableCreatures.push_back(std::make_shared<Sentos>());
    availableCreatures.push_back(std::make_shared<Sono>());
    availableCreatures.push_back(std::make_shared<Tempus>());
    availableCreatures.push_back(std::make_shared<Theran>());

}



auto Game::printAllCreatures()  -> void {
    std::cout<<"\n===============================*** ALL CREATURES ***===============================\n";
    for(int i = 0; i < availableCreatures.size(); i++){
        std::cout<<"{"<<i<<"}";
        availableCreatures[i]->show_HUD();
        std::cout<<std::endl << "===================================================================================\n";
    }
}

auto Game::printPlayerCreatures() -> void{
    std::cout<<"\n=============================*** PLAYER CREATURES ***==============================\n";
    for(int j = 0; j < playerCreatures.size();j++){
        std::cout<<"{"<<j<<"}";
        playerCreatures[j]->show_HUD();
        std::cout<<"\n===================================================================================\n";
    }
}

auto Game::printEnemyCreatures() -> void {
    std::cout<<"\n==============================*** ENEMY CREATURES ***==============================\n";
    for(int i = 0; i < enemyCreatures.size(); i++){
        std::cout<<"{"<<i<<"}";
        enemyCreatures[i]->show_HUD();
        std::cout<<"\n===================================================================================\n";
    }
}

auto Game::chooseCreatures() -> void {
    int select = 0;

        while (select >= 0 && select <= availableCreatures.size()) {
            while(playerCreatures.size() != 6) {
                std::cout<<"Select the number of the creature you want to team: ";
                printAllCreatures();
                std::cin >> select;
                playerCreatures.push_back(std::move(availableCreatures[select]));
                availableCreatures.erase(availableCreatures.begin() + select);
        }
            return;
    }
}

auto Game::activeCreature() -> void {
    printPlayerCreatures();
    std::cout<<"Select your active creature: \n";
    int select = 0;
    bool selecter = select >=0 && select <= playerCreatures.size();
    while (selecter) {
        std::cin >> select;
        if(selecter) break;
    };
    player = playerCreatures[select];
}



auto Game::setEnemy() -> void {
    if(!availableCreatures.empty()) {
        while (enemyCreatures.size() != 4) {
            int randCreature = Common::randomInt( 0, availableCreatures.size() - 1);
            enemyCreatures.push_back(std::move(availableCreatures[randCreature]));
            availableCreatures.erase(availableCreatures.begin() + randCreature);

        }
    }else{
        std::cout<<"There's no more creatures!";
    }

}

auto Game::activeEnemyCreature() -> void {
    auto randCreature = Common::randomInt(0, enemyCreatures.size() - 1);
    enemy = enemyCreatures[randCreature];
}

auto Game::enemyEvolve() -> void {
    for(auto& availableCreature : availableCreatures){
        availableCreature->enemyEvolution();
    }
}



auto Game::startGame() -> void {
    std::cout<<"================================*** WHAT YOU WANT? ***===============================\n"
             <<" = 0. New game                                                                      =\n"
             <<" = 1. Continue game                                                                 =\n"
             <<"==============================*** WHAT YOU WANT? ***=================================\n";
    int choice;
    std::cin>>choice;
    if(choice == 0) {
        includeCreatures();
        chooseCreatures();
        activeCreature();
    }if(choice == 1){
        openGame();
    }
    isPlaying=true;

    // Loops while the game is still playing.

    while(isPlaying) {
        setEnemy();
        battle();
        enemyEvolve();
    }
}



auto Game::battle() -> void {

    while(isPlaying) {
        int select;
        int action = player->playerAction();
        if(action == -3){
            activeCreature();
        }if(action > 0 || action == -2) {
            printPlayerCreatures();
            printEnemyCreatures();
            do  {
                std::cout << " -> Select enemy you want to attack: \n";
                std::cin >> select;
            } while (select < 0 || select >= enemyCreatures.size() );

            if(action == -2){enemyCreatures[select]->takeSuperDamage(player);}
            if(action > 0){enemyCreatures[select]->takeDamage(player);}


            if (enemyCreatures[select]->isDead()) {

                player->addExperience(enemyCreatures[select]->getExp());

                enemyCreatures.erase(enemyCreatures.begin() + select);

                if (enemyCreatures.empty()) {
                    if(availableCreatures.empty()){
                        Common::winMessage();
                        exit(0);
                    }
                    continueGame();
                    return;
                }
            }

            activeEnemyCreature();

            int enemyAction = enemy->enemyAction();
            int enemyIsAttack = Common::randomInt(0, playerCreatures.size() - 1);

            if(enemyAction == -2) {playerCreatures[enemyIsAttack]->takeSuperDamage(enemy);}
            if(enemyAction >= 0) {playerCreatures[enemyIsAttack]->takeDamage(enemy);}

            // Executes when player's health is 0 or below.
            if (playerCreatures[enemyIsAttack]->isDead()) {
                playerCreatures.erase(playerCreatures.begin() + enemyIsAttack);
                if (playerCreatures.empty()) {
                    Common::loseMessage();
                    exit(0);
                }
            }
        }
    }
    battle();
}



auto Game::saveGame() -> void {
    for (auto& availableCreature : availableCreatures) {
        fileSave.write(reinterpret_cast<char*>(&availableCreature),sizeof(availableCreature)) ;
    }
}

auto Game::openGame() -> void {
    std::shared_ptr<Creature> creature;
    while(fileSave.read(reinterpret_cast<char*> (&creature), sizeof(&creature)))
        availableCreatures.push_back(creature);

    printAllCreatures();

}

auto Game::continueGame() -> void{
    std::cout<<"================================*** WHAT YOU WANT? ***===============================\n"
             <<" = 0. Continue game                                                                 =\n"
             <<" = 1. Save and close game                                                           =\n"
             <<"================================*** WHAT YOU WANT? ***===============================\n";
    int choice;

    std::cin>>choice;
    while (choice != 0 || choice != 1) {
        if (choice == 0) {
            return;
        }if (choice == 1) {
            saveGame();
            isPlaying = false;
            return;
        } else {
            std::cout << "Please write correct number!\n";
            std::cin >> choice;
        }
    }
}