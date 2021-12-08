#include <iostream>
#include <string>

#include "./stack.h"
using namespace std;
int main() {
    stack* s = new stack();
    // s->isempty();
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->pop();
    cout << s->getTop() << endl;
    s->pop();
    // s->display();
    if (s) {
        delete s;
        s = nullptr;
    }
    return 0;
}