#ifndef I_MONITOR_MODULE_HPP
#define I_MONITOR_MODULE_HPP

#include <iostream>
#include <ncurses.h>

class IMonitorModule
{
protected:
    std::string _name;
    std::string _value;
public:
    IMonitorModule(/* args */);
    virtual std::string getFieldName() = 0;
    virtual std::string getFieldValue() = 0;
    virtual ~IMonitorModule();
};

#endif