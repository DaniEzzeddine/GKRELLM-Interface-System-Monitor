#include "RAMModule.hpp"

uint64_t getSysCtl(int top_level, int next_level){
	int mib[2];
    uint64_t ctlvalue;
	size_t len;

	mib[0] = top_level;
	mib[1] = next_level;
	len = sizeof(ctlvalue);
	sysctl(mib, 2, &ctlvalue, &len, NULL, 0);	
	
	return ctlvalue;
}

RAMModule::RAMModule(): IMonitorModule()
{
FILE *f = popen("vm_stat", "r");

	if (!f) {
		this->_value = "error";
		return ;
	}

	int64_t total;
	size_t size = sizeof(total);
	if (sysctlbyname("hw.memsize", &total, &size, NULL, 0) < 0) {
		this->_value = "error";
		return ;
	}

	char buf[4096];

	long bytes = 0;
	long used = 0;

	while (fgets(buf, 4096, f) != NULL)
	{
		std::string line = buf;

		if (line.compare(0, 4, "Mach") == 0)
		{
			std::stringstream ss(line.substr(line.find_first_of("0123456789")));

			ss >> bytes;
		}
		if (line.compare(0, 5, "Pages") == 0)
		{
			std::stringstream ss(line.substr(line.find_first_of("0123456789")));

			int a;
			ss >> a;

			if (line.compare(0, 12, "Pages active") == 0 ||
					line.compare(0, 14, "Pages inactive") == 0)
				used += a;
		}

		if (line.compare(0, 20, "\"Translation faults\"") == 0)
			break;
	}

	used *= bytes;

	std::stringstream ss;

 	ss << bytes_format(used) << " / " << bytes_format(total) << " ("
 		<< std::setprecision(0) << std::fixed << (used / (double)total * 100)
 		<< "%)";

	pclose(f);

	this->_value = ss.str();
    _name = "RAM";
}

RAMModule::~RAMModule()
{
}


std::string RAMModule::getFieldName()
{
    return (_name);
}

std::string RAMModule::getFieldValue()
{
FILE *f = popen("vm_stat", "r");

	if (!f) {
		this->_value = "error";
		return this->_value;
	}

	int64_t total;
	size_t size = sizeof(total);
	if (sysctlbyname("hw.memsize", &total, &size, NULL, 0) < 0) {
		this->_value = "error";
		return this->_value;
	}

	char buf[4096];

	long bytes = 0;
	long used = 0;

	while (fgets(buf, 4096, f) != NULL)
	{
		std::string line = buf;

		if (line.compare(0, 4, "Mach") == 0)
		{
			std::stringstream ss(line.substr(line.find_first_of("0123456789")));

			ss >> bytes;
		}
		if (line.compare(0, 5, "Pages") == 0)
		{
			std::stringstream ss(line.substr(line.find_first_of("0123456789")));

			int a;
			ss >> a;

			if (line.compare(0, 12, "Pages active") == 0 ||
					line.compare(0, 14, "Pages inactive") == 0)
				used += a;
		}

		if (line.compare(0, 20, "\"Translation faults\"") == 0)
			break;
	}

	used *= bytes;

	std::stringstream ss;

 	ss << bytes_format(used) << " / " << bytes_format(total) << " ("
 		<< std::setprecision(0) << std::fixed << (used / (double)total * 100)
 		<< "%)";

	pclose(f);

	this->_value = ss.str();
    return (_value);
}

