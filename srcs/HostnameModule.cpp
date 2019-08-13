#include "HostnameModule.hpp"


HostnameModule::HostnameModule(): IMonitorModule()
{
    char hostname[250];
    gethostname(hostname, 250);
    std::string temp(hostname);
    _name = "Hostname";
    _value = temp;
}

HostnameModule::~HostnameModule()
{
}



std::string HostnameModule::getFieldName()
{
    return (_name);
}

std::string HostnameModule::getFieldValue()
{
    char hostname[250];
    gethostname(hostname, 250);
    std::string temp(hostname);
    _value = temp;
    return (_value);
}

