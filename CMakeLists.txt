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

install(TARGETS SFMLComponents DESTINATION /usr/lib)
install(FILES Elements/Button.h Elements/ClickableElement.h Elements/EditField.h Elements/TextField.h Elements/Element.h
        DESTINATION /usr/include/SFMLComponents/Elements)
install(FILES Listener/Listener.h Listener/OnClickListener.h Listener/OnTextListener.h
        DESTINATION /usr/include/SFMLComponents/Listener)
install(FILES Window/ListenerRenderWindow.h
        DESTINATION /usr/include/SFMLComponents/Window)
install(FILES WindowViews/WindowView.h
        DESTINATION /usr/include/SFMLComponents/WindowViews)