#pragma once

#include <string>

class Timer
{
private:
    int s, m, h;
    std::string sec, min, hour, result;

public:
    Timer();
    void clock();
    System::String^ get_time() const;
};

