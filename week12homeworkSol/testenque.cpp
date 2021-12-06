#include <iostream>
#include <string>

#include "queue.h"
using namespace std;
int main() {
    Queue *q = new Queue();
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->Dequeue();
    q->Dequeue();
    q->Dequeue();
    q->display();

    return 0;
}