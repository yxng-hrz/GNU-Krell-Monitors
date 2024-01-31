/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** DiskModule
*/

#include "../include/DiskModule.hpp"
#include <array>
#include <memory>
#include <stdexcept>
#include <cstdio>
#include <iostream>

namespace Krell {
    DiskModule::DiskModule() {
        updateData();
    }

    void DiskModule::updateData() {
        std::array<char, 128> buffer;
        std::string result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen("df -H", "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        data = result;
    }

    std::string DiskModule::getData() const {
        return data;
    }
}
