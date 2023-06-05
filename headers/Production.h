#pragma once
#include"Product.h"
class Runner
{
public:
	Runner(ProductPool*, Console*,int);
	
protected:
	virtual void run(ProductPool*, Console*, int) = 0;
	std::thread::id get_id();
	std::thread product_thread;
};
class  Production: public Runner
{
public:
	Production(ProductPool*, Console*,int);
	Production(ProductPool*);
protected:
	void run(ProductPool*, Console*, int);
};