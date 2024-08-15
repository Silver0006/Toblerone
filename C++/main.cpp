#include <iostream>
#include <vector>
#include <random>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <toblerone/spooks_png.h>
#include <toblerone/spook1_wav.h>
#include <toblerone/spook2_ogg.h>
using namespace std;

int main() {
    // List of times that are selected by RNG
    vector<int> times = {15, 30, 45, 60, 360, 120, 21 ,49 ,63, 246};
    random_device rd;
    minstd_rand gen(rd());
    uniform_int_distribution<> distr(0, 9);
    //generates num from 1-10 to select time from list
    int time = distr(gen);
    cout << "Rando says " << time+1 << endl;
    cout << "This is sleep time: " << times[time] << endl;
    sf::sleep(sf::seconds(static_cast<float>(times[time])));
    sf::SoundBuffer buffer;
    if (!buffer.loadFromMemory(spook1_wav, spook1_wav_len)) {
        cerr << "Error loading sound from memory" << endl;
        return -1;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    sf::sleep(sf::seconds(5));
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Spooks", sf::Style::Fullscreen);
    sf::Texture texture;
    if (!texture.loadFromMemory(spooks_png, spooks_png_len)) {
        cerr << "Error loading image from memory" << endl;
        return -1;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    window.setMouseCursorVisible(false);
    window.draw(sprite);
    window.display();
    if (!buffer.loadFromMemory(spook2_ogg, spook2_ogg_len)) {
        cerr << "Error loading sound from memory" << endl;
        return -1;
    }
    sound.setBuffer(buffer);
    sound.play();
    sf::sleep(sf::seconds(4));
    window.close();
    main();
}
