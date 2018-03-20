/*
#include "Timer.h"
#include "TimeThread.h"

namespace NLib
{

	TimeThread::TimeThread(Timer& t)
		: _t(t)
	{
	}

	TimeThread::~TimeThread()
	{
		_th.join();
	}

	void TimeThread::time()
	{
		while (!_join)
		{
			cv.wait(std::unique_lock<std::mutex>(_m));
			while (_t._enabled)
			{
				_t._time += _t.duration(_t._interval_type);
				if (_t._time > _t._interval)
				{
					//execute func
					_t._time = 0.0;
				}
				_t._begin = _t.current_time();
			}
		}
	}

	void TimeThread::notify()
	{
		cv.notify_all();
	}
}*/