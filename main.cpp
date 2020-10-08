#include <iostream>
#include "Deque.h"

int main()
{
    Deque<int> deque(3);
    deque.show();
    deque.pushBack(4);
    deque.show();

    deque.pushFront(7);
    deque.show();

    deque.popBack();
    deque.show();

    deque.popFront();
    deque.show();

    deque[2] = 2;
    deque.show();

    return 0;
}