# SFMLComponents
Library with simple and dumb GUI Components for SFML

## Installation
### Dependencies
* SFML-Library
```bash
sudo apt-get install libsfml-dev
```

### SFMLComponents
```bash
git clone https://github.com/csacro/SFMLComponents.git
cd SFMLComponents
mkdir build && cd build
cmake ..
make
sudo make install
sudo ld config
```

## Usage
### Window
sf:RenderWindow that support list of Elements that are drawn and list of Listeneres that are listended at.
### Listener
Diverse Listeneres
* OnClickListeners listens for click on ClickableElement and executes defined function on click
* OnTestListener listens for text input
### Elements
Diverse Elements
* Elementis base class for every Element
* ClickableElement is base class for every Element an OnClickListener should listen at
* TextField is a sf::Text with a sf::Rectangle in the background
* EditField is a TextField that can be clicked and written to characterwise
* Button is a TextField with black edging that can be clicked
### WindowViews
* Can be inherited by a class displaying a View with diverse Elements and Listeners.
### Linking
```make
-lSFMLComponents
```
### Sample
Have a look at sample.cpp, SampleView.cpp and SampleView.h for sample usage of SFMLComponents.