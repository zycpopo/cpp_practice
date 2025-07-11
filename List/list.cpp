#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "list.h"
using namespace std;
using namespace popo;

int main() {
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(0);

    // ∑∂Œßfor±È¿˙£®“¿¿µbegin()∫Õend()£©
    for (auto e : l) {
        cout << e << " "; //  ‰≥ˆ£∫0 1 2
    }
    cout << endl;

    // constµ¸¥˙∆˜
    const list<int> cl = l;
    for (auto it = cl.begin(); it != cl.end(); ++it) {
        cout << *it << " "; //  ‰≥ˆ£∫0 1 2
    }
    cout << endl;

    return 0;
}