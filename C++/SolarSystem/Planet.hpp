#ifndef Planet_hpp
#define Planet_hpp
#include <SFML/Graphics.hpp>

class Planet 
{
public:
    Planet(int _coord, const int _radTrajectory, const sf::Texture& _planetTexture, const long double _period, const long double _speed);
    sf::CircleShape drawTrajectory();
    sf::Sprite motion(int coeff);
    sf::Sprite drawRequest(const long double tet);
private:
    sf::CircleShape trajectory;
    sf::Sprite planetSprite;
    const sf::Texture& planetTexture;
    const int radTrajectory;
    int x;
    int y;
    int coord;
    long double tetha;
    long double rotation;
    const int ellipse;
    const long double period;
    const long double speed;
};
#endif