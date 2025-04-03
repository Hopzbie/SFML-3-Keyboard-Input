// library
#include <SFML/Graphics.hpp>
#include <iostream>


// main program
int main()
{
    // create window
    sf::RenderWindow window(sf::VideoMode({1000, 400}), "Title");

    // disable key repeat
    window.setKeyRepeatEnabled(false);

    // // state of key
    // bool isPressed = false;


    // while window is still open
    while (window.isOpen())
    {
        // handle events
        while (std::optional event = window.pollEvent())
        {
            // when close button is clicked
            if (event->is<sf::Event::Closed>())
            {
                // close window
                window.close();
            }
            
            // when window is resized
            else if (event->is<sf::Event::Resized>())
            {
                // update view
                sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                window.setView(view);
            }
            
            // when keyboard is pressed
            else if (auto* key = event->getIf<sf::Event::KeyPressed>())
            {
                // only A-Z
                if (key->scancode >= sf::Keyboard::Scancode::A and
                    key->scancode <= sf::Keyboard::Scancode::Z)
                {
                    if (key->control)  std::cout << "Ctrl + ";
                    if (key->shift)    std::cout << "Shift + ";
                    if (key->alt)      std::cout << "Alt + ";
                    std::cout << sf::Keyboard::getDescription(key->scancode).toAnsiString();
                    std::cout << " is pressed\n";
                }
            }
            
            // when keyboard is released
            else if (auto* key = event->getIf<sf::Event::KeyReleased>())
            {
                // only A-Z
                if (key->scancode >= sf::Keyboard::Scancode::A and
                    key->scancode <= sf::Keyboard::Scancode::Z)
                {
                    if (key->control)  std::cout << "Ctrl + ";
                    if (key->shift)    std::cout << "Shift + ";
                    if (key->alt)      std::cout << "Alt + ";
                    std::cout << sf::Keyboard::getDescription(key->scancode).toAnsiString();
                    std::cout << " is released\n";
                }
            }
        }

        // // check keyboard input
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
        // {
        //     // if key isn't pressed yet
        //     if (not isPressed)
        //         std::cout << "A is pressed\n";
        //
        //     // set state
        //     isPressed = true;
        // }
        // else
        // {
        //     // if key is still pressed
        //     if (isPressed)
        //         std::cout << "A is released\n";
        //
        //     // reset state
        //     isPressed = false;
        // }

        // fill window with color
        window.clear(sf::Color::Black);

        // display
        window.display();
    }

    
    // program end successfully
    return 0;
}