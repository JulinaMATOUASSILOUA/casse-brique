//
// Created by matouassiloua.julina on 04/05/2020.
//

// j'ai encore rien repartie dans les différentes classes pour le moment

#include <SFML/Graphics.hpp>
//#include <string>
//#include "balle.h"
#include <iostream>
#include <ctime>
using namespace sf;

bool isCollide(RectangleShape t2, Sprite t1) {
    return t1.getGlobalBounds().intersects(t2.getGlobalBounds());
}
int main() {
    int rand(time(0));
    int const FENETRE_LARGEUR = 1000;
    //int const FENETRE_HAUTEUR = 800;
    int const BALLE_RAYON = 10;
    int const VITESSE_BALLE = 40;
    int const VITESSE_BARRE = 5;
    int const LARGEUR_BARRE = 90;
    int const HAUTEUR_BARRE = 30;
    //   int i = 1;
    // int j = 1;
    //float PAUSE = 10;
    float posBarreX = 100;
    float posBarreY = 550;
    float posBalleX = 300;
    float posBalleY = 300;
    float dx = 6, dy = 5;
    float x = 300, y = 300;
    float dirBalleX = -1;
    float dirBalleY = 1;


// création de la fenetre
    const int WIDTH = 1000;
    const int HEIGHT = 800;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Casse-Brique");
    window.setFramerateLimit(60);

    Texture t1;
    t1.loadFromFile("block03.png");
    Sprite block[200];

    int n = 0;
    int i = 1;
    int j = 1;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            block[n].setTexture(t1);
            block[n].setPosition(sf::Vector2f(i*50, j*30));
            block[n].move(sf::Vector2f(30.f, 25.f));
            n++;
        }
    //Choix de la police
    std::string fontLocation = R"(C:\Windows\Fonts\arial.ttf)";
    sf::Font font;
    if (!font.loadFromFile(fontLocation))
    {
          std::cerr << "Chargement echoue" << std::endl;
        std::exit(-1);
    }

    //ecrire du texte
    sf::Text text;
    //sf::Font font;
    text.setFont(font);
        text.setString("Bonjour, je sais ecrire du texte du coup!");
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::Magenta);

    //barre
    sf::RectangleShape barre(sf::Vector2f(90, 30));
    barre.setFillColor(sf::Color::White);
    barre.setPosition(posBarreX, posBarreY);

    // petite balle
    sf::CircleShape Balle(15.f);
    Balle.setRadius(20);
    Balle.setOutlineThickness(4);
    Balle.setOutlineColor(sf::Color::Green);
    Balle.setFillColor(sf::Color::White);
    Balle.setPosition(posBalleX, posBalleY);
    


//
        // on fait tourner le programme tant que la fenetre n'a pas été fermée

        while (window.isOpen()) {
            // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
            sf::Event event{};
            while (window.pollEvent(event)) {
                // fermeture de la fenetre lorsque l'utilisateur le souhaite
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                Balle.move(VITESSE_BALLE, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                Balle.move(-VITESSE_BALLE, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                Balle.move(0, -VITESSE_BALLE);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                Balle.move(0, VITESSE_BALLE);
            }


            //
            if (Balle.getPosition().x <= 0)
                Balle.setPosition(sf::Vector2f(0, Balle.getPosition().y));

            if (Balle.getPosition().x > WIDTH - 20)
                Balle.setPosition(sf::Vector2f(WIDTH - 20, Balle.getPosition().y));

            if (Balle.getPosition().y <= 0)
                Balle.setPosition(sf::Vector2f(0, Balle.getPosition().x));

            if (Balle.getPosition().y > HEIGHT - 20)
                Balle.setPosition(sf::Vector2f(HEIGHT - 20, Balle.getPosition().x));
//
           // float dx = 6;
            //float dy = 5;

            //bool isCollide(RectangleShape t2, Sprite t1) {
              //  return t1.getGlobalBounds().intersects(t2.getGlobalBounds());
            //}
           Balle.move(dx,0);
            for(int i=0; i<0; i++)
                if (isCollide(RectangleShape(),block[i])){
                    block[i].setPosition(-100,0); dx=-dx;
                }

            Balle.move(0,dy);
            for(int i=0; i<0; i++)
                if (isCollide(RectangleShape(),block[i])){
                    block[i].setPosition(sf::Vector2f(60.f, 70.f)); dy=-dy;
                }
//
//
            Balle.move(dx,dy);
            Vector2f b = Balle.getPosition();
            if(b.x<0 || b.y>1000) dx=-dx;
            if(b.y<0 || b.y>800) dy=-dy;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) barre.move(6,0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) barre.move(-6,0);

            if(isCollide(RectangleShape(),Sprite())) dy=-(0%5+2);
            {

            }

//                //
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//                barre.move(VITESSE_BARRE, 0);
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//                barre.move(-VITESSE_BARRE, 0);
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//                barre.move(0, -VITESSE_BARRE);
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//                barre.move(0, VITESSE_BARRE);
//            }

            if (barre.getPosition().x <= 0)
                barre.setPosition(sf::Vector2f(0, barre.getPosition().y));

            if (barre.getPosition().x > WIDTH - LARGEUR_BARRE)
                barre.setPosition(sf::Vector2f(WIDTH - LARGEUR_BARRE, barre.getPosition().y));

            if (barre.getPosition().y <= 0)
                barre.setPosition(sf::Vector2f(0, barre.getPosition().x));

            if (barre.getPosition().y > HEIGHT - HAUTEUR_BARRE)
                barre.setPosition(sf::Vector2f(HEIGHT - HAUTEUR_BARRE, barre.getPosition().x));


    //collision entre la balle et la fenetre
            if (posBalleX >= FENETRE_LARGEUR-BALLE_RAYON || posBalleX <= 0 + BALLE_RAYON)
                dirBalleX = -dirBalleY;
                        if(posBalleY <= 0 + BALLE_RAYON)
                            dirBalleY = -dirBalleY;
//
                window.clear();
                window.draw(barre);
                window.draw(Balle);
                window.draw(text);
                for(int i=0; i<n; i++)
                window.draw(block[i]);
                window.display();
                window.clear(sf::Color::Black);
        }

        return 0;
}










