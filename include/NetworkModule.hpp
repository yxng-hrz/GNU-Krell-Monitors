/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** NetworkModule
*/

#ifndef NETWORKMODULE_HPP
#define NETWORKMODULE_HPP

#include "IModule.hpp"
#include <string>

namespace Krell {
    class NetworkModule : public IModule {
        std::string data;
    public:
        NetworkModule();
        virtual void updateData() override;
        virtual std::string getData() const override;
    };
}

#endif // NETWORKMODULE_HPP