#pragma once

#include <random>

using namespace std;

template<class T>
class RandomNumberGenerator
{
public:
    RandomNumberGenerator();
    ~RandomNumberGenerator();

    T uniformRandomNumber(T min, T max);
    T normalDistributedRandomNumber(T mean = 0, T stddev = 1);
private:
    mt19937_64 rnd_engine_mt;
    random_device dev;
};
