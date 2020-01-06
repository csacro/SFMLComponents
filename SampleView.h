/**
 * @author Carolin Schindler
 */

#ifndef SFMLCOMPONENTS_SAMPLEVIEW_H
#define SFMLCOMPONENTS_SAMPLEVIEW_H


#include "Elements/TextField.h"
#include "Elements/Button.h"
#include "Elements/EditField.h"
#include "Listener/OnClickListener.h"
#include "Listener/OnTextListener.h"
#include "WindowViews/WindowView.h"

class SampleView: public WindowView {
public:
    //Constructor
    SampleView(sf::Font &font);

    void draw(sf::RenderWindow &renderWindow) override;

    void listen(sf::Event event, sf::RenderWindow &renderWindow) override;

private:
    //Elements
    inline static TextField tf;
    inline static Button bt;
    inline static EditField ef;

    //Listener
    inline static OnClickListener btListener;
    inline static OnClickListener efListener;
    inline static OnTextListener textListener;

    //Listener methods
    static void btClickFunction(Listener *listener);
    static void efClickFunction(Listener *listener);
    static void textFunction(Listener *listener);
};


#endif //SFMLCOMPONENTS_SAMPLEVIEW_H
