#include "CPUModule.hpp"

CPUModule::CPUModule(): IMonitorModule()
{
    system("echo 'Model: ' >> text.txt; sysctl -n machdep.cpu.brand_string >> text.txt; echo 'Cores: ' >> text.txt; sysctl -n hw.ncpu  >> text.txt; echo 'Activity: ' >> text.txt;ps -A -o %cpu | awk '{s+=$1} END {print s \"%\"}' >> text.txt");
    std::string line;
    std::ifstream myfile ("text.txt");
    _value = "";
    if (myfile.is_open())
    {
      while ( getline (myfile,line) )
      {
        _value += line;
        _value += "\n";
      }
      myfile.close();
    }
    remove("text.txt");
    _name = "CPU";
}

CPUModule::~CPUModule()
{
}



std::string CPUModule::getFieldName()
{
    return (_name);
}

std::string CPUModule::getFieldValue()
{
    system("echo 'Model: ' >> text.txt; sysctl -n machdep.cpu.brand_string >> text.txt; echo 'Cores: ' >> text.txt; sysctl -n hw.ncpu  >> text.txt; echo 'Activity: ' >> text.txt;ps -A -o %cpu | awk '{s+=$1} END {print s \"%\"}' >> text.txt");
    std::string line;
    std::ifstream myfile ("text.txt");
    _value = "";
    if (myfile.is_open())
    {
      while ( getline (myfile,line) )
      {
        _value += line;
        _value += "  ";
      }
      myfile.close();
    }
    remove("text.txt");
    return (_value);
}

