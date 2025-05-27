#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"

using namespace popo;

void test_basic_operations() {
    std::cout << "=== 基本构造、赋值、拷贝测试 ===\n";

    string s1("hello");
    s1.print();

    string s2 = s1;
    s2.print();

    string s3;
    s3 = s1;
    s3.print();

    std::cout << "\n";
}

void test_push_back_and_append() {
    std::cout << "=== push_back 和 append 测试 ===\n";

    string s("hi");
    s.push_back('!');
    s.print();

    s.append(" there");
    s.print();

    s += ',';
    s += " friend.";
    s.print();

    std::cout << "\n";
}

void test_insert_and_find() {
    std::cout << "=== insert 和 find 测试 ===\n";

    string s("world");
    s.insert(0, "hello ");
    s.print();

    size_t pos = s.find('o');
    std::cout << "find('o') = " << pos << "\n";

    std::cout << "\n";
}

void test_substr_and_compare() {
    std::cout << "=== substr 和 compare 测试 ===\n";

    string s("abcdefg");
    string sub = s.substr(2, 3); // should be "cde"
    sub.print();

    string t("abcdefg");
    std::cout << "compare: " << s.compare(t) << "\n";
    std::cout << "s == t ? " << (s == t) << "\n";
    std::cout << "s < t ? " << (s < t) << "\n";

    std::cout << "\n";
}

void test_clear_and_resize() {
    std::cout << "=== clear 和 resize 测试 ===\n";

    string s("12345");
    s.resize(3);
    s.print();

    s.resize(6, 'x');
    s.print();

    s.clear();
    s.print();

    std::cout << "\n";
}

void test_istream_ostream() {
    std::cout << "=== 测试输入输出流重载 ===\n";

    string s;
    std::cout << "请输入一个单词：";
    std::cin >> s;
    std::cout << "你输入的是：[" << s << "]\n";

    std::cout << "\n";
}

int main() {
    test_basic_operations();
    test_push_back_and_append();
    test_insert_and_find();
    test_substr_and_compare();
    test_clear_and_resize();
    test_istream_ostream();

    return 0;
}
