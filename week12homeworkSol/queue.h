#include <iostream>
#include <string>

#include "LinkedList.h"

class Queue {
   private:
    LinkedList* ll;

   public:
    Queue() {
        ll = new LinkedList();
    }
    ~Queue() {
        delete ll;
    }
    void enqueue(int i) {
        //  add top
        ll->AddNodeFirst(i);
    }

    void Dequeue() {
        // remove Last
        ll->removeLast();
    }
    void display() {
        Node* temp = ll->head;
        cout << " ";
        while (temp != nullptr) {
            cout << temp->element << "\n ";
            temp = temp->next;
        }
    }
};