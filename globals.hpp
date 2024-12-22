#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#define isKeyPressed sf::Keyboard::isKeyPressed
#define isButtonPressed sf::Mouse::isButtonPressed


static constexpr auto PI = 3.1415926535897932; //mmm yummy precision
static constexpr auto FRAMERATE = 60; //constant for now but will be able to be changed in settings
static constexpr auto MINE = 9;


//returns the position of the mouse relative to the window,
//this is basically a rename since its one line of code lol
static sf::Vector2f mousePos(const sf::RenderWindow& window)
{
    return sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
}


//returns a point based on an ease in movement setup, as long as t increases at a constant rate
//t MUST be between 0 and 1 for proper easing
static sf::Vector2f easeIn(const sf::Vector2f point1, const sf::Vector2f point2, const float t)
{
    const sf::Vector2f d = point2 - point1;
    const float ease = t * t;

    return {point1.x + d.x * ease, point1.y + d.y * ease};
}


//returns a point based on an ease out movement setup, as long as t increases at a constant rate
//t MUST be between 0 and 1 for proper easing
static sf::Vector2f easeOut(const sf::Vector2f point1, const sf::Vector2f point2, const float t)
{
    const sf::Vector2f d = point2 - point1;
    const float ease = -t * (t - 2);

    return {point1.x + d.x * ease, point1.y + d.y * ease};
}


//returns a point based on an ease in ease out movement setup, as long as t increases at a constant rate
//t MUST be between 0 and 1 for proper easing
static sf::Vector2f easeInOut(const sf::Vector2f point1, const sf::Vector2f point2, const float t)
{
    const sf::Vector2f d = point2 - point1;
    const float ease = t * t * (3.f - 2.f * t);

    return {point1.x + d.x * ease, point1.y + d.y * ease};
}


//returns the distance between the two points.
static float distBetween(const sf::Vector2f point1, const sf::Vector2f point2)
{
    const sf::Vector2f d = point1 - point2;
    return hypotf(d.x, d.y);
}