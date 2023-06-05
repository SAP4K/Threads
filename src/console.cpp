#include "console.h"
void Console::shows_the_console(std::string message)
{
	this->block_console.lock();
	std::cout << message+"\n";
	this->block_console.unlock();
}