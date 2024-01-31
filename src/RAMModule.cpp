/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** RAMModule
*/

#include "../include/RAMModule.hpp"
#include <fstream>
#include <sstream>
#include <string>

namespace Krell {
    RAMModule::RAMModule() {
        updateData();
    }

    void RAMModule::updateData() {
        std::ifstream meminfo("/proc/meminfo");
        std::string line;
        std::string key;
        long value;
        std::string kb;
        long memTotal, memFree, memAvailable, buffers, cached;
        while (std::getline(meminfo, line)) {
            std::istringstream iss(line);
            iss >> key >> value >> kb;
            if (key == "MemTotal:") {
                memTotal = value;
            } else if (key == "MemFree:") {
                memFree = value;
            } else if (key == "MemAvailable:") {
                memAvailable = value;
            } else if (key == "Buffers:") {
                buffers = value;
            } else if (key == "Cached:") {
                cached = value;
            }
        }
        meminfo.close();

        long memUsed = memTotal - memFree - buffers - cached;
        std::stringstream ss;
        ss << "RAM Total: " << memTotal << "kB, ";
        ss << "RAM Used: " << memUsed << "kB, ";
        ss << "RAM Free: " << memFree << "kB";
        data = ss.str();
    }

    std::string RAMModule::getData() const {
        return data;
    }
}
