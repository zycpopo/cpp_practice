#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <list>
#include "queue.h" // 请替换为包含popo::queue定义的头文件

// 测试popo::queue的函数
void test_popo_queue() {
    // 测试使用默认容器std::deque的情况
    std::cout << "=== 测试使用std::deque作为底层容器 ===" << std::endl;
    popo::queue<int> q1;

    // 测试初始状态
    std::cout << "初始时队列是否为空: " << (q1.empty() ? "是" : "否") << std::endl;
    std::cout << "初始队列大小: " << q1.size() << std::endl;

    // 测试入队操作
    q1.push(1);
    q1.push(2);
    q1.push(3);
    std::cout << "入队3个元素后，队列大小: " << q1.size() << std::endl;
    std::cout << "队头元素: " << q1.front() << std::endl; // 应输出1
    std::cout << "队尾元素: " << q1.back() << std::endl;  // 应输出3

    // 测试出队操作
    q1.pop();
    std::cout << "出队1个元素后，队头元素: " << q1.front() << std::endl; // 应输出2
    std::cout << "当前队列大小: " << q1.size() << std::endl; // 应输出2

    q1.pop();
    q1.pop();
    std::cout << "再出队2个元素后，队列是否为空: " << (q1.empty() ? "是" : "否") << std::endl; // 应输出是

    // 测试使用std::list作为底层容器的情况
    std::cout << "\n=== 测试使用std::list作为底层容器 ===" << std::endl;
    popo::queue<int, std::list<int>> q2;

    q2.push(10);
    q2.push(20);
    q2.push(30);
    std::cout << "入队3个元素后，队头元素: " << q2.front() << std::endl; // 应输出10
    std::cout << "队尾元素: " << q2.back() << std::endl;  // 应输出30
    std::cout << "队列大小: " << q2.size() << std::endl;  // 应输出3

    q2.pop();
    q2.push(40);
    std::cout << "出队1个元素并入队40后，队头元素: " << q2.front() << std::endl; // 应输出20
    std::cout << "队尾元素: " << q2.back() << std::endl;  // 应输出40
    std::cout << "队列大小: " << q2.size() << std::endl;  // 应输出3

    std::cout << "\n所有测试完成!" << std::endl;
}

// 可以在main函数中调用测试函数
int main() {
    test_popo_queue();
    return 0;
}