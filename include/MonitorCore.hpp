/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** MonitorCore
*/

#ifndef MONITORCORE_HPP
#define MONITORCORE_HPP

#include "IModule.hpp"
#include "IDisplay.hpp"
#include <vector>
#include <memory>

namespace Krell {
    class MonitorCore {
        std::vector<std::unique_ptr<IModule>> modules;
        std::unique_ptr<IDisplay> display;

    public:
        void addModule(std::unique_ptr<IModule> module);
        void setDisplay(std::unique_ptr<IDisplay> display);
        void updateAndDisplay();
    };
}

#endif // MONITORCORE_HPP
