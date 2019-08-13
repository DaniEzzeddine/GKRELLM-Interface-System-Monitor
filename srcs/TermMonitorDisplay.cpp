#include "TermMonitorDisplay.hpp"

void TermMonitorDisplay::displayModules()
{
    IMonitorModule **modules = this->moduleList.getRawList();
    std::string _fieldName;
    std::string _fieldValue;
    std::string _temp;
    int _moduleSize = this->moduleList.getSize();
    int x = 4;
    int y = 12;

    for (int i = 0; i < _moduleSize; i++)
    {
        _fieldName =  modules[i]->getFieldName();
        _fieldValue = modules[i]->getFieldValue();
         _temp = "__" + _fieldName;
        for (int i = 0; _temp.length() < 101; i++)
        {
            _temp += "_";
        }
        
        mvaddstr(y, x, _temp.c_str());
	    mvaddstr(y + 2, x + 2, _fieldValue.c_str());
        y += 4;
    }
}

void TermMonitorDisplay::addModule(IMonitorModule *obj)
{
    this->moduleList.add(obj);
}

TermMonitorDisplay::TermMonitorDisplay(int size):IMonitorDisplay(size)
{
}


TermMonitorDisplay::~TermMonitorDisplay()
{

}

