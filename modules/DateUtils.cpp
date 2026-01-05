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

bool isValidDate(const string &date) {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    int year, month, day;
    char dash1, dash2;
    stringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;
    
    if (ss.fail() || dash1 != '-' || dash2 != '-') return false;
    
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    // Days in month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        daysInMonth[2] = 29; // Leap year
    }
    
    if (day > daysInMonth[month]) return false;
    
    return true;
}
