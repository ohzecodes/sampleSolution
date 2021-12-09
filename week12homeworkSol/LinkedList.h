
/*From Muntaseer Salahuddin to Everyone: (7:13 PM)
From Muntaseer Salahuddin to Everyone: (7:16 PM)
// remove last / else case
            Node* temp = tail;
            tail = tail->prev;
            int element = temp->element;
            delete temp;
            return element;


            // remove first 
            //
            int size = this->Size();
        if (size == 0) {
            return -1;
        } else if (size == 1) {
            Node* temp = head;
            head = tail = nullptr;
            int element = temp->element;
            delete temp;
            return element;
        } else {
            Node* temp = head;
            head = head->next;
            int element = temp->element;
            delete temp;
            return element;
        }
From Muntaseer Salahuddin to Everyone: (7:31 PM)
RemoveFirst() // 2RemoveLast() // 2stack 3queue 3stack and queue must use linked list to get full points*/
#include <iostream>

using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
   public:
    int element;
    Node* next;
    Node* prev;

    Node() {
        element = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int e) {
        element = e;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
   public:
    Node* head;
    Node* tail;

    LinkedList() {
        // empty list
        head = nullptr;
        tail = nullptr;
    }

    LinkedList(int n) {
        head = tail = nullptr;
        for (int i = 0; i < n; i++) {
            AddNodeLast(i + 1);
        }
    }

    ~LinkedList() {
        Node* temp;
        Node* nextNode = nullptr;

        for (temp = head; temp != tail; temp = nextNode) {
            if (temp != nullptr) {
                nextNode = temp->next;
                delete temp;
            }
        }

        delete tail;
        head = tail = nullptr;
    }

    bool IsEmpty() {
        return tail == nullptr;
    }

    int Size() const {
        int count = 0;
        Node* temp = tail;

        while (temp != nullptr) {
            count++;
            temp = temp->prev;
        }

        return count;
    }

    void AddNodeLast(int value = 0) {
        // add a new node to the end to the end of the list
        if (IsEmpty()) {
            head = new Node(value);
            tail = head;
        } else {
            Node* temp = new Node(value);

            tail->next = temp;
            temp->prev = tail;

            tail = temp;
        }
    }

    void ShowReverse() {
        Node* temp = tail;

        while (temp != nullptr) {
            cout << temp->element << " - ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void ShowForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->element << " - ";
            temp = temp->next;
        }
        cout << endl;
    }

    void AddNodeFirst(int value = 0) {
        // add a new node at the beginning of the list i.e. new node will become the new head
        if (IsEmpty()) {
            head = new Node(value);
            tail = head;
        } else {
            head->prev = new Node(value);
            head->prev->next = head;
            head = head->prev;
        }
    }

    void AddNode(int index, int nodeValue) {
        // add a new node at position index containing nodeValue
        int sz = Size();
        if (index == 0) {
            AddNodeFirst(nodeValue);
        } else if (index == sz - 1) {
            AddNodeLast(nodeValue);
        } else if (index < sz && !(index < 0)) {
            // find the item currently at index first
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }

            //cout << temp->element << endl;
            Node* oldPrev = temp->prev;
            Node* newNode = new Node(nodeValue);
            temp->prev->next = newNode;
            temp->prev = newNode;
            newNode->next = temp;
            newNode->prev = oldPrev;
        } else {
            cout << "Index out of bounds" << endl;
        }
    }

    int removeLast() {
        int size = this->Size();
        if (size == 0) {
            return -1;
        } else if (size == 1) {
            Node* temp = head;
            head = tail = nullptr;
            int element = temp->element;
            delete temp;
            return element;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            int element = temp->element;
            delete temp;
            temp = nullptr;
            return element;
        }
    }
    int removeFirst() {
        int size = this->Size();
        if (size == 0) {
            return -1;
        } else if (size == 1) {
            Node* temp = head;
            head = tail = nullptr;
            int element = temp->element;
            delete temp;
            return element;
        } else {
            Node* temp = head;
            head = head->next;
            int element = temp->element;
            delete temp;
            return element;
        }
    }

    int getHeadValue() {
        if (this->Size() == 0)
            return -1;
        else
            return head->element;
    }

    int getTailValue() {
        if (this->Size() == 0)
            return -1;
        else
            return tail->element;
    }

    // int removeAt(int index) {
    //     int size = this->Size();
    //     if (index < 0 || index >= size)
    //         return -2;
    //     else if (index == 0)
    //         return removeFirst();
    //     else if (index == size - 1)
    //         return removeLast();
    //     else {
    //         Node* previous = head;

    //         for (int i = 1; i < index; i++) {
    //             previous = previous->next;
    //         }

    //         Node* current = previous->next;
    //         previous->next = current->next;
    //         int element = current->element;
    //         delete current;
    //         return element;
    //     }
    // }
// };
#endif