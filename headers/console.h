#pragma once
#include<vector>
#include<list>
#include<thread>
#include<mutex>
#include<chrono>
#include<map>
#include<iostream>
#include<string>
#include<condition_variable>
class Console
{
public:
	void shows_the_console(std::string);
private:
	std::mutex block_console;
};

