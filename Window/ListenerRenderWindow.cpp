/**
 * @author Carolin Schindler
 */

#include "ListenerRenderWindow.h"

void ListenerRenderWindow::run(sf::Color clearColor) {
    while (this->isOpen()) {
        sf::Event event;
        while(this->pollEvent(event)) {
            listenerLock.lock();
            for(auto it = mListenerList.begin(); !listGotCleared && it != mListenerList.end(); it++) {
                (*it)->listen(event, *this);
            }
            if(listGotCleared) {
                listGotCleared = false;
            }
            listenerLock.unlock();
            sf::FloatRect visibleArea;
            switch(event.type) {
                case sf::Event::Closed:
                    this->close();
                    break;
                case sf::Event::Resized:
                    visibleArea = sf::FloatRect(0.f, 0.f, event.size.width, event.size.height);
                    this->setView(sf::View(visibleArea));
                    break;
                default:
                    //do nothing
                    break;
            }
        }
        elementLock.lock();
        this->clear(clearColor);
        for(Element *e: mElementList) {
            e->draw(*this);
        }
        elementLock.unlock();
        this->display();
    }
}
