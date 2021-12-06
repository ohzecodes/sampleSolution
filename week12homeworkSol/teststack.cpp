#include <iostream>
#include <string>

#include "./stack.h"
using namespace std;
int main() {
    stack* s = new stack();
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->pop();
    s->pop();
    s->display();
    delete s;

    return 0;
}