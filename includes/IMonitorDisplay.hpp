#ifndef I_MONITOR_DISPLAY_HPP
#define I_MONITOR_DISPLAY_HPP

#include "IMonitorModule.hpp"
#include "MonitorModuleList.hpp"
class IMonitorDisplay
{
protected:
    MonitorModuleList moduleList;
    int                 ListSize;
public:
    IMonitorDisplay(int size);
    ~IMonitorDisplay();
    virtual void displayModules() = 0;
    virtual void addModule(IMonitorModule *obj) = 0;
};

#endif