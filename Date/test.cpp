#include "Date.h"

int main() {
    Date d1(2024, 5, 26);
    d1.Print();

    Date d2 = d1 + 10;
    d2.Print();

    d2 -= 5;
    d2.Print();

    std::cout << "相差天数: " << d2 - d1 << std::endl;

    if (d2 > d1)
        std::cout << "d2 晚于 d1" << std::endl;

    return 0;
}