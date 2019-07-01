//
// Created by utec on 21/06/19.
//

#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
enum class Opciones {
    Agregar = 1, Remover, Mostrar
}; // se usa un tipo enumerado para indicar las opciones


/*
 ********************
 *
 * Funciones de Ayuda
 *
 ********************
 */

void limpiar() {
#ifndef WIN32
    cout << "\033[2J\033[0;0H";
#else
    system("cls");
#endif
}

void esperar() {
    TipoCaracter w;
    do {
        w = input<TipoCaracter>("Presione C y Enter para continuar...");
    } while (toupper(w) != 'C');
}

/*
 ******************************
 *
 * Metodos de clase Menu
 *
 ******************************
 */

Menu::Menu(int altura, int ancho): tierra(altura, ancho), opcion{} {}

void Menu::agregarObjeto() {
}

void Menu::removerObjeto() {
}

void Menu::dibujarMapa() {
    limpiar();
    tierra.dibujarTierra();
}

void Menu::mostrarMenu() {
    limpiar();
    cout << "Menu\n";
    cout << string(4, '-') << "\n\n";
    cout << "1. Agregar un nuevo objeto\n";
    cout << "2. Remover objeto\n";
    cout << "3. Dibujar Mapa\n\n";
    cout << "0. Para Salir\n\n";
}

void Menu::seleccionarOpcion() {
    limpiar();
    switch(Opciones(opcion)) {
        case Opciones::Agregar:  // Agregar Objeto
            agregarObjeto();
            break;
        case Opciones::Remover:  // Remover Objeto
            removerObjeto();
            break;
        case  Opciones::Mostrar: // Dibujando Tierra
            dibujarMapa();
            break;
    }
}

void Menu::ejecutar() {
    do {
        mostrarMenu();
        cin >> opcion;
        seleccionarOpcion();
    } while (opcion != 0);
    cout << "Fin del programa...\n";
}
