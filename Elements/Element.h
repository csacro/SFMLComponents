/**
 * @author Carolin Schindler
 */

#ifndef SFMLCOMPONENTS_ELEMENT_H
#define SFMLCOMPONENTS_ELEMENT_H

#include <SFML/Graphics.hpp>

/**
 * abstract class that has to be inherited by all kind of Elements that should be drawn
 */
class Element {
public:
    /**
     * calls draw on all SFML/Graphics.hpp the Element consists of
     * @param renderWindow sf::RenderWindow that is drawing Element
     */
    virtual void draw(sf::RenderWindow &renderWindow) = 0;
};


#endif //SFMLCOMPONENTS_ELEMENT_H
