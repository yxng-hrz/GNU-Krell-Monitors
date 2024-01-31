/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** NcursesDisplay
*/

#ifndef NCURSESDISPLAY_HPP
#define NCURSESDISPLAY_HPP

#include "IDisplay.hpp"
#include <ncurses.h>

namespace Krell {
    class NcursesDisplay : public IDisplay {
    public:
        NcursesDisplay();
        virtual ~NcursesDisplay();
        virtual void displayData(const std::string& data) override;
    };
}

#endif // NCURSESDISPLAY_HPP
