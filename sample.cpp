#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window/ListenerRenderWindow.h"
#include "Elements/TextField.h"
#include "Elements/Button.h"
#include "Listener/OnClickListener.h"
#include "Elements/EditField.h"
#include "Listener/OnTextListener.h"
#include "SampleView.h"

int main() {
    setenv("DISPLAY", "127.0.0.1:0", true);

    ListenerRenderWindow lrw(sf::VideoMode(1000, 800), "Hexxagon", sf::Style::Default);

    sf::Font font;
    if (!font.loadFromFile("../arial.ttf")) {
        std::cout << "cannot load font" << std::endl;
    }

    SampleView s(font);
    lrw.addElement(&s);
    lrw.addListener(&s);

    lrw.clearLists();
    lrw.addElement(&s);
    lrw.addListener(&s);

    lrw.run(sf::Color::Cyan);
}
