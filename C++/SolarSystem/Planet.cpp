#include "Planet.hpp"
using namespace sf;

Planet::Planet(int _coord, const int _radTrajectory, const Texture& _planetTexture, const long double _period, const long double _speed): coord(_coord), radTrajectory(_radTrajectory), planetTexture(_planetTexture), rotation(0), tetha(0), period(_period), speed(_speed), ellipse(_radTrajectory/10)
{
    planetSprite.setTexture(planetTexture);
    planetSprite.setOrigin(planetSprite.getLocalBounds().width/2.0f, planetSprite.getLocalBounds().height/2.0f);
    trajectory.setRadius(radTrajectory);
    trajectory.setPointCount(200);
    trajectory.setScale(1.1, 1);
    trajectory.setFillColor(Color::Transparent);
    trajectory.setOutlineThickness(1);
    trajectory.setOrigin(trajectory.getLocalBounds().width/2.0f,trajectory.getLocalBounds().height/2.0f);
    trajectory.setPosition(centerX, centerY);
}

CircleShape Planet::drawTrajectory()
{
    return trajectory;
}

Sprite Planet::motion(int coeff) 
{
    rotation += 36*3/period; // speed around yourself
    if (coeff>=0) {
        tetha+=0.0055*(coeff+1);
    }
    else {
        tetha+=0.0055*coeff;
    }
    x = (radTrajectory + ellipse) * cos(tetha * speed + coord) + centerX;
    y = (radTrajectory) * sin(tetha * speed + coord) + centerY;
    planetSprite.setPosition(x, y);
    planetSprite.setRotation(rotation);
    return planetSprite;
}

Sprite Planet::drawRequest(const long double tet)
{
    x = (radTrajectory + ellipse) * cos(tet * speed + coord) + centerX;
    y = (radTrajectory) * sin(tet * speed + coord) + centerY;        
    planetSprite.setPosition(x, y);
    return planetSprite;
}
