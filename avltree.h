#ifndef AVLTREE_H
#define AVLTREE_H

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

template <class T>
class AVLNode
{

public:
    AVLNode(); //Constructor
    AVLNode(T); //Constructor with passed value
    AVLNode(T,AVLNode<T>*,AVLNode<T>*); //Constructor with passed value and children
    T& getData(); //Returns data
    AVLNode<T>*& getRight(); //Returns right node
    AVLNode<T>*& getLeft(); //Returns left node
    template <class G> friend class AVLtree; //AVLtree can access AVLNode's private members

private:
    AVLNode<T>* left; //Left node pointer
    AVLNode<T>* right; //Right node pointer
    T data; //Element data
    int height;

};

//Constructor
template<class T>
AVLNode<T>::AVLNode()
{
    //data = NULL;
    left = nullptr;
    right = nullptr;
    height = 0;

}

//Constructor with passed value
template<class T>
AVLNode<T>::AVLNode(T value)
{
    data = value;
    left = nullptr;
    right = nullptr;

}

//Constructor with passed value and children
template<class T>
AVLNode<T>::AVLNode(T value, AVLNode<T>* l, AVLNode<T>* r)
{
    data = value;
    left = l;
    right = r;
    height = 0;

}

//Returns data
template<class T>
T& AVLNode<T>::getData()
{
    return data;

}

//Returns right node
template<class T>
AVLNode<T>*& AVLNode<T>::getRight()
{
    return right;

}

//Returns left node
template<class T>
AVLNode<T>*& AVLNode<T>::getLeft()
{
    return left;

}

template <class T>
class AVLtree
{

public:
    AVLtree(); //Constructor
    AVLtree(const AVLtree &); //Copy Constructor
    ~AVLtree(); //Destructor
    AVLNode<T>* getRoot(); //Returns root

    void insert(const T&); //Calls other insert method with root
    int height() const; //Calls other height method
    int heightDiff(AVLNode<T>*); //Returns balance factor of a node
    int max(int,int) const; //Max of two elements
    const T& findMin() const; //Calls other findMin method
    const T& findMax() const; //Calls other findMax method
    AVLNode<T>* findMin(AVLNode<T>*) const;
    AVLNode<T>* findMax(AVLNode<T>*) const;

    AVLNode<T>* rotateWithLeftChild(AVLNode<T>*&); //Case 1
    AVLNode<T>* doubleWithLeftChild(AVLNode<T>*&); //Case 2
    AVLNode<T>* rotateWithRightChild(AVLNode<T>*&); //Case 4
    AVLNode<T>* doubleWithRightChild(AVLNode<T>*&); //Case 3

    bool contains(const T&) const; //Calls other contains method with root
    bool isEmpty() const; //Returns if tree has no elements
    void empty() const; //Empty the tree (Calls other empty method)
    void display(AVLNode<T>*,T);

private:
    AVLNode<T>* root;
    void empty(AVLNode<T>*&) const; //Empty a node
    bool contains(const T&,AVLNode<T>*) const; //Returns if element exists in tree
    void insert(const T&,AVLNode<T>*&); //Insert element into AVL tree
    int height(AVLNode<T>*) const; //Height of AVL tree

};

//Constructor
template<class T>
AVLtree<T>::AVLtree()
{
    root = NULL;

}

//Copy Constructor
template<class T>
AVLtree<T>::AVLtree(const AVLtree & rhs)
{
    *this = rhs;

}

//Destructor
template<class T>
AVLtree<T>::~AVLtree()
{
    empty();
}

//Returns root
template<class T>
AVLNode<T>* AVLtree<T>::getRoot()
{
    return root;

}

//Calls other insert method with root
template<class T>
void AVLtree<T>::insert(const T& x)
{
    insert(x,root);

}

//Insert element into AVL tree
template<class T>
void AVLtree<T>::insert(const T& value, AVLNode<T>*& t)
{
    //Root is empty
    if(t == nullptr)
    {
        root = new AVLNode<T>;
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
    }

    //Value less than root
    else if (t->data > value)
    {
        insert(value, t->left); //Inserting to left
        if( height(t->left) - height(t->right) == 2 )
        {
            if(t->left->data > value) //Left subtree of left child
                rotateWithLeftChild(t); //Case 1
            else
                doubleWithLeftChild(t); //Case 2
        }
    }

    //Value greater than root
    else if (t->data < value)
    {
        insert(value, t->right); //Inserting to right
        if( height(t->right) - height(t->left) == 2 )
        {
            if(t->right->data < value) //Right subtree of right child
                rotateWithRightChild(t); //Case 4
            else
                doubleWithRightChild(t); //Case 3
        }
    }

    t->height = max(height(t->left), height(t->right)) +1;

}

//Calls other height method
template<class T>
int AVLtree<T>::height() const
{
    return height(root);

}

//Returns height of AVL tree
template<class T>
int AVLtree<T>::height(AVLNode<T>* curr) const
{
    return curr == NULL ? -1 : curr->height;

}

//Returns balance factor of a node
template<class T>
int AVLtree<T>::heightDiff(AVLNode<T>* curr)
{
    int lHeight = height(curr->left);
    int rHeight = height(curr->right);

    int bFactor = lHeight - rHeight;

    return bFactor;

}

//Max of two elements
template<class T>
int AVLtree<T>::max(int lhs, int rhs) const
{
    return lhs > rhs ? lhs : rhs;

}

//Calls other findMin method
template<class T>
const T& AVLtree<T>::findMin() const
{
    return findMin(root)->data;

}

//Find smallest element in tree
template<class T>
AVLNode<T>* AVLtree<T>::findMin(AVLNode<T>* t) const
{
    if(t == NULL)
        return NULL;
    if(t->left == NULL)
        return t;
    return findMin(t->left);

}

//Calls other findMax method
template<class T>
const T& AVLtree<T>::findMax() const
{
    return findMax(root)->data;

}

//Find largest element in tree
template<class T>
AVLNode<T>* AVLtree<T>::findMax(AVLNode<T>* t) const
{
    if(t == NULL)
        return NULL;
    if(t->right == NULL)
        return t;
    return findMax(t->right);

}

//Case 1
template<class T>
AVLNode<T>* AVLtree<T>::rotateWithLeftChild(AVLNode<T>*& k2)
{
    AVLNode<T>* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( height(k2->left), height(k2->right) ) +1;
    k1->height = max( height(k1->left), height(k1->right) ) +1;
    k2 = k1; //Parent node pointer

}

//Case 2
template<class T>
AVLNode<T>* AVLtree<T>::doubleWithLeftChild(AVLNode<T>*& k1)
{
    rotateWithRightChild(k1->left); //Turn into Case 1
    rotateWithLeftChild(k1);

}

//Case 4
template<class T>
AVLNode<T>* AVLtree<T>::rotateWithRightChild(AVLNode<T>*& k2)
{
    AVLNode<T>* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max( height(k2->left), height(k2->right) ) +1;
    k1->height = max( height(k1->left), height(k1->right) ) +1;
    k2 = k1; //Parent node pointer

}

//Case 3
template<class T>
AVLNode<T>* AVLtree<T>::doubleWithRightChild(AVLNode<T>*& k1)
{
    rotateWithLeftChild(k1->left); //Turn into Case 4
    rotateWithRightChild(k1);

}

//Calls other contains method with root
template<class T>
bool AVLtree<T>::contains(const T& element) const
{
    return contains(element,root);

}

//Returns if element exists in tree
template<class T>
bool AVLtree<T>::contains(const T& element, AVLNode<T>* t) const
{
    if( t == NULL )
        return false;
    else if( t->data > element )
        return contains( element, t->left );
    else if( t->data < element )
        return contains( element, t->right );
    else //Elements match
        return true;

}

//Returns if tree has no elements
template<class T>
bool AVLtree<T>::isEmpty() const
{
    return (root == NULL);

}

//Empty the tree (Calls other empty method)
template<class T>
void AVLtree<T>::empty() const
{
    //empty(root);
}

//Empty a node
template<class T>
void AVLtree<T>::empty(AVLNode<T>*& node) const
{
    if(node != NULL)
    {
        empty(node->left);
        empty(node->right);
        delete node;
    }
    node = NULL;

}

template<class T>
void AVLtree<T>::display(AVLNode<T>*,T)
{


}

#endif // AVLTREE_H
