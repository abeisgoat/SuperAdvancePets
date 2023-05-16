cmake_minimum_required(VERSION 3.25)
project(SuperAdvancePets C)

set(CMAKE_C_STANDARD 11)
set(TONC /opt/devkitpro/libtonc/include)
set(GBA /opt/devkitpro/libgba/include)
include_directories(SYSTEM ${TONC})
include_directories(SYSTEM ${GBA})

FILE(GLOB EngineC engine/**.c)
FILE(GLOB EngineH engine/**.h)
FILE(GLOB SpritesC sprites/*.c)
FILE(GLOB SpritesH sprites/*.h)
add_executable(SuperAdvancePets
        ${TONC}/tonc.h
        ${SpritesC} ${SpritesH}
        ${EngineC} ${EngineH}
        src/sap.c src/mem_manager_enums.h src/tick.h src/tick.c src/scene_store.c src/scene_store.h engine/triggers.h)

project(SuperAdvancePetsCLI C)

set(CMAKE_C_STANDARD 11)

FILE(GLOB EngineC engine/**.c)
FILE(GLOB EngineH engine/**.h)
FILE(GLOB PetImplC engine/pet_impl/*.c)
FILE(GLOB PetImplH engine/pet_impl/*.h)
FILE(GLOB FoodImplC engine/food_impl/*.c)
FILE(GLOB FoodImplH engine/food_impl/*.h)
FILE(GLOB SpritesC sprites/*.c)
FILE(GLOB SpritesH sprites/*.h)

add_executable(SuperAdvancePetsCLI
        src/animations.h
        stubs/animations.c
        ${PetImplC} ${PetImplH}
        ${FoodImplC} ${FoodImplH}
        ${SpritesC} ${SpritesH}
        ${EngineC} ${EngineH}
        ${SrcC} ${SrcH}
        cli.c)