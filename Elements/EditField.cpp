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
