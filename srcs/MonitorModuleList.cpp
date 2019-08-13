#include "MonitorModuleList.hpp"

MonitorModuleList::MonitorModuleList()
{
	this->_objects = NULL;
	this->_numObjects = 0;
}

MonitorModuleList::MonitorModuleList(const MonitorModuleList & src)
{
	this->_numObjects = src._numObjects;
	this->_objects = new IMonitorModule * [this->_numObjects];
	for (int i = 0; i < this->_numObjects; i++)
		this->_objects[i] = src._objects[i];
}

MonitorModuleList::~MonitorModuleList()
{
	for (int i = 0; i < this->_numObjects; i++)
		delete this->_objects[i];
	delete [] this->_objects;
}

void MonitorModuleList::add(IMonitorModule *obj)
{
	if (obj == NULL)
		return;
	IMonitorModule **oldObjects = this->_objects;
	this->_objects = new IMonitorModule * [this->_numObjects + 1];
	for (int i = 0; i < this->_numObjects; i++)
		this->_objects[i] = oldObjects[i];
	delete oldObjects;
	this->_objects[this->_numObjects] = obj;
	this->_numObjects++;
}

void MonitorModuleList::dump(MonitorModuleList & dst)
{
	for (int i = 0; i < this->_numObjects; i++)
		dst.add(this->_objects[i]);
	this->_numObjects = 0;
	delete this->_objects;
	this->_objects = NULL;
}

int	MonitorModuleList::getSize() const
{
	return this->_numObjects;
}

IMonitorModule **MonitorModuleList::getRawList() const
{
	return this->_objects;
}

MonitorModuleList & MonitorModuleList::operator=(const MonitorModuleList & src)
{
	this->_numObjects = src._numObjects;
	this->_objects = new IMonitorModule * [this->_numObjects];
	for (int i = 0; i < this->_numObjects; i++)
		this->_objects[i] = src._objects[i];
	// TODO deep copy
	return *this;
}

