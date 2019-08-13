#ifndef MODULE_LIST_HPP
#define MODULE_LIST_HPP
#include "IMonitorModule.hpp"
#include <stdlib.h>

class MonitorModuleList
{
	private:
	int _numObjects;
	IMonitorModule **_objects;

	public:
	MonitorModuleList();
	MonitorModuleList(const MonitorModuleList & src);
	~MonitorModuleList();
	void add(IMonitorModule *);
	void dump(MonitorModuleList & dst);
	int	getSize() const;
	IMonitorModule **getRawList() const;

	MonitorModuleList &operator=(const MonitorModuleList & src);
};

#endif