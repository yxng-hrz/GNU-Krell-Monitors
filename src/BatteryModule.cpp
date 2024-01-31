/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** BatteryModule
*/

#include "../include/BatteryModule.hpp"
#include <fstream>
#include <sstream>

namespace Krell {
    BatteryModule::BatteryModule() {
        updateData();
    }

    void BatteryModule::updateData() {
        std::ifstream battery_file("/sys/class/power_supply/BAT0/capacity");
        if (battery_file.is_open()) {
            std::getline(battery_file, data);
            data = "Battery: " + data + "%";
        } else {
            data = "Battery status not available";
        }
    }

    std::string BatteryModule::getData() const {
        return data;
    }
}
