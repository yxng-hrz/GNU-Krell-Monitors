/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** OSModule
*/

#ifndef OSMODULE_HPP
#define OSMODULE_HPP

#include "IModule.hpp"
#include <string>
#include <sys/utsname.h>

namespace Krell {
    class OSModule : public IModule {
        std::string data;
    public:
        OSModule();
        virtual void updateData() override;
        virtual std::string getData() const override;
    };
}

#endif // OSMODULE_HPP
