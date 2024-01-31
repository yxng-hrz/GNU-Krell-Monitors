/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** TemperatureModule
*/

#include "../include/TemperatureModule.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

namespace Krell {
    TemperatureModule::TemperatureModule() {
        updateData();
    }

    void TemperatureModule::updateData() {
        std::ifstream thermal_zone("/sys/class/thermal/thermal_zone0/temp");
        if (!thermal_zone.is_open()) {
            data = "Error: Cannot open thermal zone file";
            return;
        }

        int temp;
        thermal_zone >> temp;
        thermal_zone.close();

        float tempC = temp / 1000.0f;
        std::ostringstream stream;
        stream << "CPU Temperature: " << tempC << "°C";
        data = stream.str();
    }

    std::string TemperatureModule::getData() const {
        return data;
    }
}
