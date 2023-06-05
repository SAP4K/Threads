#include "Production.h"
Runner::Runner(ProductPool* pool_of_products, Console* console,int set_id_product)
{
};
std::thread::id Runner::get_id()
{
	return this->product_thread.get_id();
}

Production::Production(ProductPool* pool_of_products, Console* console,int set_id_product):Runner(pool_of_products, console,set_id_product)
{
	this->product_thread = std::thread(&Production::run, this,pool_of_products, console, set_id_product);
}

void Production::run(ProductPool* pool_of_products,Console* console,int product_id)
{
	while (true) 
	{	
		console->shows_the_console("Se creaza produsul cu ID-ul: " + std::to_string(product_id));
		std::this_thread::sleep_for(std::chrono::milliseconds(product_id*1000));
		Product* create_product = new Product(product_id);
		pool_of_products->push_product(create_product);
		console->shows_the_console("A fost Creat produsul cu ID-ul: " + std::to_string(product_id));
	}
}
