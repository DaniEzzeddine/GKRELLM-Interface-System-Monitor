#ifndef FRAMECLOCK_H
# define FRAMECLOCK_H

#include "ft_gkrellm.hpp"

class FrameClock
{
	private:
	int _maxFPS;
	long _updateInterval;
	float _realFPS;
	struct timespec _nextUpdateAt;
	struct timespec _lastUpdateAt;

	public:
	FrameClock();
	FrameClock(const FrameClock & src);
	~FrameClock();

	bool tick();
	float getRealFPS() const;

	FrameClock & operator=(const FrameClock & src);
};

#endif
