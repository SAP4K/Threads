#pragma once
#include"Production.h"

class Consumer: public Runner
{
public:
	Consumer(ProductPool*, Console*, int);
private:
	void run(ProductPool*, Console*, int);
};