/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** SystemInfoModule
*/

#ifndef SYSTEMINFOMODULE_HPP
#define SYSTEMINFOMODULE_HPP

#include "IModule.hpp"
#include <unistd.h>
#include <limits.h>
#include <string>

namespace Krell {
    class SystemInfoModule : public IModule {
        std::string data;

    public:
        SystemInfoModule();
        virtual void updateData() override;
        virtual std::string getData() const override;
    };
}

#endif // SYSTEMINFOMODULE_HPP
