#ifndef LIST_H
#define LIST_H

template<class T>
struct Node
{
    T data;
    Node* next;
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
    Node<T>* temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    return temp->data;
}

template<class T>
int List<T>::GetSize() const
{
    return size;
}

#endif // LIST_H
