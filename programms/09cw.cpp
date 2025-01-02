#include <iostream>

template <typename T>
class Container{

virtual ~Container()
{r
    while(!=isEmpty())
    {
        pop();
    }
};
virtual void push(const T &value)=0;
virtual T pop()=0;
virtual bool isEmpty() const=0;
virtual size_t size() const=0;
};

template <typename T>
class Queue: public Container<T>
{
    Node<T> *head;
    Node<T> *tail;
    void push(const T &value)) override
    {
        queue_ = malloc(sizeof(value)+1);
        
    }

};


template<typename T>

class Stack: public Container<T>
{
    Node<T> *head;
    void push(const T &value)) override
    {

    }

};


template <typename T>
class Node {
public:
    Node(T value) : data(value), next(nullptr) {}
    T data;
    Node<T> *next;
};

int main()
{

}