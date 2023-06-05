#include "Logger.h"
#include "CustomGuard.h"

#include <iostream>

void Logger::log(const std::string& log)
{
	const CustomGuard lock(mGuard);
	std::cout << log << std::endl;
}