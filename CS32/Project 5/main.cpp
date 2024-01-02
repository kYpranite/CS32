// Menu.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string>
#include <cassert>
#include "DequeNode.h"
#include "DequeNode.cpp"
#include "Deque.h"
#include "Deque.cpp"
#include "Garage.h"

int main()
{
    using namespace std;
    using namespace cs32;


    Deque<int> test;
    Deque<int> test2;

    test.deleteFront();
    test.deleteRear();
    test.addToFront(5);
    test.addToFront(3);
    test.addToFront(5);
    test.addToFront(2);
    test.addToFront(4);
    test.addToFront(11);
    test.addToRear(5);
    test.addToFront(10);
    test.addToFront(5);
    cout << test.printItems() << endl;
    test.deleteAllItems(5);
    cout << test.printItems() << endl;
    test.makeEmpty();
    test.addToFront(5);
    test.deleteAllItems(5);
    cout << test.printItems() << endl;
    cout << test.size() << endl;
    int i = 0;
    test.get(6, i);
    cout << i << endl;
    cout << test.front() << endl;
    cout << test.rear() << endl;
    test2 = test;
    test2.addToFront(123);
    cout << test2.printItems() << endl;
    cout << test.printItems() << endl;

    // Deque Tests

    Deque< int > dInt;
    dInt.deleteFront();
    dInt.deleteRear();
    int x;
    Deque< std::string > dString;
    std::string s;

    dInt.deleteFront();
    dInt.deleteRear();
    x = 12;
    assert(dInt.deleteItem(x) == false);
    assert(dInt.size() == 0);
    assert(dInt.get(-10, x) == false);
    assert(dInt.isEmpty());

    s = "Hello";
    dString.addToFront(s);
    s = "World!";
    dString.addToRear(s);
    s = "Howard";
    assert(dString.deleteItem(s) == false);
    assert(dString.size() == 2);
    assert(dString.get(-10, s) == false);
    assert(dString.isEmpty() == false);
    assert(dString.get(0, s) && s == "Hello");
    assert(dString.get(1, s) && s == "World!");
    dString.deleteFront();
    s = "Hello";
    assert(dString.deleteItem(s) == false);
    assert(dString.size() == 1);
    assert(dString.get(0, s) && s == "World!");
    assert(dString.isEmpty() == false);
    dString.deleteRear();
    s = "World!";
    assert(dString.deleteItem(s) == false);
    assert(dString.size() == 0);
    assert(dString.get(0, s) == false);
    assert(dString.isEmpty());


    cout << "all tests passed!" << endl;
    return(0);
}
