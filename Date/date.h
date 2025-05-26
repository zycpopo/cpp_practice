#pragma once
#include <iostream>

class Date {
public:
    Date(int year = 1900, int month = 1, int day = 1);
    Date(const Date& d);
    Date& operator=(const Date& d);
    ~Date();

    void Print() const;

    // 日期运算
    Date& operator+=(int day);
    Date operator+(int day) const;
    Date& operator-=(int day);
    Date operator-(int day) const;
    int operator-(const Date& d) const;

    // 前置/后置 ++ --
    Date& operator++();     // 前置++
    Date operator++(int);   // 后置++
    Date& operator--();     // 前置--
    Date operator--(int);   // 后置--

    // 比较运算
    bool operator==(const Date& d) const;
    bool operator!=(const Date& d) const;
    bool operator<(const Date& d) const;
    bool operator<=(const Date& d) const;
    bool operator>(const Date& d) const;
    bool operator>=(const Date& d) const;

private:
    int _year;
    int _month;
    int _day;

    bool IsLeapYear(int year) const;
    int GetMonthDay(int year, int month) const;
    void AddOneDay();
    void SubOneDay();
};