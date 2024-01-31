/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** ProcessModule
*/

#ifndef PROCESSMODULE_HPP
#define PROCESSMODULE_HPP

#include "IModule.hpp"
#include <string>

namespace Krell {
    class ProcessModule : public IModule {
        std::string data;
    public:
        ProcessModule();
        virtual void updateData() override;
        virtual std::string getData() const override;
    };
}

#endif // PROCESSMODULE_HPP