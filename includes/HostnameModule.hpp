#ifndef HOSTNAME_MODULE_HPP
#define HOSTNAME_MODULE_HPP
#include <unistd.h>

#include "IMonitorModule.hpp"
class HostnameModule: public IMonitorModule
{
private:

public:
    HostnameModule();
    ~HostnameModule();
    HostnameModule(const HostnameModule &obj);
    std::string getFieldName();
    std::string getFieldValue();

};


#endif