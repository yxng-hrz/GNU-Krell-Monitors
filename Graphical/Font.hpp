/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** Font
*/

#ifndef FONT_HPP_
#define FONT_HPP_

#include <SFML/Graphics.hpp>

class Font {
    public:
        Font(sf::Font *font, float pos_x, float pos_y, std::string str, int size, sf::Color color);
        ~Font() = default;

    protected:
    private:
        sf::Font _font;
        sf::Text _text;
};

#endif /* !FONT_HPP_ */
