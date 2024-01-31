/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** NcursesDisplay
*/

#include "../include/NcursesDisplay.hpp"
#include <ncurses.h>
#include <iostream>
#include <string>
#include <sstream>

namespace Krell {
    NcursesDisplay::NcursesDisplay() {
        initscr();
        noecho();
        curs_set(FALSE);
    }

    NcursesDisplay::~NcursesDisplay() {
        endwin();
    }

    void NcursesDisplay::displayData(const std::string& data) {
        clear();
        int row = 0;
        std::istringstream stream(data);
        std::string line;
        while (std::getline(stream, line)) {
            mvprintw(row++, 0, line.c_str());
        }
        refresh();
    }
}
