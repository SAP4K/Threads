#pragma once
#include <mutex>

class CustomGuard
{
public:
    CustomGuard(std::mutex&);
    ~CustomGuard();
private:
    std::mutex* mGuard;

};