cmake_minimum_required(VERSION 3.25)
project(SuperAdvancePets C)

set(CMAKE_C_STANDARD 11)
set(TONC /opt/devkitpro/libtonc/include)
include_directories(SYSTEM ${TONC})
add_executable(SuperAutoPets ${TONC}/tonc.h src/sap.c sprites/animals.h engine/pet_data.h)