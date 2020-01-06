/**
 * @author Carolin Schindler
 */

#include "OnTextListener.h"

void OnTextListener::listen(sf::Event event, sf::RenderWindow &renderWindow) {
    switch(event.type) {
        case sf::Event::TextEntered:
            mLastText = event.text.unicode;
            mFunction(this);
            break;
        default:
            //do nothing
            break;
    }
}
