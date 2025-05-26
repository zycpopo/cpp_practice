#include "Date.h"
#include <cassert>

bool Date::IsLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::GetMonthDay(int year, int month) const {
    static int monthDays[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && IsLeapYear(year))
        return 29;
    return monthDays[month];
}

// 构造函数
Date::Date(int year, int month, int day)
    : _year(year), _month(month), _day(day)
{
    assert(year >= 1 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year, month));
}

// 拷贝构造
Date::Date(const Date& d)
    : _year(d._year), _month(d._month), _day(d._day) {}

// 赋值运算符
Date& Date::operator=(const Date& d) {
    if (this != &d) {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    return *this;
}

// 析构函数
Date::~Date() {}

// 打印
void Date::Print() const {
    printf("%04d-%02d-%02d\n", _year, _month, _day);
}

// 加减辅助函数
void Date::AddOneDay() {
    _day++;
    if (_day > GetMonthDay(_year, _month)) {
        _day = 1;
        _month++;
        if (_month > 12) {
            _month = 1;
            _year++;
        }
    }
}

void Date::SubOneDay() {
    _day--;
    if (_day < 1) {
        _month--;
        if (_month < 1) {
            _month = 12;
            _year--;
        }
        _day = GetMonthDay(_year, _month);
    }
}

// += day
Date& Date::operator+=(int day) {
    while (day > 0) {
        AddOneDay();
        --day;
    }
    return *this;
}

// + day
Date Date::operator+(int day) const {
    Date tmp(*this);
    tmp += day;
    return tmp;
}

// -= day
Date& Date::operator-=(int day) {
    while (day > 0) {
        SubOneDay();
        --day;
    }
    return *this;
}

// - day
Date Date::operator-(int day) const {
    Date tmp(*this);
    tmp -= day;
    return tmp;
}

// - Date（日期相减，返回天数差）
int Date::operator-(const Date& d) const {
    Date max = *this;
    Date min = d;
    int flag = 1;
    if (*this < d) {
        max = d;
        min = *this;
        flag = -1;
    }
    int count = 0;
    while (min != max) {
        ++min;
        ++count;
    }
    return count * flag;
}

// 前置++
Date& Date::operator++() {
    AddOneDay();
    return *this;
}

// 后置++
Date Date::operator++(int) {
    Date tmp(*this);
    AddOneDay();
    return tmp;
}

// 前置--
Date& Date::operator--() {
    SubOneDay();
    return *this;
}

// 后置--
Date Date::operator--(int) {
    Date tmp(*this);
    SubOneDay();
    return tmp;
}

// 比较运算符
bool Date::operator==(const Date& d) const {
    return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator!=(const Date& d) const {
    return !(*this == d);
}

bool Date::operator<(const Date& d) const {
    return (_year < d._year) || (_year == d._year && _month < d._month) ||
        (_year == d._year && _month == d._month && _day < d._day);
}

bool Date::operator<=(const Date& d) const {
    return *this < d || *this == d;
}

bool Date::operator>(const Date& d) const {
    return !(*this <= d);
}

bool Date::operator>=(const Date& d) const {
    return !(*this < d);
}
