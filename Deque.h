//
// Created by mi on 06.10.2020.
//

#ifndef DEQUE_DEQUE_H
#define DEQUE_DEQUE_H

#include <iostream>

template<typename T>
class Deque
{
private:
    int N;
    T *data;

public:
    int size() const
    {
        return N;
    }

    T *getData() const
    { return data; }

public:
    void show()
    {
        std::cout << "[";
        for (int i = 0; i < N; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

public:
    Deque(const int &N)
    {
        if (N < 0) throw std::bad_alloc();
        this->N = N;
        data = new T[N];
        for (int i = 0; i < N; ++i) {
            data[i] = 0;
        }
    }

    ~Deque()
    {
        delete[] data;
    }

    void pushBack(const T &arg)
    {
        T *tmp = new T[N + 1];

        for (int i = 0; i < N; ++i) {
            tmp[i] = data[i];
        }
        tmp[N] = arg;
        N += 1;

        delete[] data;

        data = tmp;
    }

    void popBack()
    {
        if (N <= 0) return;

        T *tmp = new T[N - 1];

        for (int i = 0; i < N - 1; ++i) {
            tmp[i] = data[i];
        }
        N -= 1;

        delete[] data;

        data = tmp;
    }

    void pushFront(const T &arg)
    {
        T *tmp = new T[N + 1];
        tmp[0] = arg;

        for (int i = 1; i < N + 1; ++i) {
            tmp[i] = data[i - 1];
        }

        N += 1;

        delete[] data;

        data = tmp;
    }

    void popFront()
    {
        if (N <= 0) return;

        T *tmp = new T[N - 1];

        for (int i = 0; i < N - 1; ++i) {
            tmp[i] = data[i + 1];
        }
        N -= 1;

        delete[] data;

        data = tmp;
    }

    T &operator[](const int i)
    {
        if (i < 0 || i >= N) throw std::out_of_range("Out of range access: incorrect index");
        return data[i];
    }
};


#endif //DEQUE_DEQUE_H
