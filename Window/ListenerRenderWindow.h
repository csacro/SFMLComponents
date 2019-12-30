/**
 * @author Carolin Schindler
 */

#ifndef SFMLCOMPONENTS_LISTENERRENDERWINDOW_H
#define SFMLCOMPONENTS_LISTENERRENDERWINDOW_H


#include <list>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Elements/Element.h"
#include "../Listener/Listener.h"

/**
 * class adds std::list for Elements and Listener to RenderWindow
 * simplifies handling of sf::Events
 */
class ListenerRenderWindow: public sf::RenderWindow {
private:
    std::list<Element*> mElementList; //list containing all Elements
    std::list<Listener*> mListenerList; //list containing all Listeners

public:
    /**
     * default Constructor
     */
     ListenerRenderWindow() = default;

    /**
     * Constructor calling RenderWindow-Constructor
     */
    ListenerRenderWindow(sf::VideoMode mode, const sf::String &title) : RenderWindow(mode, title) {};

    /**
     * handles sf::Events and redraw
     */
    void run();

    /**
     * add for mElementList
     * @param element Element* to be inserted
     */
     void addElement(Element* element) {mElementList.push_back(element);};
     /**
      * add for mListenerLIst
     * @param listener Listener* to be inserted
      */
     void addListener(Listener* listener) {mListenerList.push_back(listener);};
};


#endif //SFMLCOMPONENTS_LISTENERRENDERWINDOW_H
