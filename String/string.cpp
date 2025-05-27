#define _CRT_SECURE_NO_WARNINGS
#include"string.h"
#include <cstring>
#include <iostream>

namespace popo
{
    string::string(const char* str) {
        _size = std::strlen(str);
        _capacity = _size;
        _str = new char[_capacity + 1];
        std::strcpy(_str, str);
    }
    //拷贝构造
    string::string(const string& s) {
        _size = s._size;
        _capacity = s._capacity;
        _str = new char[_capacity + 1];
        std::strcpy(_str, s._str);
    }
    string& string::operator=(const string& s) {
        if (this != &s) {
            delete[] _str;
            _size = s._size;
            _capacity = s._capacity;
            _str = new char[_capacity + 1];
            std::strcpy(_str, s._str);
        }
        return *this;
    }
    //析构函数
    string::~string() {
        delete[] _str;
        _str = nullptr;
        _capacity = 0;
        _size = 0;
    }

    const char* string::c_str() const {
        return _str;
    }

    void string::print() const {
        std::cout << _str << " (size: " << _size << ", capacity: " << _capacity << ")\n";
    }

    size_t string::size() const {
        return _size;
    }

    char& string::operator[](size_t i) {
        return _str[i];
    }

    const char& string::operator[](size_t i) const {
        return _str[i];
    }

    void string::push_back(char c) {
        if (_size + 1 > _capacity) {
            reserve((_capacity == 0) ? 1 : _capacity * 2);
        }
        _str[_size] = c;
        _size++;
        _str[_size] = '\0';
    }

    void string::append(const char* str) {
        size_t len = strlen(str);
        if (_size + len > _capacity) {
            size_t newCap = _capacity == 0 ? 1 : _capacity;
            while (newCap < _size + len) {
                newCap *= 2;
            }
            reserve(newCap);
        }
        strcpy(_str + _size, str);
        _size += len;
    }

    void string::reserve(size_t newCapacity) {
        if (newCapacity > _capacity) {
            char* new_str = new char[newCapacity + 1];
            std::strcpy(new_str, _str);
            delete[] _str;
            _str = new_str;
            _capacity = newCapacity;
        }
    }

    // operator+= 添加 C 字符串
    string& string::operator+=(const char* str) {
        append(str);
        return *this;
    }
    string& string::operator+=(char c) 
    {
        push_back(c);
        return *this;
    }


    // clear 清空字符串
    void string::clear() {
        _size = 0;
        if (_str) {
            _str[0] = '\0';
        }
    }

    void string::swap(string& s) {
        std::swap(_str, s._str);
        std::swap(_size, s._size);
        std::swap(_capacity, s._capacity);
    }

    void string::resize(size_t newSize, char ch) {
        if (newSize <= _size) {
            _size = newSize;
            _str[_size] = '\0';
        }
        else {
            reserve(newSize);
            for (size_t i = _size; i < newSize; ++i) {
                _str[i] = ch;
            }
            _size = newSize;
            _str[_size] = '\0';
        }
    }

    void string::insert(size_t pos, const char* str) {
        size_t len = std::strlen(str);
        if (pos > _size) pos = _size;

        reserve(_size + len);

        // 先右移已有字符
        for (size_t i = _size; i >= pos && i < _size + len; --i) {
            _str[i + len] = _str[i];
        }

        // 插入新字符串
        for (size_t i = 0; i < len; ++i) {
            _str[pos + i] = str[i];
        }

        _size += len;
        _str[_size] = '\0';
    }

    size_t string::find(char ch, size_t pos) const {
        for (size_t i = pos; i < _size; ++i) {
            if (_str[i] == ch)
                return i;
        }
        return (size_t)-1; // 类似 std::string::npos
    }

    string string::substr(size_t pos, size_t len) const {
        if (pos >= _size) {
            return string(""); // 返回空字符串
        }

        if (len == npos || pos + len > _size) {
            len = _size - pos;
        }

        char* temp = new char[len + 1];
        std::strncpy(temp, _str + pos, len);
        temp[len] = '\0';

        string result(temp);
        delete[] temp;
        return result;
    }

    int string::compare(const string& s) const {
        return std::strcmp(_str, s._str);
    }

    void string::erase(size_t pos, size_t len) {
        if (pos >= _size) return;

        if (len == npos || pos + len > _size) {
            len = _size - pos;
        }

        for (size_t i = pos + len; i <= _size; ++i) {
            _str[i - len] = _str[i];
        }

        _size -= len;
        _str[_size] = '\0';
    }

    std::ostream& operator<<(std::ostream& out, const string& s) {
        out << s._str;
        return out;
        
    }

    std::istream& operator>>(std::istream& in, string& s) {
        s.clear();  // 清空旧内容
        char ch;

        // 跳过前导空白
        while (in.get(ch) && std::isspace(static_cast<unsigned char>(ch)))
            ;

        // 如果输入失败，直接返回
        if (!in) return in;

        // 开始读入非空白字符
        do {
            s.push_back(ch);
        } while (in.get(ch) && !std::isspace(static_cast<unsigned char>(ch)));

        // 如果最后一次读取的是空白字符，退回它
        if (in) in.unget();

        return in;
    }


    bool string::operator==(const string& s) const {
        return std::strcmp(_str, s._str) == 0;
    }

    bool string::operator!=(const string& s) const {
        return !(*this == s);
    }

    bool string::operator<(const string& s) const {
        return std::strcmp(_str, s._str) < 0;
    }

    bool string::operator>(const string& s) const {
        return std::strcmp(_str, s._str) > 0;
    }

    bool string::operator<=(const string& s) const {
        return !(*this > s);
    }

    bool string::operator>=(const string& s) const {
        return !(*this < s);
    }

}