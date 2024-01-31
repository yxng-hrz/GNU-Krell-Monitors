/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** mainDisplay
*/

#ifndef MAINDISPLAY_HPP_
#define MAINDISPLAY_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <fstream>

namespace Graphics {
    class Display {
        public:
            Display();
            ~Display();
            void mainLoop();
            void handleEvents();
            void updateInfo();
            void renderInfo();
            void updateText(const std::string &cpuInfo, const std::string &uptimeInfo);

        protected:
        private:
            sf::Font _font;
            sf::RenderWindow _window;
            sf::Event _event;
            sf::Text _text;
    };
}

#endif /* !MAINDISPLAY_HPP_ */
