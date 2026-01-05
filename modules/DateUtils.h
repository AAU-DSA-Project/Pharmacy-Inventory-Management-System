#ifndef DATE_UTILS_H
#define DATE_UTILS_H
#include <string>
using namespace std;

string getTodayDate();
bool isExpired(const string &expired, const string &today);
bool isValidDate(const string &date);
#endif