#include <iostream>

#include <SFML/OpenGL.hpp>

#include "model/Actor.h"
#include "view/GameWindow.h"

int
main()
{
    // crée la fenêtre
    sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(false);

    // activation de la fenêtre
    window.setActive(true);

    // chargement des ressources, initialisation des états OpenGL, ...
    sf::Clock clock;
    float lastTime = 0;

    // la boucle principale
    bool running = true;
    while (running) {
        // gestion des évènements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // on stoppe le programme
                running = false;
            } else if (event.type == sf::Event::Resized) {
                // on ajuste le viewport lorsque la fenêtre est redimensionnée
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        // effacement les tampons de couleur/profondeur
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // dessin...

        // termine la trame courante (en interne, échange les deux tampons de rendu)
        window.display();
    }

    // libération des ressources...

    return 0;
}
