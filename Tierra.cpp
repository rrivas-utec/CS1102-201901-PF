//
// Created by utec on 21/06/19.
//
#include "Tierra.h"
#include <string>
#include <iomanip>
#include <map>
#include <algorithm>
#include "Objeto.h"
#include "Tierra.h"


map<char, sf::Color> listaColores = {
        {'R', sf::Color::Red},
        {'G', sf::Color::Green},
        {'B', sf::Color::Blue}};


using namespace std;

Tierra::Tierra() : altura{}, ancho{} {
    plano = nullptr;
}

Tierra::Tierra(TipoEntero altura, TipoEntero ancho) : altura{altura}, ancho{ancho} {
    plano = new sf::RenderWindow();
}

Tierra::~Tierra() {
    delete plano;
}

void Tierra::adicionarObjeto(Objeto *objeto) {
    objetos.emplace_back(objeto);
}

Objeto *Tierra::removerObjeto(string &nombre) {
// Si vector esta vacio
    if (objetos.size() == 0)
        return nullptr;
// Buscando objeto
    auto iter = find_if(begin(objetos), end(objetos),
                        [&nombre](Objeto *obj) { return obj->getNombre() == nombre; });
    if (iter != end(objetos)) {
// Eliminando la referencia al puntero objeto dentro del vector objetos
        objetos.erase(iter);
//-- si encuentra al objeto lo separa del vector,
//-- (no libera de memoria el objeto encontrado), esto se hará en el menú,
//-- donde fue asignado, debido a que el objeto no es parte sino el objeto es un visitante.
        return *iter;
    }
// Si vector esta vacio
    return nullptr;
}

void Tierra::imprimirObjetos() {
    int i = 0;
    for (auto &item: objetos) {
        cout << "* * * * * * [" << i << "] ";
        cout << " Nombre = " << item->getNombre() << " "
             << item->mostrarPosicion()
             << " Color = " << item->getColor() << '\n';
        i++;
    }
}

void Tierra::actualizarTierra() {
    plano->clear();
    for (auto obj: objetos) {
        sf::CircleShape shape(10);
        shape.setPosition(static_cast<float>(obj->getPosX()), static_cast<float>(obj->getPosY()));
        shape.setFillColor(listaColores[obj->getColor()]);
        plano->draw(shape);
    }
    plano->display();
}
void Tierra::dibujarTierra() {

    // Verifica si plano ha sido creado anteriormente
    if (!plano->isOpen())
        plano->create(sf::VideoMode(ancho, altura), "Proyecto Final - Presione [ESC] para salir... ");
    else
        plano->display();

    // Bucle principal
    while (plano->isOpen()) {
        capturarEventos();
        actualizarTierra();
    }
}

TipoEntero Tierra::getAltura() {
    return plano->getSize().y;
}

TipoEntero Tierra::getAncho() {
    return plano->getSize().x;
}

TipoEntero Tierra::getCantidadObjectos() {
    return objetos.size();
}

void Tierra::capturarEventos() {
    sf::Event event{};

    while (plano->pollEvent(event)) {

        switch (event.type) {
            case sf::Event::Closed:
                plano->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    plano->close();
                break;
        }
    }
}
