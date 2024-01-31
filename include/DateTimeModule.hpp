/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** DateModule
*/

#ifndef DATETIMEMODULE_HPP
#define DATETIMEMODULE_HPP

#include "IModule.hpp"
#include <string>
#include <ctime>

namespace Krell {
    class DateTimeModule : public IModule {
        std::string data;
    public:
        DateTimeModule();
        virtual void updateData() override;
        virtual std::string getData() const override;
    };
}

#endif // DATETIMEMODULE_HPP
