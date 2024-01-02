#include <iostream>
#include <string>
#include <cassert>
#include <string>
#include "List.h"
#include "ListNode.h"

int main()
{
    using namespace std;
    using namespace cs32;

    // test code

    // the get function enables a client to iterate over all elements of a List
    List l1;
    assert(l1.min() == "");
    l1.addToFront("Hawkeye");
    l1.addToFront("Thor");
    l1.addToFront("Hulk");
    l1.addToFront("Black Widow");
    l1.addToFront("Iron Man");
    l1.addToFront("Captain America");
    for (int k = 0; k < l1.size(); k++)
    {
        string x;
        l1.get(k, x);
        cout << x << endl;
    }
    // should print: 
    // Captain America
    // Iron Man
    // Black Widow
    // Hulk
    // Thor
    // Hawkeye

    assert(l1.position("Hawkeye") == 5);
    assert(l1.position("Thor") == 4);
    assert(l1.position("Hulk") == 3);
    assert(l1.position("Black Widow") == 2);
    assert(l1.position("Iron Man") == 1);
    assert(l1.position("Captain America") == 0);
    assert(l1.position("Not there") == -1);

    assert(l1.before("Not there", "Hulk") == false);
    assert(l1.before("Hulk", "Not there") == false);
    assert(l1.before("Hulk", "Captain America") == false);
    assert(l1.before("Black Widow", "Hulk") == true);
    assert(l1.before("Captain America", "Hulk") == true);

    assert(l1.min() == "Black Widow");

    l1.removeAllBiggerThan("Happy");
    // now just "Captain America", "Black Widow"
    assert(l1.size() == 2);
    assert(l1.position("Hawkeye") == -1);
    assert(l1.position("Thor") == -1);
    assert(l1.position("Hulk") == -1);
    assert(l1.position("Black Widow") == 1);
    assert(l1.position("Iron Man") == -1);
    assert(l1.position("Captain America") == 0);
    assert(l1.position("Not there") == -1);

    List list;
    assert(list.size() == 0); // Empty list, size should be 0
    list.addToFront("A");
    assert(list.size() == 1); // After adding one element, size should be 1
    list.addToFront("B");
    assert(list.size() == 2); // After adding another element, size should be 2

    // Test position() function
    string tempA = "A";
    assert(list.position(tempA) == 1); // "A" is at index 1
    string tempB = "B";
    assert(list.position(tempB) == 0); // "B" is at index 0
    string tempC = "C";
    assert(list.position(tempC) == -1); // "C" is not in the list, should return -1

    // Test before() function
    string tempBeforeA = "A";
    string tempBeforeB = "B";
    assert(list.before(tempBeforeA, tempBeforeB) == false); // "A" comes before "B"
    assert(list.before(tempBeforeB, tempBeforeA) == true); // "B" does not come before "A"
    assert(list.before(tempBeforeA, tempBeforeA) == false); // "A" doesn't come before itself

    // Test get() function
    std::string data;
    assert(list.get(0, data) == true && data == "B"); // Element at index 0 is "B"
    assert(list.get(1, data) == true && data == "A"); // Element at index 1 is "A"
    assert(list.get(2, data) == false); // Index 2 is out of bounds, should return false

    // Test min() function
    assert(list.min() == "A"); // "A" is the smallest item in the list
    list.addToFront("C");
    assert(list.min() == "A"); // "A" is still the smallest after adding "C"
    list.makeEmpty();
    assert(list.min() == ""); // Empty list, should return an empty string

    // Test removeAllBiggerThan() function
    list.addToFront("B");
    list.addToFront("A");
    list.addToFront("C");
    string tempB2 = "B";
    list.removeAllBiggerThan(tempB2);
    assert(list.size() == 2); // After removing items bigger than "B", size should be 2
    assert(list.position("A") == 0); // "A" should still be at index 0
    assert(list.position("B") == 1); // "B" should still be at index 1
    assert(list.position("C") == -1); // "C" should be removed, position should be -1

    // Edge cases for size() function
    List emptyList;
    assert(emptyList.size() == 0); // Empty list, size should be 0

    // Edge cases for position() function
    List singleItemList;
    singleItemList.addToFront("A");
    assert(singleItemList.position(tempA) == 0); // Only one element in the list, should be at index 0
    assert(singleItemList.position(tempB) == -1); // Element not in the list, should return -1

    // Edge cases for before() function
    assert(singleItemList.before(tempBeforeA, tempBeforeB) == false); // Single item in the list, "A" doesn't come before "B"

    // Edge cases for get() function
    string emptyData;
    assert(emptyList.get(0, emptyData) == false); // Getting from an empty list, should return false

    // Edge cases for min() function
    assert(emptyList.min() == ""); // Empty list, should return an empty string

    // Edge cases for removeAllBiggerThan() function
    List listWithEqualValues;
    listWithEqualValues.addToFront("A");
    listWithEqualValues.addToFront("A");
    listWithEqualValues.addToFront("A");
    listWithEqualValues.removeAllBiggerThan(tempA);
    assert(listWithEqualValues.size() == 3); // All items are equal, none should be removed


    // Edge case for remove bigger than in an empty list




    cout << "all tests passed!" << endl;
    return(0);
}