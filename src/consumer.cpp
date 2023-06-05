#include "consumer.h"

Consumer::Consumer(ProductPool* pool_of_products, Console* console,int set_id_product):Runner(pool_of_products,console,set_id_product)
{
    this->product_thread = std::thread(&Consumer::run, this,pool_of_products, console, set_id_product);
};

void Consumer::run(ProductPool* pool_of_products, Console* console,int set_id_product)
{
    bool* check_if_exist_product = nullptr;
    std::mutex temporar;
    std::unique_lock<std::mutex> unique_lock_temporar(temporar);
    std::condition_variable* conditional_variable_from_productpool = pool_of_products->get_conditional_variable(check_if_exist_product,set_id_product);
    while(true)
    {
        conditional_variable_from_productpool->wait(unique_lock_temporar,[=](){ return (*check_if_exist_product); });
        Product* temporar_product = pool_of_products->get_product(set_id_product);
        console->shows_the_console("se consuma produsul cu ID-ul: "+std::to_string(set_id_product));
        std::this_thread::sleep_for(std::chrono::milliseconds(set_id_product));
        console->shows_the_console("a fost consumat produsul cu ID-ul: "+std::to_string(set_id_product));
    }
}