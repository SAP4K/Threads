#pragma omce
#include"console.h"
class Product
{
public:
	Product(int ID);
	Product();
	int get_id();
private:
	int ID;
};
class ProductPool
{
public:
	void push_product(Product* new_project);
	std::condition_variable* get_conditional_variable(bool*&,int);
	Product* get_product(int);
private:
	std::mutex product_lock;
	std::map<int, std::list<Product*>> products_lists;
	std::map<int,bool> existing_product;
	std::condition_variable wait_product;
};
