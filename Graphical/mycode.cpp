#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <pwd.h>
#include <ctime>

class MyGkrellM {
public:
    MyGkrellM() {
        window.create(sf::VideoMode(800, 600), "MyGkrellM");
        font.loadFromFile("/usr/share/fonts/dejavu-sans-fonts/DejaVuSans-Bold.ttf");

        text.setFont(font);
        text.setCharacterSize(15);
        text.setFillColor(sf::Color(255, 204, 153));
        text.setPosition(10.f, 10.f);

        scrollbar.setSize(sf::Vector2f(10.f, static_cast<float>(window.getSize().y)));
        scrollbar.setFillColor(sf::Color(100, 100, 100));
        scrollbar.setPosition(window.getSize().x - 10.f, 0.f);

        scrollPosition = 0.0f;
    }

    void run() {
        while (window.isOpen()) {
            handleEvents();
            update();
            render();
        }
    }

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text text;
    sf::RectangleShape scrollbar;
    float scrollPosition;
    float textHeight;
    bool isScrolling;
    float offset;

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.delta > 0) {
                    // Faire défiler vers le haut
                    scrollPosition -= 20.0f;
                } else if (event.mouseWheelScroll.delta < 0) {
                    // Faire défiler vers le bas
                    scrollPosition += 20.0f;
                }

                // Limitez la position de la scrollbar aux valeurs valides
                scrollPosition = std::max(0.0f, std::min(scrollPosition, textHeight - window.getSize().y));

                sf::View view = window.getView();
                view.reset(sf::FloatRect(0, scrollPosition, window.getSize().x, window.getSize().y));
                window.setView(view);
            } else if (event.type == sf::Event::Resized) {
                // Mise à jour de la taille de la fenêtre
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));

                // Réajuster la position de la scrollbar
                float scrollbarHandleHeight = (window.getSize().y / textHeight) * window.getSize().y;
                scrollbar.setSize(sf::Vector2f(10.f, scrollbarHandleHeight));
                float scrollbarHandlePosition = (scrollPosition / (textHeight - window.getSize().y)) * (window.getSize().y - scrollbarHandleHeight);
                scrollbar.setPosition(window.getSize().x - 10.f, scrollbarHandlePosition);
            } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                // Vérifier si la souris est sur la scrollbar
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::FloatRect scrollbarBounds = scrollbar.getGlobalBounds();

                if (scrollbarBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    // La souris est sur la scrollbar, activer le défilement
                    isScrolling = true;
                    offset = mousePos.y - scrollbar.getPosition().y;
                }
            } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                // Désactiver le défilement lorsque le bouton de la souris est relâché
                isScrolling = false;
            } else if (event.type == sf::Event::MouseMoved) {
                // Faire défiler manuellement si la souris est maintenue enfoncée sur la scrollbar
                if (isScrolling) {
                    float newScrollbarPosition = static_cast<float>(event.mouseMove.y) - offset;
                    // Limitez la position de la scrollbar aux valeurs valides
                    newScrollbarPosition = std::max(0.0f, std::min(newScrollbarPosition, window.getSize().y - scrollbar.getSize().y));

                    // Mettre à jour la position de la scrollbar
                    scrollbar.setPosition(window.getSize().x - 10.f, newScrollbarPosition);

                    // Mettre à jour la position de défilement
                    scrollPosition = (newScrollbarPosition / (window.getSize().y - scrollbar.getSize().y)) * (textHeight - window.getSize().y);

                    // Mettre à jour la vue
                    sf::View view = window.getView();
                    view.reset(sf::FloatRect(0, scrollPosition, window.getSize().x, window.getSize().y));
                    window.setView(view);
                }
            }
        }
    }

    void update() {
        std::ostringstream oss;
        oss << "System Information:" << std::endl;

        // Obtenir le hostname
        char hostname[256];
        if (gethostname(hostname, sizeof(hostname)) == 0) {
            oss << "Hostname: " << hostname << std::endl;
        } else {
            oss << "Failed to get hostname." << std::endl;
        }

        // Obtenir le username
        uid_t uid = geteuid();
        struct passwd *pw = getpwuid(uid);
        if (pw != nullptr) {
            oss << "Username: " << pw->pw_name << std::endl;
        } else {
            oss << "Failed to get username." << std::endl;
        }

        // Obtenir la date et l'heure actuelles
        std::time_t now = std::time(nullptr);
        struct tm *localTime = std::localtime(&now);

        // Afficher l'année avant l'heure
        oss << "Date and Time: " << localTime->tm_year + 1900 << '-'
            << localTime->tm_mon + 1 << '-'
            << localTime->tm_mday << ' '
            << localTime->tm_hour << ':'
            << localTime->tm_min << ':'
            << localTime->tm_sec << std::endl;

        // Exemple : Lecture du fichier /sys/class/thermal/thermal_zone0/temp pour obtenir la température CPU
        std::ifstream tempFile("/sys/class/thermal/thermal_zone0/temp");
        if (tempFile.is_open()) {
            int temp;
            tempFile >> temp;
            tempFile.close();
            // La température est souvent en millièmes de degrés Celsius, donc la diviser par 1000
            oss << "CPU Temperature: " << static_cast<float>(temp) / 1000.0f << "C" << std::endl;
        } else {
            oss << "Failed to read CPU temperature." << std::endl;
        }

        // Exemple : Lecture du fichier /sys/class/power_supply/BAT0/capacity pour obtenir le niveau de batterie
        std::ifstream batteryFile("/sys/class/power_supply/BAT0/capacity");
        if (batteryFile.is_open()) {
            int batteryLevel;
            batteryFile >> batteryLevel;
            batteryFile.close();
            oss << "Battery Level: " << batteryLevel << "%" << std::endl;
        } else {
            oss << "Failed to read battery level." << std::endl;
        }

        // Ajout : Récupération de la charge réseau
        float networkLoad = getNetworkLoad();
        oss << "Network Load: " << networkLoad << "%" << std::endl;

        // Exemple : Lecture du fichier /proc/cpuinfo pour obtenir des informations sur le processeur
        std::ifstream cpuInfo("/proc/cpuinfo");
        int processorCount = 0;  // Variable pour compter le nombre de processeurs rencontrés
        std::string line;
        if (cpuInfo.is_open()) {
            while (getline(cpuInfo, line)) {
                // Exclure les lignes contenant "stepping" et "initial apicid"
                if (line.find("stepping") != std::string::npos || line.find("initial apicid") != std::string::npos) {
                    continue;
                }

                // Ajouter une vérification pour inclure uniquement les informations du premier processeur
                if (line.find("processor") != std::string::npos && processorCount > 0) {
                    break;  // Quitter la boucle après avoir rencontré le premier processeur
                }

                oss << line << std::endl;

                // Incrémenter le compteur de processeurs
                if (line.find("processor") != std::string::npos) {
                    processorCount++;
                }
            }
            cpuInfo.close();
        } else {
            oss << "Failed to read CPU info." << std::endl;
        }

        // Exemple : Lecture du fichier /proc/meminfo pour obtenir des informations sur la mémoire
        std::ifstream memInfo("/proc/meminfo");
        if (memInfo.is_open()) {
            while (getline(memInfo, line)) {
                oss << line << std::endl;
            }
            memInfo.close();
        } else {
            oss << "Failed to read memory info." << std::endl;
        }

        // Mettez à jour le texte avec les informations du système
        text.setString(oss.str());

        // Calculez la hauteur du texte
        textHeight = text.getLocalBounds().height;

        // Ajustez la position de la scrollbar en fonction de la hauteur du texte
        if (textHeight > window.getSize().y) {
            float maxScroll = textHeight - window.getSize().y;
            scrollPosition = std::min(scrollPosition, maxScroll);

            // Mise à jour de la scrollbar
            float scrollbarHandleHeight = (window.getSize().y / textHeight) * window.getSize().y;
            scrollbar.setSize(sf::Vector2f(10.f, scrollbarHandleHeight));

            // Ajustez la position de la poignée en fonction de la position de défilement
            float scrollbarHandlePosition = (scrollPosition / maxScroll) * (window.getSize().y - scrollbarHandleHeight);
            scrollbar.setPosition(window.getSize().x - 10.f, scrollbarHandlePosition);

            sf::View view = window.getView();
            view.reset(sf::FloatRect(0, scrollPosition, window.getSize().x, window.getSize().y));
            window.setView(view);
        } else {
            // Masquer la scrollbar si le texte tient dans la fenêtre
            scrollbar.setSize(sf::Vector2f(0.f, 0.f));
        }
    }

    void render() {
        window.clear(sf::Color(0, 77, 102));
        window.draw(text);
        window.draw(scrollbar);
        window.display();
    }

    // Ajout de la déclaration de la fonction pour récupérer la charge réseau
    float getNetworkLoad();
};

// Ajout de la définition de la fonction pour récupérer la charge réseau
float MyGkrellM::getNetworkLoad() {
    // Exemple : Lecture du fichier /proc/net/dev pour obtenir des informations sur la charge réseau
    std::ifstream networkFile("/proc/net/dev");
    std::string line;
    std::string interfaceName = "eth0"; // Remplacez "eth0" par le nom de votre interface réseau

    if (networkFile.is_open()) {
        while (getline(networkFile, line)) {
            if (line.find(interfaceName) != std::string::npos) {
                std::istringstream iss(line);
                std::string token;
                // Ignorer les premières colonnes
                for (int i = 0; i < 8; ++i) {
                    iss >> token;
                }
                // Lire la colonne correspondant à la charge reçue
                float received, dropped;
                iss >> received;
                iss >> dropped;
                // Calculer la charge réseau en pourcentage
                float total = received + dropped;
                float loadPercentage = (total > 0) ? (received / total) * 100.0f : 0.0f;
                return loadPercentage;
            }
        }
        networkFile.close();
    }
    // En cas d'erreur, retourner 0%
    return 0.0f;
}

int main() {
    MyGkrellM app;
    app.run();

    return 0;
}
