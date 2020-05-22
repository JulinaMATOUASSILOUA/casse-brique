//
// Created by matouassiloua.julina on 04/05/2020.
//

// j'ai encore rien repartie dans les différentes classes pour le momment

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "balle.h"

int main() {
    int const FENETRE_LARGEUR = 1000;
   // int const FENETRE_HAUTEUR = 800;
    int const BALLE_RAYON = 10;
    int const VITESSE_BALLE = 5;
    float PAUSE =  10;
    float posBarreX = 100;
    float posBarreY = 550;
    float posBalleX = 90;
    float posBalleY = 500;
    float dirBalleX = -1;
    float dirBalleY = 1;


// création de la fenetre
    const int WIDTH = 1000;
    const int HEIGHT = 800;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Casse-Brique");
    window.setFramerateLimit(60);

    // Charge un sprite à afficher
    sf::Texture image;
    if (!image.loadFromFile("sprite.png"))
    {
     return EXIT_FAILURE;
     }
    sf::Sprite sprite(image);
    sprite.setTexture(image);
    // position
    sprite.setPosition(sf::Vector2f(60.f, 70.f)); // position absolue
    sprite.move(sf::Vector2f(10.f, 15.f)); // décalage relatif à la position actuelle

    // Choix de la police à utiliser
    std::string fontLocation = R"(C:\Windows\Fonts\arial.ttf)";
    sf::Font font;
    if (!font.loadFromFile(fontLocation)) {
        std::cerr << "Chargement échouée" << std::endl;
        std::exit(-1);
    }
    // ecrire du texte
    sf::Text text;
    text.setFont(font);
    text.setString("Bonjour, je sais donc ecrire du texte !");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Green);

    // définit un cercle
    //sf::CircleShape shape(90.f);
    //shape.setOutlineColor(sf::Color(250, 150, 100));

    // définit un rectangle de 120x50
    //sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    // change sa taille en 200x200
    // rectangle.setSize(sf::Vector2f(200.f, 200.f));
    // rectangle.setPosition(300,300);
    //rectangle.setFillColor(sf::Color(150, 140, 0));

    //barre
    sf::RectangleShape barre(sf::Vector2f(90, 30));
    barre.setFillColor(sf::Color::White);
    barre.setPosition(100, 550);
    barre.setPosition(posBarreX,posBarreY);
    // petite balle
    sf::CircleShape Balle(15.f);
    Balle. setRadius (20 );
    Balle. setOutlineThickness ( 4 );
    Balle. setOutlineColor (sf :: Color :: Green);
    Balle. setFillColor (sf :: Color :: White);
    //Balle.setPosition(sf::Vector2f(90, 500));
    Balle.setPosition(posBalleX,posBalleY);

    // on fait tourner le programme tant que la fenetre n'a pas été fermée
    while (window.isOpen()) {

        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event{};
        while (window.pollEvent(event)) {
            // fermeture de la fenetre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //gestion de clavier
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
          //  Balle.move(0, -1);
        //} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
          //  Balle.move(0, 1);
        //} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
          //  Balle.move(-1, 0);
        //} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
          //  Balle.move(1, 0);
        //});

        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);
        //dessine toutes les formes
        //window.draw(shape);
        window.draw(sprite);
        window.draw(Balle);
        window.draw(barre);
        window.draw(text);
        // DEFINITION DES TOUCHES QUI VONT BOUGER LA BARRE
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        }
            if (posBarreX + 100 < 1000) {
                posBarreX = posBarreX + PAUSE;
            }

                if (posBalleX + 100 / 2 < 1000) {
                    posBalleX = posBalleX + PAUSE;

                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    if(posBalleX + 100 < 1000){
                   // if (posBarreX > 0) {
                        posBarreX = posBarreX + PAUSE;

                        if (posBalleX - 100 / 2 > 0) {
                            posBalleX = posBalleX - PAUSE;

                        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                            dirBalleX = -1;
                            dirBalleY = 1;
                        }
                        barre.setPosition(posBarreX, posBarreY);
                        break;
                    }
                }
        //collision entre la balle et la barre
        sf::FloatRect boundingBox = barre.getGlobalBounds();

        sf::FloatRect otherBox = Balle.getGlobalBounds();
        if (boundingBox.intersects(otherBox))
        {
            dirBalleY = - dirBalleY;
        }
        //mouvement de la balle
        posBalleX += dirBalleX * VITESSE_BALLE;
        posBalleY += dirBalleY * VITESSE_BALLE;
        Balle.setPosition(posBalleX,posBalleY);

        //collision entre la balle et la fenetre
        if (posBalleX >= FENETRE_LARGEUR-BALLE_RAYON || posBalleX <= 0+BALLE_RAYON)
            dirBalleX = - dirBalleX;
        if (posBalleY <= 0+BALLE_RAYON)
            dirBalleY = - dirBalleY;

               // fin de la frame courante
                window.display();
        sf::sleep(sf::milliseconds(PAUSE));
                window.clear();
            }
            return 0;
        }