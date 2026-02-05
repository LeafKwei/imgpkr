#ifndef GLOBALCONF_H
#define GLOBALCONF_H

#include "3rdinclude/csc/core/CscHandler.hpp"

class GlobalConf
{
public:
    using GlobalConfCR = const GlobalConf&;
public:
    static GlobalConfCR globalconf();
private:
    GlobalConf();
    ~GlobalConf() =default;
    GlobalConf(const GlobalConf &other) =delete;
    GlobalConf(GlobalConf &&other) =delete;
    GlobalConf& operator=(const GlobalConf &other) =delete;
    GlobalConf& operator=(GlobalConf &&other) =delete;
};

#endif
