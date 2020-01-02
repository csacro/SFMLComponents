/**
 * @author Carolin Schindler
 */

#include "EditField.h"

void EditField::addText(sf::String &lastText) {
    if(mEdit) {
        sf::String curText = getText();
        if(lastText == '\b') {
            if(!curText.isEmpty()) {
                curText.erase(curText.getSize() - 1, 1);
            }
        } else {
            curText += lastText;
        }
        setText(curText);
    }
}

bool EditField::isPointInElement(sf::Vector2i point) {
    sf::FloatRect shape = mRectangle.getGlobalBounds();
    return shape.contains(point.x, point.y);
}
