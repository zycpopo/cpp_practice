#pragma once
#include<deque>
#include <list>

//list模拟queue实现
//namespace popo {
//    template<class T>
//    class queue
//    {
//    public:
//        queue() {}
//
//        void push(const T& x) { _c.push_back(x); }
//
//        void pop() { _c.pop_front(); }
//
//        T& back() { return _c.back(); }
//
//        const T& back()const { return _c.back(); }
//
//        T& front() { return _c.front(); }
//
//        const T& front()const { return _c.front(); }
//
//        size_t size()const { return _c.size(); }
//
//        bool empty()const { return _c.empty(); }
//
//    private:
//        std::list<T> _c;
//    };
//}

//STL-queue模拟实现
namespace popo
{
    template<class T, class Con = std::deque<T>>
    //template<class T, class Con = list<T>>
    class queue
    {
    public:
        queue() {}
        void push(const T& x) { _c.push_back(x); }
        void pop() { _c.pop_front(); }
        T& back() { return _c.back(); }
        const T& back()const { return _c.back(); }
        T& front() { return _c.front(); }
        const T& front()const { return _c.front(); }
        size_t size()const { return _c.size(); }
        bool empty()const { return _c.empty(); }
    private:
        Con _c;
    };
}