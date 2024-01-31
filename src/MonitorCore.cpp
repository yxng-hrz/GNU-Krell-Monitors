/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** MonitorCore
*/

#include "../include/MonitorCore.hpp"

namespace Krell {
    void MonitorCore::addModule(std::unique_ptr<IModule> module) {
        modules.push_back(std::move(module));
    }

    void MonitorCore::setDisplay(std::unique_ptr<IDisplay> disp) {
        display = std::move(disp);
    }

    void MonitorCore::updateAndDisplay() {
        std::string aggregatedData;
        for (auto& module : modules) {
            module->updateData();
            aggregatedData += module->getData() + "\n";
        }
        display->displayData(aggregatedData);
    }
}
