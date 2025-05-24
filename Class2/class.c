//拷贝构造
//// 这⾥可以完成拷⻉，但是不是拷⻉构造，只是⼀个普通的构造
//Date d2(&d1);
//d1.Print();
//d2.Print();
////这样写才是拷⻉构造，通过同类型的对象初始化构造，⽽不是指针
//Date d3(d1);
//d2.Print();
//// 也可以这样写，这⾥也是拷⻉构造
//Date d4 = d1;
//d2.Print();
//// Func2返回了⼀个局部对象tmp的引⽤作为返回值
//// Func2函数结束，tmp对象就销毁了，相当于了⼀个野引⽤
//Date ret = Func2();
//ret.Print();


//赋值运算符重载
//// 传引⽤返回减少拷⻉
//// d1 = d2;
//Date& operator=(const Date& d)
//{
//    // 不要检查⾃⼰给⾃⼰赋值的情况
//    if (this != &d)
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//
//    // d1 = d2表达式的返回对象应该为d1，也就是*this
//    return *this;
//}


//取地址运算符重载
//class Date
//{
//public:
//    Date* operator&()
//    {
//        return this;
//        // return nullptr;
//    }
//
//    const Date* operator&()const
//    {
//        return this;
//        // return nullptr;
//    }
//private:
//    int _year; // 年
//    int _month; // ⽉
//    int _day; // ⽇
//};