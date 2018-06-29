#include "RandomNumberGenerator.h"

template<class T> RandomNumberGenerator<T>::RandomNumberGenerator()
{
    rnd_engine_mt = mt19937_64(dev());
}

template<class T> RandomNumberGenerator<T>::~RandomNumberGenerator()
{
#if _DEBUG
    printf("RandomNumberGenerator @ %p destroy\n", this);
#endif
}

template<class T> T RandomNumberGenerator<T>::uniformRandomNumber(T min, T max)
{
    uniform_real_distribution<T> dist(min, max);
    return dist(rnd_engine_mt);
}

template<class T> T RandomNumberGenerator<T>::normalDistributedRandomNumber(T mean, T stddev)
{
    normal_distribution<T> dist(mean, stddev);
    return dist(rnd_engine_mt);
}