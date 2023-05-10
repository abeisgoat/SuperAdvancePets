cmake_minimum_required(VERSION 3.25)
project(SuperAdvancePets C)

set(CMAKE_C_STANDARD 11)
set(TONC /opt/devkitpro/libtonc/include)
set(GBA /opt/devkitpro/libgba/include)
include_directories(SYSTEM ${TONC})
include_directories(SYSTEM ${GBA})

FILE(GLOB EngineC engine/*.c)
FILE(GLOB EngineH engine/*.h)
FILE(GLOB SpritesC sprites/*.c)
FILE(GLOB SpritesH sprites/*.h)
add_executable(SuperAdvancePets
        ${TONC}/tonc.h
        ${SpritesC} ${SpritesH}
        ${EngineC} ${EngineH}
        src/sap.c)

project(SuperAdvancePetsCLI C)

set(CMAKE_C_STANDARD 11)

FILE(GLOB SrcC src/*.c)
FILE(GLOB SrcH src/*.H)
FILE(GLOB EngineC engine/*.c)
FILE(GLOB EngineH engine/*.h)
FILE(GLOB SpritesC sprites/*.c)
FILE(GLOB SpritesH sprites/*.h)

add_executable(SuperAdvancePetsCLI
        ${SpritesC} ${SpritesH}
        ${EngineC} ${EngineH}
        ${SrcC} ${SrcH}
        cli.c)