/*
** EPITECH PROJECT, 2024
** B-PDG-300-PAR-3-1-PDGRUSH3-guillaume.houriez
** File description:
** mainDisplay
*/

#include "mainDisplay.hpp"

Graphics::Display::Display()
{
    this->_window.create(sf::VideoMode(1920, 1080), "MyGKrellm");
    this->_window.setFramerateLimit(30);
    this->_font.loadFromFile("Roboto-Black.ttf"); 
}

void Graphics::Display::updateText(const std::string &cpuInfo, const std::string &uptimeInfo)
{
    std::stringstream ss;
    ss << "CPU Info:\n" << cpuInfo << "\nUptime Info:\n" << uptimeInfo;
    this->_text.setString(ss.str());
}

void Graphics::Display::updateInfo()
{
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string cpuInfo;
    std::string line;
    while (std::getline(cpuinfo, line)) {
        if (line.find("model name") != std::string::npos || line.find("cpu MHz") != std::string::npos) {
            cpuInfo += line + "\n";
        }
    }
    cpuinfo.close();

    std::ifstream uptimeinfo("/proc/uptime");
    std::string uptimeInfo;
    while (std::getline(uptimeinfo, line)) {
        uptimeInfo += line + "\n";
    }
    uptimeinfo.close();

    updateText(cpuInfo, uptimeInfo);
}

void Graphics::Display::renderInfo()
{
    this->_text.setFont(this->_font);
    this->_text.setCharacterSize(24);
    this->_text.setFillColor(sf::Color::White);
    this->_text.setPosition(0, 0);
    this->_window.draw(this->_text);
}

void Graphics::Display::handleEvents()
{
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window.close();
    }
}

void Graphics::Display::mainLoop()
{
    while (this->_window.isOpen()) {
        this->_window.clear(sf::Color(30, 30, 30));
        this->handleEvents();
        this->updateInfo();
        this->renderInfo();
        this->_window.display();
    }
}

Graphics::Display::~Display()
{
    this->_window.close();
}

int main()
{
    Graphics::Display display;

    display.mainLoop();
    return 0;
}
