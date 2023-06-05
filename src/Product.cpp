#include "Product.h"
#include<future>
Product::Product()
{
	this->ID = NULL;
}
Product::Product(int ID):ID(ID) 
{

};
void ProductPool::push_product(Product* new_product)
{
		this->product_lock.lock();
		this->products_lists[new_product->get_id()].push_back(new_product);
		this->existing_product[new_product->get_id()] = true;
		this->wait_product.notify_all();
		this->product_lock.unlock();
}
int Product::get_id()
{
	return this->ID;
}
Product* ProductPool::get_product(int product_id)
{
	this->product_lock.lock();
	Product* product_return = this->products_lists[product_id].front();
	this->products_lists[product_id].pop_front();
	if(this->products_lists[product_id].size() == 0)
	{
		this->existing_product[product_id] = false;
	}
	this->product_lock.unlock();
	return product_return;
}
std::condition_variable* ProductPool::get_conditional_variable(bool*& produc_checker, int id_product)
{
	this->product_lock.lock();
	if(this->existing_product.find(id_product) == this->existing_product.end())
	{
		this->existing_product[id_product] = false;
	}
	produc_checker = &this->existing_product[id_product];
	this->product_lock.unlock();
	return &this->wait_product;
}