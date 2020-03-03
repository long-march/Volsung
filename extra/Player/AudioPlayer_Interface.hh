
#pragma once
#include "VolsungHeader.hh"

struct AudioPlayer_Interface
{
    static const size_t blocksize = Volsung::AudioBuffer::blocksize;
    virtual void initialize(unsigned) = 0;
    virtual void play(float*) = 0;
    virtual void clean_up() = 0;
};
