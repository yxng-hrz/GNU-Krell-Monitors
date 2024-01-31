/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** IModule
*/

#ifndef IMODULE_HPP
#define IMODULE_HPP

#include <string>

namespace Krell {
    class IModule {
    public:
        virtual ~IModule() {}
        virtual void updateData() = 0;
        virtual std::string getData() const = 0;
    };
}

#endif // IMODULE_HPP
