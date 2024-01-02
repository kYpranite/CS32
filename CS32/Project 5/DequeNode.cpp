#ifndef DEQUENODE_CPP
#define DEQUENODE_CPP


#include "DequeNode.h"
using namespace std;

namespace cs32 {

    template <typename Type>
    DequeNode<Type>::DequeNode(const Type& v, // uses constructor list initialization
        DequeNode* node,
        DequeNode* pre) : value{ v }, next{ node }, previous{ pre }// :     // TODO: CS 32 Students to complete code here
    {
        // TODO: CS 32 Students to complete code here
        // DONE
    }

    template <typename Type>
    Type DequeNode<Type>::getElement() const {
        return(value);
    }

    template <typename Type>
    DequeNode<Type>* DequeNode<Type>::getNext() const { 
        // TODO: CS 32 Students to complete code here
        // DONE 
        return next;
    }

    template <typename Type>
    void DequeNode<Type>::setNext(DequeNode<Type>* node) {
        // TODO: CS 32 Students to complete code here
        // DONE
        next = node;
    }

    template <typename Type>
    DequeNode<Type>* DequeNode<Type>::getPrevious() const {
        // TODO: CS 32 Students to complete code here
        // DONE
        return previous;
    }

    template <typename Type>
    void DequeNode<Type>::setPrevious(DequeNode<Type>* node) {
        // TODO: CS 32 Students to complete code here
        // DONE
        previous = node;
    }

}
#endif
