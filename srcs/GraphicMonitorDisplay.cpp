#include "../includes/GraphicMonitorDisplay.hpp"
#include "ft_gkrellm.hpp"
void GraphicMonitorDisplay::displayModules()
{
    IMonitorModule **modules = this->moduleList.getRawList();
    std::string _fieldName;
    std::string _fieldValue;
    sf::Text    _temp;
	std::string								s = "";
    _temp.setStyle(sf::Text::Bold);
    _temp.setFillColor(sf::Color::Black);
    _temp.setCharacterSize(30);
    _temp.setPosition(10, 50);
    int _moduleSize = this->moduleList.getSize();
    // int x = 4;
    // int y = 12;

    
    for (int i = 0; i < _moduleSize; i++)
    {
        _fieldName =  modules[i]->getFieldName();
        _fieldValue = modules[i]->getFieldValue();
        s.append(_fieldName);
        s.append("\n");
        s.append(_fieldValue);
        s.append("\n");
        _temp.setString(s.c_str());
    }
}

void GraphicMonitorDisplay::displayModule(sf::RenderWindow *window)
{
    IMonitorModule **modules = this->moduleList.getRawList();
    std::string _fieldName;
    std::string _fieldValue;
    sf::Text    _temp;
	std::string								s = "";
    _temp.setStyle(sf::Text::Bold);
    _temp.setFillColor(sf::Color::Black);
    _temp.setFont(_font);
    _temp.setPosition(10, 50);
    _temp.setCharacterSize(30);
    int _moduleSize = this->moduleList.getSize();
    // int x = 4;
    // int y = 12;
    window->clear(sf::Color::White);
    
    for (int i = 0; i < _moduleSize; i++)
    {
        _fieldName =  modules[i]->getFieldName();
        _fieldValue = modules[i]->getFieldValue();
        s.append("____________________________________________________________________________________________________________________________\n");
        s.append(_fieldName);
        s.append("\n");
        s.append(_fieldValue);
        s.append("\n\n");

    }
        _temp.setString(s.c_str());
        window->draw(_temp);
        window->display();
}


void GraphicMonitorDisplay::addModule(IMonitorModule *obj)
{
    this->moduleList.add(obj);
}

GraphicMonitorDisplay::GraphicMonitorDisplay(int size):IMonitorDisplay(size)
{
    _font.loadFromFile("arial.ttf");
}


GraphicMonitorDisplay::~GraphicMonitorDisplay()
{

}

