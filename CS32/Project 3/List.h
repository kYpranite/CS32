#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include "ListNode.h"

namespace cs32 {

class List {
public:
	List();
	List( const List& rhs );
	~List();
	bool get(int i, std::string& data) const;
	bool isEmpty() const;
	bool before(const std::string& before, const std::string& after) const;
	void makeEmpty();
    void addToFront( const std::string & data );
    void addToRear( const std::string & data );
    void deleteItem( const std::string & data );
	void removeAllBiggerThan(const std::string& data);
    bool findItem( const std::string & data );
	int position(const std::string& data) const;
	size_t size() const;
    std::string printItems();
	std::string min() const;
	
	const List& operator =( const List& rhs );
private:
	ListNode * head;
	
};

}
#endif
