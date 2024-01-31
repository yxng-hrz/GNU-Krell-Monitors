/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** NetworkModule
*/

#include "../include/NetworkModule.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

namespace Krell {
    NetworkModule::NetworkModule() {
        updateData();
    }

    void NetworkModule::updateData() {
        std::ifstream net_dev("/proc/net/dev");
        std::string line;
        if (!net_dev.is_open()) {
            data = "Error: Cannot open /proc/net/dev";
            return;
        }

        std::getline(net_dev, line);
        std::getline(net_dev, line);

        std::ostringstream stream;
        while (std::getline(net_dev, line)) {
            stream << line << '\n';
        }

        data = stream.str();
        net_dev.close();
    }

    std::string NetworkModule::getData() const {
        return data;
    }
}
