/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** BatteryModule
*/

#ifndef BATTERYMODULE_HPP
#define BATTERYMODULE_HPP

#include "IModule.hpp"
#include <string>

namespace Krell {
    class BatteryModule : public IModule {
        std::string data;
    public:
        BatteryModule();
        virtual void updateData() override;
        virtual std::string getData() const override;
    };
}

#endif // BATTERYMODULE_HPP
