/**
 * @author Carolin Schindler
 */

#ifndef SFMLCOMPONENTS_ONTEXTLISTENER_H
#define SFMLCOMPONENTS_ONTEXTLISTENER_H


#include "Listener.h"

/**
 * listens for "TextEnteredEvents"
 */
class OnTextListener: virtual public Listener {
public:
    void *dummy;
    sf::String mLastText; //last text that got entered

    /**
     * default Constructor
     */
     OnTextListener() = default;

    /**
     * Constructor
     * @param function void (*)() that is getting called by Listener
     */
    explicit OnTextListener(void (*function)())
        : Listener(function) {};

    void listen(sf::Event event, sf::RenderWindow &renderWindow) override;
};


#endif //SFMLCOMPONENTS_ONTEXTLISTENER_H
