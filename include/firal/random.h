#pragma once

#include <firal/common.h>
#include <pcg32.h>

class Random {
public:
    static void initialize();
    static void reseed();
    static void reseed(unsigned int seed);
    static float getFloat();
    static double getDouble();
    static double getDouble(double start, double end);

    // debug methods
    static void clearCalls();
    static int callCount();

protected:
    static pcg32 rng;
    static int randCalls;
};
