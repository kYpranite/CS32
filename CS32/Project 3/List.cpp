#include "List.h"

using namespace std;

namespace cs32 {

List::List() {
	head = nullptr;
}

List::List( const List& rhs ) {
    if (rhs.head == nullptr) head = nullptr;
    else {
        head = new ListNode( rhs.head->getElement() );
        ListNode *q = head;
        ListNode *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new ListNode( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            p = p->getNext( );
            q = q->getNext( );
        }
    }
}

List::~List() {
	makeEmpty();
}

size_t List::size() const {
    ListNode *currNode = head; //initialize node used to traverse to head
    size_t count = 0;
    while (currNode != nullptr) { //traverses to end of linked list (marked by nullptr)
        count++; //counts total number of nodes traversed
        currNode = currNode->getNext(); //moves to next node
    }
    return count;
}

int List::position(const std::string& data) const {
    int count = 0; //count represents current position
    ListNode* currNode = head; //initialize node used to traverse to head
    while (currNode != nullptr) { 
        if (currNode->getElement() == data) { //stops counting and returns current count if position has been found
            return count;
        }
        else {
            count++; //otherwise keep counting
        }
        currNode = currNode->getNext(); //moves node forward
    }
    return -1;
}

bool List::isEmpty() const {
	return( head == nullptr );
}

bool List::before(const std::string& before, const std::string& after) const {
    int posBefore = position(before); //uses previously defined position function
    int posAfter = position(after);

    if (posBefore == -1 || posAfter == -1) { //edge case where one of the positions are not in the list, returns false
        return false;
    }

    return posBefore < posAfter; //returns boolean that checks if before
}

bool List::get(int i, std::string& data) const { //data is passed by reference so can directly channge
    if (i > this->size()-1 || isEmpty()) { //edge case where list is empty, or index given is greater than list
        return false;
    }
    ListNode* currNode = head; //initialize node used to traverse to head
    for (int j = 0; j < i; j++) {
        currNode = currNode->getNext(); //traverses currNode to the given position, no need to worry about nullptr since the first if checks if in bounds already
    }
    data = currNode->getElement(); //gets the element
    return true; //if all of the previous statements succeded, we can safely assume that the position exists
}

void List::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

void List::addToFront( const std::string & data )
{
    ListNode * newnode = new ListNode( data );
    newnode->setNext( head );
    head = newnode;
}

void List::addToRear( const std::string & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode * newnode = new ListNode( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

void List::removeAllBiggerThan(const std::string& data) {
    ListNode* currNode = head; //initialize node used to traverse to head
    while (currNode != nullptr) {
        if (currNode->getElement() > data) { //uses string comparison < > to check if it is bigger than
            ListNode* temp = currNode; //saves the currNode pointer to temp
            currNode = currNode->getNext(); //traverses currNode forward one
            deleteItem(temp->getElement()); //deletes the previously saved currNode
        }
        else { //this else is needed since when deleting, you can't just traverse forward blindly
            currNode = currNode->getNext(); //if nothing is found, just traverse forward
        }
    }
}

void List::deleteItem( const std::string & data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;

        while( node != nullptr )
        {
            if (node->getElement() == data)
            {
                if (priornode != nullptr)
                    priornode->setNext( node->getNext( ) );
                else
                    head = node->getNext();
                delete( node );
                break;
            }
            priornode = node;
            node = node->getNext();
        }
}

bool List::findItem( const std::string & data )
{
    bool result = false;
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            result = true;
            break;
        }
        node = node->getNext();
    }
    return( result );
}

std::string List::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += node->getElement();
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}

std::string List::min() const {
    if (isEmpty()) { //returns empty string if list is empty
        return "";
    } 
    ListNode* currNode = head; //initialize node used to traverse to head
    string min = head->getElement(); //gets a minimum element to keep track of what is currently smallest

    while (currNode != nullptr) {
        if (currNode->getElement() < min) { // uses string comparison to compare min to element
            min = currNode->getElement(); //if smaller element found, replace min with it
        }
        currNode = currNode->getNext(); //traverses down the list
    }
    return min;
}


// Deep copy of linked list
const List& List::operator =( const List& rhs ) {
	if (this != &rhs) {
		makeEmpty();

        ListNode * right = rhs.head;

		while( right != nullptr )
        {
            addToRear( right->getElement() );
            right = right->getNext();
		}
	}

	return( *this );
}

}


