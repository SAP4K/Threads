#pragma once
#include "IRunner.h"

class  Production: public IRunner
{
public:
	Production(ProductPool*, Console*,int);
	Production(ProductPool*);

	~Production();

protected:
	void run(ProductPool*, Console*, int);
};