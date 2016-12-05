#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class ListNode
{
public:

    ListNode(); //Constructor
    ListNode(T); //Constructor with passed T
    ListNode(T, ListNode<T>*, ListNode<T>*); //Constructor with passed elements

    ListNode<T>* getNext(); //Returns listNode next
    ListNode<T>* getPrev(); //Returns listNode prev
    void setNext(ListNode<T>&, T); //Sets listNode next
    void setPrev(ListNode<T>&, T); //Sets listNode prev
    ListNode<T>& operator=(ListNode<T>&); //Overloaded Assignment Operator
    T getData(); //Returns data of node
    template <class G> friend class LinkedList; //LinkedList can access ListNode's private members

private:
    ListNode<T>* next;
    ListNode<T>* prev;
    T data;
};



//Constructor
template <class T>
ListNode<T>::ListNode()
{
    next = nullptr;
    prev = nullptr;

}

//Constructor with passed T
template <class T>
ListNode<T>::ListNode(T t)
{
    data = t;
    next = nullptr;
    prev = nullptr;

}

//Constructor with passed elements
template <class T>
ListNode<T>::ListNode(T t, ListNode<T>* n, ListNode<T>* l)
{
    data = t;
    next = n;
    prev = l;

}

//Returns listNode next
template<class T>
ListNode<T>* ListNode<T>::getNext()
{
    return next;

}

//Returns listNode prev
template<class T>
ListNode<T>* ListNode<T>::getPrev()
{
    return prev;

}

//Sets listNode next
template<class T>
void ListNode<T>::setNext(ListNode<T>& node, T n)
{
    node.next = n;

}

//Sets listNode prev
template<class T>
void ListNode<T>::setPrev(ListNode<T>& node, T p)
{
    node.prev = p;

}

//Overloaded Assignment Operator
template<class T>
ListNode<T>& ListNode<T>::operator=(ListNode<T>& rhs)
{
    data = rhs->data;
    next = rhs->data;
    prev = rhs->data;
    return *this;

}

//Returns data of node
template<class T>
T ListNode<T>::getData()
{
    return data;

}


template<class T>
class LinkedList
{

public:

    LinkedList(); //Constructor
    //LinkedList(int); //Constructor with passed size
    LinkedList(T); //Constructor with passed element
    LinkedList(const LinkedList<T>&); //Copy Constructor

    void pushBack(T); //Adds element T to back of list
    void addToFront(T); //Adds element T to front of list
    void add(T,int); //Makes ListNode to be added at certain location
    void add(T, ListNode<T>*); //Adds ListNode to list
    T get(int); //Returns element at certain position of list
    ListNode<T>* remove(int); //Removes element at certain position of list
    ListNode<T>* removeBack(); //Removes last element of list
    bool isEmpty(); //Returns if list is empty
    int getSize(); //Returns num_elements
    ListNode<T>* getFront(); //Returns front node of list
    ~LinkedList(); //Destructor

    T& operator[](int); //Returns address of element at certain position
    LinkedList<T>& operator=(LinkedList<T>&); //Overloaded Assignment Operator
    ListNode<T>& find(T&); //Finds T and returns the Node that it is in
    bool exists(T); //Returns if T exists in the list

private:

    ListNode<T>* front;
    ListNode<T>* tail;
    int num_elements;

};


//Constructor
template<class T>
LinkedList<T>::LinkedList()
{
    front = new ListNode<T>();
    tail = new ListNode<T>();
    num_elements = 0;
}

//Constructor with passed element
template<class T>
LinkedList<T>::LinkedList(T element)
{
    front = new ListNode<T>(element);
    num_elements=1;

}

//Copy Constructor
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& t)
{
    front = nullptr;
    num_elements = 0;
    ListNode<T>* curr = front;
    for(int i=0; i<t.num_elements; i++)
    {
        pushBack(curr->getData());
        curr = curr->next;
    }

}

//Adds element T to back of list
template<class T>
void LinkedList<T>::pushBack(T element)
{
    ListNode<T>* ptr = new ListNode<T>();
    ptr->data = element;
    ptr->next = nullptr;

    if(front == nullptr)
    {
        front = ptr;
        num_elements++;
    }
    else
    {
        ListNode<T>* curr = front;
        while(curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = ptr;
        ptr->prev = curr;
        ptr->next = nullptr;
        num_elements++;

    }

}

//Adds element T to front of list
template<class T>
void LinkedList<T>::addToFront(T element)
{
    ListNode<T>* first = new ListNode<T>(element);
    first->next = front;
    front->prev = first;
    front = first;
    num_elements++;

}

//Makes ListNode to be added at certain location
template<class T>
void LinkedList<T>::add(T element, int loc)
{
    if(loc == 0 || front == nullptr) //No elements, add to front
    {
        front = new ListNode<T>(element, front, nullptr);
        num_elements++;
    }
    else if(loc > num_elements) //Add at end
    {
        pushBack(element);
        num_elements++;
    }
    else //Add at certain location
    {
        ListNode<T>* curr = front;
        int x=0;
        for(x=0; x<loc-1 && curr!=nullptr; x++)
        {
            curr = curr->next;
        }
        add(element, curr);
        num_elements++;
    }

}

//Adds ListNode to list
template<class T>
void LinkedList<T>::add(T element, ListNode<T>* c)
{
    ListNode<T> * temp = new ListNode<T>(element);
    temp->next = c->next;
    temp->prev = c;
    c->next = temp;

}

//Returns element at certain position of list
template<class T>
T LinkedList<T>::get(int x)
{
    return operator[](x);

}

//Removes element at certain position of list
template<class T>
ListNode<T>* LinkedList<T>::remove(int x)
{
    if(x==0) //Delete first element in list
    {
        ListNode<T>* temp = front;
        front = front->next;
        num_elements--;
        front->prev = nullptr;
        return temp;
        delete temp;
    }
    else
    {
        ListNode<T>* curr = front;
        for(int i=0; i<x-1; i++)
        {
            curr = curr->next;
        }
        ListNode<T>* temp = curr->next;
        curr->next = temp->next;
        temp->next->prev = curr;
        temp->next = nullptr;
        num_elements--;
        return temp;
        delete curr;
    }

}

//Removes last element of list
template<class T>
ListNode<T>* LinkedList<T>::removeBack()
{
    if (front == nullptr) //Empty list
    {
        throw out_of_range("No elemenets in list");
    }
    if (front == tail) //Only 1 element in list
    {
        ListNode<T>* temp = front;
        front = tail = nullptr;
        num_elements--;
        return front;
        delete temp;
    }
    else //Multiple elements in list
    {
        ListNode<T>* temp = front;
        for(int i = 1; i < num_elements-1; i++)
        {
            temp = temp->next; //Getting to next to last element
        }
        ListNode<T>* removed = temp->next;
        tail = temp;
        tail->next = nullptr;
        num_elements--;
        return removed;
        delete temp;

    }

}

//Returns if list is empty
template<class T>
bool LinkedList<T>::isEmpty()
{
    if(front == nullptr)
        return true;
    else
        return false;

}

//Returns num_elements
template<class T>
int LinkedList<T>::getSize()
{
    return num_elements;

}

//Returns front node of list
template<class T>
ListNode<T>* LinkedList<T>::getFront()
{
    return front;

}

//Destructor
template<class T>
LinkedList<T>::~LinkedList()
{
    ListNode<T>* curr = front;
    while(curr != nullptr)
    {
        ListNode<T>* temp = curr->next;
        delete curr;
        curr = temp;

    }
    front = nullptr;
    tail = nullptr;
    num_elements = 0;

}

//Returns address of element at certain position
template<class T>
T& LinkedList<T>::operator[](int x)
{
    if(x>0 && x<=num_elements)
    {
        ListNode<T>* curr = front;
        int i=0;
        for(i=0; i<x; i++)
        {
            curr = curr->next;
        }
        return curr->data;
    }
    if(x==0)
    {
        return front->data;
    }
    else
        throw out_of_range("Not in range");


}

//Overloaded Assignment Operator
template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& rhs)
{
    if(this != &rhs)
    {
        delete front;
        delete tail;
        num_elements = 0;
        num_elements = rhs.num_elements;
        ListNode<T>* curr = rhs.front;
        while(curr->next != nullptr)
        {
            pushBack(curr->getData());
            curr = curr->next;
        }
    }
    return *this;

}

//Finds T and returns the Node that it is in
template<class T>
ListNode<T>& LinkedList<T>::find(T& rhs)
{
    ListNode<T> curr = front;
    for(int i=0; i<num_elements; i++)
    {
        if(get(i) == rhs)
            return curr;
        curr = curr->next;
    }

}

//Returns if T exists in the list
template<class T>
bool LinkedList<T>::exists(T rhs)
{
    bool exists = false;
    ListNode<T> curr = front;
    for(int i=0; i<num_elements; i++)
    {
        if(get(i) == rhs)
            return true;
        curr = curr->next;
    }
    return exists;

}

#endif
