/**
 * @author Carolin Schindler
 */

#include "ListenerRenderWindow.h"

void ListenerRenderWindow::run(sf::Color clearColor) {
    while (this->isOpen()) {
        sf::Event event;
        while(this->pollEvent(event)) {
            for(auto it = mListenerList.begin(); !listGotCleared && it != mListenerList.end(); it++) {
                (*it)->listen(event, *this);
            }
            if(listGotCleared) {
                listGotCleared = false;
            }
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
        this->clear(clearColor);
        for(Element *e: mElementList) {
            e->draw(*this);
        }
        this->display();
    }
}
