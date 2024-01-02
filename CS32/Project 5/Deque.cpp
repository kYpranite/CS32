#ifndef DEQUE_CPP
#define DEQUE_CPP
#include "Deque.h"
#include <string>
#include <sstream>
using namespace std;
namespace cs32 {
template <typename Type>
Deque<Type>::Deque() // :      // TODO: CS 32 Students to complete code here
{
    // Should automatically be nullptr
    head = nullptr;
    tail = nullptr;
}
template <typename Type>
Deque<Type>::Deque( const Deque& rhs ) {
    if (rhs.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = new DequeNode<Type>( rhs.head->getElement() );
        tail = head;
        DequeNode<Type> *q = head;
        DequeNode<Type> *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new DequeNode<Type>( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            q->getNext()->setPrevious( q );
            tail = q->getNext();
            p = p->getNext();
            q = q->getNext();
        }
    }
}
template <typename Type>
Deque<Type>::~Deque() {
	makeEmpty();
}
template <typename Type>
bool Deque<Type>::isEmpty() const {
    if (head == nullptr) // if head is nullptr its empty
        return true;
    return( false );
}
template <typename Type>
void Deque<Type>::makeEmpty() {
    DequeNode<Type>* currNode = head; // iterates through the deque, and deletes each node until null
    while (currNode != nullptr) {
        head = currNode->getNext();
        delete currNode;
        currNode = head;
    }
    tail = nullptr; // tail cannot be uninitialized
}
template <typename Type>
void Deque<Type>::addToFront( const Type & data )
{
    // TODO: CS 32 Students to complete code here
    // DONE
    if (head == nullptr) { // if list is empty, need to set tail too
        head = new DequeNode<Type>(data); 
        tail = head;
    }
    else { // otherwise if lsit is not empty
        DequeNode<Type>* priorHead = head;
        head = new DequeNode<Type>(data, priorHead, nullptr); 
        priorHead->setPrevious(head);
    }
}
template <typename Type>
void Deque<Type>::addToRear( const Type & data )
{
    // TODO: CS 32 Students to complete code here
    if (tail == nullptr) { // if list is empty, need to set head
        tail = new DequeNode<Type>(data);
        head = tail;
    }
    else { // if list not empty
        DequeNode<Type>* priorTail = tail;
        tail = new DequeNode<Type>(data, nullptr, priorTail);
        priorTail->setNext(tail);
        tail->setPrevious(priorTail); // sets the new tail's previous
    }

    // DONE
}
template <typename Type>
void Deque<Type>::deleteFront( )
{   
    DequeNode<Type>* oldHead = head; // need to save the old head to delete later
    if (size() == 1) { // edge case where only 1 item in the list, need to set tail
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else if (head != nullptr) { 
        head = head->getNext();  
        head->setPrevious(nullptr); // don't leave tail uninitialized 
        delete oldHead;
    }
}
template <typename Type>
bool Deque<Type>::deleteItem( const Type & data )
{
    DequeNode<Type>* node = head;
    DequeNode<Type>* priornode = nullptr;
    while (node != nullptr) // iterates through deque to search
    { 
        if (node->getElement() == data) // found data to delete
        {
            if (priornode != nullptr) { // if not at head
                priornode->setNext(node->getNext());
                if (node == tail) { // edge case at end
                    tail = priornode; // need to set tail if you are deleting last node
                }
                else { // not at end
                    node->getNext()->setPrevious(priornode);
                }
            }
            else { // edge case at head
                if (node->getNext() == nullptr) { //if list size = 1
                    head = node->getNext();
                }
                else { // at head but list size > 1
                    head = node->getNext();
                    head->setPrevious(nullptr); // cant leave previous uninitialized
                }

            }
            delete(node);
            return true;
        }
        priornode = node;
        node = node->getNext(); // traverse
    }
    return( false );
}
template <typename Type>
Type Deque<Type>::front( ) const 
{
    Type result = Type(); // runs the no args default constructor for type incase head is null
    if (head != nullptr) { // nullptr check, essentially a getter
        result = head->getElement();
    }
    return( result );
}

template <typename Type>
Type Deque<Type>::rear( ) const // same logic as front()
{
    Type result = Type();
    if (tail != nullptr) {
        result = tail->getElement();
    }
    return( result );
}

template <typename Type>
void Deque<Type>::deleteRear( ) //same logic as delete front
{
    DequeNode<Type>* oldTail = tail;
    if (size() == 1) {  
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else if (tail != nullptr) {
        tail = tail->getPrevious();
        tail->setNext(nullptr);
        delete oldTail;
    }
}

// Howard is supplying code to convert a Type to a string using its operator <<
template <typename Type>
std::string Deque<Type>::to_string( const Type & value ) const
{
    stringstream s;
    // call the Type's operator <<
    s << value;
    return( s.str() );
}
template <typename Type>
std::string Deque<Type>::printItems() const
{
    string s;
    if (this->isEmpty()) { // edge case if empty
        s += "----> empty list";
    }
    else {
        s += "head -> ";
        DequeNode<Type>* currNode = head;
        while (currNode != nullptr) { // iterates through deque with element and ->
            s = s + to_string(currNode->getElement()) + " -> ";
            currNode = currNode->getNext();
        }
        s += "nullptr\n";
        s += "tail -> "; // also prints it backwards to test previous pointers
        currNode = tail;
        while (currNode != nullptr) {
            s = s + to_string(currNode->getElement()) + " -> ";
            currNode = currNode->getPrevious();
        }
        s += "nullptr";
    }
    return( s );
}
// Deep copy of linked list
template <typename Type>
const Deque<Type> & Deque<Type>::operator =( const Deque<Type> & rhs ) {
    // TODO: CS 32 Students to complete code here
    if (this != &rhs) {
        makeEmpty(); // clear list if not identical

        DequeNode<Type>* right = rhs.head; // rebuilding the list again from scratch, iterating through previous list and adding manually
        while (right != nullptr)
        {
            addToRear(right->getElement());
            right = right->getNext();
        }
    }
	return( *this );
}
template <typename Type>
size_t Deque<Type>::size() const
{
    size_t result = 0; // simply iterates through list and has a counter variable to see how many times you iterate
    DequeNode<Type>* currNode = head;
    while (currNode != nullptr) {
        result++;
        currNode = currNode->getNext();
    }
    return( result );
}
template <typename Type>
bool   Deque<Type>::get( int i, Type & data ) const
{
    // TODO: CS 32 Students to complete code here
    if (isEmpty() || i > size() - 1 || i < 0) { // lots of edge cases, list cannot be empty, i cannot be negative, i needs to be in bounds of the deque
        return false;
    }
    DequeNode<Type>* currNode = head;
    for (int j = 0; j < i; j++) { // iterates you to the current node given the eindex
        currNode = currNode->getNext();
    }
    data = currNode->getElement();
    return( true );
}

template <typename Type>
void Deque<Type>::deleteAllItems(const Type& data) {
    DequeNode<Type>* currNode = head;
    DequeNode<Type>* priorNode = nullptr;

    while (currNode != nullptr) {
        if (currNode->getElement() == data) { // found data to delete
            if (priorNode == nullptr) { // at head
                if (currNode->getNext() == nullptr) { // only item in list
                    delete currNode;
                    head = nullptr;
                    tail = nullptr;
                }
                else { // more than 1 item in list
                    head = currNode->getNext();
                    head->setPrevious(nullptr);
                    delete currNode;
                }
            }
            else { // not at head
                if (currNode == tail) { // edge case where currNode at tail
                    tail = currNode->getPrevious();
                    tail->setNext(nullptr);
                    delete currNode;
                }
                else {
                    priorNode->setNext(currNode->getNext()); // skipping node to delete
                    currNode->getNext()->setPrevious(priorNode);
                    delete currNode;
                }
            }
            // at any of these situations, currNode is now nullptr and we need to go back now
            // lowkey overcomplicated, you can also just currNode = currNode->getNext() right before you delete it
            if (priorNode == nullptr) {
                currNode = head;
            }
            else {
                currNode = priorNode;
                priorNode = currNode->getPrevious();
            }
        }
        else {
            priorNode = currNode;
            currNode = currNode->getNext();
        }


    }
}
/*
*  save c 
set b next to d
set d previous to b
delete b
skip getting next
*/
}





#endif
