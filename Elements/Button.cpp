/**
 * @author Carolin Schindler
 */

#include "Button.h"

bool Button::isPointInElement(sf::Vector2i point) {
    sf::FloatRect shape = mRectangle.getGlobalBounds();
    return shape.contains(point.x, point.y);
}

Button::Button(sf::Vector2i pos, sf::String &text, sf::Font &font, float minWidth, float minHeight)
    : TextField(pos, text, font, minWidth+1, minHeight+1) {
    float outline = 5.0;
    mRectangle.setOutlineThickness(outline/2);
    mRectangle.setOutlineColor(sf::Color::Black);
}