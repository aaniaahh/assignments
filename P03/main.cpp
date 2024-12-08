#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
// Create a window with a title and dimensions (800x600)
sf::RenderWindow window(sf::VideoMode(1024, 768), "Aniah's Knucklebones Game");

// clock to calculate fps
sf::Clock clock;

    // Main game loop
    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close the window if the user presses Escape or clicks the close button
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

    sf::Time elapsed = clock.restart();
    float fps = 1.0f / elapsed.asSeconds();
    std::cout << "FPS: " << fps << std::endl;

        // Clear the window with a specific color
        window.clear(sf::Color::Blue);

        // Display the contents of the window
        window.display();

    }

    return 0;

}