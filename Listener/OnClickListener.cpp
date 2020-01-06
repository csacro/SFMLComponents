/**
 * @author Carolin Schindler
 */

#include "OnClickListener.h"

OnClickListener::OnClickListener(ClickableElement &clickableElement, void (*function)(Listener *listener))
    : Listener(function) {
    mClickableElement = &clickableElement;
}

void OnClickListener::listen(sf::Event event, sf::RenderWindow &renderWindow) {
    if(mClickableElement->isVisible) {
        switch (event.type) {
            case sf::Event::MouseButtonPressed:
                if (mClickableElement->isPointInElement(sf::Mouse::getPosition(renderWindow))) {
                    mPressed = true;
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (mPressed) {
                    mPressed = false;
                    if (mClickableElement->isPointInElement(sf::Mouse::getPosition(renderWindow))) {
                        mFunction(this);
                    }
                }
                break;
            default:
                //do nothing
                break;
        }
    }
}
