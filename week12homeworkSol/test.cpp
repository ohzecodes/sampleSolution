#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList list(10);

    list.ShowForward();
    list.RemoveLast();
    list.ShowForward();

    return 0;
}