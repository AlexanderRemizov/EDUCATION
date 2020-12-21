#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Planet.hpp"
#include <cmath>
#include <ctime>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <codecvt>
#define centerX  1280
#define centerY  800
using namespace sf;
using namespace std;

int days (int month) 
{
    switch (month) {
        case 1: {
            return 0;
            break;
        }
        case 2: {
            return 31;
            break;
        }
        case 3: {
            return 59;
            break;
        }
        case 4: {
            return 90;
            break;
        }
        case 5: {
            return 120;
            break;
        }
        case 6: {
            return 151;
            break;
        }
        case 7: {
            return 181;
            break;
        }
        case 8: {
            return 212;
            break;
        }
        case 9: {
            return 243;
            break;
        }
        case 10: {
            return 273;
            break;
        }
        case 11: {
            return 304;
            break;
        }
        case 12: {
            return 334;
            break;
        }
    }
}

int main(int, char const**)
{
    sf::RenderWindow window(VideoMode(2000, 1000), "Our Solar System", Style::Fullscreen);

    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "src/sun.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "src/background.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "src/sansation.ttf")) {
        return EXIT_FAILURE;
    }
    
    sf::Text text("OUR", font, 40);
    text.setFillColor(sf::Color::White);
    text.setPosition(1120, 10);
    sf::Text text1("SOLAR", font, 40);
    text1.setFillColor(sf::Color::Yellow);
    text1.setPosition(1220, 10);
    sf::Text text2("SYSTEM", font, 40);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(1380, 10);
    sf::Text text3("Day   Month   Year", font, 40);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(100, 40);
    sf::Text textDate("", font, 50);
    textDate.setFillColor(sf::Color::Black);
    textDate.setPosition(100, 85);
    sf::Text incorrect("incorrect date", font, 40);
    incorrect.setFillColor(sf::Color(62, 70, 59));
    incorrect.setPosition(100, 150);
    sf::Text del("delete", font, 40);
    del.setFillColor(sf::Color(62, 70, 59));
    del.setPosition(400, 95);
    Text plus("+", font, 150);
    plus.setFillColor(Color::Yellow);
    plus.setPosition(200, 1400);
    Text minus("-", font, 150);
    minus.setFillColor(Color::Yellow);
    minus.setPosition(100, 1400);
    
    Texture DateTexture;
    DateTexture.loadFromFile(resourcePath() + "dates.png");
    Sprite Date;
    Date.setTexture(DateTexture);
    Date.setPosition(90, 90);
    
    std::vector<Planet> system;
    Texture SunTexture;
    SunTexture.loadFromFile(resourcePath() + "src/sun.png");
    Planet Sun(centerX, 0, SunTexture, 24.47, 0);
    system.push_back(Sun);
    Texture MercuryTexture;
    MercuryTexture.loadFromFile(resourcePath() + "src/Mercury.png");
    Planet Mercury(700, 110, MercuryTexture, 58.8, 1/0.241);
    system.push_back(Mercury);
    Texture VenusTexture;
    VenusTexture.loadFromFile(resourcePath() + "src/Venus.png");
    Planet Venus(600, 150, VenusTexture, -243, 1/0.61);
    system.push_back(Venus);
    Texture EarthTexture;
    EarthTexture.loadFromFile(resourcePath() + "src/Earth.png");
    Planet Earth(1100, 192, EarthTexture, 0.997222222, 1/1);
    system.push_back(Earth);
    Texture MarsTexture;
    MarsTexture.loadFromFile(resourcePath() + "src/Mars.png");
    Planet Mars(200, 260, MarsTexture, 0.9840277777, 1/1.88);
    system.push_back(Mars);
    Texture JupiterTexture;
    JupiterTexture.loadFromFile(resourcePath() + "src/Jupiter.png");
    Planet Jupiter(1350, 340, JupiterTexture, 0.410069444, 1/11.86);
    system.push_back(Jupiter);
    Texture SaturnTexture;
    SaturnTexture.loadFromFile(resourcePath() + "src/Saturn.png");
    Planet Saturn(520, 440, SaturnTexture, 0.59305555555, 1/29.46);
    system.push_back(Saturn);
    Texture UranusTexture;
    UranusTexture.loadFromFile(resourcePath() + "src/Uranus.png");
    Planet Uranus(700, 540, UranusTexture, -0.45069444444, 1/84.02);
    system.push_back(Uranus);
    Texture NeptuneTexture;
    NeptuneTexture.loadFromFile(resourcePath() + "src/Neptune.png");
    Planet Neptune(550, 710, NeptuneTexture, 0.652777777, 1/164.78);
    system.push_back(Neptune);
    
    sf::Font rus;
    if (!font.loadFromFile("1.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text hello("Привет", font, 20);
    hello.setColor(sf::Color::Red);
    
    string str;
    int date;
    int day = 0;
    int month = 0;
    int year = -1;
    bool request = false;
    int coefficient = 0;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    if (isdigit(static_cast<char>(event.text.unicode))) {
                        str += static_cast<char>(event.text.unicode);
                    }
                }
                std::ostringstream streamText;
                streamText << str;
                textDate.setString("" + streamText.str());
            }
            if (event.key.code == sf::Keyboard::Return) {
                if (str.size() > 3) {
                    std::istringstream (str) >> date;
                    if (str.size() == 5) {
                        year = date % 10;
                        date = date / 10;
                    }
                    if (str.size() == 6) {
                        year = date % 100;
                        date = date / 100;
                    }
                    if (str.size() == 7) {
                        year = date % 1000;
                        date = date / 1000;
                    }
                    if (str.size() == 8) {
                        year = date % 10000;
                        date = date / 10000;
                    }
                    if ((date % 100) < 13) {
                        month = date % 100;
                    }
                    if ((date / 100) < 32) {
                        day = date / 100;
                    }
                }
            }
            if (event.key.code == sf::Keyboard::BackSpace) {
                day = 0;
                month = 0;
                year = -1;
                str = "";
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                Vector2i localPosition = sf::Mouse::getPosition(window);
                if ((1478<=localPosition.y)&&(localPosition.y<=1525)) {
                    if ((100<=localPosition.x)&&(localPosition.x<=150)) {
                        coefficient = coefficient-1;
                    }
                    if ((200<=localPosition.x)&&(localPosition.x<=250)) {
                        coefficient = coefficient+1;
                    }
                }
            }
        }
        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(del);
        window.draw(Date);
        window.draw(textDate);
        window.draw(plus);
        window.draw(minus);
        window.draw(del);
        if ((day > 32) || (month > 12) || (year > 10000) || (day == 0) || (month == 0) || (year == -1)) {
            window.draw(incorrect);
            request = false;
        }
        else {
            request = true;
            for (int i = 0; i < system.size(); ++i) {
                long double now = 2018.1589;
                long double need;
                if (year % 4 == 0) {
                    need = (1 + days(month) + day)/366;
                }
                else {
                    need = (days(month) + day)/365;
                }
                need = need + year;
                long double tet = (need - now)*3.14159265*2;
                window.draw(system[i].drawTrajectory());
                window.draw(system[i].drawRequest(tet));
                
            }

        }
        if (!request) {
            for (int i = 0; i < system.size(); ++i) {
                window.draw(system[i].drawTrajectory());
                window.draw(system[i].motion(coefficient));
            }
        }
        window.display();
    }
    return EXIT_SUCCESS;
}
