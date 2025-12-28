#include "modules/DateUtils.h"
#include <iostream>
using namespace std;

int main(){
    string today = getTodayDate();
    cout << isExpired("01-01-2025", today)<<endl;
}