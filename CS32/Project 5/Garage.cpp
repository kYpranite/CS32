#include "Garage.h"
namespace cs32
{
Garage::Garage( size_t capacity ): mCapacity{capacity} // :       // TODO: CS 32 Students to complete code here
{
    // simple constructor list initialization
}
// put something in the garage
// silently, it purges something once the garage is full
bool Garage::tossIn( std::string s )
{
    if (mCapacity != 0) { // edge case if capacity is zero
        mDeque.addToFront(s);
    }
    if (mDeque.size() > mCapacity) { // checks if you went past capacity after adding
        mDeque.deleteRear(); // deletes last used item if you did
        return true;
    }
    return( false );
}
bool Garage::tossOut( std::string s )
{
    return mDeque.deleteItem(s); // delegated to deque's deleteItem
}
// use something from the garage
// must be findable, then moved to the used pile
bool Garage::use( std::string s ) 
{
    // TODO: CS 32 Students to complete code here
    bool result = mDeque.deleteItem(s); // deletes the item from the list, also saving result to see if it exists
    if (result) { // if it exists, add it again to the front
        mDeque.addToFront(s);
    }
    return( result );
}
// is it in the garage?
bool Garage::find( std::string s )
{
    Deque<std::string> temp = mDeque; // makes deep copy of list
    while (!temp.isEmpty()) {  // pops off the front until empty
        if (temp.front() == s) { // checks if the front is == to s
            return true;
        }
        temp.deleteFront(); // otherwse delete front
    }
    return( false );
}
// how much can this garage maximally hold?
size_t Garage::capacity()
{
    return mCapacity;
}
// how much is in this garage right now?
size_t Garage::size( )
{
    return mDeque.size();
}
std::string Garage::printItems( )
{
    return( mDeque.printItems() );
}
}
