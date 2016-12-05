#ifndef VECTOR
#define VECTOR

#include<iostream>
#include <fstream>
#include <stdexcept>
#include "DSString.h"
using namespace std;

template<class T>
class myVector
{

  public:

      typedef T* iterator;
      myVector(); //Constructor
      myVector(int); //Constructor with size
      myVector(const myVector<T>&); //Copy constructor
      ~myVector(); //Destructor

      void add(T&); //Add new element to vector
      void add(T&, int); //Add new element to vector in certain position
      T& get(int);
      void pushBack(T&); //Add new element to end of vector
      void popBack(); //Removes the last element of the vector
      int getSize();
      int& changeSize();
      int& changeCap();
      void sort(); //Selection Sort
      void swap(T&,T&); //Swaps two elements in vector
      void resize(T*&, int&); //Resizes the vector by growing the capacity; Passed by reference of data and capacity
      bool isEmpty(); //Returns if vector is empty
      bool exists(T); //Returns if an element already exists in the vector
      void clear(); //Empties the vector
      T* firstIndex();
      T* lastIndex();

      T operator[](int);
      myVector<T>& operator=(const myVector<T>&); //Overloaded Assignment Operator
      void operator+=(T); //Same as add(T) and pushBack(T)

      bool operator== (T*); //Overloaded Equality Operator with a pointer
      bool operator== (const T&); //Overloaded Equality Operator reference

  private:

      int size;
      int cap;
      T* data;

};
#endif


//Constructor
template <class T>
myVector<T>::myVector()
{
    size = 0;
    cap = 10;
    data = new T[10];

}

//Constructor with size parameter
template <class T>
myVector<T>::myVector(int s)
{
    size = s;
    cap = 10;
    if(size>=cap)
        resize(data,cap);
    data = new T[cap];

}

//Copy Constructor with a reference
template <class T>
myVector<T>::myVector(const myVector<T>& v)
{
    size = v.size;
    cap = v.cap;
    data = v.data;

}

//Deconstructor
template <class T>
myVector<T>::~myVector()
{
    if( data != NULL )
        delete [] data;

}

//Adds a new element into vector at end
template <class T>
void myVector<T>::add(T& element)
{
    size++;
    if(cap<=size)
        resize(data,cap);
    data[size-1] = element;

}

//Adds a new element into vector at certain spot
template <class T>
void myVector<T>::add(T& element, int x)
{
    T temp[] = data;
    size++;
    if(cap<=size)
        resize(data,cap);
    for(int i=0; i<x; i++)
    {
        temp[i] = data[i];
    }

    for(int i=x; i<size-1; i++)
    {
        temp[i+1] = data[i];
    }

    delete [] data;
    data = temp;
    data[x] = element;

}

//Similar to [] ??
template <class T>
T& myVector<T>::get(int x)
{
    if(x<size && x>=0)
        return data[x];
    else
       throw out_of_range("error");

}

template <class T>
void myVector<T>::pushBack(T& element)
{
    size++;
    if(cap <= size-1)
    {
        resize(data,cap);
    }
    data[size-1] = element;

}

template <class T>
void myVector<T>::popBack()
{
    size--;

}

//Returns the size of the vector
template <class T>
int myVector<T>::getSize()
{
    return size;

}

template <class T>
int& myVector<T>::changeSize()
{
    return size;

}

template <class T>
int& myVector<T>::changeCap()
{
    return cap;

}

//Selection sort
template <class T>
void myVector<T>::sort()
{
    int minIndex;
    for(int i=0; i<size-1; i++)
    {
        minIndex=i;
        for(int j=i+1; j<size; j++)
        {
            if(data[j] < data[minIndex])
                minIndex = j;
        }
        if(minIndex != i)
            swap(data[minIndex],data[i]);
    }

}

//Swaps two elements in vector
template <class T>
void myVector<T>::swap(T& a, T& b) //Passed by reference
{
    T temp;
    temp = a;
    a = b;
    b = temp;

}

//Resizes the vector by growing the capacity
template <class T>
void myVector<T>::resize(T*& p, int& cap) //Passed by reference of data and capacity
{
    int cOld = cap;
    if(cap == 0)
    {
        cap = 2;
    }
    else
        cap *= 1.5; //Changes capacity

}

//Returns if vector is empty
template <class T>
bool myVector<T>::isEmpty()
{
    return (size==0);

}

//Returns if element already exists in vector
template <class T>
bool myVector<T>::exists(T element)
{
    bool exists = false;
    for(int i=0; i<size; i++)
    {
        if(element == data[i])
            exists = true;
    }
    return exists;

}

//Empties the vector
template <class T>
void myVector<T>::clear()
{
    size = 0;

}

//Returns pointer to the first index in the vector
template <class T>
T* myVector<T>::firstIndex()
{
    return data;
}

//Returns pointer to the last index in the vector
template <class T>
T* myVector<T>::lastIndex()
{
    return data + size;
}

//Overloaded [] operator that calls data in index place of vector
template <class T>
T myVector<T>::operator[](int x)
{
    if(x<0) //If index is negative
    {
        int s = this->size;
        return data[s+x-1]; //Returns index number from back
    }
    else if(x<size)//Index is positive
        return data[x];
    else
        throw out_of_range("error");

}

//Overloaded assignment operator
template <class T>
myVector<T>& myVector<T>::operator=(const myVector<T>& v)
{
    if(data!=nullptr)
    {
        delete [] data;
    }
    size = v.size;
    cap = v.cap;
    data = new T[cap];
    for (int i = 0; i < size; i++)
        data[i] = v.data[i];
    return *this;

}

//Same as add(T) and pushBack(T)
template <class T>
void myVector<T>::operator+=(T element)
{
    add(element);

}

//Overloaded Equality Operator with char pointer
template <class T>
bool myVector<T>::operator== (T* rhs)
{
    bool equals = false;
    int counter = 0;

    while(rhs[counter] != '\0')
    {
        counter++;
    }

    if(counter != this-> size)
        equals = false;
    else
    {
         for(int i=0; i<counter; i++)
         {
             if(rhs[i] != this-> data[i])
             {
                 equals = false;
                 return equals;
             }
             else
                 equals = true;
         }
         return equals;
    }

}

//Overloaded Equality Operator
template <class T>
bool myVector<T>::operator== (const T& rhs)
{
    bool equals = false;
    if (this-> size == rhs.size) //Both strings of same length
    {
        int i=0;
        while(i != size)
        {
            if(this-> data[i] != rhs.data[i]) //At first instance of not matching characters, returns false
            {
                equals = false;
                return equals;
            }
            else
                equals = true;
            i++;
        }
        equals = true;
    }
    else //Both strings of different length, not equal
        equals = false;
    return equals;

}
