cmake_minimum_required(VERSION 3.13)
project(ProyectoFinalPOO)

set(SOURCE
        main.cpp
        Tipos.h
        Menu.cpp Menu.h
        Tierra.cpp Tierra.h
        Objeto.cpp Objeto.h)
set(CMAKE_CXX_STANDARD 14)

# Si esta configuracion funciona solamente en Windows,
# En caso funcionara en Macs cambiarlo a:  if (WIN32 AND APPLE)
if (WIN32)
    # Modificar al folder donde se encuentre la libreria SFML instalada
    set(SFML_ROOT "C:/XXXX") # <--------- Modificar Aqui

    set(SFML_INCLUDE_DIR "{SFML_ROOT}/SFML-2.5.1/include")
    set(SFML_LIBRARY_DIR "{SFML_ROOT}/SFML-2.5.1/lib")
    set(SFML_DIR "{SFML_ROOT}/SFML-2.5.1/lib/cmake/SFML")
    link_directories(SFML_LIBRARY_DIR)
    include_directories(SFML_INCLUDE_DIR)
endif()

add_executable(${PROJECT_NAME} main.cpp Tipos.h Menu.cpp Menu.h Tierra.cpp Tierra.h Objeto.cpp Objeto.h)

find_package(SFML 2.5.1
        COMPONENTS system window graphics network audio REQUIRED)

target_link_libraries (${PROJECT_NAME}
        sfml-graphics
        sfml-window
        sfml-system)