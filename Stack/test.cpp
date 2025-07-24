#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
// 假设你的stack类定义在这个头文件中，根据实际情况修改
#include "stack.h"

// 测试popo命名空间下的stack类
void test_popo_stack() {
    // 创建一个存储int类型的栈，使用默认底层容器deque
    popo::stack<int> s;

    // 测试栈是否为空
    std::cout << "测试栈是否为空: " << (s.empty() ? "是空" : "不是空") << std::endl;

    // 测试入栈操作
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    std::cout << "入栈5个元素后，栈的大小: " << s.size() << std::endl;

    // 测试访问栈顶元素
    std::cout << "当前栈顶元素: " << s.top() << std::endl;

    // 测试出栈操作
    s.pop();
    std::cout << "出栈一个元素后，栈顶元素: " << s.top() << std::endl;
    std::cout << "出栈一个元素后，栈的大小: " << s.size() << std::endl;

    // 连续出栈，直到栈为空
    std::cout << "连续出栈剩余元素: ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    // 测试栈为空时的操作
    std::cout << "所有元素出栈后，栈是否为空: " << (s.empty() ? "是空" : "不是空") << std::endl;
    std::cout << "所有元素出栈后，栈的大小: " << s.size() << std::endl;

    // 测试使用vector作为底层容器
    popo::stack<std::string, std::vector<std::string>> str_stack;
    str_stack.push("hello");
    str_stack.push("world");
    std::cout << "\n使用vector作为底层容器的栈，栈顶元素: " << str_stack.top() << std::endl;
    str_stack.pop();
    std::cout << "出栈后，栈顶元素: " << str_stack.top() << std::endl;
}

int main() {
    test_popo_stack();
    return 0;
}
