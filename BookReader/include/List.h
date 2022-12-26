#ifndef LIST_H
#define LIST_H

template<class T>
class Iterator;

template<class T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node (T);
    ~Node() = default;
};

template<class T>
Node<T>::Node(T _data) : data(_data)
{ }

template<class T>
class List
{
public:
    List();
    ~List() = default;
    void Append(T);
    void Pop();
    void Clear();
    T operator[](int);
    int GetSize() const;
    friend class Iterator<T>;

private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};

template<class T>
List<T>::List() : head(nullptr), tail(nullptr), size(0)
{ }

template<class T>
void List<T>::Append(T data)
{
    Node<T>* temp = new Node(data);
    if (!head)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }

    size++;
}

template<class T>
void List<T>::Pop()
{
    if (head)
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    size--;
}

template<class T>
void List<T>::Clear()
{
    int tmpSize = size;
    for (int i = 0; i < tmpSize; i++)
    {
        Pop();
    }

    head = nullptr;
    tail = nullptr;
}

template<class T>
T List<T>::operator[](int index)
{
    Iterator<T> iterator = head;
    for (int i = 0; i < index; i++)
    {
        ++iterator;
    }

    return *iterator;
}

template<class T>
int List<T>::GetSize() const
{
    return size;
}

template<class T>
class Iterator
{
public:
    Iterator(Node<T>*);
    ~Iterator() = default;
    Iterator<T>& operator++();
    T& operator*() const;

private:
    Node<T>* currentNode;
};

template<class T>
Iterator<T>::Iterator(Node<T>* node) : currentNode(node)
{ }

template<class T>
Iterator<T> &Iterator<T>::operator++()
{
    currentNode = currentNode->next;
    return *this;
}

template<class T>
T &Iterator<T>::operator*() const
{
    return currentNode->data;
}

#endif // LIST_H
