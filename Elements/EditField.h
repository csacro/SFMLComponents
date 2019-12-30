/**
 * @author Carolin Schindler
 */

#ifndef SFMLCOMPONENTS_EDITFIELD_H
#define SFMLCOMPONENTS_EDITFIELD_H


#include "Button.h"

class EditField: public Button {
public:
    bool mEdit = false; //bool is true when text should be written to EditField

    /**
     * default Constructor
     */
    EditField() = default;

    /**
     * Constructor calling Button-Constructor
     */
    EditField(sf::Vector2i pos, sf::String &text, sf::Font &font, float minWidth, float minHeight)
            : Button(pos, text, font, minWidth, minHeight) {};

    /**
     * appends text to TextField if edit is true
     * @param lastText sf::String to add to current text
     */
    void addText(sf::String &lastText);
};


#endif //SFMLCOMPONENTS_EDITFIELD_H
