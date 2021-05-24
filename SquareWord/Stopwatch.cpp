#include "Stopwatch.h"

Stopwatch::Stopwatch()
{
    s = m = h = 0;
    sec = min = hour = "00";
    result = "00:00:00";
}

void Stopwatch::clock()
{
    s++;

    if (s == 60) { // if a minute has passed
        s = 0;
        m++;
    }
    if (m == 60) { // if a hour has passed
        m = 0;
        h++;
    }

    sec = std::to_string(s);
    if (s < 10) {
        sec = "0" + sec;
    }
    min = std::to_string(m);
    if (m < 10) {
        min = "0" + min;
    }
    hour = std::to_string(h);
    if (h < 10) {
        hour = "0" + hour;
    }

    result = hour + ":" + min + ":" + sec;
}

System::String^ Stopwatch::get_time() const
{
    // convert std::string to SysString:
    System::String^ sysStr = gcnew System::String(result.c_str());
    return sysStr;
}
