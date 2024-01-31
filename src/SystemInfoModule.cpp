/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** SystemInfoModule
*/

#include "../include/SystemInfoModule.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <cstring>

namespace Krell {
    SystemInfoModule::SystemInfoModule() {
        updateData();
    }

    void SystemInfoModule::updateData() {
        char hostname[HOST_NAME_MAX];
        gethostname(hostname, HOST_NAME_MAX);

        struct passwd *pw;
        uid_t uid = geteuid();
        pw = getpwuid(uid);

        data = "Hostname: ";
        data += hostname;
        data += "\nUsername: ";
        data += pw ? pw->pw_name : "unknown";
    }

    std::string SystemInfoModule::getData() const {
        return data;
    }
}
