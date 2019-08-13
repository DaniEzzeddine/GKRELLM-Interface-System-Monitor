#ifndef OS_MODULE_HPP
#define OS_MODULE_HPP
#include "IMonitorModule.hpp"
#include <sys/utsname.h>

class OSModule: public IMonitorModule
{
private:

public:
    OSModule();
    ~OSModule();
    OSModule(const OSModule &obj);
    std::string getFieldName();
    std::string getFieldValue();

};


#endif