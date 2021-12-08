#include <iostream>

#include "./stack.h"
#include "LinkedList.h"
#include "queue.h"

using namespace std;

int main() {
    int count = 4;
    stack s;
    for (int i = 1; i <= count; i++) {
        s.push(i);
    }
    cout << s.getTop() << endl;
    s.display();
    s.pop();

    cout
        << endl;
    s.display();
    cout << s.getTop() << endl;
    cout << "Queue" << endl;
    Queue q;
    cout << boolalpha << q.isempty() << endl;
    for (int i = 1; i <= count; i++) {
        q.enqueue(i);
    }
    q.enqueue(5);
    q.display();
    q.Dequeue();
    q.display();

    return 0;
}