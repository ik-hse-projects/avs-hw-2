#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>

class Buffer {
 public:
    virtual unsigned int read_uint(unsigned int lower, unsigned int upper) = 0;
    virtual int read_int(unsigned int lower, unsigned int upper) = 0;
};

class Stdin : public Buffer {
    std::istream& stream;

 public:
    Stdin(std::istream& stream) : stream(stream) {}
    unsigned int read_uint(unsigned int lower, unsigned int upper) override;
    int read_int(unsigned int lower, unsigned int upper) override;
};

class Randomized : public Buffer {
 public:
    unsigned int read_uint(unsigned int lower, unsigned int upper) override;

    int read_int(unsigned int lower, unsigned int upper) override;
};

#endif