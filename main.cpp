#include "consumer.h"
 
int main()
{
	ProductPool my_pool;
	Console con;
	Production pr(&my_pool, &con, 3);
    Production pr2(&my_pool, &con, 5);
    Consumer cons(&my_pool,&con,5);
    Consumer cons2(&my_pool,&con,3);
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	}
} 