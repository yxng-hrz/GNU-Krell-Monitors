/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** ProcessModule
*/

#include "../include/ProcessModule.hpp"
#include <array>
#include <memory>
#include <stdexcept>
#include <cstdio>
#include <iostream>

namespace Krell {
    ProcessModule::ProcessModule() {
        updateData();
    }

    void ProcessModule::updateData() {
        std::array<char, 128> buffer;
        std::string result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen("ps -aux", "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        data = result;
    }

    std::string ProcessModule::getData() const {
        return data;
    }
}
