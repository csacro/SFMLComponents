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
    //TODO: OnCloseListener and OnResizeListener

private:
    std::list<Element*> mElementList; //list containing all Elements
    std::list<Listener*> mListenerList; //list containing all Listeners
    bool listGotCleared = false;

    std::mutex elementLock;
    std::mutex listenerLock;

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
         elementLock.lock();
         mElementList.push_back(element);
         elementLock.unlock();
     };
     /**
      * add for mListenerLIst
     * @param listener Listener* to be inserted
      */
     void addListener(Listener* listener) {
         listenerLock.lock();
         mListenerList.push_back(listener);
         listenerLock.unlock();
     };
     /**
      * clear for mElementList and mListenerList
      */
     void clearLists(){
         listenerLock.lock();
         elementLock.lock();
         mElementList.clear();
         mListenerList.clear();
         listGotCleared = true;
         elementLock.unlock();
         listenerLock.unlock();
     };
};


#endif //SFMLCOMPONENTS_LISTENERRENDERWINDOW_H
