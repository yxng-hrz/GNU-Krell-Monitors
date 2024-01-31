/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** DiskModule
*/

#ifndef DISKMODULE_HPP
#define DISKMODULE_HPP

#include "IModule.hpp"
#include <string>

namespace Krell {
    class DiskModule : public IModule {
        std::string data;
    public:
        DiskModule();
        virtual void updateData() override;
        virtual std::string getData() const override;
    };
}

#endif // DISKMODULE_HPP