// File: ProductList.h

#ifndef PRODUCT_LIST_H
#define PRODUCT_LIST_H

using namespace std;
using std::string;

class ProductList {
private:
	
  // Node Class
    class Node{
    	
    	public:
    		int key;
    		string data;
    		double price;
    		Node* next;	
	};
	
	Node *head, *cursor ,  *previous;
	//typedef node * NodePointer;
	//NodePointer head, cursor, previous;
	    
public:
	// ----------------------------Member Functions------------------------------
	
    // (Constructor) Create an empty List	
    ProductList();

    // (Destructor) Destroy List
    ~ProductList();
    
    // Functions Prototype Definitions
    
    bool listIsEmpty() const;
	bool curIsEmpty() const;

    void toFirst();
	bool atFirst() const;
	
	void advance();
		
	void toEnd();
	bool atEnd() const;
	
	int listSize() const;
	
	//  insert Functions
	void insertFirst(const int &, const string & );	
	void insertAfter(const int &, const string & );	
	void insertBefore(const int &, const string & );
	void insertEnd(const int &, const string & );
	
	//  update Functions
	void updateData(const string & );
	void retrieveData(string &, int &) const;
	void retrieveKey(int &) const;
	
	//  delete Functions
	void deleteNode();
	void deleteFirst();
	void deleteEnd();
	void makeListEmpty();
	
	// search - orderInsert Functions
	bool search(const int & );
	void orderInsert(const string &, const int & );
	
	void traverse();
};

#endif // PRODUCT_LIST_H
