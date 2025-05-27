#pragma once
#include<iostream>
#include <cstddef>
#include <cctype>

namespace popo
{
    class string {
        friend std::ostream& operator<<(std::ostream& out, const string& s);
        friend std::istream& operator>>(std::istream& in, string& s);

    private:
        char* _str;
        size_t _capacity;
        size_t _size;

    public:
        string(const char* str = "");
        string(const string& s);
        string& operator=(const string& s);
        ~string();

        //返回一个char指针
        const char* c_str() const;
        void print() const;

        //返回字符串给大小
        size_t size() const;
        //访问下标是i的字符
        char& operator[](size_t i);
        //只读访问
        const char& operator[](size_t i) const;

        void push_back(char c);
        string& operator+=(char c);

        void append(const char* str);
        string& operator+=(const char* str);

        void clear();
        void swap(string& s);

        void resize(size_t newSize, char ch = '\0');
        void reserve(size_t newCapacity);
        void insert(size_t pos, const char* str);
        size_t find(char ch, size_t pos = 0) const;

        static const size_t npos = (size_t)-1;

        string substr(size_t pos = 0, size_t len = npos) const;
        int compare(const string& s) const;
        void erase(size_t pos, size_t len = npos);

        // 关系运算符重载
        bool operator==(const string& s) const;
        bool operator!=(const string& s) const;
        bool operator<(const string& s) const;
        bool operator>(const string& s) const;
        bool operator<=(const string& s) const;
        bool operator>=(const string& s) const;

    };
}