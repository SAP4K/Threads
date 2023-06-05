#pragma once
#include<string>
#include<mutex>

class Logger
{
public:
	void log(const std::string& log);
private:
	std::mutex mGuard;
};

