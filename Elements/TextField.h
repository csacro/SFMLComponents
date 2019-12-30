/**
 * @author Carolin Schindler
 */

#ifndef SFMLCOMPONENTS_TEXTFIELD_H
#define SFMLCOMPONENTS_TEXTFIELD_H

#include <SFML/Graphics.hpp>
#include "Element.h"

/**
 * is a sf::Text with a sf::RectangleShape in the background
 */
class TextField: virtual public Element {
protected:
    sf::Vector2i mPos; //position where the TextField is rendered
    sf::Text mText; //text of the TextField
    sf::RectangleShape mRectangle; //background of the TextField
    sf::FloatRect mMinSize; //minimal Size for TextField

public:
    /**
     * default Constructor
     */
    TextField() = default;

    /**
     * Constructor for TextField
     * @param pos sf::Vector2f which gives the position to place the TextField at
     * @param text std::string which is displayed by TextField
     * @param font sf::Font of text in TextField
     */
    TextField(sf::Vector2i pos, sf::String &text, sf::Font &font, float minWidth, float minHeight);

    /**
     * changes the text of the TextField
     * @param text sf::String to be displayed
     */
    void setText(sf::String &text);
    /**
     * get the current text of the TextField
     */
     sf::String getText();

    void draw(sf::RenderWindow &renderWindow) override;

private:
    void adjustSizeAndPosition();
};


#endif //SFMLCOMPONENTS_TEXTFIELD_H
