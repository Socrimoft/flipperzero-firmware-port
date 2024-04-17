#include <SFML/Graphics.hpp>

#define TAG "Main"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define MULT_FACTOR 10

#define WINDOW_WIDTH SCREEN_WIDTH* MULT_FACTOR
#define WINDOW_HEIGHT SCREEN_HEIGHT* MULT_FACTOR

#define PIXEL_OFF 0xF28C28
#define PIXEL_ON 0

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Flipper Zero");

    sf::Texture texture;
    texture.create(SCREEN_WIDTH, SCREEN_HEIGHT);
    sf::Sprite screen(texture);
    screen.setScale(MULT_FACTOR, MULT_FACTOR);

    uint8_t dummy[SCREEN_WIDTH * SCREEN_HEIGHT * 4];

    for(size_t i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT * 4; i += 4) {
        *(reinterpret_cast<uint32_t*>(&dummy[i])) = PIXEL_OFF;
    }

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) window.close();
            if(event.type == sf::Event::KeyPressed) {
            }
        }

        // logic

        // drawing
        texture.update(dummy);

        window.clear();
        window.draw(screen);
        window.display();
    }

    return 0;
}