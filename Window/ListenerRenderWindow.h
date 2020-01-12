/**
 * @author Carolin Schindler
 */

#ifndef SFMLCOMPONENTS_LISTENERRENDERWINDOW_H
#define SFMLCOMPONENTS_LISTENERRENDERWINDOW_H


#include <iostream>
#include <list>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <mutex>
#include "../Elements/Element.h"
#include "../Listener/Listener.h"

/**
 * class adds std::list for Elements and Listener to RenderWindow
 * simplifies handling of sf::Events
 */
class ListenerRenderWindow: public sf::RenderWindow {
    //TODO: make Lists Thread-safe
    //TODO: OnCloseListener and OnResizeListener

private:
    std::list<Element*> mElementList; //list containing all Elements
    std::list<Listener*> mListenerList; //list containing all Listeners
    bool listGotCleared = false;

public:
    /**
     * default Constructor
     */
     ListenerRenderWindow() = default;

    /**
     * Constructor calling RenderWindow-Constructor
     */
    ListenerRenderWindow(sf::VideoMode mode, const sf::String &title, sf::Uint32 style)
        : RenderWindow(mode, title, style) {};

    /**
     * handles sf::Events and redraw
     * @param clearColor sf::Color used to clear Window
     */
    void run(sf::Color clearColor);

    /**
     * add for mElementList
     * @param element Element* to be inserted
     */
     void addElement(Element* element) {
         mElementList.push_back(element);
     };
     /**
      * add for mListenerLIst
     * @param listener Listener* to be inserted
      */
     void addListener(Listener* listener) {
         mListenerList.push_back(listener);
     };
     /**
      * clear for mElementList and mListenerList
      */
     void clearLists(){
         mElementList.clear();
         mListenerList.clear();
         listGotCleared = true;
     };
};


#endif //SFMLCOMPONENTS_LISTENERRENDERWINDOW_H
