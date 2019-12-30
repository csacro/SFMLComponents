/**
 * @author Carolin Schindler
 */

#ifndef SFMLCOMPONENTS_WINDOWVIEW_H
#define SFMLCOMPONENTS_WINDOWVIEW_H


#include "../Listener/Listener.h"
#include "../Elements/Element.h"

/**
 * abstract class that has to be inherited by all WindowViews which are grouping Elements and Listeners
 */
class WindowView: virtual public Element, virtual public Listener {
};


#endif //SFMLCOMPONENTS_WINDOWVIEW_H
