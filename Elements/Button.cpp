/**
 * @author Carolin Schindler
 */

#include "Button.h"

bool Button::isPointInElement(sf::Vector2i point) {
    sf::FloatRect shape = mRectangle.getGlobalBounds();
    return shape.contains(point.x, point.y);
}
