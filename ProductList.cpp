// File: ProductList.cpp  (implementation file)

#include <iostream>
#include"ProductList.h"
using namespace std;
using std::string;

// ----------------------------- Member Functions ----------------------
// ProductList - Constructor
ProductList::ProductList(){
	head = NULL; cursor = NULL;  previous = NULL;
}

// ProductList - Destructor
ProductList::~ProductList(){
	makeListEmpty();
}

bool ProductList::listIsEmpty() const{
	return (head == NULL);
}


bool ProductList::curIsEmpty() const{
	return (cursor == NULL);
}


void ProductList::toFirst(){
	cursor = head;  previous = NULL;
}


bool ProductList::atFirst() const{
	return (cursor == head);
}


void ProductList::advance(){
	previous = cursor;
	cursor = cursor->next;
}


void ProductList::toEnd(){
	toFirst();
	if (! listIsEmpty())
		while ( cursor->next != NULL) advance();
}


bool ProductList::atEnd() const{
	if ( listIsEmpty()) return true;
		else if (curIsEmpty()) return false;
			else return (cursor->next == NULL);
}


int ProductList::listSize() const{
	Node *temp; // node * q;
	int count = 0;
	temp = head;
	while (temp != NULL)
	{
		count++; 	
		temp = temp->next;
	}
	return count;
}

// ------------------------ insert Functions ------------------------------

void ProductList::insertFirst(const int &k, const string &d ){
	Node *pnew; //NodePointer pnew; 
	pnew = new Node;
	pnew->key = k; pnew->data = d;
	pnew->next = head;
	head = pnew;
	cursor = head;
	previous = NULL;
}

void ProductList::insertAfter(const int &k, const string &d ){
	Node *pnew; //NodePointer pnew; 
	pnew = new Node;
	pnew->key = k; pnew->data = d;
	pnew->next = cursor->next;
 	cursor->next = pnew;
 	previous = cursor;
 	cursor = pnew;
}

void ProductList::insertBefore(const int &k, const string &d){
	Node *pnew; //NodePointer pnew; 
	pnew = new Node;
	pnew->key = k; pnew->data = d;
	pnew->next = cursor; //pnew->next = prev ->next
    previous->next = pnew;
	cursor = pnew;
}

void ProductList::insertEnd(const int &k, const string &d){
	if (listIsEmpty()) insertFirst(k,d);
	else {toEnd(); insertAfter(k,d); }
}


// ------------------------- update Functions -----------------------------

void ProductList::updateData(const string &d){
	cursor->data = d;
}

void ProductList::retrieveData(string &d, int &k) const {
	d = cursor->data; //return cursor->data
	k = cursor ->key;
}

void ProductList::retrieveKey(int &k) const {
	k = cursor->key; //return cursor->data
}

// ------------------------- delete Functions -----------------------------

void ProductList::deleteNode(){
	Node *q;
   	if(! curIsEmpty())
	{			// current node is not empty
		if (atFirst()) 	// delete head node
   		{	q = cursor;
			cursor = cursor->next;
			head = cursor;
      		delete q;
      		//q= head;
      		//head = head->next;
      		//cursor = head;
      		//delete q;
		}

		else 		// delete non-head node
   		{	q = cursor;
			cursor = cursor->next;
			previous->next = cursor;
			delete q;
		}
   }
}


void ProductList::deleteFirst()
{
	if(! listIsEmpty()) {toFirst(); deleteNode();}
}


void ProductList::deleteEnd()
{
	if(! listIsEmpty()) {toEnd(); deleteNode();}
}


void ProductList::makeListEmpty()
{
	//head = NULL, prev = NULL , cursor = NULL
     toFirst();
     while (! listIsEmpty())
        deleteNode();
}

// ------------------------- search Functions -----------------------------

bool ProductList::search(const int &k)
{
	bool found = false;
  	toFirst();
	while ((! found) && (cursor != NULL))
		if (k == cursor->key)  found = true;
			else advance();
	return found;
}


void ProductList::orderInsert(const string &d, const int &k)
{
	toFirst();
	while ((cursor != NULL) && (k > cursor->key)) advance();
	
	if (previous == NULL)  insertFirst(k,d);
		else insertBefore(k,d);
}


void ProductList::traverse(){
	
	toFirst();
	while (! curIsEmpty())
	{
		cout <<" # "<< cursor->key << " - "<< cursor->data << cursor->key << endl;
		advance();
	}
}



