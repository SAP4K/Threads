cmake_minimum_required(VERSION 3.14)
project(Thread_Consumer_Product)

target_sources(${PROJECT_NAME} PRIVATE /root/Consumer_Product/src/Product.cpp Product.h /root/Consumer_Product/src/Production.cpp Production.h /root/Consumer_Product/src/console.cpp console.h /root/Consumer_Product/src/consumer.cpp consumer.h)
