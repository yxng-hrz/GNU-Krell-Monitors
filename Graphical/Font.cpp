/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** Font
*/

#include "Font.hpp"

Font::Font(sf::Font *font, float pos_x, float pos_y, std::string str, int size, sf::Color color)
{
    this->_text.setFont(*font);
    this->_text.setString(str);
    this->_text.setCharacterSize(size);
    this->_text.setFillColor(color);
    this->_text.setPosition(pos_x, pos_y);
}
