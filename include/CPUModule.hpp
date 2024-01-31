/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** CPUModule
*/

#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP

#include "IModule.hpp"
#include <string>

namespace Krell {
    class CPUModule : public IModule {
        std::string data;

    public:
        CPUModule();
        virtual void updateData() override;
        virtual std::string getData() const override;
    };
}

#endif // CPUMODULE_HPP
