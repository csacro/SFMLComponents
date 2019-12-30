/**
 * @author Carolin Schindler
 */

#include <iostream>
#include "TextField.h"

float getMaxFloat(float is, float min, float *margin) {
    if(is >= min) {
        return is;
    } else {
        *margin = is - min;
        return min;
    }
}

void TextField::adjustSizeAndPosition() {
    sf::FloatRect textBounds = mText.getLocalBounds();
    sf::FloatRect shape = textBounds;
    float marginWidth = 0;
    float marginHeight = 0;
    shape.width = getMaxFloat(textBounds.width, mMinSize.width, &marginWidth);
    shape.height = getMaxFloat(textBounds.height, mMinSize.height, &marginHeight);
    int margin = 10;
    mRectangle.setSize(sf::Vector2f(shape.width + margin, shape.height + margin));
    mRectangle.setPosition(mPos.x + shape.left - (margin+marginWidth)/2, mPos.y + shape.top - (margin+marginHeight)/2);
    mText.setPosition(mPos.x, mPos.y);
}

TextField::TextField(sf::Vector2i pos,
                     sf::String &text, sf::Font &font,
                     float minWidth, float minHeight) {

    mPos = pos;
    mMinSize.width = minWidth;
    mMinSize.height = minHeight;

    mText.setFont(font); //TODO: sf::Font causes Segmentation fault
    mText.setString(text);
    mText.setFillColor(sf::Color::Black);

    adjustSizeAndPosition();

}

void TextField::setText(sf::String &text) {
    mText.setString(text);
    adjustSizeAndPosition();
}
sf::String TextField::getText() {
    return mText.getString();
}

void TextField::draw(sf::RenderWindow &renderWindow) {
    renderWindow.draw(mRectangle);
    renderWindow.draw(mText);
}
