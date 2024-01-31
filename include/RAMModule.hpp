/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** RAMModule
*/

#ifndef RAMMODULE_HPP
#define RAMMODULE_HPP

#include "IModule.hpp"
#include <string>

namespace Krell {
    class RAMModule : public IModule {
        std::string data;

    public:
        RAMModule();
        virtual void updateData() override;
        virtual std::string getData() const override;
    };
}

#endif // RAMMODULE_HPP
