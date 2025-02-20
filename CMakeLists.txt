cmake_minimum_required(VERSION 3.10)
project(svg_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fichiers sources
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.hpp")

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Inclusion des répertoires d'en-têtes
target_include_directories(${PROJECT_NAME} PRIVATE src)