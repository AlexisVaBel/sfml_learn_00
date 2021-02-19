cmake_minimum_required(VERSION 3.5)
project(10_tiledt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


link_directories(/opt/sfml/lib)


set(incs "/opt/sfml/include/" "." "states/" "entities/")


include_directories(${incs})



message("adding includes ... ")

set(sources
        main.cpp game.cpp states/gamestate.cpp states/nocoinstate.cpp states/getreadystate.cpp states/loststate.cpp states/wonstate.cpp states/playingstate.cpp
        entities/bonus.cpp entities/dot.cpp entities/character.cpp entities/pacwoman.cpp entities/ghost.cpp
        animation/animator.cpp
        )



add_executable(${CMAKE_PROJECT_NAME} ${sources})

message("linking libraies ... ")

target_link_libraries(${CMAKE_PROJECT_NAME} sfml-window sfml-graphics sfml-system  )

