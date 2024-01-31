/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** DateModule
*/

#include "../include/DateTimeModule.hpp"
#include <sstream>

namespace Krell {
    DateTimeModule::DateTimeModule() {
        updateData();
    }

    void DateTimeModule::updateData() {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
        data = buf;
    }

    std::string DateTimeModule::getData() const {
        return data;
    }
}
