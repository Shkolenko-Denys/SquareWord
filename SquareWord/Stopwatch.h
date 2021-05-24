#pragma once

#include <string>

class Stopwatch
{
private:
    int s, m, h;
    std::string sec, min, hour, result;

public:
    Stopwatch();
    void clock();
    System::String^ get_time() const;
};

