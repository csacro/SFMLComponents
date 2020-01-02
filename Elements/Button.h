/**
 * @author Carolin Schindler
 */

#ifndef SFMLCOMPONENTS_BUTTON_H
#define SFMLCOMPONENTS_BUTTON_H


#include "TextField.h"
#include "ClickableElement.h"

/**
 * is a TextField that is "Clickable"
 */
class Button: public TextField, virtual public ClickableElement {
public:
    /**
     * default Constructor
     */
    Button() = default;

    /**
     * Constructor calling TextField-Constructor
     */
    Button(sf::Vector2i pos, sf::String &text, sf::Font &font, float minWidth, float minHeight);

    bool isPointInElement(sf::Vector2i point) override;
};


#endif //SFMLCOMPONENTS_BUTTON_H
