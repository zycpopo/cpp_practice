#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"vector.h"

int main() {
    // ≤‚ ‘≥ı ºªØ¡–±Ìππ‘Ï
    popo::vector<int> vec = { 1, 2, 3, 4, 5 };
    std::cout << "Initial vector: ";
    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << "\n\n";

    // ≤‚ ‘ push_back
    vec.push_back(6);
    std::cout << "After push_back(6): ";
    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << "\n\n";

    // ≤‚ ‘ pop_back
    vec.pop_back();
    std::cout << "After pop_back(): ";
    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << "\n\n";

    // ≤‚ ‘ insert
    vec.insert(vec.begin() + 2, 99);
    std::cout << "After insert at pos 2 (value=99): ";
    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << "\n\n";

    // ≤‚ ‘ erase
    vec.erase(vec.begin());
    std::cout << "After erase first element: ";
    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << "\n\n";

    // ≤‚ ‘ resize
    vec.resize(10, 100);
    std::cout << "After resize(10, 100): ";
    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << "\n\n";

    // ≤‚ ‘ shrink_to_fit
    vec.shrink_to_fit();
    std::cout << "After shrink_to_fit(): ";
    for (auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << "\n\n";

    return 0;
}