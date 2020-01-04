/**
 * @author Carolin Schindler
 */

#include <iostream>
#include "SampleView.h"


SampleView::SampleView(sf::Font &font) {
    //Elements
    sf::Vector2i pos(20,20);

    sf::String text("TextField");
    tf = TextField(pos, text, font, 0, 0);

    pos.y += 60;
    sf::String buttonText("Click me");
    bt = Button(pos, buttonText, font, 0, 0);

    pos.y += 60;
    sf::String editText("");
    ef = EditField(pos, editText, font, 5, 5);


    //Listener
    btListener = OnClickListener(bt, btClickFunction);
    efListener = OnClickListener(ef, efClickFunction);
    textListener = OnTextListener(textFunction);
}

void SampleView::btClickFunction() {
    static int count = 0;
    ef.mEdit = false;
    count++;
    sf::String text = "Got clicked " + std::to_string(count) + " times";
    bt.setText(text);
    bt.isVisible = true;
    if(count%3 == 0) {
        bt.isVisible = false;
    }
}

void SampleView::efClickFunction() {
    ef.mEdit = true;
}

void SampleView::textFunction() {
    ef.addText(textListener.mLastText);
}

void SampleView::draw(sf::RenderWindow &renderWindow) {
    tf.draw(renderWindow);
    bt.draw(renderWindow);
    ef.draw(renderWindow);
}

void SampleView::listen(sf::Event event, sf::RenderWindow &renderWindow) {
    btListener.listen(event, renderWindow);
    efListener.listen(event, renderWindow);
    textListener.listen(event, renderWindow);
}
