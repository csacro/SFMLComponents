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
    ListenerRenderWindow lrw(sf::VideoMode(1000, 800), "Hexxagon");

    sf::Font test;
    if (!test.loadFromFile("../arial.ttf")) {
        std::cout << "cannot load font" << std::endl;
    }

    SampleView s(test);
    lrw.addElement(&s);
    lrw.addListener(&s);

    lrw.run(sf::Color::Cyan);
}
