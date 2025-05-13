#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//class Date
//{
//public:
//     //1.⽆参构造函数
//    Date()
//    {
//        _year = 1;
//	    _month = 1;
//	    _day = 1;
//    }
//    // 2.带参构造函数
//    Date(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    // 3.全缺省构造函数
//    /*Date(int year = 1, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }*/
//
//    void Print()
//    {
//        cout << _year << "/" << _month << "/" << _day << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    Date d1;
//    Date d2(2025, 1, 1);
//
//    Date d3();
//
//    d1.Print();
//    d2.Print();
//
//    return 0;
//}

//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n= 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//
//		_capacity = n;
//		_top = 0;
//	}
//
//	~Stack()
//	{
//		cout << "-Stack()"<< endl;
//
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//
//class MyQueue
//{
//public:
//private:
//	Stack pushst;
//	Stack popst;
//};
//
//int main()
//{
//	Stack st;
//
//	MyQueue mq;
//
//	return 0;
//}