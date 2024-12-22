cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(BlackJackSDL)

# Configurações do compilador
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0")

# Diretórios de inclusão
include_directories(
    ${CMAKE_SOURCE_DIR}/src/core
    ${CMAKE_SOURCE_DIR}/src/events
    ${CMAKE_SOURCE_DIR}/src/gameplay
    ${CMAKE_SOURCE_DIR}/src/graphics
    ${CMAKE_SOURCE_DIR}/src/graphics/scene
    ${CMAKE_SOURCE_DIR}/src/utils
)

# Configuração do SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Fontes principais
file(GLOB CORE_SOURCES ${CMAKE_SOURCE_DIR}/src/core/*.c)
file(GLOB EVENTS_SOURCES ${CMAKE_SOURCE_DIR}/src/events/*.c)
file(GLOB GAMEPLAY_SOURCES ${CMAKE_SOURCE_DIR}/src/gameplay/*.c)
file(GLOB GRAPHICS_SOURCES ${CMAKE_SOURCE_DIR}/src/graphics/*.c)
file(GLOB SCENE_SOURCES ${CMAKE_SOURCE_DIR}/src/graphics/scene/*.c)
file(GLOB UTILS_SOURCES ${CMAKE_SOURCE_DIR}/src/utils/*.c)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.c
    ${CORE_SOURCES}
    ${EVENTS_SOURCES}
    ${GAMEPLAY_SOURCES}
    ${GRAPHICS_SOURCES}
    ${SCENE_SOURCES}
    ${UTILS_SOURCES}
)

# Diretório de build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/Debug)

# Alvo principal
add_executable(21_Master ${SOURCES})

# Linking
target_link_libraries(21_Master ${SDL2_LIBRARIES} SDL2_ttf SDL2_mixer)

