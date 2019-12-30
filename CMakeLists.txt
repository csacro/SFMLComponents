cmake_minimum_required(VERSION 3.10)
project(SFMLComponents)

set(CMAKE_CXX_STANDARD 17)

add_library(SFMLComponents
        Elements/Element.h Elements/ClickableElement.h
        Elements/TextField.cpp  Elements/TextField.h
        Elements/Button.cpp Elements/Button.h
        Elements/EditField.cpp Elements/EditField.h
        Listener/Listener.h
        Listener/OnClickListener.cpp Listener/OnClickListener.h
        Listener/OnTextListener.cpp Listener/OnTextListener.h
        Window/ListenerRenderWindow.cpp Window/ListenerRenderWindow.h
        WindowViews/WindowView.h
        )

target_link_libraries (SFMLComponents
        sfml-graphics sfml-window sfml-system
        )

add_executable(SFMLComponentsSample sample.cpp SampleView.cpp SampleView.h)
target_link_libraries(SFMLComponentsSample SFMLComponents)

install(TARGETS SFMLComponents DESTINATION /usr/lib/SFMLComponents)
install(FILES TextFieldOrButton.h DESTINATION /usr/include/SFMLComponents)