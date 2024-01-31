/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** OSModule
*/

#include "../include/OSModule.hpp"

namespace Krell {
    OSModule::OSModule() {
        updateData();
    }

    void OSModule::updateData() {
        struct utsname unameData;
        uname(&unameData);
        data = "OS: " + std::string(unameData.sysname) + "\n";
        data += "Kernel: " + std::string(unameData.release);
    }

    std::string OSModule::getData() const {
        return data;
    }
}
