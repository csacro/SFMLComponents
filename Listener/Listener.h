/**
 * @author Carolin Schindler
 */

#ifndef SFMLCOMPONENTS_LISTENER_H
#define SFMLCOMPONENTS_LISTENER_H


#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

/**
 * abstract class that has to be inherited by all kind of Listeners
 */
class Listener {
public:
    /**
     * calls mFunction if event is one that is listened at
     * (should be called by sf::Window after poll(event))
     * @param event sf::Event that has been polled by sf::Window
     * @param renderWindow sf::RenderWindow which polled event
     */
    virtual void listen(sf::Event event, sf::RenderWindow &renderWindow) = 0;

protected:
    void (*mFunction)(Listener *listener) = {}; //function getting called by Listener

    /**
     * default Constructor
     */
     Listener() = default;

    /**
     * Constructor setting mFunction
     * @param function void (*)(Listener *listener) that is getting called by Listener
     */
    Listener(void (*function)(Listener *listener)) {
        mFunction = function;
    };
};


#endif //SFMLCOMPONENTS_LISTENER_H
