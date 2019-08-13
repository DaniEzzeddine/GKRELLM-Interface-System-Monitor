#ifndef TERM_MONITOR_DISPLAY_HPP
#define TERM_MONITOR_DISPLAY_HPP


#include "IMonitorDisplay.hpp"
class TermMonitorDisplay: public IMonitorDisplay
{
private:
public:
    TermMonitorDisplay(int size);
    ~TermMonitorDisplay();
    void displayModules();
    void addModule(IMonitorModule *obj);

};

#endif