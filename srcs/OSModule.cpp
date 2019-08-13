#include "OSModule.hpp"


OSModule::OSModule(): IMonitorModule()
{
	struct utsname name;
	if(uname(&name)) exit(-1);
    std::string temp(name.version);
    _value = temp;
    _name = "OS version";
}

OSModule::~OSModule()
{
}



std::string OSModule::getFieldName()
{
    return (_name);
}

std::string OSModule::getFieldValue()
{
	struct utsname name;
	if(uname(&name)) exit(-1);
    std::string temp(name.version);
    _value = temp;
    return (_value);
}

