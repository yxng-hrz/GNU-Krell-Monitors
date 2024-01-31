/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** CPUModule
*/

#include "../include/CPUModule.hpp"
#include <fstream>
#include <sstream>

namespace Krell {
    CPUModule::CPUModule() {
        updateData();
    }

    void CPUModule::updateData() {
        std::ifstream cpuinfo("/proc/cpuinfo");
        std::string line;
        while (std::getline(cpuinfo, line)) {
            if (line.substr(0, 10) == "model name") {
                size_t colon = line.find(":");
                data = "CPU Model: " + line.substr(colon + 2);
                break;
            }
        }
        cpuinfo.close();
    }

    std::string CPUModule::getData() const {
        return data;
    }
}
