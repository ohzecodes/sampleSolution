#include <iostream>
#include <string>

#include "./LinkedList.h"
using namespace std;
#ifndef STACK_H
#define STACK_H

class stack {
   private:
    LinkedList* ll;
    int addtop(int i) {
        ll->AddNodeFirst(i);
        return ll->getHeadValue();
    }
    int remove() {
        int i = ll->getHeadValue();
        ll->removeFirst();
        return i;
    }

   public:
    stack() {
        ll = new LinkedList();
    }
    ~stack() {
        delete ll;
    }
    int push(int i) {
        return addtop(i);
    };

    int pop() {
        return remove();
    }
    bool isempty() {
        return ll->IsEmpty();
    }
    int getTop() {
        return ll->FirstIndexOf();
    }
    void
    display() {
        Node* temp = ll->head;
        cout << " ";
        while (temp != nullptr) {
            cout << temp->element << "\n ";
            temp = temp->next;
        }

        cout << endl;
        cout << endl;
    }
};

#endif