/**
 * @author Carolin Schindler
 */

#ifndef SFMLCOMPONENTS_CLICKABLEELEMENT_H
#define SFMLCOMPONENTS_CLICKABLEELEMENT_H


#include <SFML/System.hpp>
#include "Element.h"

/**
 * abstract class that has to be inherited by all Elements interacting with OnClickListener
 */
class ClickableElement: virtual public Element {
public:
    /**
     * checks wether point is part of the Element or not
     * @param point sf::Vector2f is point to check
     * @return true if point is part of Element, false if not
     */
    virtual bool isPointInElement(sf::Vector2i point) = 0;
};


#endif //SFMLCOMPONENTS_CLICKABLEELEMENT_H
