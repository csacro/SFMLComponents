/**
 * @author Carolin Schindler
 */

#include "ListenerRenderWindow.h"

void ListenerRenderWindow::run() {
    while (this->isOpen()) {
        sf::Event event;
        while(this->pollEvent(event)) {
            for(Listener *l: mListenerList) {
                l->listen(event, *this);
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
        this->clear(sf::Color::Black);
        for(Element *e: mElementList) {
            e->draw(*this);
        }
        this->display();
    }
}
