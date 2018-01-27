#include <firal/random.h>
#include <random>

pcg32 Random::rng;
int Random::randCalls;

void Random::initialize() {
    reseed();
    randCalls = 0;
}

void Random::reseed() {
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);
    uint64_t r1 = rand();
    uint64_t r2 = rand();
    rng = pcg32(r1, r2);
    randCalls = 0;
}

void Random::reseed(unsigned int seed) {
    srand(seed);
    uint64_t r1 = rand();
    uint64_t r2 = rand();
    rng = pcg32(r1, r2);
    randCalls = 0;
}

float Random::getFloat() {
    randCalls++;
    return rng.nextFloat();
}

double Random::getDouble() {
    randCalls++;
    return rng.nextDouble();
}

double Random::getDouble(double start, double end) {
    randCalls++;
    double ret = (end - start) * getDouble() + start;
    // cout << "RAND: " << ret << endl;
    return ret;
}

void Random::clearCalls() {
    randCalls = 0;
}

int Random::callCount() {
    return randCalls;
}
