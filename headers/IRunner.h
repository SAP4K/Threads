#pragma once
#include <thread>

class Runner
{
public:
	Runner();
	
protected:
	virtual void run() = 0;

	std::thread mThread;
};