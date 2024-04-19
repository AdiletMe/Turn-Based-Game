cmake_minimum_required(VERSION 3.21)
project(untitled3)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled3 main.cpp
        Creature.cpp                       Creature.hpp
        Common.cpp                         Common.hpp
        Game.cpp                           Game.hpp
        cppCreatures/Malos.cpp             hppCreatures/Malos.hpp
        cppCreatures/Mortus.cpp            hppCreatures/Mortus.hpp
        cppCreatures/Genos.cpp             hppCreatures/Genos.hpp
        cppCreatures/Glo.cpp               hppCreatures/Glo.hpp
        cppCreatures/Lumus.cpp             hppCreatures/Lumus.hpp
        cppCreatures/Aeranas.cpp           hppCreatures/Aeranas.hpp
        cppCreatures/Sono.cpp              hppCreatures/Sono.hpp
        cppCreatures/Demis.cpp             hppCreatures/Demis.hpp
        cppCreatures/Grav.cpp              hppCreatures/Grav.hpp
        cppCreatures/Crayg.cpp             hppCreatures/Crayg.hpp
        cppCreatures/Lutu.cpp              hppCreatures/Lutu.hpp
        cppCreatures/Frose.cpp             hppCreatures/Frose.hpp
        cppCreatures/Gliss.cpp             hppCreatures/Gliss.hpp
        cppCreatures/Arte.cpp              hppCreatures/Arte.hpp
        cppCreatures/Sentos.cpp            hppCreatures/Sentos.hpp
        cppCreatures/Divos.cpp             hppCreatures/Divos.hpp
        cppCreatures/Cryogen.cpp           hppCreatures/Cryogen.hpp
        cppCreatures/Theran.cpp            hppCreatures/Theran.hpp
        cppCreatures/Quarris.cpp           hppCreatures/Quarris.hpp
        cppCreatures/Amogus.cpp            hppCreatures/Amogus.hpp
        cppCreatures/Rayne.cpp             hppCreatures/Rayne.hpp
        cppCreatures/Tempus.cpp            hppCreatures/Tempus.hpp

        hppCreatures/hppCreatures.hpp)
