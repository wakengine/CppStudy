#pragma once

#include <string>

#define FuncTrace() ScopeTrace s(__FUNCTION__, __LINE__)

class ScopeTrace {
public:
    ScopeTrace(const char * name, int line) : mName(name), mLine(line) {
        printf("Enter: %s line:%d\n", mName.c_str(), mLine);
    }

    ~ScopeTrace() {
        printf("Exit: %s for line:%d\n", mName.c_str(), mLine);
    }
private:
    std::string mName;
    int mLine;
};