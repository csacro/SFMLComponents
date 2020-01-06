/**
 * @author Carolin Schinlder
 */

#ifndef SFMLCOMPONENTS_ONCLICKLISTENER_H
#define SFMLCOMPONENTS_ONCLICKLISTENER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Listener.h"
#include "../Elements/ClickableElement.h"

/**
 * listens for "ClickEvents"
 */
class OnClickListener: virtual public Listener {
private:
    ClickableElement *mClickableElement; //Clickable Element that is listened on
    bool mPressed = false; //true if MouseButton has been Pressed but not Released yet
public:
    /**
     * default Constructor
     */
    OnClickListener() = default;

    /**
     * Constructor
     * @param clickableElement ClickableElement& that is listened on
     * @param function void (*)(Listener *listener) that is getting called by Listener
     */
    OnClickListener(ClickableElement &clickableElement, void (*function)(Listener *listener));

    void listen(sf::Event event, sf::RenderWindow &renderWindow) override;
};


#endif //SFMLCOMPONENTS_ONCLICKLISTENER_H
