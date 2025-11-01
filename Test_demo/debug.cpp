#include <iostream>
#include <functional>
#include <stdio.h>
#include <vector>

using namespace std;


class MyCircularQueue {
private:
    vector<int> _circularQueue;
    int _rear;
    int _front;
public:
    MyCircularQueue(int k) {
        _circularQueue.resize(k);
        _rear = 0;
        _front = 0;
    }

    bool enQueue(int value) {
        if (!isFull())
        {
            _circularQueue[_rear] = value;
            ++_rear;
            if (_rear == _circularQueue.size())
                _rear %= _circularQueue.size();
            return true;
        }
        else
        {
            return false;
        }
    }

    bool deQueue() {
        if (!isEmpty())
        {
            _front++;
            if (_front == _circularQueue.size())
                _front %= _circularQueue.size();
            return true;
        }
        else
        {
            return false;
        }
    }

    int Front() {
        if (isEmpty())
            return -1;
        else
        {
            return _circularQueue[_front];
        }
    }

    int Rear() {
        if (isEmpty())
            return -1;
        else
        {
            return _circularQueue[_rear];
        }
    }

    bool isEmpty() {
        return _front == _rear;
    }

    bool isFull() {
        return (_rear + 1) == _front;
    }
};

int main()
{
    MyCircularQueue myQueue(3);
    myQueue.enQueue(1);
    myQueue.enQueue(2);
    myQueue.enQueue(3);
    return 0;
}