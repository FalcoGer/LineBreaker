#pragma once

#include <random>

using namespace std;

template<class T>
class RandomNumberGenerator
{
public:
    RandomNumberGenerator()
	{
		rnd_engine_mt = mt19937_64(dev());
	}
    ~RandomNumberGenerator()
	{
		#if _DEBUG
				printf("RandomNumberGenerator @ %p destroy\n", this);
		#endif
	}

    T uniformRandomNumber(T min, T max)
	{
		uniform_real_distribution<double> dist(static_cast<double>(min), static_cast<double>(max));
		return static_cast<T>(dist(rnd_engine_mt));
	}
    T normalDistributedRandomNumber(T mean = 0, T stddev = 1)
	{
		normal_distribution<double> dist(static_cast<double>(mean), static_cast<double>(stddev));
		return static_cast<T>(dist(rnd_engine_mt));
	}
private:
    mt19937_64 rnd_engine_mt;
    random_device dev;
};
