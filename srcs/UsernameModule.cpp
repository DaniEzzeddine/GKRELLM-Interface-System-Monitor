#include "UsernameModule.hpp"

UsernameModule::UsernameModule(): IMonitorModule()
{
    char username[250];
    getlogin_r(username, 250);
    std::string temp(username);
    _name = "Username";
    _value = temp;
}

UsernameModule::~UsernameModule()
{
}


std::string UsernameModule::getFieldName()
{
    return (_name);
}

std::string UsernameModule::getFieldValue()
{
    char username[250];
    getlogin_r(username, 250);
    std::string temp(username);
    _value = temp;
    return (_value);
}

