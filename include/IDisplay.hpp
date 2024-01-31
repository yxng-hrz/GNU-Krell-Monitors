/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include <string>

namespace Krell {
    class IDisplay {
    public:
        virtual ~IDisplay() {}
        virtual void displayData(const std::string& data) = 0;
    };
}

#endif // IDISPLAY_HPP
