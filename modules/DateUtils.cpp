#include "DateUtils.h"
#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

string getTodayDate(){
    using namespace std::chrono;

    auto now = system_clock::now();
    time_t t = system_clock::to_time_t(now);

    tm localTime{};
    #ifdef _WIN32
        localtime_s(&localTime, &t); // Windows
    #else
        localtime_r(&t, &localTime); // Linux/Macos
    #endif

    ostringstream oss;
    oss << put_time(&localTime, "%Y-%m-%d");
    return oss.str();
}

bool isExpired(const string &expired, const string &today){
    return expired < today;
}
