#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window/ListenerRenderWindow.h"
#include "Elements/TextField.h"
#include "Elements/Button.h"
#include "Listener/OnClickListener.h"
#include "Elements/EditField.h"
#include "Listener/OnTextListener.h"

TextField tf;
Button bt;
EditField ef;

OnClickListener btListener;
OnClickListener efListener;
OnTextListener textListener;

void btClickFunction() {
    ef.mEdit = false;
    static int count = 0;
    count++;
    sf::String text = "Got clicked " + std::to_string(count) + " times";
    bt.setText(text);
}

void efClickFunction() {
    ef.mEdit = true;
}

void textFunction() {
    ef.addText(textListener.mLastText);
}

int main() {
    ListenerRenderWindow lrw(sf::VideoMode(1000, 800), "Hexxagon");

    sf::Font font;
    if (!font.loadFromFile("../arial.ttf")) {
        std::cout << "no font in main" << std::endl;
    }

    sf::Vector2i pos(20,20);
    sf::String text("TextField");
    tf = TextField(pos, text, font, 0, 0);
    lrw.addElement(&tf);

    pos.y += 60;
    sf::String buttonText("Click me");
    bt = Button(pos, buttonText, font, 0, 0);
    lrw.addElement(&bt);
    btListener = OnClickListener(bt, btClickFunction);
    lrw.addListener(&btListener);

    pos.y += 60;
    sf::String editText("");
    ef = EditField(pos, editText, font, 5, 5);
    lrw.addElement(&ef);
    efListener = OnClickListener(ef, efClickFunction);
    lrw.addListener(&efListener);

    textListener = OnTextListener(textFunction);
    lrw.addListener(&textListener);

    lrw.run();
}
