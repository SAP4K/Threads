#include "CustomGuard.h"

CustomGuard::CustomGuard(std::mutex& guard)
{
    mGuard = &guard;
    mGuard->lock();
}

CustomGuard::~CustomGuard()
{
    mGuard->unlock();
}