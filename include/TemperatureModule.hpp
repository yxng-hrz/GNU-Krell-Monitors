/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** TemperatureModule
*/

#ifndef TEMPERATUREMODULE_HPP
#define TEMPERATUREMODULE_HPP

#include "IModule.hpp"
#include <string>

namespace Krell {
    class TemperatureModule : public IModule {
        std::string data;
    public:
        TemperatureModule();
        virtual void updateData() override;
        virtual std::string getData() const override;
    };
}

#endif // TEMPERATUREMODULE_HPP