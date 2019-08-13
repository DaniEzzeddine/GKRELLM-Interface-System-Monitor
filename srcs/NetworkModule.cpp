#include "NetworkModule.hpp"

NetworkModule::NetworkModule(): IMonitorModule()
{
    FILE 						*in;
    char						buffer[512];
    std::stringstream			sstr;

    if(not (in = popen("/usr/bin/top | /usr/bin/head -n9 | /usr/bin/grep 'Network'", "r")))
        return ;

    while(fgets(buffer, sizeof(buffer), in))
        sstr << buffer;

    pclose(in);

    std::string 				str = sstr.str();
    _value = str;
    _name = "Network";
}

NetworkModule::~NetworkModule()
{
}



std::string NetworkModule::getFieldName()
{
    return (_name);
}

std::string NetworkModule::getFieldValue()
{
        FILE 						*in;
    char						buffer[512];
    std::stringstream			sstr;

    if(not (in = popen("/usr/bin/top | /usr/bin/head -n9 | /usr/bin/grep 'Network'", "r")))
        return "";

    while(fgets(buffer, sizeof(buffer), in))
        sstr << buffer;

    pclose(in);

    std::string 				str = sstr.str();
    _value = str;
    return (_value);
}

