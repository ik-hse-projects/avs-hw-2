#include "buffer.h"
#include <cmath>

unsigned int Stream::read_uint(unsigned int lower, unsigned int upper) {
    unsigned int result;
    this->stream >> result;
    return result;
}

int Stream::read_int(unsigned int lower, unsigned int upper) {
    int result;
    this->stream >> result;
    return result;
}

static unsigned int random_in_range(unsigned int lower,
                                    unsigned int upper) {
    unsigned int range = upper - lower;
    unsigned int num = rand();
    unsigned int result = (num % range) + lower;
    return result;
}

unsigned int Randomized::read_uint(unsigned int lower, unsigned int upper) {
    return random_in_range(lower, upper);
}

int Randomized::read_int(unsigned int lower, unsigned int upper) {
    return random_in_range(lower, upper);
}
