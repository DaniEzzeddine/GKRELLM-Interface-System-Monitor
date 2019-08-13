#ifndef GRAPHIC_MONITOR_DISPLAY_HPP
#define GRAPHIC_MONITOR_DISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include <SFML/Graphics.hpp>
class GraphicMonitorDisplay: public IMonitorDisplay
{
private:
    sf::Font						_font;
public:
    GraphicMonitorDisplay(int size);
    ~GraphicMonitorDisplay();
    void displayModules();
    void displayModule(sf::RenderWindow *window);
    void addModule(IMonitorModule *obj);
};

#endif